
#include <stdlib.h>
#include <string.h>
#include "sc_types.h"
#include "Prefix.h"
#include "PrefixRequired.h"
/*! \file Implementation of the state machine 'prefix'
*/

/* prototypes of all internal functions */
static sc_boolean prefix_check_main_region_APAGADO_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_main_region_ENCENDIDO_tr0_tr0(const Prefix* handle);
static void prefix_effect_main_region_APAGADO_tr0(Prefix* handle);
static void prefix_effect_main_region_ENCENDIDO_tr0(Prefix* handle);
static void prefix_enact_main_region_APAGADO(Prefix* handle);
static void prefix_enact_main_region_ENCENDIDO(Prefix* handle);
static void prefix_exact_main_region_APAGADO(Prefix* handle);
static void prefix_exact_main_region_ENCENDIDO(Prefix* handle);
static void prefix_enseq_main_region_APAGADO_default(Prefix* handle);
static void prefix_enseq_main_region_ENCENDIDO_default(Prefix* handle);
static void prefix_enseq_main_region_default(Prefix* handle);
static void prefix_exseq_main_region_APAGADO(Prefix* handle);
static void prefix_exseq_main_region_ENCENDIDO(Prefix* handle);
static void prefix_exseq_main_region(Prefix* handle);
static void prefix_react_main_region_APAGADO(Prefix* handle);
static void prefix_react_main_region_ENCENDIDO(Prefix* handle);
static void prefix_react_main_region__entry_Default(Prefix* handle);
static void prefix_clearInEvents(Prefix* handle);
static void prefix_clearOutEvents(Prefix* handle);

const sc_integer PREFIX_PREFIXIFACE_LED3 = 5;
const sc_boolean PREFIX_PREFIXIFACE_LED_ON = bool_false;
const sc_boolean PREFIX_PREFIXIFACE_LED_OFF = bool_true;

void prefix_init(Prefix* handle)
{
	sc_integer i;

	for (i = 0; i < PREFIX_MAX_ORTHOGONAL_STATES; ++i)
	{
		handle->stateConfVector[i] = Prefix_last_state;
	}
	
	
	handle->stateConfVectorPosition = 0;

	prefix_clearInEvents(handle);
	prefix_clearOutEvents(handle);


}

void prefix_enter(Prefix* handle)
{
	/* Default enter sequence for statechart prefix */
	prefix_enseq_main_region_default(handle);
}

void prefix_exit(Prefix* handle)
{
	/* Default exit sequence for statechart prefix */
	prefix_exseq_main_region(handle);
}

sc_boolean prefix_isActive(const Prefix* handle)
{
	sc_boolean result;
	if (handle->stateConfVector[0] != Prefix_last_state)
	{
		result =  bool_true;
	}
	else
	{
		result = bool_false;
	}
	return result;
}

/* 
 * Always returns 'false' since this state machine can never become final.
 */
sc_boolean prefix_isFinal(const Prefix* handle)
{
   return bool_false;
}

static void prefix_clearInEvents(Prefix* handle)
{
	handle->timeEvents.prefix_main_region_APAGADO_tev0_raised = bool_false;
	handle->timeEvents.prefix_main_region_ENCENDIDO_tev0_raised = bool_false;
}

static void prefix_clearOutEvents(Prefix* handle)
{
}

void prefix_runCycle(Prefix* handle)
{
	
	prefix_clearOutEvents(handle);
	
	for (handle->stateConfVectorPosition = 0;
		handle->stateConfVectorPosition < PREFIX_MAX_ORTHOGONAL_STATES;
		handle->stateConfVectorPosition++)
		{
			
		switch (handle->stateConfVector[handle->stateConfVectorPosition])
		{
		case Prefix_main_region_APAGADO :
		{
			prefix_react_main_region_APAGADO(handle);
			break;
		}
		case Prefix_main_region_ENCENDIDO :
		{
			prefix_react_main_region_ENCENDIDO(handle);
			break;
		}
		default:
			break;
		}
	}
	
	prefix_clearInEvents(handle);
}

void prefix_raiseTimeEvent(const Prefix* handle, sc_eventid evid)
{
	if ( ((sc_intptr_t)evid) >= ((sc_intptr_t)&(handle->timeEvents))
		&&  ((sc_intptr_t)evid) < ((sc_intptr_t)&(handle->timeEvents)) + sizeof(PrefixTimeEvents))
		{
		*(sc_boolean*)evid = bool_true;
	}		
}

sc_boolean prefix_isStateActive(const Prefix* handle, PrefixStates state)
{
	sc_boolean result = bool_false;
	switch (state)
	{
		case Prefix_main_region_APAGADO :
			result = (sc_boolean) (handle->stateConfVector[0] == Prefix_main_region_APAGADO
			);
			break;
		case Prefix_main_region_ENCENDIDO :
			result = (sc_boolean) (handle->stateConfVector[0] == Prefix_main_region_ENCENDIDO
			);
			break;
		default:
			result = bool_false;
			break;
	}
	return result;
}



