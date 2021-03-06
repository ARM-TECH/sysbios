/*
 * Copyright (c) 2013, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*
 *  ======== Mmu.xdc ========
 */

package ti.sysbios.family.arm.a15;

import xdc.rov.ViewInfo;

/*!
 *  ======== Mmu ========
 *  Memory Management Unit Manager.
 *
 *  This module allows the ARM processor to map a 32-bit virtual address
 *  to a 40-bit physical address (supports Large physical address extensions)
 *  and enable/disable the MMU. It does this through translation tables
 *  in memory. The MMU hardware supports upto 3-levels of translation tables.
 *  This module only supports the first 2 levels of translation tables.
 *  The level1 translation table is a 32B descriptor table comprising of
 *  four 64bit entries. There can be upto 4 level2 translation tables,
 *  each 4KB in size and comprising of 512 64bit entries.
 *
 *  Each entry in the level1 table either gives the base address and
 *  defines the attributes of a memory area of size 1GB or gives the
 *  address of the next level of translation table and some attributes
 *  for that translation.
 *
 *  Each entry in the level2 table either gives the base address and
 *  defines the attributes of a memory area of size 2MB or gives the
 *  address of the next level of translation table and some attributes
 *  for that translation.
 *
 *  By default, the MMU level1 and level2 translation tables are initialized
 *  with cache-enabled entries for every memory-segment defined in the
 *  platform (see {@link #cachePlatformMemory}). Cache-disabled entries are
 *  also added for the peripheral addresses used by SYS/BIOS
 *  (i.e. Timers, Interrupt controller).
 *
 *  The level1 translation table is placed in an output section called
 *  "ti.sysbios.family.arm.a15.mmuFirstLevelTableSection". Each of the
 *  level2 translation table is placed in output sections called
 *  "ti.sysbios.family.arm.a15.mmuSecondLevelTableSection0",
 *  "ti.sysbios.family.arm.a15.mmuSecondLevelTableSection1",
 *  "ti.sysbios.family.arm.a15.mmuSecondLevelTableSection2", and
 *  "ti.sysbios.family.arm.a15.mmuSecondLevelTableSection3". These
 *  sections are placed into the platform's default dataMemory and
 *  in order to minimize object file size,
 *  specified to not be initialized via the "NOLOAD" type on GNU compilers
 *  and "NOINIT" on TI compilers.
 *
 *  This module does not manage the third level descriptor tables.
 *
 *  The following is an example of how to place the MMU table
 *  and how to enable L1/L2 data caching for the address range
 *  0x80000000-0x90000000 in the *.cfg file:
 *
 *  @p(code)
 *
 *    var Mmu = xdc.useModule('ti.sysbios.family.arm.a15.Mmu');
 *
 *    // descriptor attribute structure
 *    var attrs = new Mmu.DescriptorAttrs();
 *
 *    Mmu.initDescAttrsMeta(attrs);
 *    attrs.type = Mmu.DescriptorType_BLOCK;    // BLOCK descriptor
 *    attrs.shareable = 3;                      // inner-sharerable
 *    attrs.attrIndx = 2;                       // MAIR0 Byte2 describes
 *                                              // memory attributes for
 *                                              // this level2 entry
 *
 *    // write memory region attribute in mairRegAttr[2] i.e. MAIR0 Reg Byte2
 *    Mmu.setMAIRMeta(2, 0xFF);              // Mark mem regions as cacheable
 *
 *    // Set the descriptor for each entry in the address range
 *    for (var i=0x80000000; i < 0x90000000; i = i + 0x00200000) {
 *        // Each 'BLOCK' descriptor entry spans a 2MB address range
 *        Mmu.setSecondLevelDescMeta(i, i, attrs);
 *    }
 *
 *    var memmap = Program.cpu.memoryMap;
 *    var DDR = null;
 *
 *    // Find DDR in memory map
 *    for (var i=0; i < memmap.length; i++) {
 *        if (memmap[i].name == "DDR") {
 *            DDR = memmap[i];
 *        }
 *    }
 *
 *    // Place the MMU table in the DDR memory segment if it exists
 *    if (DDR != null) {
 *        var sectionName =
 *                  "ti.sysbios.family.arm.a15.mmuSecondLevelTableSection2";
 *        Program.sectMap[sectionName] = new Program.SectionSpec();
 *        Program.sectMap[sectionName].type = "NOLOAD";
 *        Program.sectMap[sectionName].loadSegment = "DDR";
 *    }
 *    else {
 *        print("No DDR memory segment was found");
 *    }
 *
 *  @p
 *
 *  The following example demonstrates how to add a peripheral's address
 *  to the MMU table so that it can be accessed by code at runtime:
 *
 *  @p(code)
 *    var Cache = xdc.useModule('ti.sysbios.family.arm.a15.Cache');
 *    var Mmu = xdc.useModule('ti.sysbios.family.arm.a15.Mmu');
 *
 *    // Enable the cache
 *    Cache.enableCache = true;
 *
 *    // Enable the MMU (Required for L1/L2 data caching)
 *    Mmu.enableMMU = true;
 *
 *    // descriptor attribute structure
 *    var peripheralAttrs = new Mmu.DescriptorAttrs();
 *
 *    Mmu.initDescAttrsMeta(peripheralAttrs);
 *
 *    peripheralAttrs.type = Mmu.DescriptorType_BLOCK;  // BLOCK descriptor
 *    peripheralAttrs.noExecute = true;                 // not executable
 *    peripheralAttrs.accPerm = 0;                      // read/write at PL1
 *    peripheralAttrs.attrIndx = 1;                     // MAIR0 Byte1 describes
 *                                                      // memory attributes for
 *                                                      // each BLOCK MMU entry
 *
 *    // write memory region attribute in mairRegAttr[1] i.e. MAIR0 Reg Byte1
 *    Mmu.setMAIRMeta(1, 0x0);    // Mark mem regions as strongly ordered memory
 *
 *    // Define the base address of the 2 MB page
 *    // the peripheral resides in.
 *    var peripheralBaseAddr = 0xa0400000;
 *
 *    // Configure the corresponding MMU page descriptor accordingly
 *    Mmu.setSecondLevelDescMeta(peripheralBaseAddr,
 *                               peripheralBaseAddr,
 *                               peripheralAttrs);
 *  @p
 *
 *  The following example demonstrates how to modify the first level MMU entry
 *  at runtime. This example changes the descriptor type of the first level
 *  table entry from Table (default) to Block (maps memory region of size 1GB).
 *
 *  @p(code)
 *  ...
 *
 *  Void main(Int argc, Char * argv[])
 *  {
 *      Mmu_DescriptorAttrs attrs;
 *      Mmu_initDescAttrs(&attrs);
 *
 *      attrs.type = Mmu_DescriptorType_BLOCK;
 *      attrs.shareable = 0;            // non-shareable
 *      attrs.accPerm = 1;              // read/write at any privelege level
 *      attrs.attrIndx = 3;             // Use MAIR0 Register Byte 3 for
 *                                      // determining the memory attributes
 *                                      // for each MMU entry
 *
 *      // attrIndx[2] = 0b0 selects MAIR0
 *      // attrIndx[1:0] = 0b11 selects Byte 3 in MAIR0
 *      //
 *      // A value of 0x4F is written to Byte 3 of MAIR0. This marks the memory
 *      // as Normal Memory that is outer non-cacheable and inner write-back
 *      // cacheable for both reads and writes.
 *
 *      Mmu_setMAIR(3, 0x4F);
 *
 *      // Update the first level table's MMU entry for 0x80000000 with the
 *      // new attributes.
 *      Mmu_setFirstLevelDesc((Ptr)0x80000000, (UInt64)0x80000000, &attrs);
 *  }
 *
 *  @p
 *
 *  The following example demonstrates how to modify the memory attributes
 *  for a second level MMU entry at runtime.
 *
 *  @p(code)
 *  ...
 *
 *  Void main(Int argc, Char * argv[])
 *  {
 *      Mmu_DescriptorAttrs attrs;
 *      Mmu_initDescAttrs(&attrs);
 *
 *      attrs.type = Mmu_DescriptorType_BLOCK;
 *      attrs.shareable = 0;            // non-shareable
 *      attrs.accPerm = 1;              // read/write at any privelege level
 *      attrs.attrIndx = 4;             // Use MAIR1 Register Byte 0 for
 *                                      // determining the memory attributes
 *                                      // for each MMU entry
 *
 *      // attrIndx[2] = 0b1 selects MAIR1
 *      // attrIndx[1:0] = 0b00 selects Byte 0 in MAIR1
 *      //
 *      // A value of 0x4F is written to Byte 0 of MAIR1. This marks the memory
 *      // as Normal Memory that is outer non-cacheable and inner write-back
 *      // cacheable for both reads and writes.
 *
 *      Mmu_setMAIR(4, 0x4F);
 *
 *      // Update the MMU entry for 0x80000000 with the new attributes.
 *      Mmu_setSecondLevelDesc((Ptr)0x80000000, (UInt64)0x80000000, &attrs);
 *  }
 *
 *  @p
 *
 *  Notes:
 *  @p(blist)
 *      -There are size and alignment requirements on the third
 *       level descriptor tables depending on the page size.
 *      -See the {@link http://infocenter.arm.com/help/topic/com.arm.doc.ddi0406c/index.html ARM v7AR Architecture Reference Manual}
 *       for more info.
 *  @p
 *
 */

