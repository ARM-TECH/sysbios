/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-y51
 */

/*
 * ======== GENERATED SECTIONS ========
 *     
 *     PROLOGUE
 *     INCLUDES
 *     
 *     INTERNAL DEFINITIONS
 *     MODULE-WIDE CONFIGS
 *     VIRTUAL FUNCTIONS
 *     FUNCTION DECLARATIONS
 *     CONVERTORS
 *     SYSTEM FUNCTIONS
 *     
 *     EPILOGUE
 *     STATE STRUCTURES
 *     PREFIX ALIASES
 */


/*
 * ======== PROLOGUE ========
 */

#ifndef ti_sysbios_family_arm_da830_TimestampProvider__include
#define ti_sysbios_family_arm_da830_TimestampProvider__include

#ifndef __nested__
#define __nested__
#define ti_sysbios_family_arm_da830_TimestampProvider__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_sysbios_family_arm_da830_TimestampProvider___VERS 150


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <ti/sysbios/family/arm/da830/package/package.defs.h>

#include <ti/sysbios/interfaces/ITimestamp.h>
#include <xdc/runtime/Assert.h>
#include <ti/sysbios/family/arm/da830/Hwi.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */

/* CountType */
enum ti_sysbios_family_arm_da830_TimestampProvider_CountType {
    ti_sysbios_family_arm_da830_TimestampProvider_CountType_CYCLES,
    ti_sysbios_family_arm_da830_TimestampProvider_CountType_INSTRUCTIONS
};
typedef enum ti_sysbios_family_arm_da830_TimestampProvider_CountType ti_sysbios_family_arm_da830_TimestampProvider_CountType;

/* IceCrusherRegs */
typedef xdc_UInt32 __T1_ti_sysbios_family_arm_da830_TimestampProvider_IceCrusherRegs__RES_58;
typedef xdc_UInt32 __ARRAY1_ti_sysbios_family_arm_da830_TimestampProvider_IceCrusherRegs__RES_58[10];
typedef __ARRAY1_ti_sysbios_family_arm_da830_TimestampProvider_IceCrusherRegs__RES_58 __TA_ti_sysbios_family_arm_da830_TimestampProvider_IceCrusherRegs__RES_58;
typedef xdc_UInt32 __T1_ti_sysbios_family_arm_da830_TimestampProvider_IceCrusherRegs__RES_BC;
typedef xdc_UInt32 __ARRAY1_ti_sysbios_family_arm_da830_TimestampProvider_IceCrusherRegs__RES_BC[14];
typedef __ARRAY1_ti_sysbios_family_arm_da830_TimestampProvider_IceCrusherRegs__RES_BC __TA_ti_sysbios_family_arm_da830_TimestampProvider_IceCrusherRegs__RES_BC;
struct ti_sysbios_family_arm_da830_TimestampProvider_IceCrusherRegs {
    xdc_UInt32 VER;
    xdc_UInt32 DBGCFG;
    xdc_UInt32 DBGCNTL;
    xdc_UInt32 RES_0C;
    xdc_UInt32 TRIGCNTL;
    xdc_UInt32 RSTCNTL;
    xdc_UInt32 THRDIDCLM;
    xdc_UInt32 THRDID;
    xdc_UInt32 INTCNTL;
    xdc_UInt32 ETMCNTL;
    xdc_UInt32 ETMPID;
    xdc_UInt32 TEST;
    xdc_UInt32 SWBRKCTL;
    xdc_UInt32 SWBRKVAL;
    xdc_UInt32 RES_38;
    xdc_UInt32 RES_3C;
    xdc_UInt32 BCNT0CTRL;
    xdc_UInt32 BCNT0;
    xdc_UInt32 RES_48;
    xdc_UInt32 RES_4C;
    xdc_UInt32 BCNT1CTRL;
    xdc_UInt32 BCNT1;
    __TA_ti_sysbios_family_arm_da830_TimestampProvider_IceCrusherRegs__RES_58 RES_58;
    xdc_UInt32 HWBRK0CTL;
    xdc_UInt32 HWBRK0ADR;
    xdc_UInt32 HWBRK0ADRMASK;
    xdc_UInt32 RES_8C;
    xdc_UInt32 HWBRK1CTL;
    xdc_UInt32 HWBRK1ADR;
    xdc_UInt32 HWBRK1ADRMASK;
    xdc_UInt32 RES_9C;
    xdc_UInt32 HWBRK2CTL;
    xdc_UInt32 HWBRK2ADR;
    xdc_UInt32 HWBRK2ADRMASK;
    xdc_UInt32 RES_AC;
    xdc_UInt32 HWBRK3CTL;
    xdc_UInt32 HWBRK3ADR;
    xdc_UInt32 HWBRK3ADRMASK;
    __TA_ti_sysbios_family_arm_da830_TimestampProvider_IceCrusherRegs__RES_BC RES_BC;
    xdc_UInt32 OS_LOCKSTS;
    xdc_UInt32 OS_LOCK;
    xdc_UInt32 DCON;
};

