
#include <stdlib.h>
#include <string.h>
#include "sc_types.h"
#include "Prefix.h"
#include "PrefixRequired.h"
/*! \file Implementation of the state machine 'prefix'
*/

/* prototypes of all internal functions */
static sc_boolean prefix_check_TECLAS_NO_OPRIMIDAS_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_TECLAS_DEBOUNCE_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_TECLAS_VALIDACION_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_TECLAS_VALIDACION_tr1_tr1(const Prefix* handle);
static sc_boolean prefix_check_TECLAS_OPRIMIDAS_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_LED_RGB_LEDRgb_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_LED_RGB_LEDrGb_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_LED_RGB_LEDrgB_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_LED1_AMPLITUD_FRECUENCIA_LED1OFF_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_LED1_AMPLITUD_FRECUENCIA_LED1ON_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_LED2___LED2OFF_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_LED2___LED2OFF_tr1_tr1(const Prefix* handle);
static sc_boolean prefix_check_LED2___LED2OFF_tr2_tr2(const Prefix* handle);
static sc_boolean prefix_check_LED2___LED2ON_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_LED3___LED3OFF_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_LED3___LED3OFF_tr1_tr1(const Prefix* handle);
static sc_boolean prefix_check_LED3___LED3OFF_tr2_tr2(const Prefix* handle);
static sc_boolean prefix_check_LED3___LED3ON_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_ESTADOS_FrecuencySelected_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_ESTADOS_FrecuencySelected_tr1_tr1(const Prefix* handle);
static sc_boolean prefix_check_ESTADOS_FrecuencySelected_tr2_tr2(const Prefix* handle);
static sc_boolean prefix_check_ESTADOS_AmplitudeSelected_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_ESTADOS_AmplitudeSelected_tr1_tr1(const Prefix* handle);
static sc_boolean prefix_check_ESTADOS_AmplitudeSelected_tr2_tr2(const Prefix* handle);
static void prefix_effect_TECLAS_NO_OPRIMIDAS_tr0(Prefix* handle);
static void prefix_effect_TECLAS_DEBOUNCE_tr0(Prefix* handle);
static void prefix_effect_TECLAS_VALIDACION_tr0(Prefix* handle);
static void prefix_effect_TECLAS_VALIDACION_tr1(Prefix* handle);
static void prefix_effect_TECLAS_OPRIMIDAS_tr0(Prefix* handle);
static void prefix_effect_LED_RGB_LEDRgb_tr0(Prefix* handle);
static void prefix_effect_LED_RGB_LEDrGb_tr0(Prefix* handle);
static void prefix_effect_LED_RGB_LEDrgB_tr0(Prefix* handle);
static void prefix_effect_LED1_AMPLITUD_FRECUENCIA_LED1OFF_tr0(Prefix* handle);
static void prefix_effect_LED1_AMPLITUD_FRECUENCIA_LED1ON_tr0(Prefix* handle);
static void prefix_effect_LED2___LED2OFF_tr0(Prefix* handle);
static void prefix_effect_LED2___LED2OFF_tr1(Prefix* handle);
static void prefix_effect_LED2___LED2OFF_tr2(Prefix* handle);
static void prefix_effect_LED2___LED2ON_tr0(Prefix* handle);
static void prefix_effect_LED3___LED3OFF_tr0(Prefix* handle);
static void prefix_effect_LED3___LED3OFF_tr1(Prefix* handle);
static void prefix_effect_LED3___LED3OFF_tr2(Prefix* handle);
static void prefix_effect_LED3___LED3ON_tr0(Prefix* handle);
static void prefix_effect_ESTADOS_FrecuencySelected_tr0(Prefix* handle);
static void prefix_effect_ESTADOS_FrecuencySelected_tr1(Prefix* handle);
static void prefix_effect_ESTADOS_FrecuencySelected_tr2(Prefix* handle);
static void prefix_effect_ESTADOS_AmplitudeSelected_tr0(Prefix* handle);
static void prefix_effect_ESTADOS_AmplitudeSelected_tr1(Prefix* handle);
static void prefix_effect_ESTADOS_AmplitudeSelected_tr2(Prefix* handle);
static void prefix_enact_TECLAS_DEBOUNCE(Prefix* handle);
static void prefix_enact_TECLAS_OPRIMIDAS(Prefix* handle);
static void prefix_enact_LED_RGB_LEDRgb(Prefix* handle);
static void prefix_enact_LED_RGB_LEDrGb(Prefix* handle);
static void prefix_enact_LED_RGB_LEDrgB(Prefix* handle);
static void prefix_enact_LED1_AMPLITUD_FRECUENCIA_LED1OFF(Prefix* handle);
static void prefix_enact_LED1_AMPLITUD_FRECUENCIA_LED1ON(Prefix* handle);
static void prefix_enact_LED2___LED2OFF(Prefix* handle);
static void prefix_enact_LED2___LED2ON(Prefix* handle);
static void prefix_enact_LED3___LED3OFF(Prefix* handle);
static void prefix_enact_LED3___LED3ON(Prefix* handle);
static void prefix_enact_ESTADOS_FrecuencySelected(Prefix* handle);
static void prefix_enact_ESTADOS_AmplitudeSelected(Prefix* handle);
static void prefix_exact_TECLAS_DEBOUNCE(Prefix* handle);
static void prefix_enseq_TECLAS_NO_OPRIMIDAS_default(Prefix* handle);
static void prefix_enseq_TECLAS_DEBOUNCE_default(Prefix* handle);
static void prefix_enseq_TECLAS_VALIDACION_default(Prefix* handle);
static void prefix_enseq_TECLAS_OPRIMIDAS_default(Prefix* handle);
static void prefix_enseq_LED_RGB_LEDRgb_default(Prefix* handle);
static void prefix_enseq_LED_RGB_LEDrGb_default(Prefix* handle);
static void prefix_enseq_LED_RGB_LEDrgB_default(Prefix* handle);
static void prefix_enseq_LED1_AMPLITUD_FRECUENCIA_LED1OFF_default(Prefix* handle);
static void prefix_enseq_LED1_AMPLITUD_FRECUENCIA_LED1ON_default(Prefix* handle);
static void prefix_enseq_LED2___LED2OFF_default(Prefix* handle);
static void prefix_enseq_LED2___LED2ON_default(Prefix* handle);
static void prefix_enseq_LED3___LED3OFF_default(Prefix* handle);
static void prefix_enseq_LED3___LED3ON_default(Prefix* handle);
static void prefix_enseq_ESTADOS_FrecuencySelected_default(Prefix* handle);
static void prefix_enseq_ESTADOS_AmplitudeSelected_default(Prefix* handle);
static void prefix_enseq_TECLAS_default(Prefix* handle);
static void prefix_enseq_LED_RGB_default(Prefix* handle);
static void prefix_enseq_LED1_AMPLITUD_FRECUENCIA_default(Prefix* handle);
static void prefix_enseq_LED2___default(Prefix* handle);
static void prefix_enseq_LED3___default(Prefix* handle);
static void prefix_enseq_ESTADOS_default(Prefix* handle);
static void prefix_exseq_TECLAS_NO_OPRIMIDAS(Prefix* handle);
static void prefix_exseq_TECLAS_DEBOUNCE(Prefix* handle);
static void prefix_exseq_TECLAS_VALIDACION(Prefix* handle);
static void prefix_exseq_TECLAS_OPRIMIDAS(Prefix* handle);
static void prefix_exseq_LED_RGB_LEDRgb(Prefix* handle);
static void prefix_exseq_LED_RGB_LEDrGb(Prefix* handle);
static void prefix_exseq_LED_RGB_LEDrgB(Prefix* handle);
static void prefix_exseq_LED1_AMPLITUD_FRECUENCIA_LED1OFF(Prefix* handle);
static void prefix_exseq_LED1_AMPLITUD_FRECUENCIA_LED1ON(Prefix* handle);
static void prefix_exseq_LED2___LED2OFF(Prefix* handle);
static void prefix_exseq_LED2___LED2ON(Prefix* handle);
static void prefix_exseq_LED3___LED3OFF(Prefix* handle);
static void prefix_exseq_LED3___LED3ON(Prefix* handle);
static void prefix_exseq_ESTADOS_FrecuencySelected(Prefix* handle);
static void prefix_exseq_ESTADOS_AmplitudeSelected(Prefix* handle);
static void prefix_exseq_TECLAS(Prefix* handle);
static void prefix_exseq_LED_RGB(Prefix* handle);
static void prefix_exseq_LED1_AMPLITUD_FRECUENCIA(Prefix* handle);
static void prefix_exseq_LED2__(Prefix* handle);
static void prefix_exseq_LED3__(Prefix* handle);
static void prefix_exseq_ESTADOS(Prefix* handle);
static void prefix_react_TECLAS_NO_OPRIMIDAS(Prefix* handle);
static void prefix_react_TECLAS_DEBOUNCE(Prefix* handle);
static void prefix_react_TECLAS_VALIDACION(Prefix* handle);
static void prefix_react_TECLAS_OPRIMIDAS(Prefix* handle);
static void prefix_react_LED_RGB_LEDRgb(Prefix* handle);
static void prefix_react_LED_RGB_LEDrGb(Prefix* handle);
static void prefix_react_LED_RGB_LEDrgB(Prefix* handle);
static void prefix_react_LED1_AMPLITUD_FRECUENCIA_LED1OFF(Prefix* handle);
static void prefix_react_LED1_AMPLITUD_FRECUENCIA_LED1ON(Prefix* handle);
static void prefix_react_LED2___LED2OFF(Prefix* handle);
static void prefix_react_LED2___LED2ON(Prefix* handle);
static void prefix_react_LED3___LED3OFF(Prefix* handle);
static void prefix_react_LED3___LED3ON(Prefix* handle);
static void prefix_react_ESTADOS_FrecuencySelected(Prefix* handle);
static void prefix_react_ESTADOS_AmplitudeSelected(Prefix* handle);
static void prefix_react_TECLAS__entry_Default(Prefix* handle);
static void prefix_react_LED_RGB__entry_Default(Prefix* handle);
static void prefix_react_LED1_AMPLITUD_FRECUENCIA__entry_Default(Prefix* handle);
static void prefix_react_LED2____entry_Default(Prefix* handle);
static void prefix_react_LED3____entry_Default(Prefix* handle);
static void prefix_react_ESTADOS__entry_Default(Prefix* handle);
static void prefix_clearInEvents(Prefix* handle);
static void prefix_clearOutEvents(Prefix* handle);

