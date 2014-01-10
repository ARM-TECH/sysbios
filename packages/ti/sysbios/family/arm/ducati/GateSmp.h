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
 *     PER-INSTANCE TYPES
 *     VIRTUAL FUNCTIONS
 *     FUNCTION DECLARATIONS
 *     FUNCTION SELECTORS
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

#ifndef ti_sysbios_family_arm_ducati_GateSmp__include
#define ti_sysbios_family_arm_ducati_GateSmp__include

#ifndef __nested__
#define __nested__
#define ti_sysbios_family_arm_ducati_GateSmp__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_sysbios_family_arm_ducati_GateSmp___VERS 150


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/IInstance.h>
#include <ti/sysbios/family/arm/ducati/package/package.defs.h>

#include <xdc/runtime/IGateProvider.h>
#include <xdc/runtime/Assert.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */

/* Q_BLOCKING */
#define ti_sysbios_family_arm_ducati_GateSmp_Q_BLOCKING (1)

/* Q_PREEMPTING */
#define ti_sysbios_family_arm_ducati_GateSmp_Q_PREEMPTING (2)


/*
 * ======== INTERNAL DEFINITIONS ========
 */


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__ti_sysbios_family_arm_ducati_GateSmp_Module__diagsEnabled;
__extern __FAR__ const CT__ti_sysbios_family_arm_ducati_GateSmp_Module__diagsEnabled ti_sysbios_family_arm_ducati_GateSmp_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__ti_sysbios_family_arm_ducati_GateSmp_Module__diagsIncluded;
__extern __FAR__ const CT__ti_sysbios_family_arm_ducati_GateSmp_Module__diagsIncluded ti_sysbios_family_arm_ducati_GateSmp_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16* CT__ti_sysbios_family_arm_ducati_GateSmp_Module__diagsMask;
__extern __FAR__ const CT__ti_sysbios_family_arm_ducati_GateSmp_Module__diagsMask ti_sysbios_family_arm_ducati_GateSmp_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__ti_sysbios_family_arm_ducati_GateSmp_Module__gateObj;
__extern __FAR__ const CT__ti_sysbios_family_arm_ducati_GateSmp_Module__gateObj ti_sysbios_family_arm_ducati_GateSmp_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__ti_sysbios_family_arm_ducati_GateSmp_Module__gatePrms;
__extern __FAR__ const CT__ti_sysbios_family_arm_ducati_GateSmp_Module__gatePrms ti_sysbios_family_arm_ducati_GateSmp_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__ti_sysbios_family_arm_ducati_GateSmp_Module__id;
__extern __FAR__ const CT__ti_sysbios_family_arm_ducati_GateSmp_Module__id ti_sysbios_family_arm_ducati_GateSmp_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__ti_sysbios_family_arm_ducati_GateSmp_Module__loggerDefined;
__extern __FAR__ const CT__ti_sysbios_family_arm_ducati_GateSmp_Module__loggerDefined ti_sysbios_family_arm_ducati_GateSmp_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__ti_sysbios_family_arm_ducati_GateSmp_Module__loggerObj;
__extern __FAR__ const CT__ti_sysbios_family_arm_ducati_GateSmp_Module__loggerObj ti_sysbios_family_arm_ducati_GateSmp_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__ti_sysbios_family_arm_ducati_GateSmp_Module__loggerFxn0;
__extern __FAR__ const CT__ti_sysbios_family_arm_ducati_GateSmp_Module__loggerFxn0 ti_sysbios_family_arm_ducati_GateSmp_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__ti_sysbios_family_arm_ducati_GateSmp_Module__loggerFxn1;
__extern __FAR__ const CT__ti_sysbios_family_arm_ducati_GateSmp_Module__loggerFxn1 ti_sysbios_family_arm_ducati_GateSmp_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__ti_sysbios_family_arm_ducati_GateSmp_Module__loggerFxn2;
__extern __FAR__ const CT__ti_sysbios_family_arm_ducati_GateSmp_Module__loggerFxn2 ti_sysbios_family_arm_ducati_GateSmp_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__ti_sysbios_family_arm_ducati_GateSmp_Module__loggerFxn4;
__extern __FAR__ const CT__ti_sysbios_family_arm_ducati_GateSmp_Module__loggerFxn4 ti_sysbios_family_arm_ducati_GateSmp_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__ti_sysbios_family_arm_ducati_GateSmp_Module__loggerFxn8;
__extern __FAR__ const CT__ti_sysbios_family_arm_ducati_GateSmp_Module__loggerFxn8 ti_sysbios_family_arm_ducati_GateSmp_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__ti_sysbios_family_arm_ducati_GateSmp_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__ti_sysbios_family_arm_ducati_GateSmp_Module__startupDoneFxn ti_sysbios_family_arm_ducati_GateSmp_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__ti_sysbios_family_arm_ducati_GateSmp_Object__count;
__extern __FAR__ const CT__ti_sysbios_family_arm_ducati_GateSmp_Object__count ti_sysbios_family_arm_ducati_GateSmp_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__ti_sysbios_family_arm_ducati_GateSmp_Object__heap;
__extern __FAR__ const CT__ti_sysbios_family_arm_ducati_GateSmp_Object__heap ti_sysbios_family_arm_ducati_GateSmp_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__ti_sysbios_family_arm_ducati_GateSmp_Object__sizeof;
__extern __FAR__ const CT__ti_sysbios_family_arm_ducati_GateSmp_Object__sizeof ti_sysbios_family_arm_ducati_GateSmp_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__ti_sysbios_family_arm_ducati_GateSmp_Object__table;
__extern __FAR__ const CT__ti_sysbios_family_arm_ducati_GateSmp_Object__table ti_sysbios_family_arm_ducati_GateSmp_Object__table__C;