@Template ("./Mmu.xdt") /* generate function to init MMU page table */
@ModuleStartup

module Mmu
{
    const UInt NUM_LEVEL1_ENTRIES = 4;

    const UInt NUM_LEVEL2_ENTRIES = 512;

    // -------- ROV views --------

    /*! @_nodoc */
    metaonly struct PageView {
        String      Type;
        String      AddrVirtual;
        String      AddrPhysical;
        String      NextLevelTablePtr;
        Bool        NSTable;
        String      APTable;
        Bool        XNTable;
        Bool        PXNTable;
        Bool        NoExecute;
        Bool        PrivNoExecute;
        Bool        Contiguous;
        Bool        NotGlobal;
        Bool        AccessFlag;
        String      Shareable;
        String      AccessPerm;
        Bool        NonSecure;
        String      MemAttr;
        String      AttrIndx;
    };

    @Facet
    metaonly config ViewInfo.Instance rovViewInfo =
        ViewInfo.create({
            viewMap: [
                ['Level1View', {
                    type: ViewInfo.MODULE_DATA,
                    viewInitFxn: 'viewLevel1Page',
                    structName: 'PageView'
                }],
                ['Level2View', {
                    type: ViewInfo.TREE_TABLE,
                    viewInitFxn: 'viewLevel2Page',
                    structName: 'PageView'
                }]
           ]
       });

