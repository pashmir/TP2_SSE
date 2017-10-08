
#include <stdlib.h>
#include <string.h>
#include "sc_types.h"
#include "Prefix.h"
#include "PrefixRequired.h"
/*! \file Implementation of the state machine 'prefix'
*/

/* prototypes of all internal functions */
static sc_boolean prefix_check_TECX_DEBOUNCE_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_TECX_NO_OPRIMIDO_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_TECX_OPRIMIDO_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_TECX_VALIDACION_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_TECX_VALIDACION_tr1_tr1(const Prefix* handle);
static sc_boolean prefix_check_LED3_TITILA_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_LED3_TITILA_r1_ENCENDIDO_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_LED3_TITILA_r1_APAGADO_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_LED3_REPOSO_tr0_tr0(const Prefix* handle);
static void prefix_effect_TECX_DEBOUNCE_tr0(Prefix* handle);
static void prefix_effect_TECX_NO_OPRIMIDO_tr0(Prefix* handle);
static void prefix_effect_TECX_OPRIMIDO_tr0(Prefix* handle);
static void prefix_effect_TECX_VALIDACION_tr0(Prefix* handle);
static void prefix_effect_TECX_VALIDACION_tr1(Prefix* handle);
static void prefix_effect_LED3_TITILA_tr0(Prefix* handle);
static void prefix_effect_LED3_TITILA_r1_ENCENDIDO_tr0(Prefix* handle);
static void prefix_effect_LED3_TITILA_r1_APAGADO_tr0(Prefix* handle);
static void prefix_effect_LED3_REPOSO_tr0(Prefix* handle);
static void prefix_enact_TECX_DEBOUNCE(Prefix* handle);
static void prefix_enact_TECX_OPRIMIDO(Prefix* handle);
static void prefix_enact_TECX_LED(Prefix* handle);
static void prefix_enact_LED3_TITILA_r1_ENCENDIDO(Prefix* handle);
static void prefix_enact_LED3_TITILA_r1_APAGADO(Prefix* handle);
static void prefix_enact_LED3_REPOSO(Prefix* handle);
static void prefix_exact_TECX_DEBOUNCE(Prefix* handle);
static void prefix_exact_TECX_OPRIMIDO(Prefix* handle);
static void prefix_exact_LED3_TITILA_r1_ENCENDIDO(Prefix* handle);
static void prefix_exact_LED3_TITILA_r1_APAGADO(Prefix* handle);
static void prefix_enseq_TECX_DEBOUNCE_default(Prefix* handle);
static void prefix_enseq_TECX_NO_OPRIMIDO_default(Prefix* handle);
static void prefix_enseq_TECX_OPRIMIDO_default(Prefix* handle);
static void prefix_enseq_TECX_VALIDACION_default(Prefix* handle);
static void prefix_enseq_TECX_LED_default(Prefix* handle);
static void prefix_enseq_LED3_TITILA_default(Prefix* handle);
static void prefix_enseq_LED3_TITILA_r1_ENCENDIDO_default(Prefix* handle);
static void prefix_enseq_LED3_TITILA_r1_APAGADO_default(Prefix* handle);
static void prefix_enseq_LED3_REPOSO_default(Prefix* handle);
static void prefix_enseq_TECX_default(Prefix* handle);
static void prefix_enseq_LED3_default(Prefix* handle);
static void prefix_enseq_LED3_TITILA_r1_default(Prefix* handle);
static void prefix_exseq_TECX_DEBOUNCE(Prefix* handle);
static void prefix_exseq_TECX_NO_OPRIMIDO(Prefix* handle);
static void prefix_exseq_TECX_OPRIMIDO(Prefix* handle);
static void prefix_exseq_TECX_VALIDACION(Prefix* handle);
static void prefix_exseq_TECX_LED(Prefix* handle);
static void prefix_exseq_LED3_TITILA(Prefix* handle);
static void prefix_exseq_LED3_TITILA_r1_ENCENDIDO(Prefix* handle);
static void prefix_exseq_LED3_TITILA_r1_APAGADO(Prefix* handle);
static void prefix_exseq_LED3_REPOSO(Prefix* handle);
static void prefix_exseq_TECX(Prefix* handle);
static void prefix_exseq_LED3(Prefix* handle);
static void prefix_exseq_LED3_TITILA_r1(Prefix* handle);
static void prefix_react_TECX_DEBOUNCE(Prefix* handle);
static void prefix_react_TECX_NO_OPRIMIDO(Prefix* handle);
static void prefix_react_TECX_OPRIMIDO(Prefix* handle);
static void prefix_react_TECX_VALIDACION(Prefix* handle);
static void prefix_react_TECX_LED(Prefix* handle);
static void prefix_react_LED3_TITILA_r1_ENCENDIDO(Prefix* handle);
static void prefix_react_LED3_TITILA_r1_APAGADO(Prefix* handle);
static void prefix_react_LED3_REPOSO(Prefix* handle);
static void prefix_react_TECX__entry_Default(Prefix* handle);
static void prefix_react_LED3_TITILA_r1__entry_Default(Prefix* handle);
static void prefix_react_LED3__entry_Default(Prefix* handle);
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
	prefix_enseq_TECX_default(handle);
	prefix_enseq_LED3_default(handle);
}

