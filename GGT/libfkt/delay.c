#include "lpc24xx.h"
#include "delay.h"
#include "target_info.h"

//-- the standard correction value is valid when
//-- CPU clock 48 MHz
//-- peripheral clock 12 MHz
//-- MAM partly enabled
//-- MAM 3 wait states
//--
#define STD_CORRECTION_VALUE 60

static unsigned int __Fpclk = 0;                 /* CPU Clock in Hz */
static uint32_t __delay_correction = 60;
/*****************************************************************************
** Function name:		delay
**
** Descriptions:		Start the timer delay in 10th of mili seconds
**						Timer 2 is used
**
** parameters:			Delay value in 10th of mili second			 
** 						
** Returned value:      None
** 
*****************************************************************************/
void delay(uint32_t delayIn10ofMs)
{
    
	/*
	* setup timer #2 for measurement
	*/
	TIMER2_TCR = 0x02;		/* reset timer */
	TIMER2_PR  = 0x00;		/* set prescaler to zero */
	TIMER2_MR0 = (delayIn10ofMs * (__Fpclk / 10000-1)) - __delay_correction;
	TIMER2_IR  = 0xff;		/* reset all interrrupts */
	TIMER2_MCR = 0x04;		/* stop timer on match */
	TIMER2_TCR = 0x01;		/* start timer */
	
	/* wait until delay time has elapsed */
	while (TIMER2_TCR & 0x01);
    
    return;
}


/*****************************************************************************
** Function name:		init_delay
**
** Descriptions:		Gets peripheral clock and sets correction factor
**						
**
** parameters:			Delay value in mili second			 
** 						
** Returned value:      actual correction value
** 
*****************************************************************************/
uint32_t init_delay(uint32_t correct_val)
{
    
    __Fpclk = GetPclk();    
    

    if (correct_val != 0){
        __delay_correction = correct_val;
    }
    else{
        __delay_correction = STD_CORRECTION_VALUE;
    }
    
    
    return (__delay_correction);
}