    /*!
     *  ======== First and Second Level descriptors ========
     *
     *  Different descriptor type encodings:
     *  @p(blist)
     *  - Invalid or Fault entry (0b00 or 0b10)
     *  - Block descriptor entry (0b01)
     *  - Table descriptor entry (0b11)
     *  @p
     *
     *  If a First-level table contains only one entry, it would be skipped,
     *  and the TTBR points to the Second-level table. This happens if the
     *  VA address range is 30 bits or less.
     */
    enum DescriptorType {
        DescriptorType_INVALID0 = 0,   /*! Virtual address is unmapped     */
        DescriptorType_BLOCK = 1,      /*! Block descriptor                */
        DescriptorType_INVALID1 = 2,   /*! Virtual address is unmapped     */
        DescriptorType_TABLE = 3       /*! Next-level table address        */
    };

    /*!
     *  Structure for setting first and second level descriptor entries
     *
     *  nsTable, apTable, xnTable and pxnTable fields are used only for
     *  DescriptorType.TABLE
     *
     *  noExecute, privNoExecute, contiguous, notGlobal, accessFlag, shareable,
     *  accPerm, nonSecure and attrIndx fields are used only for
     *  DescriptorType.BLOCK
     */
    struct DescriptorAttrs {
        DescriptorType type;    /*! first level descriptor type             */
        Bool  nsTable;          /*! security level for subsequent levels    */
        UInt8 apTable;          /*! access perm limit for subsequent levels */
        Bool  xnTable;          /*! XN limit for subsequent levels          */
        Bool  pxnTable;         /*! PXN limit for subsequent levels         */
        Bool  noExecute;        /*! execute-never bit                       */
        Bool  privNoExecute;    /*! privileged execute-never bit            */
        Bool  contiguous;       /*! hint bit indicating 16 adjacent table
                                    entries point to contiguos memory       */
        Bool  notGlobal;        /*! not global bit                          */
        Bool  accessFlag;       /*! access flag                             */
        UInt8 shareable;        /*! shareability field value 0-3            */
        UInt8 accPerm;          /*! access permission bits value 0-3        */
        Bool  nonSecure;        /*! non-secure bit                          */
        UInt8 attrIndx;         /*! stage 1 memory attributes index field for
                                    the indicated MAIRn register value 0-7  */
        UInt8 reserved;         /*! Bits[58:55] reserved for software use   */
    };