const sc_integer PREFIX_PREFIXIFACE_LEDR = 0;
const sc_integer PREFIX_PREFIXIFACE_LEDG = 1;
const sc_integer PREFIX_PREFIXIFACE_LEDB = 2;
const sc_integer PREFIX_PREFIXIFACE_LED1 = 3;
const sc_integer PREFIX_PREFIXIFACE_LED2 = 4;
const sc_integer PREFIX_PREFIXIFACE_LED3 = 5;
const sc_boolean PREFIX_PREFIXIFACE_LED_ON = bool_false;
const sc_boolean PREFIX_PREFIXIFACE_LED_OFF = bool_true;
const sc_boolean PREFIX_PREFIXIFACE_FRECSELECTED = bool_false;
const sc_boolean PREFIX_PREFIXIFACE_AMPSELECTED = bool_true;
const sc_integer PREFIX_PREFIXIFACE_TEC1 = 1 << 0;
const sc_integer PREFIX_PREFIXIFACE_TEC2 = 1 << 1;
const sc_integer PREFIX_PREFIXIFACE_TEC3 = 1 << 2;
const sc_integer PREFIX_PREFIXIFACE_TEC4 = 1 << 3;
const sc_integer PREFIX_PREFIXIFACE_FRECMAX = 5;
const sc_integer PREFIX_PREFIXIFACE_FRECMIN = 0;
const sc_integer PREFIX_PREFIXIFACE_AMPMAX = 5;
const sc_integer PREFIX_PREFIXIFACE_AMPMIN = 0;

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
	
		/* Default init sequence for statechart prefix */
		handle->internal.viTecla = 0;
		handle->internal.viSelector = bool_false;
		handle->internal.viFrecuencia = 0;
		handle->internal.viAmplitud = 0;
}

void prefix_enter(Prefix* handle)
{
	/* Default enter sequence for statechart prefix */
	prefix_enseq_TECLAS_default(handle);
	prefix_enseq_LED_RGB_default(handle);
	prefix_enseq_LED1_AMPLITUD_FRECUENCIA_default(handle);
	prefix_enseq_LED2___default(handle);
	prefix_enseq_LED3___default(handle);
	prefix_enseq_ESTADOS_default(handle);
}

void prefix_exit(Prefix* handle)
{
	/* Default exit sequence for statechart prefix */
	prefix_exseq_TECLAS(handle);
	prefix_exseq_LED_RGB(handle);
	prefix_exseq_LED1_AMPLITUD_FRECUENCIA(handle);
	prefix_exseq_LED2__(handle);
	prefix_exseq_LED3__(handle);
	prefix_exseq_ESTADOS(handle);
}

