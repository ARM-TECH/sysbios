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
 *  ======== Timer.xdc ========
 */

package ti.sysbios.family.arm.a9;

import xdc.rov.ViewInfo;

import xdc.runtime.Error;
import xdc.runtime.Types;

import ti.sysbios.family.arm.gic.Hwi;
import ti.sysbios.interfaces.ITimer;

/*!
 *  ======== Timer ========
 *  Private Timer Peripheral Manager for Arm Cortex-A9 family prcoessors
 *
 *  @p(html)
 *  <h3> Calling Context </h3>
 *  <table border="1" cellpadding="3">
 *    <colgroup span="1"></colgroup> <colgroup span="5" align="center"></colgroup>
 *
 *    <tr><th> Function                 </th><th>  Hwi   </th><th>  Swi   </th><th>  Task  </th><th>  Main  </th><th>  Startup  </th></tr>
 *    <!--                                                                                                                 -->
 *    <tr><td> {@link #getNumTimers}            </td><td>   Y    </td><td>   Y    </td><td>   Y    </td><td>   Y    </td><td>   N    </td></tr>
 *    <tr><td> {@link #getStatus}               </td><td>   Y    </td><td>   Y    </td><td>   Y    </td><td>   Y    </td><td>   N    </td></tr>
 *    <tr><td> {@link #Params_init}             </td><td>   Y    </td><td>   Y    </td><td>   Y    </td><td>   Y    </td><td>   N    </td></tr>
 *    <tr><td> {@link #construct}               </td><td>   Y    </td><td>   Y    </td><td>   Y    </td><td>   Y    </td><td>   N    </td></tr>
 *    <tr><td> {@link #create}                  </td><td>   N    </td><td>   N    </td><td>   Y    </td><td>   Y    </td><td>   N    </td></tr>
 *    <tr><td> {@link #delete}                  </td><td>   N    </td><td>   N    </td><td>   Y    </td><td>   Y    </td><td>   N    </td></tr>
 *    <tr><td> {@link #destruct}                </td><td>   Y    </td><td>   Y    </td><td>   Y    </td><td>   Y    </td><td>   N    </td></tr>
 *    <tr><td> {@link #getCount}                </td><td>   Y    </td><td>   Y    </td><td>   Y    </td><td>   N    </td><td>   N    </td></tr>
 *    <tr><td> {@link #getFreq}                 </td><td>   Y    </td><td>   Y    </td><td>   Y    </td><td>   Y    </td><td>   N    </td></tr>
 *    <tr><td> {@link #getPeriod}               </td><td>   Y    </td><td>   Y    </td><td>   Y    </td><td>   Y    </td><td>   N    </td></tr>
 *    <tr><td> {@link #reconfig}                </td><td>   Y    </td><td>   Y    </td><td>   Y    </td><td>   Y    </td><td>   N    </td></tr>
 *    <tr><td> {@link #setPeriod}               </td><td>   Y    </td><td>   Y    </td><td>   Y    </td><td>   Y    </td><td>   N    </td></tr>
 *    <tr><td> {@link #setPeriodMicroSecs}      </td><td>   Y    </td><td>   Y    </td><td>   Y    </td><td>   Y    </td><td>   N    </td></tr>
 *    <tr><td> {@link #start}                   </td><td>   Y    </td><td>   Y    </td><td>   Y    </td><td>   N    </td><td>   N    </td></tr>
 *    <tr><td> {@link #stop}                    </td><td>   Y    </td><td>   Y    </td><td>   Y    </td><td>   N    </td><td>   N    </td></tr>
 *    <tr><td colspan="6"> Definitions: <br />
 *       <ul>
 *         <li> <b>Hwi</b>: API is callable from a Hwi thread. </li>
 *         <li> <b>Swi</b>: API is callable from a Swi thread. </li>
 *         <li> <b>Task</b>: API is callable from a Task thread. </li>
 *         <li> <b>Main</b>: API is callable during any of these phases: </li>
 *           <ul>
 *             <li> In your module startup after this module is started (e.g. Timer_Module_startupDone() returns TRUE). </li>
 *             <li> During xdc.runtime.Startup.lastFxns. </li>
 *             <li> During main().</li>
 *             <li> During BIOS.startupFxns.</li>
 *           </ul>
 *         <li> <b>Startup</b>: API is callable during any of these phases:</li>
 *           <ul>
 *             <li> During xdc.runtime.Startup.firstFxns.</li>
 *             <li> In your module startup before this module is started (e.g. Timer_Module_startupDone() returns FALSE).</li>
 *           </ul>
 *       </ul>
 *    </td></tr>
 *
 *  </table>
 *  @p
 *
 */
@InstanceFinalize       /* To cleanup */
@InstanceInitError      /* To report unavailability of timer */
@ModuleStartup          /* to configure static timers */

module Timer inherits ti.sysbios.interfaces.ITimer
{
    /*! 
     *  Max value of Timer period for PeriodType_COUNTS
     */
    const UInt32 MAX_PERIOD = 0xFFFFFFFF;

    /*! Number of timer peripherals on chip */
    const Int NUM_TIMER_DEVICES = 1;

    /*! @_nodoc */
    @XmlDtd
    metaonly struct BasicView {
        Ptr         halTimerHandle;
        String      label;
        UInt        id;
        String      startMode;
        String      runMode;
        String      period;
        String      periodType;
        String      prescale;
        UInt        intNum;
        String      tickFxn[];
        UArg        arg;  
        String      extFreq;
        String      hwiHandle;
    };