/* iceRegs */
#define ti_sysbios_family_arm_da830_TimestampProvider_iceRegs ti_sysbios_family_arm_da830_TimestampProvider_iceRegs
__extern volatile ti_sysbios_family_arm_da830_TimestampProvider_IceCrusherRegs ti_sysbios_family_arm_da830_TimestampProvider_iceRegs;


/*
 * ======== INTERNAL DEFINITIONS ========
 */


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__ti_sysbios_family_arm_da830_TimestampProvider_Module__diagsEnabled;
__extern __FAR__ const CT__ti_sysbios_family_arm_da830_TimestampProvider_Module__diagsEnabled ti_sysbios_family_arm_da830_TimestampProvider_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__ti_sysbios_family_arm_da830_TimestampProvider_Module__diagsIncluded;
__extern __FAR__ const CT__ti_sysbios_family_arm_da830_TimestampProvider_Module__diagsIncluded ti_sysbios_family_arm_da830_TimestampProvider_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16* CT__ti_sysbios_family_arm_da830_TimestampProvider_Module__diagsMask;
__extern __FAR__ const CT__ti_sysbios_family_arm_da830_TimestampProvider_Module__diagsMask ti_sysbios_family_arm_da830_TimestampProvider_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__ti_sysbios_family_arm_da830_TimestampProvider_Module__gateObj;
__extern __FAR__ const CT__ti_sysbios_family_arm_da830_TimestampProvider_Module__gateObj ti_sysbios_family_arm_da830_TimestampProvider_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__ti_sysbios_family_arm_da830_TimestampProvider_Module__gatePrms;
__extern __FAR__ const CT__ti_sysbios_family_arm_da830_TimestampProvider_Module__gatePrms ti_sysbios_family_arm_da830_TimestampProvider_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__ti_sysbios_family_arm_da830_TimestampProvider_Module__id;
__extern __FAR__ const CT__ti_sysbios_family_arm_da830_TimestampProvider_Module__id ti_sysbios_family_arm_da830_TimestampProvider_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__ti_sysbios_family_arm_da830_TimestampProvider_Module__loggerDefined;
__extern __FAR__ const CT__ti_sysbios_family_arm_da830_TimestampProvider_Module__loggerDefined ti_sysbios_family_arm_da830_TimestampProvider_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__ti_sysbios_family_arm_da830_TimestampProvider_Module__loggerObj;
__extern __FAR__ const CT__ti_sysbios_family_arm_da830_TimestampProvider_Module__loggerObj ti_sysbios_family_arm_da830_TimestampProvider_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__ti_sysbios_family_arm_da830_TimestampProvider_Module__loggerFxn0;
__extern __FAR__ const CT__ti_sysbios_family_arm_da830_TimestampProvider_Module__loggerFxn0 ti_sysbios_family_arm_da830_TimestampProvider_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__ti_sysbios_family_arm_da830_TimestampProvider_Module__loggerFxn1;
__extern __FAR__ const CT__ti_sysbios_family_arm_da830_TimestampProvider_Module__loggerFxn1 ti_sysbios_family_arm_da830_TimestampProvider_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__ti_sysbios_family_arm_da830_TimestampProvider_Module__loggerFxn2;
__extern __FAR__ const CT__ti_sysbios_family_arm_da830_TimestampProvider_Module__loggerFxn2 ti_sysbios_family_arm_da830_TimestampProvider_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__ti_sysbios_family_arm_da830_TimestampProvider_Module__loggerFxn4;
__extern __FAR__ const CT__ti_sysbios_family_arm_da830_TimestampProvider_Module__loggerFxn4 ti_sysbios_family_arm_da830_TimestampProvider_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__ti_sysbios_family_arm_da830_TimestampProvider_Module__loggerFxn8;
__extern __FAR__ const CT__ti_sysbios_family_arm_da830_TimestampProvider_Module__loggerFxn8 ti_sysbios_family_arm_da830_TimestampProvider_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__ti_sysbios_family_arm_da830_TimestampProvider_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__ti_sysbios_family_arm_da830_TimestampProvider_Module__startupDoneFxn ti_sysbios_family_arm_da830_TimestampProvider_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__ti_sysbios_family_arm_da830_TimestampProvider_Object__count;
__extern __FAR__ const CT__ti_sysbios_family_arm_da830_TimestampProvider_Object__count ti_sysbios_family_arm_da830_TimestampProvider_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__ti_sysbios_family_arm_da830_TimestampProvider_Object__heap;
__extern __FAR__ const CT__ti_sysbios_family_arm_da830_TimestampProvider_Object__heap ti_sysbios_family_arm_da830_TimestampProvider_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__ti_sysbios_family_arm_da830_TimestampProvider_Object__sizeof;
__extern __FAR__ const CT__ti_sysbios_family_arm_da830_TimestampProvider_Object__sizeof ti_sysbios_family_arm_da830_TimestampProvider_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__ti_sysbios_family_arm_da830_TimestampProvider_Object__table;
__extern __FAR__ const CT__ti_sysbios_family_arm_da830_TimestampProvider_Object__table ti_sysbios_family_arm_da830_TimestampProvider_Object__table__C;