    /*!
     *  ======== A_nullPointer ========
     *  Assert raised when a pointer is null
     */
    config xdc.runtime.Assert.Id A_nullPointer  = {
        msg: "A_nullPointer: Pointer is null"
    };

    /*!
     *  ======== A_unknownDescType ========
     *  Assert raised when the descriptor type is not recognized.
     */
    config xdc.runtime.Assert.Id A_unknownDescType =
        {msg: "A_unknownDescType: Descriptor type is not recognized"};

    /*! default descriptor attributes structure */
    config DescriptorAttrs defaultAttrs = {
        type: DescriptorType_TABLE, /* TABLE descriptor */
        nsTable: false,         /* security level for subsequent levels    */
        apTable: 0,             /* access perm limit for subsequent levels */
        xnTable: false,         /* XN limit for subsequent levels          */
        pxnTable: false,        /* PXN limit for subsequent levels         */
        noExecute: false,       /* execute-never bit                       */
        privNoExecute: false,   /* privileged execute-never bit            */
        contiguous: false,      /* hint bit indicating 16 adjacent table
                                   entries point to contiguos memory       */
        notGlobal: false,       /* not global bit                          */
        accessFlag: true,       /* access flag                             */
        shareable: 0,           /* shareability field                      */
        accPerm: 0,             /* access permission bits                  */
        nonSecure: false,       /* non-secure bit                          */
        attrIndx: 0,            /* stage 1 memory attributes index field
                                   for the indicated MAIRn register        */
        reserved: 0             /* Bits[58:55] reserved for software use   */
    };

    /*!
     *  ======== enableMMU ========
     *  Configuration parameter to enable MMU.
     */
    config Bool enableMMU = true;

    /*!
     *  ======== cachePlatformMemory ========
     *  Flag to automatically mark platform's code/data/stack memory as
     *  cacheable in MMU descriptor table
     *
     *  By default, all memory regions defined in the platform an
     *  application is built with are marked as cacheable.
     *
     *  @see xdc.bld.Program#platform
     *
     *  If manual configuration of memory regions is required, set
     *  this config parameter to 'false'.
     */
    metaonly config Bool cachePlatformMemory = true;

    /*!
     *  ======== setMAIRMeta ========
     *  Statically sets the memory attribute encoding in the MAIRn register.
     *
     *  MAIR0 and MAIR1 provide the memory attribute encodings to the possible
     *  {@link #DescriptorAttrs attrIndx} values in a Long-descriptor format
     *  translation table entry for stage 1 translations (see {@link #setMAIR}
     *  for more details).
     *
     *  @param(attrIndx)     Select appropriate MAIR register (0 or 1)
     *                       and byte offset within selected register
     *  @param(attr)         Memory attribute encoding
     */
    metaonly Void setMAIRMeta(UInt attrIndx, UInt attr);

    /*!
     *  ======== initDescAttrsMeta ========
     *  Initializes the descriptor attribute structure
     *
     *   @param(attrs)        Pointer to descriptor attribute struct
     */
    metaonly Void initDescAttrsMeta(DescriptorAttrs *descAttrs);