/* A_nestedEnter */
#define ti_sysbios_family_arm_ducati_GateSmp_A_nestedEnter (ti_sysbios_family_arm_ducati_GateSmp_A_nestedEnter__C)
typedef xdc_runtime_Assert_Id CT__ti_sysbios_family_arm_ducati_GateSmp_A_nestedEnter;
__extern __FAR__ const CT__ti_sysbios_family_arm_ducati_GateSmp_A_nestedEnter ti_sysbios_family_arm_ducati_GateSmp_A_nestedEnter__C;

/* enableStats */
#ifdef ti_sysbios_family_arm_ducati_GateSmp_enableStats__D
#define ti_sysbios_family_arm_ducati_GateSmp_enableStats (ti_sysbios_family_arm_ducati_GateSmp_enableStats__D)
#else
#define ti_sysbios_family_arm_ducati_GateSmp_enableStats (ti_sysbios_family_arm_ducati_GateSmp_enableStats__C)
typedef xdc_Bool CT__ti_sysbios_family_arm_ducati_GateSmp_enableStats;
__extern __FAR__ const CT__ti_sysbios_family_arm_ducati_GateSmp_enableStats ti_sysbios_family_arm_ducati_GateSmp_enableStats__C;
#endif


/*
 * ======== PER-INSTANCE TYPES ========
 */

/* Params */
struct ti_sysbios_family_arm_ducati_GateSmp_Params {
    size_t __size;
    const void* __self;
    void* __fxns;
    xdc_runtime_IInstance_Params* instance;
    xdc_runtime_IInstance_Params __iprms;
};

/* Struct */
struct ti_sysbios_family_arm_ducati_GateSmp_Struct {
    const ti_sysbios_family_arm_ducati_GateSmp_Fxns__* __fxns;
    volatile xdc_UInt32 __f0;
    xdc_UInt __f1;
    xdc_UInt __f2;
    xdc_UInt __f3;
    xdc_UInt __f4;
    xdc_runtime_Types_CordAddr __name;
};


/*
 * ======== VIRTUAL FUNCTIONS ========
 */

/* Fxns__ */
struct ti_sysbios_family_arm_ducati_GateSmp_Fxns__ {
    xdc_runtime_Types_Base* __base;
    const xdc_runtime_Types_SysFxns2* __sysp;
    xdc_Bool (*query)(xdc_Int);
    xdc_IArg (*enter)(ti_sysbios_family_arm_ducati_GateSmp_Handle);
    xdc_Void (*leave)(ti_sysbios_family_arm_ducati_GateSmp_Handle, xdc_IArg);
    xdc_runtime_Types_SysFxns2 __sfxns;
};

/* Module__FXNS__C */
__extern const ti_sysbios_family_arm_ducati_GateSmp_Fxns__ ti_sysbios_family_arm_ducati_GateSmp_Module__FXNS__C;


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define ti_sysbios_family_arm_ducati_GateSmp_Module_startup( state ) (-1)