/* A_counterInUse */
#define ti_sysbios_family_arm_da830_TimestampProvider_A_counterInUse (ti_sysbios_family_arm_da830_TimestampProvider_A_counterInUse__C)
typedef xdc_runtime_Assert_Id CT__ti_sysbios_family_arm_da830_TimestampProvider_A_counterInUse;
__extern __FAR__ const CT__ti_sysbios_family_arm_da830_TimestampProvider_A_counterInUse ti_sysbios_family_arm_da830_TimestampProvider_A_counterInUse__C;

/* A_intControlInUse */
#define ti_sysbios_family_arm_da830_TimestampProvider_A_intControlInUse (ti_sysbios_family_arm_da830_TimestampProvider_A_intControlInUse__C)
typedef xdc_runtime_Assert_Id CT__ti_sysbios_family_arm_da830_TimestampProvider_A_intControlInUse;
__extern __FAR__ const CT__ti_sysbios_family_arm_da830_TimestampProvider_A_intControlInUse ti_sysbios_family_arm_da830_TimestampProvider_A_intControlInUse__C;

/* benchmarkCounterId */
#ifdef ti_sysbios_family_arm_da830_TimestampProvider_benchmarkCounterId__D
#define ti_sysbios_family_arm_da830_TimestampProvider_benchmarkCounterId (ti_sysbios_family_arm_da830_TimestampProvider_benchmarkCounterId__D)
#else
#define ti_sysbios_family_arm_da830_TimestampProvider_benchmarkCounterId (ti_sysbios_family_arm_da830_TimestampProvider_benchmarkCounterId__C)
typedef xdc_UInt CT__ti_sysbios_family_arm_da830_TimestampProvider_benchmarkCounterId;
__extern __FAR__ const CT__ti_sysbios_family_arm_da830_TimestampProvider_benchmarkCounterId ti_sysbios_family_arm_da830_TimestampProvider_benchmarkCounterId__C;
#endif