    /*!
     *  ======== setFirstLevelDescMeta ========
     *  Statically sets the descriptor for the virtual address.
     *
     *  The first level table entry for the virtual address is mapped
     *  to the physical address with the attributes specified. The
     *  descriptor table is effective when the MMU is enabled.
     *
     *  @see ti.sysbios.family.arm.a15.Mmu
     *
     *  @param(virtualAddr)  The modified virtual address
     *  @param(phyAddr)      The physical address
     *  @param(attrs)        Pointer to first level descriptor attribute struct
     */
    metaonly Void setFirstLevelDescMeta(Ptr virtualAddr, UInt64 phyAddr,
                                        DescriptorAttrs attrs);

    /*!
     *  ======== setSecondLevelDescMeta ========
     *  Statically sets the descriptor for the virtual address.
     *
     *  The second level table entry for the virtual address is mapped
     *  to the physical address with the attributes specified. The
     *  descriptor table is effective when the MMU is enabled.
     *
     *  @see ti.sysbios.family.arm.a15.Mmu
     *
     *  @param(virtualAddr)  The modified virtual address
     *  @param(phyAddr)      The physical address
     *  @param(attrs)        Pointer to second level descriptor attribute struct
     */
    metaonly Void setSecondLevelDescMeta(Ptr virtualAddr, UInt64 phyAddr,
                                        DescriptorAttrs attrs);

    /*!
     *  ======== disable ========
     *  Disables the MMU.
     *
     *  If the MMU is already disabled, then simply return.
     *  Otherwise this function does the following:
     *  @p(blist)
     *  - If the L1 data cache is enabled, write back invalidate all
     *  of L1 data cache.
     *  - If the L1 program cache is enabled, invalidate all of L1
     *  program cache.
     *  @p
     *
     *  @a(Note)
     *  This function does not change the cache L1 data/program settings.
     */
    @DirectCall
    Void disable();

    /*!
     *  ======== enable ========
     *  Enables the MMU.
     *
     *  If the MMU is already enabled, then simply return.
     *  Otherwise this function does the following:
     *  @p(blist)
     *  If the L1 program cache is enabled, invalidate all of L1
     *  program cache.
     *  @p
     *
     *  @a(Note)
     *  This function does not change the L1 data/program cache settings.
     */
    @DirectCall
    Void enable();

    /*!
     *  ======== initDescAttrs() ========
     *  Initializes the descriptor attribute structure
     *
     *  @param(attrs)      Pointer to descriptor attribute struct
     */
    @DirectCall
    Void initDescAttrs(DescriptorAttrs *descAttrs);

    /*!
     *  ======== isEnabled ========
     *  Determines if the MMU is enabled
     */
    @DirectCall
    Bool isEnabled();

    /*!
     *  ======== setMAIR ========
     *  Sets the memory attribute encoding in the MAIRn register.
     *
     *  MAIR0 and MAIR1 provide the memory attribute encodings to the possible
     *  {@link #DescriptorAttrs attrIndx} values in a long-descriptor format
     *  translation table entry for stage 1 translations.
     *
     *  {@link #DescriptorAttrs attrIndx}[1:0] selects the ATTRn bit-field in
     *  the selected MAIR register.
     *
     *  {@link #DescriptorAttrs attrIndx}[2] selects the MAIR register.
     *  @p(blist)
     *   - If {@link #DescriptorAttrs attrIndx}[2] == 0, use MAIR0
     *   - If {@link #DescriptorAttrs attrIndx}[2] == 1, use MAIR1
     *  @p
     *
     *  Memory Attribute Indirection Register (MAIR) 0 and 1 bit assignments:
     *  @p(code)
     *        |31     |    24|23     |     16|15     |      8|7      |      0|
     *         --------------------------------------------------------------
     *  MAIR0 |     ATTR3    |     ATTR2     |     ATTR1     |     ATTR0     |
     *         --------------------------------------------------------------
     *  MAIR1 |     ATTR7    |     ATTR6     |     ATTR5     |     ATTR4     |
     *         --------------------------------------------------------------
     *  @p
     *
     *  SYS/BIOS assigns the following defaults to MAIR0 ATTR0, ATTR1 and ATTR2:
     *  @p(code)
     *  ATTR0 -> 0x44 (mark memory region as non-cacheable normal memory)
     *  ATTR1 -> 0x00 (mark memory region as strongly ordered and non-cacheable)
     *  ATTR2 -> 0xFF (mark memory region as normal memory, RW cacheable and
     *  RW allocate)
     *  @p
     *
     *  The level1 and level2 MMU Table entries use the above default
     *  attributes created by this module and should preferably not be
     *  changed. Please note that if the default value assigned to ATTR0 is
     *  changed, then the {@link #cachePlatformMemory} config param may not
     *  behave correctly as it uses this attribute to mark the memory as
     *  non-cacheable normal memory. If ATTR1 or ATTR2 are changed, it will
     *  affect all existing MMU Table entries which use ATTR1 or ATTR2.
     *
     *  For more details on MAIR0 and MAIR1 encodings please refer
     *  {@link http://infocenter.arm.com/help/topic/com.arm.doc.ddi0406c/index.html v7A ARM Architecture Reference Manual}
     *
     *  @param(attrIndx)     Select appropriate MAIR register (0 or 1)
     *                       and byte offset within the selected register
     *  @param(attr)         Memory attribute encoding
     */
    @DirectCall
    Void setMAIR(UInt attrIndx, UInt attr);