void prefix_exit(Prefix* handle)
{
	/* Default exit sequence for statechart prefix */
	prefix_exseq_TECX(handle);
	prefix_exseq_LED3(handle);
}

sc_boolean prefix_isActive(const Prefix* handle)
{
	sc_boolean result;
	if (handle->stateConfVector[0] != Prefix_last_state || handle->stateConfVector[1] != Prefix_last_state)
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
	handle->iface.evTECXOprimido_raised = bool_false;
	handle->iface.evTECXNoOprimido_raised = bool_false;
	handle->internal.siTitilarLED_raised = bool_false;
	handle->internal.siNoTitilarLED_raised = bool_false;
	handle->timeEvents.prefix_TECX_DEBOUNCE_tev0_raised = bool_false;
	handle->timeEvents.prefix_LED3_TITILA_r1_ENCENDIDO_tev0_raised = bool_false;
	handle->timeEvents.prefix_LED3_TITILA_r1_APAGADO_tev0_raised = bool_false;
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
		case Prefix_TECX_DEBOUNCE :
		{
			prefix_react_TECX_DEBOUNCE(handle);
			break;
		}
		case Prefix_TECX_NO_OPRIMIDO :
		{
			prefix_react_TECX_NO_OPRIMIDO(handle);
			break;
		}
		case Prefix_TECX_OPRIMIDO :
		{
			prefix_react_TECX_OPRIMIDO(handle);
			break;
		}
		case Prefix_TECX_VALIDACION :
		{
			prefix_react_TECX_VALIDACION(handle);
			break;
		}
		case Prefix_TECX_LED :
		{
			prefix_react_TECX_LED(handle);
			break;
		}
		case Prefix_LED3_TITILA_r1_ENCENDIDO :
		{
			prefix_react_LED3_TITILA_r1_ENCENDIDO(handle);
			break;
		}
		case Prefix_LED3_TITILA_r1_APAGADO :
		{
			prefix_react_LED3_TITILA_r1_APAGADO(handle);
			break;
		}
		case Prefix_LED3_REPOSO :
		{
			prefix_react_LED3_REPOSO(handle);
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
		case Prefix_TECX_DEBOUNCE :
			result = (sc_boolean) (handle->stateConfVector[0] == Prefix_TECX_DEBOUNCE
			);
			break;
		case Prefix_TECX_NO_OPRIMIDO :
			result = (sc_boolean) (handle->stateConfVector[0] == Prefix_TECX_NO_OPRIMIDO
			);
			break;
		case Prefix_TECX_OPRIMIDO :
			result = (sc_boolean) (handle->stateConfVector[0] == Prefix_TECX_OPRIMIDO
			);
			break;
		case Prefix_TECX_VALIDACION :
			result = (sc_boolean) (handle->stateConfVector[0] == Prefix_TECX_VALIDACION
			);
			break;
		case Prefix_TECX_LED :
			result = (sc_boolean) (handle->stateConfVector[0] == Prefix_TECX_LED
			);
			break;
		case Prefix_LED3_TITILA :
			result = (sc_boolean) (handle->stateConfVector[1] >= Prefix_LED3_TITILA
				&& handle->stateConfVector[1] <= Prefix_LED3_TITILA_r1_APAGADO);
			break;
		case Prefix_LED3_TITILA_r1_ENCENDIDO :
			result = (sc_boolean) (handle->stateConfVector[1] == Prefix_LED3_TITILA_r1_ENCENDIDO
			);
			break;
		case Prefix_LED3_TITILA_r1_APAGADO :
			result = (sc_boolean) (handle->stateConfVector[1] == Prefix_LED3_TITILA_r1_APAGADO
			);
			break;
		case Prefix_LED3_REPOSO :
			result = (sc_boolean) (handle->stateConfVector[1] == Prefix_LED3_REPOSO
			);
			break;
		default:
			result = bool_false;
			break;
	}
	return result;
}

