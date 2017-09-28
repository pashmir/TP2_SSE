/*
 * @brief FreeRTOS Blinky example
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
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

#include "src-gen/Prefix.h"
#include "TimerTicks.h"


/*****************************************************************************
 * Private types/enumerations/variables
 ****************************************************************************/
#define EXAMPLE_1 (1)		/* Test Statechart EDU-CIAA-NXP - Blink LED3 */
#define EXAMPLE_2 (2)		/* Test Statechart EDU-CIAA-NXP - Blink LED3 & Semaphore */
#define EXAMPLE_3 (3)		/* Test Statechart EDU-CIAA-NXP - Button */
#define EXAMPLE_4 (4)		/* */
#define EXAMPLE_5 (5)		/* */
#define EXAMPLE_6 (6)		/* */
#define EXAMPLE_7 (7)		/* */
#define EXAMPLE_8 (8)		/* */
#define EXAMPLE_9 (9)		/* */

#define TEST (EXAMPLE_2)


#if (TEST == EXAMPLE_1)
/*****************************************************************************
 * Public types/enumerations/variables
 ****************************************************************************/
volatile bool SysTick_Time_Flag = false;

/*! This is a state machine */
static Prefix statechart;

#define __USE_TIME_EVENTS (true)	/* "true" with TimerEvents or "false" without TimeEvents */

/*! This is a timed state machine that requires timer services */
#if (__USE_TIME_EVENTS == true)
	#define NOF_TIMERS (sizeof(PrefixTimeEvents)/sizeof(sc_boolean))
#else
	#define NOF_TIMERS 0
#endif

TimerTicks ticks[NOF_TIMERS];


const char *pcTextForMain = "\r\nExample 1 - Blink LED3\r\n";


/*****************************************************************************
 * Private functions
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


/* Sets up system hardware */
static void prvSetupHardware(void)
{
	SystemCoreClockUpdate();
	Board_Init();
}


void vApplicationTickHook()
{
	SysTick_Time_Flag = true;
}