/* Instance_init__F */
xdc__CODESECT(ti_sysbios_family_arm_ducati_GateSmp_Instance_init__F, "ti_sysbios_family_arm_ducati_GateSmp_Instance_init")
__extern void ti_sysbios_family_arm_ducati_GateSmp_Instance_init__F( ti_sysbios_family_arm_ducati_GateSmp_Object*, const ti_sysbios_family_arm_ducati_GateSmp_Params* );

/* Instance_init__R */
xdc__CODESECT(ti_sysbios_family_arm_ducati_GateSmp_Instance_init__R, "ti_sysbios_family_arm_ducati_GateSmp_Instance_init")
__extern void ti_sysbios_family_arm_ducati_GateSmp_Instance_init__R( ti_sysbios_family_arm_ducati_GateSmp_Object*, const ti_sysbios_family_arm_ducati_GateSmp_Params* );

/* Handle__label__S */
xdc__CODESECT(ti_sysbios_family_arm_ducati_GateSmp_Handle__label__S, "ti_sysbios_family_arm_ducati_GateSmp_Handle__label")
__extern xdc_runtime_Types_Label* ti_sysbios_family_arm_ducati_GateSmp_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label* lab );

/* Module__startupDone__S */
xdc__CODESECT(ti_sysbios_family_arm_ducati_GateSmp_Module__startupDone__S, "ti_sysbios_family_arm_ducati_GateSmp_Module__startupDone")
__extern xdc_Bool ti_sysbios_family_arm_ducati_GateSmp_Module__startupDone__S( void );

/* Object__create__S */
xdc__CODESECT(ti_sysbios_family_arm_ducati_GateSmp_Object__create__S, "ti_sysbios_family_arm_ducati_GateSmp_Object__create")
__extern xdc_Ptr ti_sysbios_family_arm_ducati_GateSmp_Object__create__S( xdc_Ptr __oa, xdc_SizeT __osz, xdc_Ptr __aa, const xdc_UChar* __pa, xdc_SizeT __psz, xdc_runtime_Error_Block* __eb );

/* Object__delete__S */
xdc__CODESECT(ti_sysbios_family_arm_ducati_GateSmp_Object__delete__S, "ti_sysbios_family_arm_ducati_GateSmp_Object__delete")
__extern xdc_Void ti_sysbios_family_arm_ducati_GateSmp_Object__delete__S( xdc_Ptr instp );

/* Object__destruct__S */
xdc__CODESECT(ti_sysbios_family_arm_ducati_GateSmp_Object__destruct__S, "ti_sysbios_family_arm_ducati_GateSmp_Object__destruct")
__extern xdc_Void ti_sysbios_family_arm_ducati_GateSmp_Object__destruct__S( xdc_Ptr objp );

/* Object__get__S */
xdc__CODESECT(ti_sysbios_family_arm_ducati_GateSmp_Object__get__S, "ti_sysbios_family_arm_ducati_GateSmp_Object__get")
__extern xdc_Ptr ti_sysbios_family_arm_ducati_GateSmp_Object__get__S( xdc_Ptr oarr, xdc_Int i );

/* Object__first__S */
xdc__CODESECT(ti_sysbios_family_arm_ducati_GateSmp_Object__first__S, "ti_sysbios_family_arm_ducati_GateSmp_Object__first")
__extern xdc_Ptr ti_sysbios_family_arm_ducati_GateSmp_Object__first__S( void );

/* Object__next__S */
xdc__CODESECT(ti_sysbios_family_arm_ducati_GateSmp_Object__next__S, "ti_sysbios_family_arm_ducati_GateSmp_Object__next")
__extern xdc_Ptr ti_sysbios_family_arm_ducati_GateSmp_Object__next__S( xdc_Ptr obj );

/* Params__init__S */
xdc__CODESECT(ti_sysbios_family_arm_ducati_GateSmp_Params__init__S, "ti_sysbios_family_arm_ducati_GateSmp_Params__init")
__extern xdc_Void ti_sysbios_family_arm_ducati_GateSmp_Params__init__S( xdc_Ptr dst, xdc_Ptr src, xdc_SizeT psz, xdc_SizeT isz );