/* countType */
#define ti_sysbios_family_arm_da830_TimestampProvider_countType (ti_sysbios_family_arm_da830_TimestampProvider_countType__C)
typedef ti_sysbios_family_arm_da830_TimestampProvider_CountType CT__ti_sysbios_family_arm_da830_TimestampProvider_countType;
__extern __FAR__ const CT__ti_sysbios_family_arm_da830_TimestampProvider_countType ti_sysbios_family_arm_da830_TimestampProvider_countType__C;


/*
 * ======== VIRTUAL FUNCTIONS ========
 */

/* Fxns__ */
struct ti_sysbios_family_arm_da830_TimestampProvider_Fxns__ {
    xdc_runtime_Types_Base* __base;
    const xdc_runtime_Types_SysFxns2* __sysp;
    xdc_Bits32 (*get32)(void);
    xdc_Void (*get64)(xdc_runtime_Types_Timestamp64*);
    xdc_Void (*getFreq)(xdc_runtime_Types_FreqHz*);
    xdc_runtime_Types_SysFxns2 __sfxns;
};

/* Module__FXNS__C */
__extern const ti_sysbios_family_arm_da830_TimestampProvider_Fxns__ ti_sysbios_family_arm_da830_TimestampProvider_Module__FXNS__C;


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define ti_sysbios_family_arm_da830_TimestampProvider_Module_startup ti_sysbios_family_arm_da830_TimestampProvider_Module_startup__E
xdc__CODESECT(ti_sysbios_family_arm_da830_TimestampProvider_Module_startup__E, "ti_sysbios_family_arm_da830_TimestampProvider_Module_startup")
__extern xdc_Int ti_sysbios_family_arm_da830_TimestampProvider_Module_startup__E( xdc_Int state );
xdc__CODESECT(ti_sysbios_family_arm_da830_TimestampProvider_Module_startup__F, "ti_sysbios_family_arm_da830_TimestampProvider_Module_startup")
__extern xdc_Int ti_sysbios_family_arm_da830_TimestampProvider_Module_startup__F( xdc_Int state );
xdc__CODESECT(ti_sysbios_family_arm_da830_TimestampProvider_Module_startup__R, "ti_sysbios_family_arm_da830_TimestampProvider_Module_startup")
__extern xdc_Int ti_sysbios_family_arm_da830_TimestampProvider_Module_startup__R( xdc_Int state );

/* Module__startupDone__S */
xdc__CODESECT(ti_sysbios_family_arm_da830_TimestampProvider_Module__startupDone__S, "ti_sysbios_family_arm_da830_TimestampProvider_Module__startupDone")
__extern xdc_Bool ti_sysbios_family_arm_da830_TimestampProvider_Module__startupDone__S( void );

/* get32__E */
#define ti_sysbios_family_arm_da830_TimestampProvider_get32 ti_sysbios_family_arm_da830_TimestampProvider_get32__E
xdc__CODESECT(ti_sysbios_family_arm_da830_TimestampProvider_get32__E, "ti_sysbios_family_arm_da830_TimestampProvider_get32")
__extern xdc_Bits32 ti_sysbios_family_arm_da830_TimestampProvider_get32__E( void );
xdc__CODESECT(ti_sysbios_family_arm_da830_TimestampProvider_get32__F, "ti_sysbios_family_arm_da830_TimestampProvider_get32")
__extern xdc_Bits32 ti_sysbios_family_arm_da830_TimestampProvider_get32__F( void );
__extern xdc_Bits32 ti_sysbios_family_arm_da830_TimestampProvider_get32__R( void );

