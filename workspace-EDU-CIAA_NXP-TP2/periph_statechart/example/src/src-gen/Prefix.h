
#ifndef PREFIX_H_
#define PREFIX_H_

#include "sc_types.h"
		
#ifdef __cplusplus
extern "C" { 
#endif 

/*! \file Header of the state machine 'prefix'.
*/

/*! Enumeration of all states */ 
typedef enum
{
	Prefix_TECLAS_NO_OPRIMIDAS,
	Prefix_TECLAS_DEBOUNCE,
	Prefix_TECLAS_VALIDACION,
	Prefix_TECLAS_OPRIMIDAS,
	Prefix_LED_RGB_LEDRgb,
	Prefix_LED_RGB_LEDrGb,
	Prefix_LED_RGB_LEDrgB,
	Prefix_LED1_AMPLITUD_FRECUENCIA_LED1OFF,
	Prefix_LED1_AMPLITUD_FRECUENCIA_LED1ON,
	Prefix_LED2___LED2OFF,
	Prefix_LED2___LED2ON,
	Prefix_LED3___LED3OFF,
	Prefix_LED3___LED3ON,
	Prefix_ESTADOS_FrecuencySelected,
	Prefix_ESTADOS_AmplitudeSelected,
	Prefix_last_state
} PrefixStates;

/*! Type definition of the data structure for the PrefixIface interface scope. */
typedef struct
{
	sc_boolean evTeclaXOprimida_raised;
	sc_integer evTeclaXOprimida_value;
	sc_boolean evTeclaXNoOprimida_raised;
} PrefixIface;

/* Declaration of constants for scope PrefixIface. */
extern const sc_integer PREFIX_PREFIXIFACE_LEDR;
extern const sc_integer PREFIX_PREFIXIFACE_LEDG;
extern const sc_integer PREFIX_PREFIXIFACE_LEDB;
extern const sc_integer PREFIX_PREFIXIFACE_LED1;
extern const sc_integer PREFIX_PREFIXIFACE_LED2;
extern const sc_integer PREFIX_PREFIXIFACE_LED3;
extern const sc_boolean PREFIX_PREFIXIFACE_LED_ON;
extern const sc_boolean PREFIX_PREFIXIFACE_LED_OFF;
extern const sc_boolean PREFIX_PREFIXIFACE_FRECSELECTED;
extern const sc_boolean PREFIX_PREFIXIFACE_AMPSELECTED;
extern const sc_integer PREFIX_PREFIXIFACE_TEC1;
extern const sc_integer PREFIX_PREFIXIFACE_TEC2;
extern const sc_integer PREFIX_PREFIXIFACE_TEC3;
extern const sc_integer PREFIX_PREFIXIFACE_TEC4;
extern const sc_integer PREFIX_PREFIXIFACE_FRECMAX;
extern const sc_integer PREFIX_PREFIXIFACE_FRECMIN;
extern const sc_integer PREFIX_PREFIXIFACE_AMPMAX;
extern const sc_integer PREFIX_PREFIXIFACE_AMPMIN;

/*! Type definition of the data structure for the PrefixInternal interface scope. */
typedef struct
{
	sc_boolean siTitilarLED_raised;
	sc_boolean siNoTitilarLED_raised;
	sc_boolean siTECXOK_raised;
	sc_boolean evAmplitudeSelected_raised;
	sc_boolean evFrecuencySelected_raised;
	sc_boolean evMas_raised;
	sc_boolean evMenos_raised;
	sc_integer viTecla;
	sc_boolean viSelector;
	sc_integer viFrecuencia;
	sc_integer viAmplitud;
} PrefixInternal;

/*! Type definition of the data structure for the PrefixTimeEvents interface scope. */
typedef struct
{
	sc_boolean prefix_TECLAS_DEBOUNCE_tev0_raised;
} PrefixTimeEvents;


/*! Define dimension of the state configuration vector for orthogonal states. */
#define PREFIX_MAX_ORTHOGONAL_STATES 6

/*! 
 * Type definition of the data structure for the Prefix state machine.
 * This data structure has to be allocated by the client code. 
 */
typedef struct
{
	PrefixStates stateConfVector[PREFIX_MAX_ORTHOGONAL_STATES];
	sc_ushort stateConfVectorPosition; 
	
	PrefixIface iface;
	PrefixInternal internal;
	PrefixTimeEvents timeEvents;
} Prefix;

/*! Initializes the Prefix state machine data structures. Must be called before first usage.*/
extern void prefix_init(Prefix* handle);

/*! Activates the state machine */
extern void prefix_enter(Prefix* handle);

/*! Deactivates the state machine */
extern void prefix_exit(Prefix* handle);

/*! Performs a 'run to completion' step. */
extern void prefix_runCycle(Prefix* handle);

/*! Raises a time event. */
extern void prefix_raiseTimeEvent(const Prefix* handle, sc_eventid evid);

/*! Raises the in event 'evTeclaXOprimida' that is defined in the default interface scope. */ 
extern void prefixIface_raise_evTeclaXOprimida(Prefix* handle, sc_integer value);

/*! Raises the in event 'evTeclaXNoOprimida' that is defined in the default interface scope. */ 
extern void prefixIface_raise_evTeclaXNoOprimida(Prefix* handle);

/*! Gets the value of the variable 'LEDR' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_lEDR(const Prefix* handle);
/*! Gets the value of the variable 'LEDG' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_lEDG(const Prefix* handle);
/*! Gets the value of the variable 'LEDB' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_lEDB(const Prefix* handle);
/*! Gets the value of the variable 'LED1' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_lED1(const Prefix* handle);
/*! Gets the value of the variable 'LED2' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_lED2(const Prefix* handle);
/*! Gets the value of the variable 'LED3' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_lED3(const Prefix* handle);
/*! Gets the value of the variable 'LED_ON' that is defined in the default interface scope. */ 
extern const sc_boolean prefixIface_get_lED_ON(const Prefix* handle);
/*! Gets the value of the variable 'LED_OFF' that is defined in the default interface scope. */ 
extern const sc_boolean prefixIface_get_lED_OFF(const Prefix* handle);
/*! Gets the value of the variable 'FrecSelected' that is defined in the default interface scope. */ 
extern const sc_boolean prefixIface_get_frecSelected(const Prefix* handle);
/*! Gets the value of the variable 'AmpSelected' that is defined in the default interface scope. */ 
extern const sc_boolean prefixIface_get_ampSelected(const Prefix* handle);
/*! Gets the value of the variable 'TEC1' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_tEC1(const Prefix* handle);
/*! Gets the value of the variable 'TEC2' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_tEC2(const Prefix* handle);
/*! Gets the value of the variable 'TEC3' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_tEC3(const Prefix* handle);
/*! Gets the value of the variable 'TEC4' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_tEC4(const Prefix* handle);
/*! Gets the value of the variable 'FRECMAX' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_fRECMAX(const Prefix* handle);
/*! Gets the value of the variable 'FRECMIN' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_fRECMIN(const Prefix* handle);
/*! Gets the value of the variable 'AMPMAX' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_aMPMAX(const Prefix* handle);
/*! Gets the value of the variable 'AMPMIN' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_aMPMIN(const Prefix* handle);

/*!
 * Checks whether the state machine is active (until 2.4.1 this method was used for states).
 * A state machine is active if it was entered. It is inactive if it has not been entered at all or if it has been exited.
 */
extern sc_boolean prefix_isActive(const Prefix* handle);

/*!
 * Checks if all active states are final. 
 * If there are no active states then the state machine is considered being inactive. In this case this method returns false.
 */
extern sc_boolean prefix_isFinal(const Prefix* handle);

/*! Checks if the specified state is active (until 2.4.1 the used method for states was called isActive()). */
extern sc_boolean prefix_isStateActive(const Prefix* handle, PrefixStates state);

#ifdef __cplusplus
}
#endif 

#endif /* PREFIX_H_ */