void prefixIface_raise_evTECXOprimido(Prefix* handle)
{
	handle->iface.evTECXOprimido_raised = bool_true;
}
void prefixIface_raise_evTECXNoOprimido(Prefix* handle)
{
	handle->iface.evTECXNoOprimido_raised = bool_true;
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

static sc_boolean prefix_check_TECX_DEBOUNCE_tr0_tr0(const Prefix* handle)
{
	return handle->timeEvents.prefix_TECX_DEBOUNCE_tev0_raised;
}

static sc_boolean prefix_check_TECX_NO_OPRIMIDO_tr0_tr0(const Prefix* handle)
{
	return handle->iface.evTECXOprimido_raised;
}

static sc_boolean prefix_check_TECX_OPRIMIDO_tr0_tr0(const Prefix* handle)
{
	return handle->iface.evTECXNoOprimido_raised;
}

static sc_boolean prefix_check_TECX_VALIDACION_tr0_tr0(const Prefix* handle)
{
	return handle->iface.evTECXOprimido_raised;
}

static sc_boolean prefix_check_TECX_VALIDACION_tr1_tr1(const Prefix* handle)
{
	return handle->iface.evTECXNoOprimido_raised;
}

static sc_boolean prefix_check_LED3_TITILA_tr0_tr0(const Prefix* handle)
{
	return handle->internal.siNoTitilarLED_raised;
}

static sc_boolean prefix_check_LED3_TITILA_r1_ENCENDIDO_tr0_tr0(const Prefix* handle)
{
	return handle->timeEvents.prefix_LED3_TITILA_r1_ENCENDIDO_tev0_raised;
}

static sc_boolean prefix_check_LED3_TITILA_r1_APAGADO_tr0_tr0(const Prefix* handle)
{
	return handle->timeEvents.prefix_LED3_TITILA_r1_APAGADO_tev0_raised;
}

static sc_boolean prefix_check_LED3_REPOSO_tr0_tr0(const Prefix* handle)
{
	return handle->internal.siTitilarLED_raised;
}

static void prefix_effect_TECX_DEBOUNCE_tr0(Prefix* handle)
{
	prefix_exseq_TECX_DEBOUNCE(handle);
	prefix_enseq_TECX_VALIDACION_default(handle);
}

static void prefix_effect_TECX_NO_OPRIMIDO_tr0(Prefix* handle)
{
	prefix_exseq_TECX_NO_OPRIMIDO(handle);
	prefix_enseq_TECX_DEBOUNCE_default(handle);
}

static void prefix_effect_TECX_OPRIMIDO_tr0(Prefix* handle)
{
	prefix_exseq_TECX_OPRIMIDO(handle);
	prefix_enseq_TECX_NO_OPRIMIDO_default(handle);
}

static void prefix_effect_TECX_VALIDACION_tr0(Prefix* handle)
{
	prefix_exseq_TECX_VALIDACION(handle);
	prefix_enseq_TECX_OPRIMIDO_default(handle);
}

static void prefix_effect_TECX_VALIDACION_tr1(Prefix* handle)
{
	prefix_exseq_TECX_VALIDACION(handle);
	prefix_enseq_TECX_NO_OPRIMIDO_default(handle);
}

static void prefix_effect_LED3_TITILA_tr0(Prefix* handle)
{
	prefix_exseq_LED3_TITILA(handle);
	prefix_enseq_LED3_REPOSO_default(handle);
}

static void prefix_effect_LED3_TITILA_r1_ENCENDIDO_tr0(Prefix* handle)
{
	prefix_exseq_LED3_TITILA_r1_ENCENDIDO(handle);
	prefix_enseq_LED3_TITILA_r1_APAGADO_default(handle);
}

static void prefix_effect_LED3_TITILA_r1_APAGADO_tr0(Prefix* handle)
{
	prefix_exseq_LED3_TITILA_r1_APAGADO(handle);
	prefix_enseq_LED3_TITILA_r1_ENCENDIDO_default(handle);
}

static void prefix_effect_LED3_REPOSO_tr0(Prefix* handle)
{
	prefix_exseq_LED3_REPOSO(handle);
	prefix_enseq_LED3_TITILA_default(handle);
}

/* Entry action for state 'DEBOUNCE'. */
static void prefix_enact_TECX_DEBOUNCE(Prefix* handle)
{
	/* Entry action for state 'DEBOUNCE'. */
	prefix_setTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_TECX_DEBOUNCE_tev0_raised) , 50, bool_false);
}