/* get64__E */
#define ti_sysbios_family_arm_da830_TimestampProvider_get64 ti_sysbios_family_arm_da830_TimestampProvider_get64__E
xdc__CODESECT(ti_sysbios_family_arm_da830_TimestampProvider_get64__E, "ti_sysbios_family_arm_da830_TimestampProvider_get64")
__extern xdc_Void ti_sysbios_family_arm_da830_TimestampProvider_get64__E( xdc_runtime_Types_Timestamp64* result );
xdc__CODESECT(ti_sysbios_family_arm_da830_TimestampProvider_get64__F, "ti_sysbios_family_arm_da830_TimestampProvider_get64")
__extern xdc_Void ti_sysbios_family_arm_da830_TimestampProvider_get64__F( xdc_runtime_Types_Timestamp64* result );
__extern xdc_Void ti_sysbios_family_arm_da830_TimestampProvider_get64__R( xdc_runtime_Types_Timestamp64* result );

/* getFreq__E */
#define ti_sysbios_family_arm_da830_TimestampProvider_getFreq ti_sysbios_family_arm_da830_TimestampProvider_getFreq__E
xdc__CODESECT(ti_sysbios_family_arm_da830_TimestampProvider_getFreq__E, "ti_sysbios_family_arm_da830_TimestampProvider_getFreq")
__extern xdc_Void ti_sysbios_family_arm_da830_TimestampProvider_getFreq__E( xdc_runtime_Types_FreqHz* freq );
xdc__CODESECT(ti_sysbios_family_arm_da830_TimestampProvider_getFreq__F, "ti_sysbios_family_arm_da830_TimestampProvider_getFreq")
__extern xdc_Void ti_sysbios_family_arm_da830_TimestampProvider_getFreq__F( xdc_runtime_Types_FreqHz* freq );
__extern xdc_Void ti_sysbios_family_arm_da830_TimestampProvider_getFreq__R( xdc_runtime_Types_FreqHz* freq );

/* overflowHandler__I */
#define ti_sysbios_family_arm_da830_TimestampProvider_overflowHandler ti_sysbios_family_arm_da830_TimestampProvider_overflowHandler__I
xdc__CODESECT(ti_sysbios_family_arm_da830_TimestampProvider_overflowHandler__I, "ti_sysbios_family_arm_da830_TimestampProvider_overflowHandler")
__extern xdc_Void ti_sysbios_family_arm_da830_TimestampProvider_overflowHandler__I( xdc_UArg arg );

/* releaseCounters__I */
#define ti_sysbios_family_arm_da830_TimestampProvider_releaseCounters ti_sysbios_family_arm_da830_TimestampProvider_releaseCounters__I
xdc__CODESECT(ti_sysbios_family_arm_da830_TimestampProvider_releaseCounters__I, "ti_sysbios_family_arm_da830_TimestampProvider_releaseCounters")
__extern xdc_Void ti_sysbios_family_arm_da830_TimestampProvider_releaseCounters__I( void );


/*
 * ======== CONVERTORS ========
 */

/* Module_upCast */
static inline ti_sysbios_interfaces_ITimestamp_Module ti_sysbios_family_arm_da830_TimestampProvider_Module_upCast( void )
{
    return (ti_sysbios_interfaces_ITimestamp_Module)&ti_sysbios_family_arm_da830_TimestampProvider_Module__FXNS__C;
}

/* Module_to_ti_sysbios_interfaces_ITimestamp */
#define ti_sysbios_family_arm_da830_TimestampProvider_Module_to_ti_sysbios_interfaces_ITimestamp ti_sysbios_family_arm_da830_TimestampProvider_Module_upCast