/* query__E */
#define ti_sysbios_family_arm_ducati_GateSmp_query ti_sysbios_family_arm_ducati_GateSmp_query__E
xdc__CODESECT(ti_sysbios_family_arm_ducati_GateSmp_query__E, "ti_sysbios_family_arm_ducati_GateSmp_query")
__extern xdc_Bool ti_sysbios_family_arm_ducati_GateSmp_query__E( xdc_Int qual );
xdc__CODESECT(ti_sysbios_family_arm_ducati_GateSmp_query__F, "ti_sysbios_family_arm_ducati_GateSmp_query")
__extern xdc_Bool ti_sysbios_family_arm_ducati_GateSmp_query__F( xdc_Int qual );
__extern xdc_Bool ti_sysbios_family_arm_ducati_GateSmp_query__R( xdc_Int qual );

/* enter__E */
#define ti_sysbios_family_arm_ducati_GateSmp_enter ti_sysbios_family_arm_ducati_GateSmp_enter__E
xdc__CODESECT(ti_sysbios_family_arm_ducati_GateSmp_enter__E, "ti_sysbios_family_arm_ducati_GateSmp_enter")
__extern xdc_IArg ti_sysbios_family_arm_ducati_GateSmp_enter__E( ti_sysbios_family_arm_ducati_GateSmp_Handle __inst );
xdc__CODESECT(ti_sysbios_family_arm_ducati_GateSmp_enter__F, "ti_sysbios_family_arm_ducati_GateSmp_enter")
__extern xdc_IArg ti_sysbios_family_arm_ducati_GateSmp_enter__F( ti_sysbios_family_arm_ducati_GateSmp_Object* __inst );
__extern xdc_IArg ti_sysbios_family_arm_ducati_GateSmp_enter__R( ti_sysbios_family_arm_ducati_GateSmp_Handle __inst );

/* leave__E */
#define ti_sysbios_family_arm_ducati_GateSmp_leave ti_sysbios_family_arm_ducati_GateSmp_leave__E
xdc__CODESECT(ti_sysbios_family_arm_ducati_GateSmp_leave__E, "ti_sysbios_family_arm_ducati_GateSmp_leave")
__extern xdc_Void ti_sysbios_family_arm_ducati_GateSmp_leave__E( ti_sysbios_family_arm_ducati_GateSmp_Handle __inst, xdc_IArg key );
xdc__CODESECT(ti_sysbios_family_arm_ducati_GateSmp_leave__F, "ti_sysbios_family_arm_ducati_GateSmp_leave")
__extern xdc_Void ti_sysbios_family_arm_ducati_GateSmp_leave__F( ti_sysbios_family_arm_ducati_GateSmp_Object* __inst, xdc_IArg key );
__extern xdc_Void ti_sysbios_family_arm_ducati_GateSmp_leave__R( ti_sysbios_family_arm_ducati_GateSmp_Handle __inst, xdc_IArg key );

/* sync__E */
#define ti_sysbios_family_arm_ducati_GateSmp_sync ti_sysbios_family_arm_ducati_GateSmp_sync__E
xdc__CODESECT(ti_sysbios_family_arm_ducati_GateSmp_sync__E, "ti_sysbios_family_arm_ducati_GateSmp_sync")
__extern xdc_Void ti_sysbios_family_arm_ducati_GateSmp_sync__E( ti_sysbios_family_arm_ducati_GateSmp_Handle __inst );
xdc__CODESECT(ti_sysbios_family_arm_ducati_GateSmp_sync__F, "ti_sysbios_family_arm_ducati_GateSmp_sync")
__extern xdc_Void ti_sysbios_family_arm_ducati_GateSmp_sync__F( ti_sysbios_family_arm_ducati_GateSmp_Object* __inst );
__extern xdc_Void ti_sysbios_family_arm_ducati_GateSmp_sync__R( ti_sysbios_family_arm_ducati_GateSmp_Handle __inst );


/*
 * ======== FUNCTION SELECTORS ========
 */

/* enter_{FxnT,fxnP} */
typedef xdc_IArg (*ti_sysbios_family_arm_ducati_GateSmp_enter_FxnT)(void*);
static inline ti_sysbios_family_arm_ducati_GateSmp_enter_FxnT ti_sysbios_family_arm_ducati_GateSmp_enter_fxnP( void )
{
    return (ti_sysbios_family_arm_ducati_GateSmp_enter_FxnT)ti_sysbios_family_arm_ducati_GateSmp_enter; 
}