sc_boolean prefix_isActive(const Prefix* handle)
{
	sc_boolean result = bool_false;
	int i;
	
	for(i = 0; i < PREFIX_MAX_ORTHOGONAL_STATES; i++)
	{
		result = result || handle->stateConfVector[i] != Prefix_last_state;
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
	handle->iface.evTeclaXOprimida_raised = bool_false;
	handle->iface.evTeclaXNoOprimida_raised = bool_false;
	handle->internal.siTitilarLED_raised = bool_false;
	handle->internal.siNoTitilarLED_raised = bool_false;
	handle->internal.siTECXOK_raised = bool_false;
	handle->internal.evAmplitudeSelected_raised = bool_false;
	handle->internal.evFrecuencySelected_raised = bool_false;
	handle->internal.evMas_raised = bool_false;
	handle->internal.evMenos_raised = bool_false;
	handle->timeEvents.prefix_TECLAS_DEBOUNCE_tev0_raised = bool_false;
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
		case Prefix_TECLAS_NO_OPRIMIDAS:
		{
			prefix_react_TECLAS_NO_OPRIMIDAS(handle);
			break;
		}
		case Prefix_TECLAS_DEBOUNCE:
		{
			prefix_react_TECLAS_DEBOUNCE(handle);
			break;
		}
		case Prefix_TECLAS_VALIDACION:
		{
			prefix_react_TECLAS_VALIDACION(handle);
			break;
		}
		case Prefix_TECLAS_OPRIMIDAS:
		{
			prefix_react_TECLAS_OPRIMIDAS(handle);
			break;
		}
		case Prefix_LED_RGB_LEDRgb:
		{
			prefix_react_LED_RGB_LEDRgb(handle);
			break;
		}
		case Prefix_LED_RGB_LEDrGb:
		{
			prefix_react_LED_RGB_LEDrGb(handle);
			break;
		}
		case Prefix_LED_RGB_LEDrgB:
		{
			prefix_react_LED_RGB_LEDrgB(handle);
			break;
		}
		case Prefix_LED1_AMPLITUD_FRECUENCIA_LED1OFF:
		{
			prefix_react_LED1_AMPLITUD_FRECUENCIA_LED1OFF(handle);
			break;
		}
		case Prefix_LED1_AMPLITUD_FRECUENCIA_LED1ON:
		{
			prefix_react_LED1_AMPLITUD_FRECUENCIA_LED1ON(handle);
			break;
		}
		case Prefix_LED2___LED2OFF:
		{
			prefix_react_LED2___LED2OFF(handle);
			break;
		}
		case Prefix_LED2___LED2ON:
		{
			prefix_react_LED2___LED2ON(handle);
			break;
		}
		case Prefix_LED3___LED3OFF:
		{
			prefix_react_LED3___LED3OFF(handle);
			break;
		}
		case Prefix_LED3___LED3ON:
		{
			prefix_react_LED3___LED3ON(handle);
			break;
		}
		case Prefix_ESTADOS_FrecuencySelected:
		{
			prefix_react_ESTADOS_FrecuencySelected(handle);
			break;
		}
		case Prefix_ESTADOS_AmplitudeSelected:
		{
			prefix_react_ESTADOS_AmplitudeSelected(handle);
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
		case Prefix_TECLAS_NO_OPRIMIDAS :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PREFIX_TECLAS_NO_OPRIMIDAS] == Prefix_TECLAS_NO_OPRIMIDAS
			);
			break;
		case Prefix_TECLAS_DEBOUNCE :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PREFIX_TECLAS_DEBOUNCE] == Prefix_TECLAS_DEBOUNCE
			);
			break;
		case Prefix_TECLAS_VALIDACION :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PREFIX_TECLAS_VALIDACION] == Prefix_TECLAS_VALIDACION
			);
			break;
		case Prefix_TECLAS_OPRIMIDAS :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PREFIX_TECLAS_OPRIMIDAS] == Prefix_TECLAS_OPRIMIDAS
			);
			break;
		case Prefix_LED_RGB_LEDRgb :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PREFIX_LED_RGB_LEDRGB] == Prefix_LED_RGB_LEDRgb
			);
			break;
		case Prefix_LED_RGB_LEDrGb :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PREFIX_LED_RGB_LEDRGB] == Prefix_LED_RGB_LEDrGb
			);
			break;
		case Prefix_LED_RGB_LEDrgB :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PREFIX_LED_RGB_LEDRGB] == Prefix_LED_RGB_LEDrgB
			);
			break;
		case Prefix_LED1_AMPLITUD_FRECUENCIA_LED1OFF :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PREFIX_LED1_AMPLITUD_FRECUENCIA_LED1OFF] == Prefix_LED1_AMPLITUD_FRECUENCIA_LED1OFF
			);
			break;
		case Prefix_LED1_AMPLITUD_FRECUENCIA_LED1ON :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PREFIX_LED1_AMPLITUD_FRECUENCIA_LED1ON] == Prefix_LED1_AMPLITUD_FRECUENCIA_LED1ON
			);
			break;
		case Prefix_LED2___LED2OFF :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PREFIX_LED2___LED2OFF] == Prefix_LED2___LED2OFF
			);
			break;
		case Prefix_LED2___LED2ON :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PREFIX_LED2___LED2ON] == Prefix_LED2___LED2ON
			);
			break;
		case Prefix_LED3___LED3OFF :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PREFIX_LED3___LED3OFF] == Prefix_LED3___LED3OFF
			);
			break;
		case Prefix_LED3___LED3ON :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PREFIX_LED3___LED3ON] == Prefix_LED3___LED3ON
			);
			break;
		case Prefix_ESTADOS_FrecuencySelected :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PREFIX_ESTADOS_FRECUENCYSELECTED] == Prefix_ESTADOS_FrecuencySelected
			);
			break;
		case Prefix_ESTADOS_AmplitudeSelected :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PREFIX_ESTADOS_AMPLITUDESELECTED] == Prefix_ESTADOS_AmplitudeSelected
			);
			break;
		default:
			result = bool_false;
			break;
	}
	return result;
}

void prefixIface_raise_evTeclaXOprimida(Prefix* handle, sc_integer value)
{
	handle->iface.evTeclaXOprimida_value = value;
	handle->iface.evTeclaXOprimida_raised = bool_true;
}
void prefixIface_raise_evTeclaXNoOprimida(Prefix* handle)
{
	handle->iface.evTeclaXNoOprimida_raised = bool_true;
}