/* Module_upCast2 */
static inline xdc_runtime_ITimestampProvider_Module ti_sysbios_family_arm_da830_TimestampProvider_Module_upCast2( void )
{
    return (xdc_runtime_ITimestampProvider_Module)&ti_sysbios_family_arm_da830_TimestampProvider_Module__FXNS__C;
}

/* Module_to_xdc_runtime_ITimestampProvider */
#define ti_sysbios_family_arm_da830_TimestampProvider_Module_to_xdc_runtime_ITimestampProvider ti_sysbios_family_arm_da830_TimestampProvider_Module_upCast2

/* Module_upCast3 */
static inline xdc_runtime_ITimestampClient_Module ti_sysbios_family_arm_da830_TimestampProvider_Module_upCast3( void )
{
    return (xdc_runtime_ITimestampClient_Module)&ti_sysbios_family_arm_da830_TimestampProvider_Module__FXNS__C;
}

/* Module_to_xdc_runtime_ITimestampClient */
#define ti_sysbios_family_arm_da830_TimestampProvider_Module_to_xdc_runtime_ITimestampClient ti_sysbios_family_arm_da830_TimestampProvider_Module_upCast3


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define ti_sysbios_family_arm_da830_TimestampProvider_Module_startupDone() ti_sysbios_family_arm_da830_TimestampProvider_Module__startupDone__S()

/* Object_heap */
#define ti_sysbios_family_arm_da830_TimestampProvider_Object_heap() ti_sysbios_family_arm_da830_TimestampProvider_Object__heap__C

/* Module_heap */
#define ti_sysbios_family_arm_da830_TimestampProvider_Module_heap() ti_sysbios_family_arm_da830_TimestampProvider_Object__heap__C