    /*!
     *  ======== setFirstLevelDesc ========
     *  Sets the descriptor for the virtual address.
     *
     *  The first level table entry for the virtual address is mapped
     *  to the physical address with the attributes specified. The
     *  descriptor table is effective when the MMU is enabled.
     *
     *  @see ti.sysbios.family.arm.a15.Mmu
     *
     *  @param(virtualAddr) The modified virtual address
     *  @param(phyAddr)     The physical address
     *  @param(attrs)       Pointer to first level descriptor attribute struct
     */
    @DirectCall
    Void setFirstLevelDesc(Ptr virtualAddr, UInt64 phyAddr,
                           DescriptorAttrs *attrs);

    /*!
     *  ======== setSecondLevelDesc ========
     *  Sets the descriptor for the virtual address.
     *
     *  The second level table entry for the virtual address is mapped
     *  to the physical address with the attributes specified. The
     *  descriptor table is effective when the MMU is enabled.
     *
     *  @see ti.sysbios.family.arm.a15.Mmu
     *
     *  @param(virtualAddr) The modified virtual address
     *  @param(phyAddr)     The physical address
     *  @param(attrs)       Pointer to second level descriptor attribute struct
     */
    @DirectCall
    Void setSecondLevelDesc(Ptr virtualAddr, UInt64 phyAddr,
                            DescriptorAttrs *attrs);

internal:

    /*! static array to hold first level dscriptor table */
    metaonly config UInt32 firstLevelTableBuf[];

    /*! static array to hold second level dscriptor table */
    metaonly config UInt32 secondLevelTableBuf[NUM_LEVEL1_ENTRIES][];

    /*!
     *  Memory Attribute Indirection Register 0 and 1
     */
    config UInt mairRegAttr[8];

    /*!
     *  ======== init ========
     *  initialize mmu registers
     */
    Void init();

    /*!
     *  ======== enableAsm ========
     *  Assembly function to enable the MMU.
     */
    Void enableAsm();

    /*!
     *  ======== disableAsm ========
     *  Assembly function to disable the MMU.
     */
    Void disableAsm();

    /*!
     *  ======== writeMAIRAsm ========
     */
    Void writeMAIRAsm(UInt attrIndx, UInt attr);

    /*! function generated to initialize first level descriptor table */
    Void initFirstLevelTableBuf(UInt64 *firstLevelTableBuf,
                                UInt64 **secondLevelTableBuf);

    /*! function generated to initialize second level descriptor table */
    Void initSecondLevelTableBuf(UInt64 **secondLevelTableBuf);

    /*! Module state */
    struct Module_State {
        /*
         *  32 Byte array for first-level descriptors
         */
        UInt64 firstLevelTableBuf[];

        /*
         *  4 KByte array for second-level descriptors
         */
        UInt64 secondLevelTableBuf[NUM_LEVEL1_ENTRIES][];

        /*
         *  Memory Attribute Indirection Register 0 and 1
         */
        UInt mairRegAttr[8];
    }
}