/* leave_{FxnT,fxnP} */
typedef xdc_Void (*ti_sysbios_family_arm_ducati_GateSmp_leave_FxnT)(void*, xdc_IArg);
static inline ti_sysbios_family_arm_ducati_GateSmp_leave_FxnT ti_sysbios_family_arm_ducati_GateSmp_leave_fxnP( void )
{
    return (ti_sysbios_family_arm_ducati_GateSmp_leave_FxnT)ti_sysbios_family_arm_ducati_GateSmp_leave; 
}

/* sync_{FxnT,fxnP} */
typedef xdc_Void (*ti_sysbios_family_arm_ducati_GateSmp_sync_FxnT)(void*);
static inline ti_sysbios_family_arm_ducati_GateSmp_sync_FxnT ti_sysbios_family_arm_ducati_GateSmp_sync_fxnP( void )
{
    return (ti_sysbios_family_arm_ducati_GateSmp_sync_FxnT)ti_sysbios_family_arm_ducati_GateSmp_sync; 
}


/*
 * ======== CONVERTORS ========
 */

/* Module_upCast */
static inline xdc_runtime_IGateProvider_Module ti_sysbios_family_arm_ducati_GateSmp_Module_upCast( void )
{
    return (xdc_runtime_IGateProvider_Module)&ti_sysbios_family_arm_ducati_GateSmp_Module__FXNS__C;
}

/* Module_to_xdc_runtime_IGateProvider */
#define ti_sysbios_family_arm_ducati_GateSmp_Module_to_xdc_runtime_IGateProvider ti_sysbios_family_arm_ducati_GateSmp_Module_upCast

/* Handle_upCast */
static inline xdc_runtime_IGateProvider_Handle ti_sysbios_family_arm_ducati_GateSmp_Handle_upCast( ti_sysbios_family_arm_ducati_GateSmp_Handle i )
{
    return (xdc_runtime_IGateProvider_Handle)i;
}

/* Handle_to_xdc_runtime_IGateProvider */
#define ti_sysbios_family_arm_ducati_GateSmp_Handle_to_xdc_runtime_IGateProvider ti_sysbios_family_arm_ducati_GateSmp_Handle_upCast

/* Handle_downCast */
static inline ti_sysbios_family_arm_ducati_GateSmp_Handle ti_sysbios_family_arm_ducati_GateSmp_Handle_downCast( xdc_runtime_IGateProvider_Handle i )
{
    xdc_runtime_IGateProvider_Handle i2 = (xdc_runtime_IGateProvider_Handle)i;
    return (void*)i2->__fxns == (void*)&ti_sysbios_family_arm_ducati_GateSmp_Module__FXNS__C ? (ti_sysbios_family_arm_ducati_GateSmp_Handle)i : 0;
}

/* Handle_from_xdc_runtime_IGateProvider */
#define ti_sysbios_family_arm_ducati_GateSmp_Handle_from_xdc_runtime_IGateProvider ti_sysbios_family_arm_ducati_GateSmp_Handle_downCast


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define ti_sysbios_family_arm_ducati_GateSmp_Module_startupDone() ti_sysbios_family_arm_ducati_GateSmp_Module__startupDone__S()

/* Object_heap */
#define ti_sysbios_family_arm_ducati_GateSmp_Object_heap() ti_sysbios_family_arm_ducati_GateSmp_Object__heap__C

/* Module_heap */
#define ti_sysbios_family_arm_ducati_GateSmp_Module_heap() ti_sysbios_family_arm_ducati_GateSmp_Object__heap__C