const sc_integer prefixIface_get_lED3(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_LED3;
}
const sc_boolean prefixIface_get_lED_ON(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_LED_ON;
}
const sc_boolean prefixIface_get_lED_OFF(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_LED_OFF;
}

/* implementations of all internal functions */

static sc_boolean prefix_check_main_region_APAGADO_tr0_tr0(const Prefix* handle)
{
	return handle->timeEvents.prefix_main_region_APAGADO_tev0_raised;
}

static sc_boolean prefix_check_main_region_ENCENDIDO_tr0_tr0(const Prefix* handle)
{
	return handle->timeEvents.prefix_main_region_ENCENDIDO_tev0_raised;
}

static void prefix_effect_main_region_APAGADO_tr0(Prefix* handle)
{
	prefix_exseq_main_region_APAGADO(handle);
	prefix_enseq_main_region_ENCENDIDO_default(handle);
}

static void prefix_effect_main_region_ENCENDIDO_tr0(Prefix* handle)
{
	prefix_exseq_main_region_ENCENDIDO(handle);
	prefix_enseq_main_region_APAGADO_default(handle);
}

/* Entry action for state 'APAGADO'. */
static void prefix_enact_main_region_APAGADO(Prefix* handle)
{
	/* Entry action for state 'APAGADO'. */
	prefix_setTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_main_region_APAGADO_tev0_raised) , 250, bool_false);
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LED3, PREFIX_PREFIXIFACE_LED_OFF);
}

/* Entry action for state 'ENCENDIDO'. */
static void prefix_enact_main_region_ENCENDIDO(Prefix* handle)
{
	/* Entry action for state 'ENCENDIDO'. */
	prefix_setTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_main_region_ENCENDIDO_tev0_raised) , 500, bool_false);
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LED3, PREFIX_PREFIXIFACE_LED_ON);
}

/* Exit action for state 'APAGADO'. */
static void prefix_exact_main_region_APAGADO(Prefix* handle)
{
	/* Exit action for state 'APAGADO'. */
	prefix_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_main_region_APAGADO_tev0_raised) );		
}

/* Exit action for state 'ENCENDIDO'. */
static void prefix_exact_main_region_ENCENDIDO(Prefix* handle)
{
	/* Exit action for state 'ENCENDIDO'. */
	prefix_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_main_region_ENCENDIDO_tev0_raised) );		
}

/* 'default' enter sequence for state APAGADO */
static void prefix_enseq_main_region_APAGADO_default(Prefix* handle)
{
	/* 'default' enter sequence for state APAGADO */
	prefix_enact_main_region_APAGADO(handle);
	handle->stateConfVector[0] = Prefix_main_region_APAGADO;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state ENCENDIDO */
static void prefix_enseq_main_region_ENCENDIDO_default(Prefix* handle)
{
	/* 'default' enter sequence for state ENCENDIDO */
	prefix_enact_main_region_ENCENDIDO(handle);
	handle->stateConfVector[0] = Prefix_main_region_ENCENDIDO;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for region main region */
static void prefix_enseq_main_region_default(Prefix* handle)
{
	/* 'default' enter sequence for region main region */
	prefix_react_main_region__entry_Default(handle);
}

/* Default exit sequence for state APAGADO */
static void prefix_exseq_main_region_APAGADO(Prefix* handle)
{
	/* Default exit sequence for state APAGADO */
	handle->stateConfVector[0] = Prefix_last_state;
	handle->stateConfVectorPosition = 0;
	prefix_exact_main_region_APAGADO(handle);
}

/* Default exit sequence for state ENCENDIDO */
static void prefix_exseq_main_region_ENCENDIDO(Prefix* handle)
{
	/* Default exit sequence for state ENCENDIDO */
	handle->stateConfVector[0] = Prefix_last_state;
	handle->stateConfVectorPosition = 0;
	prefix_exact_main_region_ENCENDIDO(handle);
}

/* Default exit sequence for region main region */
static void prefix_exseq_main_region(Prefix* handle)
{
	/* Default exit sequence for region main region */
	/* Handle exit of all possible states (of prefix.main_region) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case Prefix_main_region_APAGADO :
		{
			prefix_exseq_main_region_APAGADO(handle);
			break;
		}
		case Prefix_main_region_ENCENDIDO :
		{
			prefix_exseq_main_region_ENCENDIDO(handle);
			break;
		}
		default: break;
	}
}

/* The reactions of state APAGADO. */
static void prefix_react_main_region_APAGADO(Prefix* handle)
{
	/* The reactions of state APAGADO. */
	if (prefix_check_main_region_APAGADO_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_main_region_APAGADO_tr0(handle);
	} 
}

/* The reactions of state ENCENDIDO. */
static void prefix_react_main_region_ENCENDIDO(Prefix* handle)
{
	/* The reactions of state ENCENDIDO. */
	if (prefix_check_main_region_ENCENDIDO_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_main_region_ENCENDIDO_tr0(handle);
	} 
}

/* Default react sequence for initial entry  */
static void prefix_react_main_region__entry_Default(Prefix* handle)
{
	/* Default react sequence for initial entry  */
	prefix_enseq_main_region_APAGADO_default(handle);
}