const sc_integer prefixIface_get_lEDR(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_LEDR;
}
const sc_integer prefixIface_get_lEDG(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_LEDG;
}
const sc_integer prefixIface_get_lEDB(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_LEDB;
}
const sc_integer prefixIface_get_lED1(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_LED1;
}
const sc_integer prefixIface_get_lED2(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_LED2;
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
const sc_boolean prefixIface_get_frecSelected(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_FRECSELECTED;
}
const sc_boolean prefixIface_get_ampSelected(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_AMPSELECTED;
}
const sc_integer prefixIface_get_tEC1(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_TEC1;
}
const sc_integer prefixIface_get_tEC2(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_TEC2;
}
const sc_integer prefixIface_get_tEC3(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_TEC3;
}
const sc_integer prefixIface_get_tEC4(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_TEC4;
}
const sc_integer prefixIface_get_fRECMAX(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_FRECMAX;
}
const sc_integer prefixIface_get_fRECMIN(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_FRECMIN;
}
const sc_integer prefixIface_get_aMPMAX(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_AMPMAX;
}
const sc_integer prefixIface_get_aMPMIN(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_AMPMIN;
}

/* implementations of all internal functions */

static sc_boolean prefix_check_TECLAS_NO_OPRIMIDAS_tr0_tr0(const Prefix* handle)
{
	return handle->iface.evTeclaXOprimida_raised;
}

static sc_boolean prefix_check_TECLAS_DEBOUNCE_tr0_tr0(const Prefix* handle)
{
	return handle->timeEvents.prefix_TECLAS_DEBOUNCE_tev0_raised;
}

static sc_boolean prefix_check_TECLAS_VALIDACION_tr0_tr0(const Prefix* handle)
{
	return handle->iface.evTeclaXOprimida_raised;
}

static sc_boolean prefix_check_TECLAS_VALIDACION_tr1_tr1(const Prefix* handle)
{
	return handle->iface.evTeclaXNoOprimida_raised;
}

static sc_boolean prefix_check_TECLAS_OPRIMIDAS_tr0_tr0(const Prefix* handle)
{
	return handle->iface.evTeclaXNoOprimida_raised;
}

static sc_boolean prefix_check_LED_RGB_LEDRgb_tr0_tr0(const Prefix* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == PREFIX_PREFIXIFACE_TEC1)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_LED_RGB_LEDrGb_tr0_tr0(const Prefix* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == 1)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_LED_RGB_LEDrgB_tr0_tr0(const Prefix* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == PREFIX_PREFIXIFACE_TEC1)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_LED1_AMPLITUD_FRECUENCIA_LED1OFF_tr0_tr0(const Prefix* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == PREFIX_PREFIXIFACE_TEC2)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_LED1_AMPLITUD_FRECUENCIA_LED1ON_tr0_tr0(const Prefix* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == PREFIX_PREFIXIFACE_TEC2)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_LED2___LED2OFF_tr0_tr0(const Prefix* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == PREFIX_PREFIXIFACE_TEC3)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_LED2___LED2OFF_tr1_tr1(const Prefix* handle)
{
	return (handle->internal.viSelector == PREFIX_PREFIXIFACE_AMPSELECTED && handle->internal.viAmplitud == PREFIX_PREFIXIFACE_AMPMAX) ? bool_true : bool_false;
}

static sc_boolean prefix_check_LED2___LED2OFF_tr2_tr2(const Prefix* handle)
{
	return (handle->internal.viSelector == PREFIX_PREFIXIFACE_FRECSELECTED && handle->internal.viFrecuencia == PREFIX_PREFIXIFACE_FRECMAX) ? bool_true : bool_false;
}

static sc_boolean prefix_check_LED2___LED2ON_tr0_tr0(const Prefix* handle)
{
	return ((handle->iface.evTeclaXNoOprimida_raised) && ((handle->internal.viSelector == PREFIX_PREFIXIFACE_AMPSELECTED && handle->internal.viAmplitud != PREFIX_PREFIXIFACE_AMPMAX) || (handle->internal.viSelector == PREFIX_PREFIXIFACE_FRECSELECTED && handle->internal.viFrecuencia != PREFIX_PREFIXIFACE_FRECMAX))) ? bool_true : bool_false;
}

static sc_boolean prefix_check_LED3___LED3OFF_tr0_tr0(const Prefix* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == PREFIX_PREFIXIFACE_TEC4)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_LED3___LED3OFF_tr1_tr1(const Prefix* handle)
{
	return (handle->internal.viSelector == PREFIX_PREFIXIFACE_AMPSELECTED && handle->internal.viAmplitud == PREFIX_PREFIXIFACE_AMPMIN) ? bool_true : bool_false;
}

static sc_boolean prefix_check_LED3___LED3OFF_tr2_tr2(const Prefix* handle)
{
	return (handle->internal.viSelector == PREFIX_PREFIXIFACE_FRECSELECTED && handle->internal.viFrecuencia == PREFIX_PREFIXIFACE_FRECMIN) ? bool_true : bool_false;
}

static sc_boolean prefix_check_LED3___LED3ON_tr0_tr0(const Prefix* handle)
{
	return ((handle->iface.evTeclaXNoOprimida_raised) && ((handle->internal.viSelector == PREFIX_PREFIXIFACE_FRECSELECTED && handle->internal.viFrecuencia != PREFIX_PREFIXIFACE_FRECMIN) || (handle->internal.viSelector == PREFIX_PREFIXIFACE_AMPSELECTED && handle->internal.viAmplitud != PREFIX_PREFIXIFACE_AMPMIN))) ? bool_true : bool_false;
}

static sc_boolean prefix_check_ESTADOS_FrecuencySelected_tr0_tr0(const Prefix* handle)
{
	return handle->internal.evAmplitudeSelected_raised;
}

static sc_boolean prefix_check_ESTADOS_FrecuencySelected_tr1_tr1(const Prefix* handle)
{
	return ((handle->internal.evMas_raised) && (handle->internal.viFrecuencia != PREFIX_PREFIXIFACE_FRECMAX)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_ESTADOS_FrecuencySelected_tr2_tr2(const Prefix* handle)
{
	return ((handle->internal.evMenos_raised) && (handle->internal.viFrecuencia != PREFIX_PREFIXIFACE_FRECMIN)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_ESTADOS_AmplitudeSelected_tr0_tr0(const Prefix* handle)
{
	return handle->internal.evFrecuencySelected_raised;
}

static sc_boolean prefix_check_ESTADOS_AmplitudeSelected_tr1_tr1(const Prefix* handle)
{
	return ((handle->internal.evMas_raised) && (handle->internal.viAmplitud != PREFIX_PREFIXIFACE_AMPMAX)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_ESTADOS_AmplitudeSelected_tr2_tr2(const Prefix* handle)
{
	return ((handle->internal.evMenos_raised) && (handle->internal.viAmplitud != PREFIX_PREFIXIFACE_AMPMIN)) ? bool_true : bool_false;
}

static void prefix_effect_TECLAS_NO_OPRIMIDAS_tr0(Prefix* handle)
{
	prefix_exseq_TECLAS_NO_OPRIMIDAS(handle);
	prefix_enseq_TECLAS_DEBOUNCE_default(handle);
}

static void prefix_effect_TECLAS_DEBOUNCE_tr0(Prefix* handle)
{
	prefix_exseq_TECLAS_DEBOUNCE(handle);
	prefix_enseq_TECLAS_VALIDACION_default(handle);
}

static void prefix_effect_TECLAS_VALIDACION_tr0(Prefix* handle)
{
	prefix_exseq_TECLAS_VALIDACION(handle);
	prefix_enseq_TECLAS_OPRIMIDAS_default(handle);
}

static void prefix_effect_TECLAS_VALIDACION_tr1(Prefix* handle)
{
	prefix_exseq_TECLAS_VALIDACION(handle);
	prefix_enseq_TECLAS_NO_OPRIMIDAS_default(handle);
}

static void prefix_effect_TECLAS_OPRIMIDAS_tr0(Prefix* handle)
{
	prefix_exseq_TECLAS_OPRIMIDAS(handle);
	prefix_enseq_TECLAS_NO_OPRIMIDAS_default(handle);
}

static void prefix_effect_LED_RGB_LEDRgb_tr0(Prefix* handle)
{
	prefix_exseq_LED_RGB_LEDRgb(handle);
	prefix_enseq_LED_RGB_LEDrGb_default(handle);
}

static void prefix_effect_LED_RGB_LEDrGb_tr0(Prefix* handle)
{
	prefix_exseq_LED_RGB_LEDrGb(handle);
	prefix_enseq_LED_RGB_LEDrgB_default(handle);
}

static void prefix_effect_LED_RGB_LEDrgB_tr0(Prefix* handle)
{
	prefix_exseq_LED_RGB_LEDrgB(handle);
	prefix_enseq_LED_RGB_LEDRgb_default(handle);
}

static void prefix_effect_LED1_AMPLITUD_FRECUENCIA_LED1OFF_tr0(Prefix* handle)
{
	prefix_exseq_LED1_AMPLITUD_FRECUENCIA_LED1OFF(handle);
	prefix_enseq_LED1_AMPLITUD_FRECUENCIA_LED1ON_default(handle);
}

static void prefix_effect_LED1_AMPLITUD_FRECUENCIA_LED1ON_tr0(Prefix* handle)
{
	prefix_exseq_LED1_AMPLITUD_FRECUENCIA_LED1ON(handle);
	prefix_enseq_LED1_AMPLITUD_FRECUENCIA_LED1OFF_default(handle);
}

static void prefix_effect_LED2___LED2OFF_tr0(Prefix* handle)
{
	prefix_exseq_LED2___LED2OFF(handle);
	handle->internal.evMas_raised = bool_true;
	prefix_enseq_LED2___LED2ON_default(handle);
}

static void prefix_effect_LED2___LED2OFF_tr1(Prefix* handle)
{
	prefix_exseq_LED2___LED2OFF(handle);
	prefix_enseq_LED2___LED2ON_default(handle);
}

static void prefix_effect_LED2___LED2OFF_tr2(Prefix* handle)
{
	prefix_exseq_LED2___LED2OFF(handle);
	prefix_enseq_LED2___LED2ON_default(handle);
}

static void prefix_effect_LED2___LED2ON_tr0(Prefix* handle)
{
	prefix_exseq_LED2___LED2ON(handle);
	prefix_enseq_LED2___LED2OFF_default(handle);
}

static void prefix_effect_LED3___LED3OFF_tr0(Prefix* handle)
{
	prefix_exseq_LED3___LED3OFF(handle);
	handle->internal.evMenos_raised = bool_true;
	prefix_enseq_LED3___LED3ON_default(handle);
}

static void prefix_effect_LED3___LED3OFF_tr1(Prefix* handle)
{
	prefix_exseq_LED3___LED3OFF(handle);
	prefix_enseq_LED3___LED3ON_default(handle);
}

static void prefix_effect_LED3___LED3OFF_tr2(Prefix* handle)
{
	prefix_exseq_LED3___LED3OFF(handle);
	prefix_enseq_LED3___LED3ON_default(handle);
}

static void prefix_effect_LED3___LED3ON_tr0(Prefix* handle)
{
	prefix_exseq_LED3___LED3ON(handle);
	prefix_enseq_LED3___LED3OFF_default(handle);
}

static void prefix_effect_ESTADOS_FrecuencySelected_tr0(Prefix* handle)
{
	prefix_exseq_ESTADOS_FrecuencySelected(handle);
	prefix_enseq_ESTADOS_AmplitudeSelected_default(handle);
}

static void prefix_effect_ESTADOS_FrecuencySelected_tr1(Prefix* handle)
{
	prefix_exseq_ESTADOS_FrecuencySelected(handle);
	handle->internal.viFrecuencia = handle->internal.viFrecuencia + 1;
	prefix_enseq_ESTADOS_FrecuencySelected_default(handle);
}

static void prefix_effect_ESTADOS_FrecuencySelected_tr2(Prefix* handle)
{
	prefix_exseq_ESTADOS_FrecuencySelected(handle);
	handle->internal.viFrecuencia = handle->internal.viFrecuencia - 1;
	prefix_enseq_ESTADOS_FrecuencySelected_default(handle);
}

static void prefix_effect_ESTADOS_AmplitudeSelected_tr0(Prefix* handle)
{
	prefix_exseq_ESTADOS_AmplitudeSelected(handle);
	prefix_enseq_ESTADOS_FrecuencySelected_default(handle);
}

static void prefix_effect_ESTADOS_AmplitudeSelected_tr1(Prefix* handle)
{
	prefix_exseq_ESTADOS_AmplitudeSelected(handle);
	handle->internal.viAmplitud = handle->internal.viAmplitud + 1;
	prefix_enseq_ESTADOS_AmplitudeSelected_default(handle);
}

static void prefix_effect_ESTADOS_AmplitudeSelected_tr2(Prefix* handle)
{
	prefix_exseq_ESTADOS_AmplitudeSelected(handle);
	handle->internal.viAmplitud = handle->internal.viAmplitud - 1;
	prefix_enseq_ESTADOS_AmplitudeSelected_default(handle);
}

/* Entry action for state 'DEBOUNCE'. */
static void prefix_enact_TECLAS_DEBOUNCE(Prefix* handle)
{
	/* Entry action for state 'DEBOUNCE'. */
	prefix_setTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_TECLAS_DEBOUNCE_tev0_raised) , 50, bool_false);
}

/* Entry action for state 'OPRIMIDAS'. */
static void prefix_enact_TECLAS_OPRIMIDAS(Prefix* handle)
{
	/* Entry action for state 'OPRIMIDAS'. */
	handle->internal.siTECXOK_raised = bool_true;
	handle->internal.viTecla = handle->iface.evTeclaXOprimida_value;
}

/* Entry action for state 'LEDRgb'. */
static void prefix_enact_LED_RGB_LEDRgb(Prefix* handle)
{
	/* Entry action for state 'LEDRgb'. */
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LEDR, PREFIX_PREFIXIFACE_LED_ON);
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LEDG, PREFIX_PREFIXIFACE_LED_OFF);
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LEDB, PREFIX_PREFIXIFACE_LED_OFF);
}

/* Entry action for state 'LEDrGb'. */
static void prefix_enact_LED_RGB_LEDrGb(Prefix* handle)
{
	/* Entry action for state 'LEDrGb'. */
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LEDR, PREFIX_PREFIXIFACE_LED_OFF);
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LEDG, PREFIX_PREFIXIFACE_LED_ON);
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LEDB, PREFIX_PREFIXIFACE_LED_OFF);
}