/* Module_id */
static inline CT__ti_sysbios_family_arm_da830_TimestampProvider_Module__id ti_sysbios_family_arm_da830_TimestampProvider_Module_id( void ) 
{
    return ti_sysbios_family_arm_da830_TimestampProvider_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool ti_sysbios_family_arm_da830_TimestampProvider_Module_hasMask( void ) 
{
    return ti_sysbios_family_arm_da830_TimestampProvider_Module__diagsMask__C != NULL;
}

/* Module_getMask */
static inline xdc_Bits16 ti_sysbios_family_arm_da830_TimestampProvider_Module_getMask( void ) 
{
    return ti_sysbios_family_arm_da830_TimestampProvider_Module__diagsMask__C != NULL ? *ti_sysbios_family_arm_da830_TimestampProvider_Module__diagsMask__C : 0;
}

/* Module_setMask */
static inline xdc_Void ti_sysbios_family_arm_da830_TimestampProvider_Module_setMask( xdc_Bits16 mask ) 
{
    if (ti_sysbios_family_arm_da830_TimestampProvider_Module__diagsMask__C != NULL) *ti_sysbios_family_arm_da830_TimestampProvider_Module__diagsMask__C = mask;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_sysbios_family_arm_da830_TimestampProvider__top__
#undef __nested__
#endif

#endif /* ti_sysbios_family_arm_da830_TimestampProvider__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(ti_sysbios_family_arm_da830_TimestampProvider__internalaccess))

#ifndef ti_sysbios_family_arm_da830_TimestampProvider__include_state
#define ti_sysbios_family_arm_da830_TimestampProvider__include_state

/* Module_State */
struct ti_sysbios_family_arm_da830_TimestampProvider_Module_State {
    xdc_UInt32 upper32Bits;
    ti_sysbios_family_arm_da830_Hwi_Handle hwi;
};

/* Module__state__V */
extern struct ti_sysbios_family_arm_da830_TimestampProvider_Module_State__ ti_sysbios_family_arm_da830_TimestampProvider_Module__state__V;

#endif /* ti_sysbios_family_arm_da830_TimestampProvider__include_state */

#endif


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_sysbios_family_arm_da830_TimestampProvider__nolocalnames)

#ifndef ti_sysbios_family_arm_da830_TimestampProvider__localnames__done
#define ti_sysbios_family_arm_da830_TimestampProvider__localnames__done

/* module prefix */
#define TimestampProvider_CountType ti_sysbios_family_arm_da830_TimestampProvider_CountType
#define TimestampProvider_IceCrusherRegs ti_sysbios_family_arm_da830_TimestampProvider_IceCrusherRegs
#define TimestampProvider_iceRegs ti_sysbios_family_arm_da830_TimestampProvider_iceRegs
#define TimestampProvider_Module_State ti_sysbios_family_arm_da830_TimestampProvider_Module_State
#define TimestampProvider_CountType_CYCLES ti_sysbios_family_arm_da830_TimestampProvider_CountType_CYCLES
#define TimestampProvider_CountType_INSTRUCTIONS ti_sysbios_family_arm_da830_TimestampProvider_CountType_INSTRUCTIONS
#define TimestampProvider_A_counterInUse ti_sysbios_family_arm_da830_TimestampProvider_A_counterInUse
#define TimestampProvider_A_intControlInUse ti_sysbios_family_arm_da830_TimestampProvider_A_intControlInUse
#define TimestampProvider_benchmarkCounterId ti_sysbios_family_arm_da830_TimestampProvider_benchmarkCounterId
#define TimestampProvider_countType ti_sysbios_family_arm_da830_TimestampProvider_countType
#define TimestampProvider_get32 ti_sysbios_family_arm_da830_TimestampProvider_get32
#define TimestampProvider_get64 ti_sysbios_family_arm_da830_TimestampProvider_get64
#define TimestampProvider_getFreq ti_sysbios_family_arm_da830_TimestampProvider_getFreq
#define TimestampProvider_Module_name ti_sysbios_family_arm_da830_TimestampProvider_Module_name
#define TimestampProvider_Module_id ti_sysbios_family_arm_da830_TimestampProvider_Module_id
#define TimestampProvider_Module_startup ti_sysbios_family_arm_da830_TimestampProvider_Module_startup
#define TimestampProvider_Module_startupDone ti_sysbios_family_arm_da830_TimestampProvider_Module_startupDone
#define TimestampProvider_Module_hasMask ti_sysbios_family_arm_da830_TimestampProvider_Module_hasMask
#define TimestampProvider_Module_getMask ti_sysbios_family_arm_da830_TimestampProvider_Module_getMask
#define TimestampProvider_Module_setMask ti_sysbios_family_arm_da830_TimestampProvider_Module_setMask
#define TimestampProvider_Object_heap ti_sysbios_family_arm_da830_TimestampProvider_Object_heap
#define TimestampProvider_Module_heap ti_sysbios_family_arm_da830_TimestampProvider_Module_heap
#define TimestampProvider_Module_upCast ti_sysbios_family_arm_da830_TimestampProvider_Module_upCast
#define TimestampProvider_Module_to_ti_sysbios_interfaces_ITimestamp ti_sysbios_family_arm_da830_TimestampProvider_Module_to_ti_sysbios_interfaces_ITimestamp
#define TimestampProvider_Module_upCast2 ti_sysbios_family_arm_da830_TimestampProvider_Module_upCast2
#define TimestampProvider_Module_to_xdc_runtime_ITimestampProvider ti_sysbios_family_arm_da830_TimestampProvider_Module_to_xdc_runtime_ITimestampProvider
#define TimestampProvider_Module_upCast3 ti_sysbios_family_arm_da830_TimestampProvider_Module_upCast3
#define TimestampProvider_Module_to_xdc_runtime_ITimestampClient ti_sysbios_family_arm_da830_TimestampProvider_Module_to_xdc_runtime_ITimestampClient

#endif /* ti_sysbios_family_arm_da830_TimestampProvider__localnames__done */
#endif
