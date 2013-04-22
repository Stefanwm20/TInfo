#ifndef delay_h
#define delay_h
/*****************************************************************************
 *   delay.h:  Timing function for NXP LPC23xx/34xx Family 
 *   Microprocessors
 *
 *   Copyright(C) 2006, NXP Semiconductor
 *   All rights reserved.
 *
 *   History
 *
 *   19.06.2008  ver 1.00    Version for NXP LPC-Stick (Hitex)
 *                           Timer 2 is fixed selected 
 *                           Alfred Lohmann  HAW-Hamburg   
 *
 *  30.07.2008   ver 1.10    Implementation of correction value to obtain
 *                           correct timing
 *                           Alfred Lohmann  HAW-Hamburg 
 *
*****************************************************************************/
#include <inttypes.h>

//-- old function name for compatability 
#define delayMs(x)      delay((x))

//-- converts x msec to 10th of msec for delayMS()
#define MSec(x)  ((x)*10)
//-- converts x usec to 10th of msec for delayMS()
#define USec(x)   ((x)/100)   

/*****************************************************************************
** Function name:		delay
**
** Descriptions:		Start the timer delay in 10th of mili seconds
**						      until elapsed Timer 2 is used
**
** parameters:			Delay value in 10th of mili second			 
** 						
** Returned value:  None
** 
*****************************************************************************/
void delay(uint32_t delayIn10ofMs);

/*****************************************************************************
** Function name:		init_delay
**
** Descriptions:		Gets peripheral clock and correction factor
**						
**
** parameters:			Value to correct the timing to exact value			 
** 						
** Returned value:              actual correction value
** 
*****************************************************************************/
uint32_t init_delay(uint32_t correct_val);

#endif