/* Entry action for state 'OPRIMIDO'. */
static void prefix_enact_TECX_OPRIMIDO(Prefix* handle)
{
	/* Entry action for state 'OPRIMIDO'. */
	handle->internal.siTitilarLED_raised = bool_true;
}

/* Entry action for state 'LED'. */
static void prefix_enact_TECX_LED(Prefix* handle)
{
	/* Entry action for state 'LED'. */
	handle->internal.siTitilarLED_raised = bool_true;
}

/* Entry action for state 'ENCENDIDO'. */
static void prefix_enact_LED3_TITILA_r1_ENCENDIDO(Prefix* handle)
{
	/* Entry action for state 'ENCENDIDO'. */
	prefix_setTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_LED3_TITILA_r1_ENCENDIDO_tev0_raised) , 500, bool_false);
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LED3, PREFIX_PREFIXIFACE_LED_ON);
}

/* Entry action for state 'APAGADO'. */
static void prefix_enact_LED3_TITILA_r1_APAGADO(Prefix* handle)
{
	/* Entry action for state 'APAGADO'. */
	prefix_setTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_LED3_TITILA_r1_APAGADO_tev0_raised) , 250, bool_false);
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LED3, PREFIX_PREFIXIFACE_LED_OFF);
}

/* Entry action for state 'REPOSO'. */
static void prefix_enact_LED3_REPOSO(Prefix* handle)
{
	/* Entry action for state 'REPOSO'. */
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LED3, PREFIX_PREFIXIFACE_LED_OFF);
}

/* Exit action for state 'DEBOUNCE'. */
static void prefix_exact_TECX_DEBOUNCE(Prefix* handle)
{
	/* Exit action for state 'DEBOUNCE'. */
	prefix_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_TECX_DEBOUNCE_tev0_raised) );		
}

/* Exit action for state 'OPRIMIDO'. */
static void prefix_exact_TECX_OPRIMIDO(Prefix* handle)
{
	/* Exit action for state 'OPRIMIDO'. */
	handle->internal.siNoTitilarLED_raised = bool_true;
}

/* Exit action for state 'ENCENDIDO'. */
static void prefix_exact_LED3_TITILA_r1_ENCENDIDO(Prefix* handle)
{
	/* Exit action for state 'ENCENDIDO'. */
	prefix_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_LED3_TITILA_r1_ENCENDIDO_tev0_raised) );		
}

/* Exit action for state 'APAGADO'. */
static void prefix_exact_LED3_TITILA_r1_APAGADO(Prefix* handle)
{
	/* Exit action for state 'APAGADO'. */
	prefix_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_LED3_TITILA_r1_APAGADO_tev0_raised) );		
}