/* Entry action for state 'LEDrgB'. */
static void prefix_enact_LED_RGB_LEDrgB(Prefix* handle)
{
	/* Entry action for state 'LEDrgB'. */
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LEDR, PREFIX_PREFIXIFACE_LED_OFF);
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LEDG, PREFIX_PREFIXIFACE_LED_OFF);
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LEDB, PREFIX_PREFIXIFACE_LED_ON);
}

/* Entry action for state 'LED1OFF'. */
static void prefix_enact_LED1_AMPLITUD_FRECUENCIA_LED1OFF(Prefix* handle)
{
	/* Entry action for state 'LED1OFF'. */
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LED1, PREFIX_PREFIXIFACE_LED_OFF);
	handle->internal.evFrecuencySelected_raised = bool_true;
}

/* Entry action for state 'LED1ON'. */
static void prefix_enact_LED1_AMPLITUD_FRECUENCIA_LED1ON(Prefix* handle)
{
	/* Entry action for state 'LED1ON'. */
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LED1, PREFIX_PREFIXIFACE_LED_ON);
	handle->internal.evAmplitudeSelected_raised = bool_true;
}

/* Entry action for state 'LED2OFF'. */
static void prefix_enact_LED2___LED2OFF(Prefix* handle)
{
	/* Entry action for state 'LED2OFF'. */
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LED2, PREFIX_PREFIXIFACE_LED_OFF);
}

/* Entry action for state 'LED2ON'. */
static void prefix_enact_LED2___LED2ON(Prefix* handle)
{
	/* Entry action for state 'LED2ON'. */
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LED2, PREFIX_PREFIXIFACE_LED_ON);
}

/* Entry action for state 'LED3OFF'. */
static void prefix_enact_LED3___LED3OFF(Prefix* handle)
{
	/* Entry action for state 'LED3OFF'. */
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LED3, PREFIX_PREFIXIFACE_LED_OFF);
}

/* Entry action for state 'LED3ON'. */
static void prefix_enact_LED3___LED3ON(Prefix* handle)
{
	/* Entry action for state 'LED3ON'. */
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LED3, PREFIX_PREFIXIFACE_LED_ON);
}

/* Entry action for state 'FrecuencySelected'. */
static void prefix_enact_ESTADOS_FrecuencySelected(Prefix* handle)
{
	/* Entry action for state 'FrecuencySelected'. */
	handle->internal.viSelector = PREFIX_PREFIXIFACE_FRECSELECTED;
}

/* Entry action for state 'AmplitudeSelected'. */
static void prefix_enact_ESTADOS_AmplitudeSelected(Prefix* handle)
{
	/* Entry action for state 'AmplitudeSelected'. */
	handle->internal.viSelector = PREFIX_PREFIXIFACE_AMPSELECTED;
}

/* Exit action for state 'DEBOUNCE'. */
static void prefix_exact_TECLAS_DEBOUNCE(Prefix* handle)
{
	/* Exit action for state 'DEBOUNCE'. */
	prefix_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_TECLAS_DEBOUNCE_tev0_raised) );		
}