/* Module_id */
static inline CT__ti_sysbios_family_arm_ducati_GateSmp_Module__id ti_sysbios_family_arm_ducati_GateSmp_Module_id( void ) 
{
    return ti_sysbios_family_arm_ducati_GateSmp_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool ti_sysbios_family_arm_ducati_GateSmp_Module_hasMask( void ) 
{
    return ti_sysbios_family_arm_ducati_GateSmp_Module__diagsMask__C != NULL;
}

/* Module_getMask */
static inline xdc_Bits16 ti_sysbios_family_arm_ducati_GateSmp_Module_getMask( void ) 
{
    return ti_sysbios_family_arm_ducati_GateSmp_Module__diagsMask__C != NULL ? *ti_sysbios_family_arm_ducati_GateSmp_Module__diagsMask__C : 0;
}

/* Module_setMask */
static inline xdc_Void ti_sysbios_family_arm_ducati_GateSmp_Module_setMask( xdc_Bits16 mask ) 
{
    if (ti_sysbios_family_arm_ducati_GateSmp_Module__diagsMask__C != NULL) *ti_sysbios_family_arm_ducati_GateSmp_Module__diagsMask__C = mask;
}

/* Params_init */
static inline void ti_sysbios_family_arm_ducati_GateSmp_Params_init( ti_sysbios_family_arm_ducati_GateSmp_Params* prms ) 
{
    if (prms) {
        ti_sysbios_family_arm_ducati_GateSmp_Params__init__S(prms, 0, sizeof(ti_sysbios_family_arm_ducati_GateSmp_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Params_copy */
static inline void ti_sysbios_family_arm_ducati_GateSmp_Params_copy( ti_sysbios_family_arm_ducati_GateSmp_Params* dst, const ti_sysbios_family_arm_ducati_GateSmp_Params* src ) 
{
    if (dst) {
        ti_sysbios_family_arm_ducati_GateSmp_Params__init__S(dst, (xdc_Ptr)src, sizeof(ti_sysbios_family_arm_ducati_GateSmp_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Object_count */
#define ti_sysbios_family_arm_ducati_GateSmp_Object_count() ti_sysbios_family_arm_ducati_GateSmp_Object__count__C

/* Object_sizeof */
#define ti_sysbios_family_arm_ducati_GateSmp_Object_sizeof() ti_sysbios_family_arm_ducati_GateSmp_Object__sizeof__C

/* Object_get */
static inline ti_sysbios_family_arm_ducati_GateSmp_Handle ti_sysbios_family_arm_ducati_GateSmp_Object_get( ti_sysbios_family_arm_ducati_GateSmp_Instance_State* oarr, int i ) 
{
    return (ti_sysbios_family_arm_ducati_GateSmp_Handle)ti_sysbios_family_arm_ducati_GateSmp_Object__get__S(oarr, i);
}

/* Object_first */
static inline ti_sysbios_family_arm_ducati_GateSmp_Handle ti_sysbios_family_arm_ducati_GateSmp_Object_first( void )
{
    return (ti_sysbios_family_arm_ducati_GateSmp_Handle)ti_sysbios_family_arm_ducati_GateSmp_Object__first__S();
}

/* Object_next */
static inline ti_sysbios_family_arm_ducati_GateSmp_Handle ti_sysbios_family_arm_ducati_GateSmp_Object_next( ti_sysbios_family_arm_ducati_GateSmp_Object* obj )
{
    return (ti_sysbios_family_arm_ducati_GateSmp_Handle)ti_sysbios_family_arm_ducati_GateSmp_Object__next__S(obj);
}

/* Handle_label */
static inline xdc_runtime_Types_Label* ti_sysbios_family_arm_ducati_GateSmp_Handle_label( ti_sysbios_family_arm_ducati_GateSmp_Handle inst, xdc_runtime_Types_Label* lab )
{
    return ti_sysbios_family_arm_ducati_GateSmp_Handle__label__S(inst, lab);
}

/* Handle_name */
static inline String ti_sysbios_family_arm_ducati_GateSmp_Handle_name( ti_sysbios_family_arm_ducati_GateSmp_Handle inst )
{
    xdc_runtime_Types_Label lab;
    return ti_sysbios_family_arm_ducati_GateSmp_Handle__label__S(inst, &lab)->iname;
}

/* create */
static inline ti_sysbios_family_arm_ducati_GateSmp_Handle ti_sysbios_family_arm_ducati_GateSmp_create( const ti_sysbios_family_arm_ducati_GateSmp_Params* __prms, xdc_runtime_Error_Block* __eb )
{
    return (ti_sysbios_family_arm_ducati_GateSmp_Handle)ti_sysbios_family_arm_ducati_GateSmp_Object__create__S(0, 0, 0, (const xdc_UChar*)__prms, sizeof(ti_sysbios_family_arm_ducati_GateSmp_Params), __eb);
}

/* construct */
static inline void ti_sysbios_family_arm_ducati_GateSmp_construct( ti_sysbios_family_arm_ducati_GateSmp_Struct* __obj, const ti_sysbios_family_arm_ducati_GateSmp_Params* __prms )
{
    ti_sysbios_family_arm_ducati_GateSmp_Object__create__S(__obj, sizeof (ti_sysbios_family_arm_ducati_GateSmp_Struct), 0, (const xdc_UChar*)__prms, sizeof(ti_sysbios_family_arm_ducati_GateSmp_Params), NULL);
}

/* delete */
static inline void ti_sysbios_family_arm_ducati_GateSmp_delete( ti_sysbios_family_arm_ducati_GateSmp_Handle* instp )
{
    ti_sysbios_family_arm_ducati_GateSmp_Object__delete__S(instp);
}

/* destruct */
static inline void ti_sysbios_family_arm_ducati_GateSmp_destruct( ti_sysbios_family_arm_ducati_GateSmp_Struct* obj )
{
    ti_sysbios_family_arm_ducati_GateSmp_Object__destruct__S(obj);
}

/* handle */
static inline ti_sysbios_family_arm_ducati_GateSmp_Handle ti_sysbios_family_arm_ducati_GateSmp_handle( ti_sysbios_family_arm_ducati_GateSmp_Struct* str )
{
    return (ti_sysbios_family_arm_ducati_GateSmp_Handle)str;
}

/* struct */
static inline ti_sysbios_family_arm_ducati_GateSmp_Struct* ti_sysbios_family_arm_ducati_GateSmp_struct( ti_sysbios_family_arm_ducati_GateSmp_Handle inst )
{
    return (ti_sysbios_family_arm_ducati_GateSmp_Struct*)inst;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_sysbios_family_arm_ducati_GateSmp__top__
#undef __nested__
#endif

#endif /* ti_sysbios_family_arm_ducati_GateSmp__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(ti_sysbios_family_arm_ducati_GateSmp__internalaccess))

#ifndef ti_sysbios_family_arm_ducati_GateSmp__include_state
#define ti_sysbios_family_arm_ducati_GateSmp__include_state

/* Object */
struct ti_sysbios_family_arm_ducati_GateSmp_Object {
    const ti_sysbios_family_arm_ducati_GateSmp_Fxns__* __fxns;
    volatile xdc_UInt32 gateWord;
    xdc_UInt stalls;
    xdc_UInt noStalls;
    xdc_UInt totalStalls;
    xdc_UInt maxStall;
};

#endif /* ti_sysbios_family_arm_ducati_GateSmp__include_state */

#endif


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_sysbios_family_arm_ducati_GateSmp__nolocalnames)

#ifndef ti_sysbios_family_arm_ducati_GateSmp__localnames__done
#define ti_sysbios_family_arm_ducati_GateSmp__localnames__done

/* module prefix */
#define GateSmp_Instance ti_sysbios_family_arm_ducati_GateSmp_Instance
#define GateSmp_Handle ti_sysbios_family_arm_ducati_GateSmp_Handle
#define GateSmp_Module ti_sysbios_family_arm_ducati_GateSmp_Module
#define GateSmp_Object ti_sysbios_family_arm_ducati_GateSmp_Object
#define GateSmp_Struct ti_sysbios_family_arm_ducati_GateSmp_Struct
#define GateSmp_Q_BLOCKING ti_sysbios_family_arm_ducati_GateSmp_Q_BLOCKING
#define GateSmp_Q_PREEMPTING ti_sysbios_family_arm_ducati_GateSmp_Q_PREEMPTING
#define GateSmp_Instance_State ti_sysbios_family_arm_ducati_GateSmp_Instance_State
#define GateSmp_A_nestedEnter ti_sysbios_family_arm_ducati_GateSmp_A_nestedEnter
#define GateSmp_enableStats ti_sysbios_family_arm_ducati_GateSmp_enableStats
#define GateSmp_Params ti_sysbios_family_arm_ducati_GateSmp_Params
#define GateSmp_query ti_sysbios_family_arm_ducati_GateSmp_query
#define GateSmp_enter ti_sysbios_family_arm_ducati_GateSmp_enter
#define GateSmp_enter_fxnP ti_sysbios_family_arm_ducati_GateSmp_enter_fxnP
#define GateSmp_enter_FxnT ti_sysbios_family_arm_ducati_GateSmp_enter_FxnT
#define GateSmp_leave ti_sysbios_family_arm_ducati_GateSmp_leave
#define GateSmp_leave_fxnP ti_sysbios_family_arm_ducati_GateSmp_leave_fxnP
#define GateSmp_leave_FxnT ti_sysbios_family_arm_ducati_GateSmp_leave_FxnT
#define GateSmp_sync ti_sysbios_family_arm_ducati_GateSmp_sync
#define GateSmp_sync_fxnP ti_sysbios_family_arm_ducati_GateSmp_sync_fxnP
#define GateSmp_sync_FxnT ti_sysbios_family_arm_ducati_GateSmp_sync_FxnT
#define GateSmp_Module_name ti_sysbios_family_arm_ducati_GateSmp_Module_name
#define GateSmp_Module_id ti_sysbios_family_arm_ducati_GateSmp_Module_id
#define GateSmp_Module_startup ti_sysbios_family_arm_ducati_GateSmp_Module_startup
#define GateSmp_Module_startupDone ti_sysbios_family_arm_ducati_GateSmp_Module_startupDone
#define GateSmp_Module_hasMask ti_sysbios_family_arm_ducati_GateSmp_Module_hasMask
#define GateSmp_Module_getMask ti_sysbios_family_arm_ducati_GateSmp_Module_getMask
#define GateSmp_Module_setMask ti_sysbios_family_arm_ducati_GateSmp_Module_setMask
#define GateSmp_Object_heap ti_sysbios_family_arm_ducati_GateSmp_Object_heap
#define GateSmp_Module_heap ti_sysbios_family_arm_ducati_GateSmp_Module_heap
#define GateSmp_construct ti_sysbios_family_arm_ducati_GateSmp_construct
#define GateSmp_create ti_sysbios_family_arm_ducati_GateSmp_create
#define GateSmp_handle ti_sysbios_family_arm_ducati_GateSmp_handle
#define GateSmp_struct ti_sysbios_family_arm_ducati_GateSmp_struct
#define GateSmp_Handle_label ti_sysbios_family_arm_ducati_GateSmp_Handle_label
#define GateSmp_Handle_name ti_sysbios_family_arm_ducati_GateSmp_Handle_name
#define GateSmp_Instance_init ti_sysbios_family_arm_ducati_GateSmp_Instance_init
#define GateSmp_Object_count ti_sysbios_family_arm_ducati_GateSmp_Object_count
#define GateSmp_Object_get ti_sysbios_family_arm_ducati_GateSmp_Object_get
#define GateSmp_Object_first ti_sysbios_family_arm_ducati_GateSmp_Object_first
#define GateSmp_Object_next ti_sysbios_family_arm_ducati_GateSmp_Object_next
#define GateSmp_Object_sizeof ti_sysbios_family_arm_ducati_GateSmp_Object_sizeof
#define GateSmp_Params_copy ti_sysbios_family_arm_ducati_GateSmp_Params_copy
#define GateSmp_Params_init ti_sysbios_family_arm_ducati_GateSmp_Params_init
#define GateSmp_delete ti_sysbios_family_arm_ducati_GateSmp_delete
#define GateSmp_destruct ti_sysbios_family_arm_ducati_GateSmp_destruct
#define GateSmp_Module_upCast ti_sysbios_family_arm_ducati_GateSmp_Module_upCast
#define GateSmp_Module_to_xdc_runtime_IGateProvider ti_sysbios_family_arm_ducati_GateSmp_Module_to_xdc_runtime_IGateProvider
#define GateSmp_Handle_upCast ti_sysbios_family_arm_ducati_GateSmp_Handle_upCast
#define GateSmp_Handle_to_xdc_runtime_IGateProvider ti_sysbios_family_arm_ducati_GateSmp_Handle_to_xdc_runtime_IGateProvider
#define GateSmp_Handle_downCast ti_sysbios_family_arm_ducati_GateSmp_Handle_downCast
#define GateSmp_Handle_from_xdc_runtime_IGateProvider ti_sysbios_family_arm_ducati_GateSmp_Handle_from_xdc_runtime_IGateProvider

#endif /* ti_sysbios_family_arm_ducati_GateSmp__localnames__done */
#endif