    /*! @_nodoc */
    metaonly struct DeviceView {
        UInt        id;
        String      deviceAddr;
        UInt        intNum;
        String      period;
        String      currCount;
        String      remainingCount;
        String      prescale;
    }

    /*! @_nodoc */
    @Facet
    metaonly config ViewInfo.Instance rovViewInfo = 
        ViewInfo.create({
            viewMap: [
            [
                'Basic',
                {
                    type: ViewInfo.INSTANCE,
                    viewInitFxn: 'viewInitBasic',
                    structName: 'BasicView'
                }
            ],
            [
                'Device',
                {
                    type: ViewInfo.INSTANCE,
                    viewInitFxn: 'viewInitDevice',
                    structName: 'DeviceView'
                }
            ],
            ]
        });

    /*! 
     *  Error raised when timer id specified is not supported.
     */
    config Error.Id E_invalidTimer  = 
        {msg: "E_invalidTimer: Invalid Timer Id %d"}; 

    /*! 
     *  Error raised when timer requested is in use
     */
    config Error.Id E_notAvailable  = 
        {msg: "E_notAvailable: Timer not available %d"}; 

    /*! 
     *  Error raised when period requested is not supported
     */
    config Error.Id E_cannotSupport  = 
        {msg: "E_cannotSupport: Timer cannot support requested period %d"}; 

    /*!
     *  ======== intNumDef ========
     *  A9 Private Timer Interrupt number
     * 
     *  A9 Private Timer Interrupt is forwarded to GIC's private peripheral
     *  interrupt and has a architecture defined fixed mapping that should
     *  be same across all A9 variants.
     *
     *  Private Timer -> PPI1 or Interrupt #29
     */
    config UInt intNumDef[NUM_TIMER_DEVICES];

    /*!
     *  @_nodoc
     *  ======== anyMask ========
     *  Available mask to be used when select = Timer_ANY
     */
    config UInt anyMask = 0x1;

    /*!
     *  @_nodoc
     *  ======== availMask ========
     *  Available mask tracks the available/free timer peripherals
     */
    config UInt availMask = 0x1;

    /*!
     *  Private timer registers. Symbol "Timer_privateRegs" is a
     *  physical device.
     */
    struct PrivateRegs {
        UInt32 LOAD;
        UInt32 COUNTER;
        UInt32 CONTROL;
        UInt32 INTSTATUS;
    };

    extern volatile PrivateRegs privateRegs;

    /*!
     *  @_nodoc
     *  ======== stub ========
     *  This stub is used to acknowledge a Timer interrupt.
     *
     *  @param(arg)     Timer Handle.
     */
    @DirectCall
    Void stub(UArg arg);

    /*!
     *  @_nodoc
     *  ======== getHandle ========
     *  Used by TimestampProvider module to get hold of timer handle used by 
     *  Clock.
     *
     *  @param(id)      timer Id.
     */
    @DirectCall
    Handle getHandle(UInt id);

instance:

    /*! Hwi Params for Hwi Object. Default is null.*/
    config Hwi.Params *hwiParams = null;

    /*!
     *  ======== prescale ========
     *  Prescale factor.
     *
     *  The Prescale factor can be used to achieve longer timer periods.
     *  With a prescale factor specified, the actual timer period is
     *  period * (prescale + 1).
     */
    config UInt8 prescale = 0;

    /*!
     *  ======== reconfig ========
     *  Used to modify static timer instances at runtime.
     *
     *  @param(timerParams)     timer Params
     *  @param(tickFxn)         functions that runs when timer expires.
     */
    @DirectCall
    Void reconfig(FuncPtr tickFxn, const Params *timerParams, Error.Block *eb);

    /*!
     *  ======== setPrescale ========
     *  Set timer prescale value.
     *
     *  This function sets the value of the prescaler, and will also reload
     *  the timer counter and prescale registers.
     *
     *  @param(preScaler)       prescale value
     */
    Void setPrescale(UInt8 preScaler);

    /*!
     *  ======== getPrescale ========
     *  Get timer prescale value.
     *
     *  @b(returns)             prescale value
     */
    UInt8 getPrescale();

internal:   /* not for client use */
   
    /*!
     *  ======== startupNeeded ========
     *  Flag used to prevent misc code from being brought in
     *  un-necessarily
     */
    config UInt startupNeeded = false;

    /*!
     *  ======== privTimerRegBaseAddress ========
     *  Cortex-A9 Private Timer Register base address
     */
    metaonly config Ptr privTimerRegBaseAddress;

    /*
     *  ======== initDevice ========
     *  reset timer to its resting state
     */
    Void initDevice(Object *timer);

    /*
     *  ======== postInit ========
     *  finish initializing static and dynamic Timers
     */
    Int postInit(Object *timer, Error.Block *eb);

    /*
     *  ======== checkOverflow ========
     */
    Bool checkOverflow(UInt32 a, UInt32 b);

    struct Instance_State {
        Bool                staticInst;
        Int                 id;            
        ITimer.RunMode      runMode;    
        ITimer.StartMode    startMode;
        UInt32              period;
        ITimer.PeriodType   periodType;    
        UInt                intNum;
        UInt8               prescale;
        UArg                arg;  
        Hwi.FuncPtr         tickFxn;
        Types.FreqHz        extFreq;
        Hwi.Handle          hwi;
    }

    struct Module_State {
        UInt                availMask;  /* available peripherals */
        Handle              handles[];  /* array of handles based on id */
    }
}
