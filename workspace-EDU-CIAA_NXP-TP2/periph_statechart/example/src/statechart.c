/*
 * @brief Statechart example using sysTick
 *
 * @note
 * Copyright(C) NXP Semiconductors, 2013
 * All rights reserved.
 *
 * @par
 * Software that is described herein is for illustrative purposes only
 * which provides customers with programming information regarding the
 * LPC products.  This software is supplied "AS IS" without any warranties of
 * any kind, and NXP Semiconductors and its licensor disclaim any and
 * all warranties, express or implied, including all implied warranties of
 * merchantability, fitness for a particular purpose and non-infringement of
 * intellectual property rights.  NXP Semiconductors assumes no responsibility
 * or liability for the use of the software, conveys no license or rights under any
 * patent, copyright, mask work right, or any other intellectual property rights in
 * or to any products. NXP Semiconductors reserves the right to make changes
 * in the software without notification. NXP Semiconductors also makes no
 * representation or warranty that such application will be suitable for the
 * specified use without further testing or modification.
 *
 * @par
 * Permission to use, copy, modify, and distribute this software and its
 * documentation is hereby granted, under NXP Semiconductors' and its
 * licensor's relevant copyrights in the software, without fee, provided that it
 * is used in conjunction with NXP Semiconductors microcontrollers.  This
 * copyright, permission, and disclaimer notice must appear in all copies of
 * this code.
 */

#include "board.h"
#include "src-gen/Prefix.h"
#include "TimerTicks.h"


/*****************************************************************************
 * Private types/enumerations/variables
 ****************************************************************************/
#define TICKRATE_10HZ (10)				/* 10 ticks per second */
#define TICKRATE_100HZ (100)			/* 100 ticks per second */
#define TICKRATE_1000HZ (1000)			/* 1000 ticks per second */
#define TICKRATE_HZ (TICKRATE_1000HZ)


#define TP2_X ('X')	/* Test Statechart EDU-CIAA-NXP - Blink LED3. Usar prefix=BlinkWOTimeEvent.sct*/
#define TP2_XX ('XX')	/* Test Statechart EDU-CIAA-NXP - Blink TimeEvent LED3 Usar prefix=BlinkTimeEvent.sct*/
#define TP2_Y ('Y')	/* Test Statechart EDU-CIAA-NXP - Idle Blink LED3 */
#define TP2_Z ('Y')	/* Test Statechart EDU-CIAA-NXP - Button */
#define TP2_1 (1)	/* Test Statechart EDU-CIAA-NXP - IDE LPCXpresso - Application */
#define TP2_2 (2)	/* Test Statechart EDU-CIAA-NXP - Panel de Control Generador de Señales */
#define TP2_3 (3)	/* Test Statechart EDU-CIAA-NXP - Puerta Corrediza */
#define TP2_4 (4)	/* Test Statechart EDU-CIAA-NXP - Portón de Cochera */
#define TP2_5 (5)	/* Test Statechart EDU-CIAA-NXP - Escalera Mecánica */
#define TP2_6 (6)	/* Test Statechart EDU-CIAA-NXP - Horno Microondas */

#define TEST (TP2_XX)


/*****************************************************************************
 * Public types/enumerations/variables
 ****************************************************************************/
volatile bool SysTick_Time_Flag = false;

/*! This is a state machine */
static Prefix statechart;

#if TEST== TP2_X
#define __USE_TIME_EVENTS (false)	/* "true" with TimerEvents or "false" without TimeEvents */
#elif TEST== TP2_XX
#define __USE_TIME_EVENTS (true)
#endif

/*! This is a timed state machine that requires timer services */
#if (__USE_TIME_EVENTS == true)
	#define NOF_TIMERS (sizeof(PrefixTimeEvents)/sizeof(sc_boolean))
#else
	#define NOF_TIMERS 0
#endif

TimerTicks ticks[NOF_TIMERS];


/*****************************************************************************
 * Private functions
 ****************************************************************************/

/*****************************************************************************
 * Public functions
 ****************************************************************************/
/*! \file This header defines prototypes for all functions that are required by the state machine implementation.

This is a state machine uses time events which require access to a timing service. Thus the function prototypes:
	- prefix_setTimer and
	- prefix_unsetTimer
are defined.

This state machine makes use of operations declared in the state machines interface or internal scopes. Thus the function prototypes:
	- prefixIface_opLED
are defined.

These functions will be called during a 'run to completion step' (runCycle) of the statechart.
There are some constraints that have to be considered for the implementation of these functions:
	- never call the statechart API functions from within these functions.
	- make sure that the execution time is as short as possible.

*/
void prefixIface_opLED(Prefix* handle, sc_integer LEDNumber, sc_boolean State)
{
	Board_LED_Set((uint8_t) LEDNumber, State);
}


/*!
 * This is a timed state machine that requires timer services
 */

#if (__USE_TIME_EVENTS == true)
/*! This function has to set up timers for the time events that are required by the state machine. */
/*!
	This function will be called for each time event that is relevant for a state when a state will be entered.
	\param evid An unique identifier of the event.
	\time_ms The time in milli seconds
	\periodic Indicates the the time event must be raised periodically until the timer is unset
*/
void prefix_setTimer(Prefix* handle, const sc_eventid evid, const sc_integer time_ms, const sc_boolean periodic)
{
	SetNewTimerTick(ticks, NOF_TIMERS, evid, time_ms, periodic);
}

/*! This function has to unset timers for the time events that are required by the state machine. */
/*!
	This function will be called for each time event taht is relevant for a state when a state will be left.
	\param evid An unique identifier of the event.
*/
void prefix_unsetTimer(Prefix* handle, const sc_eventid evid)
{
	UnsetTimerTick(ticks, NOF_TIMERS, evid);
}
#endif