/* LED3 toggle thread */
static void vLED3Task(void *pvParameters) {
	const char *pcTaskName = "LED3Task is running\r\n";

	#if (__USE_TIME_EVENTS == true)
	uint32_t i;
	#endif

	/* Statechart Initialization */
	#if (__USE_TIME_EVENTS == true)
	InitTimerTicks(ticks, NOF_TIMERS);
	#endif

	prefix_init(&statechart);
	prefix_enter(&statechart);

	/* Print out the name of this task. */
	DEBUGOUT(pcTaskName);
	while (1) {

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


/* UART (or output) thread */
static void vUARTTask(void *pvParameters) {
	int tickCnt = 0;

	while (1) {
		DEBUGOUT("Tick: %d \r\n", tickCnt);
		tickCnt++;

		/* About a 1s delay here */
		vTaskDelay(configTICK_RATE_HZ);
	}
}


/*****************************************************************************
 * Public functions
 ****************************************************************************/

/**
 * @brief	main routine for FreeRTOS blinky example
 * @return	Nothing, function should not exit
 */
int main(void)
{
	/* Sets up system hardware */
	prvSetupHardware();

	/* Print out the name of this example. */
	DEBUGOUT(pcTextForMain);

	/* Blink LED3 thread */
	xTaskCreate((TaskFunction_t) vLED3Task,					/* Pointer to the function thats implement the task. */
				(const char * const) "LED3Task",			/* Text name for the task. This is to facilitate debugging only. */
				(uint16_t) configMINIMAL_STACK_SIZE,		/* Stack depth in words. */
				(void *) NULL,								/* We are not using the task parameter. */
				(UBaseType_t) (tskIDLE_PRIORITY + 1UL),		/* This task will run at priority 1. */
				(TaskHandle_t *) NULL);						/* We are not going to use the task handle. */

	/* UART output thread, simply counts seconds */
	xTaskCreate((TaskFunction_t) vUARTTask, (const char * const) "vTaskUart", (uint16_t) configMINIMAL_STACK_SIZE,
				(void *) NULL, (UBaseType_t) (tskIDLE_PRIORITY + 1UL), (TaskHandle_t *) NULL);

	/* Start the scheduler so our tasks start executing. */
	vTaskStartScheduler();

	/* If all is well we will never reach here as the scheduler will now be
	 * running.  If we do reach here then it is likely that there was insufficient
	 * heap available for the idle task to be created. */
	while (1);

	/* Should never arrive here */
	return ((int) NULL);
}
#endif


#if (TEST == EXAMPLE_2)
/*****************************************************************************
 * Public types/enumerations/variables
 ****************************************************************************/
volatile bool SysTick_Time_Flag = false;

/*! This is a state machine */
static Prefix statechart;

#define __USE_TIME_EVENTS (true)	/* "true" with TimerEvents or "false" without TimeEvents */

/*! This is a timed state machine that requires timer services */
#if (__USE_TIME_EVENTS == true)
	#define NOF_TIMERS (sizeof(PrefixTimeEvents)/sizeof(sc_boolean))
#else
	#define NOF_TIMERS 0
#endif

TimerTicks ticks[NOF_TIMERS];


const char *pcTextForMain = "\r\nExample 2 - Blink LED3 & Semaphore\r\n";

/* Declare a variable of type xSemaphoreHandle.  This is used to reference the
 * semaphore that is used to synchronize a task with an interrupt. */
xSemaphoreHandle xBinarySemaphore;


/*****************************************************************************
 * Private functions
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


/* Sets up system hardware */
static void prvSetupHardware(void)
{
	SystemCoreClockUpdate();
	Board_Init();
}


void vApplicationTickHook()
{
	portBASE_TYPE xHigherPriorityTaskWoken = pdFALSE;

    xSemaphoreGiveFromISR(xBinarySemaphore, &xHigherPriorityTaskWoken);
}


/* LED3 toggle thread */
static void vLED3Task(void *pvParameters) {
	const char *pcTaskName = "LED3Task is running\r\n";

	#if (__USE_TIME_EVENTS == true)
	uint32_t i;
	#endif

    /* Before a semaphore is used it must be explicitly created.  In this example
     * a binary semaphore is created. */
    vSemaphoreCreateBinary(xBinarySemaphore);

    /* Check the semaphore was created successfully. */
    if (xBinarySemaphore != (xSemaphoreHandle) NULL) {

    	/* As per most tasks, this task is implemented within an infinite loop.
    	 *
    	 * Take the semaphore once to start with so the semaphore is empty before the
    	 * infinite loop is entered.  The semaphore was created before the scheduler
    	 * was started so before this task ran for the first time.*/
    	xSemaphoreTake(xBinarySemaphore, (portTickType) 0);

    	/* Statechart Initialization */
		#if (__USE_TIME_EVENTS == true)
    	InitTimerTicks(ticks, NOF_TIMERS);
		#endif

    	prefix_init(&statechart);
    	prefix_enter(&statechart);

    	/* Print out the name of this task. */
    	DEBUGOUT(pcTaskName);
    	while (1) {

    		/* Use the semaphore to wait for the event.  The task blocks
    		 * indefinitely meaning this function call will only return once the
    		 * semaphore has been successfully obtained - so there is no need to check
    		 * the returned value. */
    		xSemaphoreTake(xBinarySemaphore, portMAX_DELAY);

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


/* UART (or output) thread */
static void vUARTTask(void *pvParameters) {
	int tickCnt = 0;

	while (1) {
		DEBUGOUT("Tick: %d \r\n", tickCnt);
		tickCnt++;

		/* About a 1s delay here */
		vTaskDelay(configTICK_RATE_HZ);
	}
}


/*****************************************************************************
 * Public functions
 ****************************************************************************/

/**
 * @brief	main routine for FreeRTOS blinky example
 * @return	Nothing, function should not exit
 */
int main(void)
{
	/* Sets up system hardware */
	prvSetupHardware();

	/* Print out the name of this example. */
	DEBUGOUT(pcTextForMain);

   	/* Blink LED3 thread */
   	xTaskCreate((TaskFunction_t) vLED3Task,					/* Pointer to the function thats implement the task. */
   				(const char * const) "LED3Task",			/* Text name for the task. This is to facilitate debugging only. */
				(uint16_t) configMINIMAL_STACK_SIZE,		/* Stack depth in words. */
				(void *) NULL,								/* We are not using the task parameter. */
				(UBaseType_t) (tskIDLE_PRIORITY + 3UL),		/* This task will run at priority 3. */
				(TaskHandle_t *) NULL);						/* We are not going to use the task handle. */

   	/* UART output thread, simply counts seconds */
 	xTaskCreate((TaskFunction_t) vUARTTask, (const char * const) "vTaskUart", (uint16_t) configMINIMAL_STACK_SIZE,
   				(void *) NULL, (UBaseType_t) (tskIDLE_PRIORITY + 1UL), (TaskHandle_t *) NULL);

    /* Start the scheduler so our tasks start executing. */
    vTaskStartScheduler();

	/* If all is well we will never reach here as the scheduler will now be
	 * running.  If we do reach here then it is likely that there was insufficient
	 * heap available for the idle task to be created. */
	while (1);

	/* Should never arrive here */
	return ((int) NULL);
}
#endif