/* 'default' enter sequence for state DEBOUNCE */
static void prefix_enseq_TECX_DEBOUNCE_default(Prefix* handle)
{
	/* 'default' enter sequence for state DEBOUNCE */
	prefix_enact_TECX_DEBOUNCE(handle);
	handle->stateConfVector[0] = Prefix_TECX_DEBOUNCE;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state NO_OPRIMIDO */
static void prefix_enseq_TECX_NO_OPRIMIDO_default(Prefix* handle)
{
	/* 'default' enter sequence for state NO_OPRIMIDO */
	handle->stateConfVector[0] = Prefix_TECX_NO_OPRIMIDO;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state OPRIMIDO */
static void prefix_enseq_TECX_OPRIMIDO_default(Prefix* handle)
{
	/* 'default' enter sequence for state OPRIMIDO */
	prefix_enact_TECX_OPRIMIDO(handle);
	handle->stateConfVector[0] = Prefix_TECX_OPRIMIDO;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state VALIDACION */
static void prefix_enseq_TECX_VALIDACION_default(Prefix* handle)
{
	/* 'default' enter sequence for state VALIDACION */
	handle->stateConfVector[0] = Prefix_TECX_VALIDACION;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state LED */
static void prefix_enseq_TECX_LED_default(Prefix* handle)
{
	/* 'default' enter sequence for state LED */
	prefix_enact_TECX_LED(handle);
	handle->stateConfVector[0] = Prefix_TECX_LED;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state TITILA */
static void prefix_enseq_LED3_TITILA_default(Prefix* handle)
{
	/* 'default' enter sequence for state TITILA */
	prefix_enseq_LED3_TITILA_r1_default(handle);
}

/* 'default' enter sequence for state ENCENDIDO */
static void prefix_enseq_LED3_TITILA_r1_ENCENDIDO_default(Prefix* handle)
{
	/* 'default' enter sequence for state ENCENDIDO */
	prefix_enact_LED3_TITILA_r1_ENCENDIDO(handle);
	handle->stateConfVector[1] = Prefix_LED3_TITILA_r1_ENCENDIDO;
	handle->stateConfVectorPosition = 1;
}

/* 'default' enter sequence for state APAGADO */
static void prefix_enseq_LED3_TITILA_r1_APAGADO_default(Prefix* handle)
{
	/* 'default' enter sequence for state APAGADO */
	prefix_enact_LED3_TITILA_r1_APAGADO(handle);
	handle->stateConfVector[1] = Prefix_LED3_TITILA_r1_APAGADO;
	handle->stateConfVectorPosition = 1;
}

/* 'default' enter sequence for state REPOSO */
static void prefix_enseq_LED3_REPOSO_default(Prefix* handle)
{
	/* 'default' enter sequence for state REPOSO */
	prefix_enact_LED3_REPOSO(handle);
	handle->stateConfVector[1] = Prefix_LED3_REPOSO;
	handle->stateConfVectorPosition = 1;
}

/* 'default' enter sequence for region TECX */
static void prefix_enseq_TECX_default(Prefix* handle)
{
	/* 'default' enter sequence for region TECX */
	prefix_react_TECX__entry_Default(handle);
}

/* 'default' enter sequence for region LED3 */
static void prefix_enseq_LED3_default(Prefix* handle)
{
	/* 'default' enter sequence for region LED3 */
	prefix_react_LED3__entry_Default(handle);
}

/* 'default' enter sequence for region r1 */
static void prefix_enseq_LED3_TITILA_r1_default(Prefix* handle)
{
	/* 'default' enter sequence for region r1 */
	prefix_react_LED3_TITILA_r1__entry_Default(handle);
}

/* Default exit sequence for state DEBOUNCE */
static void prefix_exseq_TECX_DEBOUNCE(Prefix* handle)
{
	/* Default exit sequence for state DEBOUNCE */
	handle->stateConfVector[0] = Prefix_last_state;
	handle->stateConfVectorPosition = 0;
	prefix_exact_TECX_DEBOUNCE(handle);
}

/* Default exit sequence for state NO_OPRIMIDO */
static void prefix_exseq_TECX_NO_OPRIMIDO(Prefix* handle)
{
	/* Default exit sequence for state NO_OPRIMIDO */
	handle->stateConfVector[0] = Prefix_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state OPRIMIDO */
static void prefix_exseq_TECX_OPRIMIDO(Prefix* handle)
{
	/* Default exit sequence for state OPRIMIDO */
	handle->stateConfVector[0] = Prefix_last_state;
	handle->stateConfVectorPosition = 0;
	prefix_exact_TECX_OPRIMIDO(handle);
}

/* Default exit sequence for state VALIDACION */
static void prefix_exseq_TECX_VALIDACION(Prefix* handle)
{
	/* Default exit sequence for state VALIDACION */
	handle->stateConfVector[0] = Prefix_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state LED */
static void prefix_exseq_TECX_LED(Prefix* handle)
{
	/* Default exit sequence for state LED */
	handle->stateConfVector[0] = Prefix_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state TITILA */
static void prefix_exseq_LED3_TITILA(Prefix* handle)
{
	/* Default exit sequence for state TITILA */
	prefix_exseq_LED3_TITILA_r1(handle);
}

/* Default exit sequence for state ENCENDIDO */
static void prefix_exseq_LED3_TITILA_r1_ENCENDIDO(Prefix* handle)
{
	/* Default exit sequence for state ENCENDIDO */
	handle->stateConfVector[1] = Prefix_last_state;
	handle->stateConfVectorPosition = 1;
	prefix_exact_LED3_TITILA_r1_ENCENDIDO(handle);
}

/* Default exit sequence for state APAGADO */
static void prefix_exseq_LED3_TITILA_r1_APAGADO(Prefix* handle)
{
	/* Default exit sequence for state APAGADO */
	handle->stateConfVector[1] = Prefix_last_state;
	handle->stateConfVectorPosition = 1;
	prefix_exact_LED3_TITILA_r1_APAGADO(handle);
}

/* Default exit sequence for state REPOSO */
static void prefix_exseq_LED3_REPOSO(Prefix* handle)
{
	/* Default exit sequence for state REPOSO */
	handle->stateConfVector[1] = Prefix_last_state;
	handle->stateConfVectorPosition = 1;
}

/* Default exit sequence for region TECX */
static void prefix_exseq_TECX(Prefix* handle)
{
	/* Default exit sequence for region TECX */
	/* Handle exit of all possible states (of prefix.TECX) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case Prefix_TECX_DEBOUNCE :
		{
			prefix_exseq_TECX_DEBOUNCE(handle);
			break;
		}
		case Prefix_TECX_NO_OPRIMIDO :
		{
			prefix_exseq_TECX_NO_OPRIMIDO(handle);
			break;
		}
		case Prefix_TECX_OPRIMIDO :
		{
			prefix_exseq_TECX_OPRIMIDO(handle);
			break;
		}
		case Prefix_TECX_VALIDACION :
		{
			prefix_exseq_TECX_VALIDACION(handle);
			break;
		}
		case Prefix_TECX_LED :
		{
			prefix_exseq_TECX_LED(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region LED3 */
static void prefix_exseq_LED3(Prefix* handle)
{
	/* Default exit sequence for region LED3 */
	/* Handle exit of all possible states (of prefix.LED3) at position 1... */
	switch(handle->stateConfVector[ 1 ])
	{
		case Prefix_LED3_TITILA_r1_ENCENDIDO :
		{
			prefix_exseq_LED3_TITILA_r1_ENCENDIDO(handle);
			break;
		}
		case Prefix_LED3_TITILA_r1_APAGADO :
		{
			prefix_exseq_LED3_TITILA_r1_APAGADO(handle);
			break;
		}
		case Prefix_LED3_REPOSO :
		{
			prefix_exseq_LED3_REPOSO(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region r1 */
static void prefix_exseq_LED3_TITILA_r1(Prefix* handle)
{
	/* Default exit sequence for region r1 */
	/* Handle exit of all possible states (of prefix.LED3.TITILA.r1) at position 1... */
	switch(handle->stateConfVector[ 1 ])
	{
		case Prefix_LED3_TITILA_r1_ENCENDIDO :
		{
			prefix_exseq_LED3_TITILA_r1_ENCENDIDO(handle);
			break;
		}
		case Prefix_LED3_TITILA_r1_APAGADO :
		{
			prefix_exseq_LED3_TITILA_r1_APAGADO(handle);
			break;
		}
		default: break;
	}
}

/* The reactions of state DEBOUNCE. */
static void prefix_react_TECX_DEBOUNCE(Prefix* handle)
{
	/* The reactions of state DEBOUNCE. */
	if (prefix_check_TECX_DEBOUNCE_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_TECX_DEBOUNCE_tr0(handle);
	} 
}

/* The reactions of state NO_OPRIMIDO. */
static void prefix_react_TECX_NO_OPRIMIDO(Prefix* handle)
{
	/* The reactions of state NO_OPRIMIDO. */
	if (prefix_check_TECX_NO_OPRIMIDO_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_TECX_NO_OPRIMIDO_tr0(handle);
	} 
}

/* The reactions of state OPRIMIDO. */
static void prefix_react_TECX_OPRIMIDO(Prefix* handle)
{
	/* The reactions of state OPRIMIDO. */
	if (prefix_check_TECX_OPRIMIDO_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_TECX_OPRIMIDO_tr0(handle);
	} 
}

/* The reactions of state VALIDACION. */
static void prefix_react_TECX_VALIDACION(Prefix* handle)
{
	/* The reactions of state VALIDACION. */
	if (prefix_check_TECX_VALIDACION_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_TECX_VALIDACION_tr0(handle);
	}  else
	{
		if (prefix_check_TECX_VALIDACION_tr1_tr1(handle) == bool_true)
		{ 
			prefix_effect_TECX_VALIDACION_tr1(handle);
		} 
	}
}

/* The reactions of state LED. */
static void prefix_react_TECX_LED(Prefix* handle)
{
	/* The reactions of state LED. */
}

/* The reactions of state ENCENDIDO. */
static void prefix_react_LED3_TITILA_r1_ENCENDIDO(Prefix* handle)
{
	/* The reactions of state ENCENDIDO. */
	if (prefix_check_LED3_TITILA_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_LED3_TITILA_tr0(handle);
	}  else
	{
		if (prefix_check_LED3_TITILA_r1_ENCENDIDO_tr0_tr0(handle) == bool_true)
		{ 
			prefix_effect_LED3_TITILA_r1_ENCENDIDO_tr0(handle);
		} 
	}
}

/* The reactions of state APAGADO. */
static void prefix_react_LED3_TITILA_r1_APAGADO(Prefix* handle)
{
	/* The reactions of state APAGADO. */
	if (prefix_check_LED3_TITILA_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_LED3_TITILA_tr0(handle);
	}  else
	{
		if (prefix_check_LED3_TITILA_r1_APAGADO_tr0_tr0(handle) == bool_true)
		{ 
			prefix_effect_LED3_TITILA_r1_APAGADO_tr0(handle);
		} 
	}
}

/* The reactions of state REPOSO. */
static void prefix_react_LED3_REPOSO(Prefix* handle)
{
	/* The reactions of state REPOSO. */
	if (prefix_check_LED3_REPOSO_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_LED3_REPOSO_tr0(handle);
	} 
}

/* Default react sequence for initial entry  */
static void prefix_react_TECX__entry_Default(Prefix* handle)
{
	/* Default react sequence for initial entry  */
	prefix_enseq_TECX_LED_default(handle);
}

/* Default react sequence for initial entry  */
static void prefix_react_LED3_TITILA_r1__entry_Default(Prefix* handle)
{
	/* Default react sequence for initial entry  */
	prefix_enseq_LED3_TITILA_r1_APAGADO_default(handle);
}

/* Default react sequence for initial entry  */
static void prefix_react_LED3__entry_Default(Prefix* handle)
{
	/* Default react sequence for initial entry  */
	prefix_enseq_LED3_REPOSO_default(handle);
}