/**
 * @brief	Handle interrupt from SysTick timer
 * @return	Nothing
 */
void SysTick_Handler(void)
{
	SysTick_Time_Flag = true;
}


#if (TEST == TP2_X)
/**
 * @brief	main routine for statechart example
 * @return	Function should not exit.
 */
int main(void)
{
	#if (__USE_TIME_EVENTS == true)
	uint32_t i;
	#endif

	/* Generic Initialization */
	SystemCoreClockUpdate();
	Board_Init();

	/* Enable and setup SysTick Timer at a periodic rate */
	SysTick_Config(SystemCoreClock / TICKRATE_HZ);

	/* Statechart Initialization */
	#if (__USE_TIME_EVENTS == true)
	InitTimerTicks(ticks, NOF_TIMERS);
	#endif

	prefix_init(&statechart);
	prefix_enter(&statechart);

	/* LEDs toggle in main */
	while (1) {
		__WFI();

		if (SysTick_Time_Flag == true) {
			SysTick_Time_Flag = false;

			#if (__USE_TIME_EVENTS == true)
			UpdateTimers(ticks, NOF_TIMERS);
			for (i = 0; i < NOF_TIMERS; i++) {
				if (IsPendEvent(ticks, NOF_TIMERS, ticks[i].evid) == true) {

					prefix_raiseTimeEvent(&statechart, ticks[i].evid);	// Event -> Ticks.evid => OK
					MarkAsAttEvent(ticks, NOF_TIMERS, ticks[i].evid);
				}
			}
			#else
			prefixIface_raise_evTick(&statechart);					// Event -> evTick => OK
			#endif

			prefix_runCycle(&statechart);							// Run Cycle of Statechart
		}
	}
}
#endif


#if (TEST == TP2_Y)
/**
 * @brief	main routine for statechart example
 * @return	Function should not exit.
 */
int main(void)
{
#if (__USE_TIME_EVENTS == true)
	uint32_t i;
#endif

	uint32_t BUTTON_Status;

	/* Generic Initialization */
	SystemCoreClockUpdate();
	Board_Init();

	/* Enable and setup SysTick Timer at a periodic rate */
	SysTick_Config(SystemCoreClock / TICKRATE_HZ);

	/* Statechart Initialization */
	#if (__USE_TIME_EVENTS == true)
	InitTimerTicks(ticks, NOF_TIMERS);
	#endif

	prefix_init(&statechart);
	prefix_enter(&statechart);

	/* LEDs toggle in main */
	while (1) {
		__WFI();

		if (SysTick_Time_Flag == true) {
			SysTick_Time_Flag = false;

			#if (__USE_TIME_EVENTS == true)
			UpdateTimers(ticks, NOF_TIMERS);
			for (i = 0; i < NOF_TIMERS; i++) {
				if (IsPendEvent(ticks, NOF_TIMERS, ticks[i].evid) == true) {

					prefix_raiseTimeEvent(&statechart, ticks[i].evid);	// Event -> Ticks.evid => OK
					MarkAsAttEvent(ticks, NOF_TIMERS, ticks[i].evid);
				}
			}
			#else
			prefixIface_raise_evTick(&statechart);					// Event -> evTick => OK
			#endif

			BUTTON_Status = Buttons_GetStatus();
			if (BUTTON_Status != 0)
				prefixIface_raise_evTECXOprimido(&statechart);		// Event -> evTECXOprimodo => OK
			else
				prefixIface_raise_evTECXNoOprimido(&statechart);	// Event -> evTECXNoOprimido => OK

			prefix_runCycle(&statechart);							// Run Cycle of Statechart
		}
	}
}
#endif


#if (TEST == TP2_1)
/**
 * @brief	main routine for statechart example
 * @return	Function should not exit.
 */
int main(void)
{
	#if (__USE_TIME_EVENTS == true)
	uint32_t i;
	#endif

	uint32_t BUTTON_Status;

	/* Generic Initialization */
	SystemCoreClockUpdate();
	Board_Init();

	/* Enable and setup SysTick Timer at a periodic rate */
	SysTick_Config(SystemCoreClock / TICKRATE_HZ);

	/* Statechart Initialization */
	#if (__USE_TIME_EVENTS == true)
	InitTimerTicks(ticks, NOF_TIMERS);
	#endif

	prefix_init(&statechart);
	prefix_enter(&statechart);

	/* LEDs toggle in main */
	while (1) {
		__WFI();

		if (SysTick_Time_Flag == true) {
			SysTick_Time_Flag = false;

			#if (__USE_TIME_EVENTS == true)
			UpdateTimers(ticks, NOF_TIMERS);
			for (i = 0; i < NOF_TIMERS; i++) {
				if (IsPendEvent(ticks, NOF_TIMERS, ticks[i].evid) == true) {

					prefix_raiseTimeEvent(&statechart, ticks[i].evid);	// Event -> Ticks.evid => OK
					MarkAsAttEvent(ticks, NOF_TIMERS, ticks[i].evid);
				}
			}
			#else
			prefixIface_raise_evTick(&statechart);					// Event -> evTick => OK
			#endif

			BUTTON_Status = Buttons_GetStatus();
			if (BUTTON_Status != 0)									// Event -> evTECXOprimodo => OK
				prefixIface_raise_evTECXOprimido(&statechart, BUTTON_Status);	// Value -> Tecla
			else													// Event -> evTECXNoOprimido => OK
				prefixIface_raise_evTECXNoOprimido(&statechart);

			prefix_runCycle(&statechart);							// Run Cycle of Statechart
		}
	}
}
#endif