/* 'default' enter sequence for state NO_OPRIMIDAS */
static void prefix_enseq_TECLAS_NO_OPRIMIDAS_default(Prefix* handle)
{
	/* 'default' enter sequence for state NO_OPRIMIDAS */
	handle->stateConfVector[0] = Prefix_TECLAS_NO_OPRIMIDAS;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state DEBOUNCE */
static void prefix_enseq_TECLAS_DEBOUNCE_default(Prefix* handle)
{
	/* 'default' enter sequence for state DEBOUNCE */
	prefix_enact_TECLAS_DEBOUNCE(handle);
	handle->stateConfVector[0] = Prefix_TECLAS_DEBOUNCE;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state VALIDACION */
static void prefix_enseq_TECLAS_VALIDACION_default(Prefix* handle)
{
	/* 'default' enter sequence for state VALIDACION */
	handle->stateConfVector[0] = Prefix_TECLAS_VALIDACION;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state OPRIMIDAS */
static void prefix_enseq_TECLAS_OPRIMIDAS_default(Prefix* handle)
{
	/* 'default' enter sequence for state OPRIMIDAS */
	prefix_enact_TECLAS_OPRIMIDAS(handle);
	handle->stateConfVector[0] = Prefix_TECLAS_OPRIMIDAS;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state LEDRgb */
static void prefix_enseq_LED_RGB_LEDRgb_default(Prefix* handle)
{
	/* 'default' enter sequence for state LEDRgb */
	prefix_enact_LED_RGB_LEDRgb(handle);
	handle->stateConfVector[1] = Prefix_LED_RGB_LEDRgb;
	handle->stateConfVectorPosition = 1;
}

/* 'default' enter sequence for state LEDrGb */
static void prefix_enseq_LED_RGB_LEDrGb_default(Prefix* handle)
{
	/* 'default' enter sequence for state LEDrGb */
	prefix_enact_LED_RGB_LEDrGb(handle);
	handle->stateConfVector[1] = Prefix_LED_RGB_LEDrGb;
	handle->stateConfVectorPosition = 1;
}

/* 'default' enter sequence for state LEDrgB */
static void prefix_enseq_LED_RGB_LEDrgB_default(Prefix* handle)
{
	/* 'default' enter sequence for state LEDrgB */
	prefix_enact_LED_RGB_LEDrgB(handle);
	handle->stateConfVector[1] = Prefix_LED_RGB_LEDrgB;
	handle->stateConfVectorPosition = 1;
}

/* 'default' enter sequence for state LED1OFF */
static void prefix_enseq_LED1_AMPLITUD_FRECUENCIA_LED1OFF_default(Prefix* handle)
{
	/* 'default' enter sequence for state LED1OFF */
	prefix_enact_LED1_AMPLITUD_FRECUENCIA_LED1OFF(handle);
	handle->stateConfVector[2] = Prefix_LED1_AMPLITUD_FRECUENCIA_LED1OFF;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state LED1ON */
static void prefix_enseq_LED1_AMPLITUD_FRECUENCIA_LED1ON_default(Prefix* handle)
{
	/* 'default' enter sequence for state LED1ON */
	prefix_enact_LED1_AMPLITUD_FRECUENCIA_LED1ON(handle);
	handle->stateConfVector[2] = Prefix_LED1_AMPLITUD_FRECUENCIA_LED1ON;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state LED2OFF */
static void prefix_enseq_LED2___LED2OFF_default(Prefix* handle)
{
	/* 'default' enter sequence for state LED2OFF */
	prefix_enact_LED2___LED2OFF(handle);
	handle->stateConfVector[3] = Prefix_LED2___LED2OFF;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state LED2ON */
static void prefix_enseq_LED2___LED2ON_default(Prefix* handle)
{
	/* 'default' enter sequence for state LED2ON */
	prefix_enact_LED2___LED2ON(handle);
	handle->stateConfVector[3] = Prefix_LED2___LED2ON;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state LED3OFF */
static void prefix_enseq_LED3___LED3OFF_default(Prefix* handle)
{
	/* 'default' enter sequence for state LED3OFF */
	prefix_enact_LED3___LED3OFF(handle);
	handle->stateConfVector[4] = Prefix_LED3___LED3OFF;
	handle->stateConfVectorPosition = 4;
}

/* 'default' enter sequence for state LED3ON */
static void prefix_enseq_LED3___LED3ON_default(Prefix* handle)
{
	/* 'default' enter sequence for state LED3ON */
	prefix_enact_LED3___LED3ON(handle);
	handle->stateConfVector[4] = Prefix_LED3___LED3ON;
	handle->stateConfVectorPosition = 4;
}

/* 'default' enter sequence for state FrecuencySelected */
static void prefix_enseq_ESTADOS_FrecuencySelected_default(Prefix* handle)
{
	/* 'default' enter sequence for state FrecuencySelected */
	prefix_enact_ESTADOS_FrecuencySelected(handle);
	handle->stateConfVector[5] = Prefix_ESTADOS_FrecuencySelected;
	handle->stateConfVectorPosition = 5;
}

/* 'default' enter sequence for state AmplitudeSelected */
static void prefix_enseq_ESTADOS_AmplitudeSelected_default(Prefix* handle)
{
	/* 'default' enter sequence for state AmplitudeSelected */
	prefix_enact_ESTADOS_AmplitudeSelected(handle);
	handle->stateConfVector[5] = Prefix_ESTADOS_AmplitudeSelected;
	handle->stateConfVectorPosition = 5;
}

/* 'default' enter sequence for region TECLAS */
static void prefix_enseq_TECLAS_default(Prefix* handle)
{
	/* 'default' enter sequence for region TECLAS */
	prefix_react_TECLAS__entry_Default(handle);
}

/* 'default' enter sequence for region LED RGB */
static void prefix_enseq_LED_RGB_default(Prefix* handle)
{
	/* 'default' enter sequence for region LED RGB */
	prefix_react_LED_RGB__entry_Default(handle);
}

/* 'default' enter sequence for region LED1_AMPLITUD_FRECUENCIA */
static void prefix_enseq_LED1_AMPLITUD_FRECUENCIA_default(Prefix* handle)
{
	/* 'default' enter sequence for region LED1_AMPLITUD_FRECUENCIA */
	prefix_react_LED1_AMPLITUD_FRECUENCIA__entry_Default(handle);
}

/* 'default' enter sequence for region LED2_+ */
static void prefix_enseq_LED2___default(Prefix* handle)
{
	/* 'default' enter sequence for region LED2_+ */
	prefix_react_LED2____entry_Default(handle);
}

/* 'default' enter sequence for region LED3_- */
static void prefix_enseq_LED3___default(Prefix* handle)
{
	/* 'default' enter sequence for region LED3_- */
	prefix_react_LED3____entry_Default(handle);
}

/* 'default' enter sequence for region ESTADOS */
static void prefix_enseq_ESTADOS_default(Prefix* handle)
{
	/* 'default' enter sequence for region ESTADOS */
	prefix_react_ESTADOS__entry_Default(handle);
}

/* Default exit sequence for state NO_OPRIMIDAS */
static void prefix_exseq_TECLAS_NO_OPRIMIDAS(Prefix* handle)
{
	/* Default exit sequence for state NO_OPRIMIDAS */
	handle->stateConfVector[0] = Prefix_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state DEBOUNCE */
static void prefix_exseq_TECLAS_DEBOUNCE(Prefix* handle)
{
	/* Default exit sequence for state DEBOUNCE */
	handle->stateConfVector[0] = Prefix_last_state;
	handle->stateConfVectorPosition = 0;
	prefix_exact_TECLAS_DEBOUNCE(handle);
}

/* Default exit sequence for state VALIDACION */
static void prefix_exseq_TECLAS_VALIDACION(Prefix* handle)
{
	/* Default exit sequence for state VALIDACION */
	handle->stateConfVector[0] = Prefix_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state OPRIMIDAS */
static void prefix_exseq_TECLAS_OPRIMIDAS(Prefix* handle)
{
	/* Default exit sequence for state OPRIMIDAS */
	handle->stateConfVector[0] = Prefix_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state LEDRgb */
static void prefix_exseq_LED_RGB_LEDRgb(Prefix* handle)
{
	/* Default exit sequence for state LEDRgb */
	handle->stateConfVector[1] = Prefix_last_state;
	handle->stateConfVectorPosition = 1;
}

/* Default exit sequence for state LEDrGb */
static void prefix_exseq_LED_RGB_LEDrGb(Prefix* handle)
{
	/* Default exit sequence for state LEDrGb */
	handle->stateConfVector[1] = Prefix_last_state;
	handle->stateConfVectorPosition = 1;
}

/* Default exit sequence for state LEDrgB */
static void prefix_exseq_LED_RGB_LEDrgB(Prefix* handle)
{
	/* Default exit sequence for state LEDrgB */
	handle->stateConfVector[1] = Prefix_last_state;
	handle->stateConfVectorPosition = 1;
}

/* Default exit sequence for state LED1OFF */
static void prefix_exseq_LED1_AMPLITUD_FRECUENCIA_LED1OFF(Prefix* handle)
{
	/* Default exit sequence for state LED1OFF */
	handle->stateConfVector[2] = Prefix_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for state LED1ON */
static void prefix_exseq_LED1_AMPLITUD_FRECUENCIA_LED1ON(Prefix* handle)
{
	/* Default exit sequence for state LED1ON */
	handle->stateConfVector[2] = Prefix_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for state LED2OFF */
static void prefix_exseq_LED2___LED2OFF(Prefix* handle)
{
	/* Default exit sequence for state LED2OFF */
	handle->stateConfVector[3] = Prefix_last_state;
	handle->stateConfVectorPosition = 3;
}

/* Default exit sequence for state LED2ON */
static void prefix_exseq_LED2___LED2ON(Prefix* handle)
{
	/* Default exit sequence for state LED2ON */
	handle->stateConfVector[3] = Prefix_last_state;
	handle->stateConfVectorPosition = 3;
}

/* Default exit sequence for state LED3OFF */
static void prefix_exseq_LED3___LED3OFF(Prefix* handle)
{
	/* Default exit sequence for state LED3OFF */
	handle->stateConfVector[4] = Prefix_last_state;
	handle->stateConfVectorPosition = 4;
}

/* Default exit sequence for state LED3ON */
static void prefix_exseq_LED3___LED3ON(Prefix* handle)
{
	/* Default exit sequence for state LED3ON */
	handle->stateConfVector[4] = Prefix_last_state;
	handle->stateConfVectorPosition = 4;
}

/* Default exit sequence for state FrecuencySelected */
static void prefix_exseq_ESTADOS_FrecuencySelected(Prefix* handle)
{
	/* Default exit sequence for state FrecuencySelected */
	handle->stateConfVector[5] = Prefix_last_state;
	handle->stateConfVectorPosition = 5;
}

/* Default exit sequence for state AmplitudeSelected */
static void prefix_exseq_ESTADOS_AmplitudeSelected(Prefix* handle)
{
	/* Default exit sequence for state AmplitudeSelected */
	handle->stateConfVector[5] = Prefix_last_state;
	handle->stateConfVectorPosition = 5;
}

/* Default exit sequence for region TECLAS */
static void prefix_exseq_TECLAS(Prefix* handle)
{
	/* Default exit sequence for region TECLAS */
	/* Handle exit of all possible states (of prefix.TECLAS) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case Prefix_TECLAS_NO_OPRIMIDAS :
		{
			prefix_exseq_TECLAS_NO_OPRIMIDAS(handle);
			break;
		}
		case Prefix_TECLAS_DEBOUNCE :
		{
			prefix_exseq_TECLAS_DEBOUNCE(handle);
			break;
		}
		case Prefix_TECLAS_VALIDACION :
		{
			prefix_exseq_TECLAS_VALIDACION(handle);
			break;
		}
		case Prefix_TECLAS_OPRIMIDAS :
		{
			prefix_exseq_TECLAS_OPRIMIDAS(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region LED RGB */
static void prefix_exseq_LED_RGB(Prefix* handle)
{
	/* Default exit sequence for region LED RGB */
	/* Handle exit of all possible states (of prefix.LED_RGB) at position 1... */
	switch(handle->stateConfVector[ 1 ])
	{
		case Prefix_LED_RGB_LEDRgb :
		{
			prefix_exseq_LED_RGB_LEDRgb(handle);
			break;
		}
		case Prefix_LED_RGB_LEDrGb :
		{
			prefix_exseq_LED_RGB_LEDrGb(handle);
			break;
		}
		case Prefix_LED_RGB_LEDrgB :
		{
			prefix_exseq_LED_RGB_LEDrgB(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region LED1_AMPLITUD_FRECUENCIA */
static void prefix_exseq_LED1_AMPLITUD_FRECUENCIA(Prefix* handle)
{
	/* Default exit sequence for region LED1_AMPLITUD_FRECUENCIA */
	/* Handle exit of all possible states (of prefix.LED1_AMPLITUD_FRECUENCIA) at position 2... */
	switch(handle->stateConfVector[ 2 ])
	{
		case Prefix_LED1_AMPLITUD_FRECUENCIA_LED1OFF :
		{
			prefix_exseq_LED1_AMPLITUD_FRECUENCIA_LED1OFF(handle);
			break;
		}
		case Prefix_LED1_AMPLITUD_FRECUENCIA_LED1ON :
		{
			prefix_exseq_LED1_AMPLITUD_FRECUENCIA_LED1ON(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region LED2_+ */
static void prefix_exseq_LED2__(Prefix* handle)
{
	/* Default exit sequence for region LED2_+ */
	/* Handle exit of all possible states (of prefix.LED2__) at position 3... */
	switch(handle->stateConfVector[ 3 ])
	{
		case Prefix_LED2___LED2OFF :
		{
			prefix_exseq_LED2___LED2OFF(handle);
			break;
		}
		case Prefix_LED2___LED2ON :
		{
			prefix_exseq_LED2___LED2ON(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region LED3_- */
static void prefix_exseq_LED3__(Prefix* handle)
{
	/* Default exit sequence for region LED3_- */
	/* Handle exit of all possible states (of prefix.LED3__) at position 4... */
	switch(handle->stateConfVector[ 4 ])
	{
		case Prefix_LED3___LED3OFF :
		{
			prefix_exseq_LED3___LED3OFF(handle);
			break;
		}
		case Prefix_LED3___LED3ON :
		{
			prefix_exseq_LED3___LED3ON(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region ESTADOS */
static void prefix_exseq_ESTADOS(Prefix* handle)
{
	/* Default exit sequence for region ESTADOS */
	/* Handle exit of all possible states (of prefix.ESTADOS) at position 5... */
	switch(handle->stateConfVector[ 5 ])
	{
		case Prefix_ESTADOS_FrecuencySelected :
		{
			prefix_exseq_ESTADOS_FrecuencySelected(handle);
			break;
		}
		case Prefix_ESTADOS_AmplitudeSelected :
		{
			prefix_exseq_ESTADOS_AmplitudeSelected(handle);
			break;
		}
		default: break;
	}
}

/* The reactions of state NO_OPRIMIDAS. */
static void prefix_react_TECLAS_NO_OPRIMIDAS(Prefix* handle)
{
	/* The reactions of state NO_OPRIMIDAS. */
	if (prefix_check_TECLAS_NO_OPRIMIDAS_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_TECLAS_NO_OPRIMIDAS_tr0(handle);
	} 
}

/* The reactions of state DEBOUNCE. */
static void prefix_react_TECLAS_DEBOUNCE(Prefix* handle)
{
	/* The reactions of state DEBOUNCE. */
	if (prefix_check_TECLAS_DEBOUNCE_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_TECLAS_DEBOUNCE_tr0(handle);
	} 
}

/* The reactions of state VALIDACION. */
static void prefix_react_TECLAS_VALIDACION(Prefix* handle)
{
	/* The reactions of state VALIDACION. */
	if (prefix_check_TECLAS_VALIDACION_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_TECLAS_VALIDACION_tr0(handle);
	}  else
	{
		if (prefix_check_TECLAS_VALIDACION_tr1_tr1(handle) == bool_true)
		{ 
			prefix_effect_TECLAS_VALIDACION_tr1(handle);
		} 
	}
}

/* The reactions of state OPRIMIDAS. */
static void prefix_react_TECLAS_OPRIMIDAS(Prefix* handle)
{
	/* The reactions of state OPRIMIDAS. */
	if (prefix_check_TECLAS_OPRIMIDAS_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_TECLAS_OPRIMIDAS_tr0(handle);
	} 
}

/* The reactions of state LEDRgb. */
static void prefix_react_LED_RGB_LEDRgb(Prefix* handle)
{
	/* The reactions of state LEDRgb. */
	if (prefix_check_LED_RGB_LEDRgb_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_LED_RGB_LEDRgb_tr0(handle);
	} 
}

/* The reactions of state LEDrGb. */
static void prefix_react_LED_RGB_LEDrGb(Prefix* handle)
{
	/* The reactions of state LEDrGb. */
	if (prefix_check_LED_RGB_LEDrGb_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_LED_RGB_LEDrGb_tr0(handle);
	} 
}

/* The reactions of state LEDrgB. */
static void prefix_react_LED_RGB_LEDrgB(Prefix* handle)
{
	/* The reactions of state LEDrgB. */
	if (prefix_check_LED_RGB_LEDrgB_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_LED_RGB_LEDrgB_tr0(handle);
	} 
}

/* The reactions of state LED1OFF. */
static void prefix_react_LED1_AMPLITUD_FRECUENCIA_LED1OFF(Prefix* handle)
{
	/* The reactions of state LED1OFF. */
	if (prefix_check_LED1_AMPLITUD_FRECUENCIA_LED1OFF_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_LED1_AMPLITUD_FRECUENCIA_LED1OFF_tr0(handle);
	} 
}

/* The reactions of state LED1ON. */
static void prefix_react_LED1_AMPLITUD_FRECUENCIA_LED1ON(Prefix* handle)
{
	/* The reactions of state LED1ON. */
	if (prefix_check_LED1_AMPLITUD_FRECUENCIA_LED1ON_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_LED1_AMPLITUD_FRECUENCIA_LED1ON_tr0(handle);
	} 
}

/* The reactions of state LED2OFF. */
static void prefix_react_LED2___LED2OFF(Prefix* handle)
{
	/* The reactions of state LED2OFF. */
	if (prefix_check_LED2___LED2OFF_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_LED2___LED2OFF_tr0(handle);
	}  else
	{
		if (prefix_check_LED2___LED2OFF_tr1_tr1(handle) == bool_true)
		{ 
			prefix_effect_LED2___LED2OFF_tr1(handle);
		}  else
		{
			if (prefix_check_LED2___LED2OFF_tr2_tr2(handle) == bool_true)
			{ 
				prefix_effect_LED2___LED2OFF_tr2(handle);
			} 
		}
	}
}

/* The reactions of state LED2ON. */
static void prefix_react_LED2___LED2ON(Prefix* handle)
{
	/* The reactions of state LED2ON. */
	if (prefix_check_LED2___LED2ON_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_LED2___LED2ON_tr0(handle);
	} 
}

/* The reactions of state LED3OFF. */
static void prefix_react_LED3___LED3OFF(Prefix* handle)
{
	/* The reactions of state LED3OFF. */
	if (prefix_check_LED3___LED3OFF_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_LED3___LED3OFF_tr0(handle);
	}  else
	{
		if (prefix_check_LED3___LED3OFF_tr1_tr1(handle) == bool_true)
		{ 
			prefix_effect_LED3___LED3OFF_tr1(handle);
		}  else
		{
			if (prefix_check_LED3___LED3OFF_tr2_tr2(handle) == bool_true)
			{ 
				prefix_effect_LED3___LED3OFF_tr2(handle);
			} 
		}
	}
}

/* The reactions of state LED3ON. */
static void prefix_react_LED3___LED3ON(Prefix* handle)
{
	/* The reactions of state LED3ON. */
	if (prefix_check_LED3___LED3ON_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_LED3___LED3ON_tr0(handle);
	} 
}

/* The reactions of state FrecuencySelected. */
static void prefix_react_ESTADOS_FrecuencySelected(Prefix* handle)
{
	/* The reactions of state FrecuencySelected. */
	if (prefix_check_ESTADOS_FrecuencySelected_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_ESTADOS_FrecuencySelected_tr0(handle);
	}  else
	{
		if (prefix_check_ESTADOS_FrecuencySelected_tr1_tr1(handle) == bool_true)
		{ 
			prefix_effect_ESTADOS_FrecuencySelected_tr1(handle);
		}  else
		{
			if (prefix_check_ESTADOS_FrecuencySelected_tr2_tr2(handle) == bool_true)
			{ 
				prefix_effect_ESTADOS_FrecuencySelected_tr2(handle);
			} 
		}
	}
}

/* The reactions of state AmplitudeSelected. */
static void prefix_react_ESTADOS_AmplitudeSelected(Prefix* handle)
{
	/* The reactions of state AmplitudeSelected. */
	if (prefix_check_ESTADOS_AmplitudeSelected_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_ESTADOS_AmplitudeSelected_tr0(handle);
	}  else
	{
		if (prefix_check_ESTADOS_AmplitudeSelected_tr1_tr1(handle) == bool_true)
		{ 
			prefix_effect_ESTADOS_AmplitudeSelected_tr1(handle);
		}  else
		{
			if (prefix_check_ESTADOS_AmplitudeSelected_tr2_tr2(handle) == bool_true)
			{ 
				prefix_effect_ESTADOS_AmplitudeSelected_tr2(handle);
			} 
		}
	}
}

/* Default react sequence for initial entry  */
static void prefix_react_TECLAS__entry_Default(Prefix* handle)
{
	/* Default react sequence for initial entry  */
	prefix_enseq_TECLAS_NO_OPRIMIDAS_default(handle);
}

/* Default react sequence for initial entry  */
static void prefix_react_LED_RGB__entry_Default(Prefix* handle)
{
	/* Default react sequence for initial entry  */
	prefix_enseq_LED_RGB_LEDRgb_default(handle);
}

/* Default react sequence for initial entry  */
static void prefix_react_LED1_AMPLITUD_FRECUENCIA__entry_Default(Prefix* handle)
{
	/* Default react sequence for initial entry  */
	prefix_enseq_LED1_AMPLITUD_FRECUENCIA_LED1OFF_default(handle);
}

/* Default react sequence for initial entry  */
static void prefix_react_LED2____entry_Default(Prefix* handle)
{
	/* Default react sequence for initial entry  */
	prefix_enseq_LED2___LED2OFF_default(handle);
}

/* Default react sequence for initial entry  */
static void prefix_react_LED3____entry_Default(Prefix* handle)
{
	/* Default react sequence for initial entry  */
	prefix_enseq_LED3___LED3OFF_default(handle);
}

/* Default react sequence for initial entry  */
static void prefix_react_ESTADOS__entry_Default(Prefix* handle)
{
	/* Default react sequence for initial entry  */
	prefix_enseq_ESTADOS_FrecuencySelected_default(handle);
}


