#include "lpc24xx.h"
#include "target_info.h"

#define PLL_M (PLLCFG & 0x00007FFF)
#define PLL_N ((PLLCFG & 0x00FF0000) >> 16)
#define CCLKCFG_VAL (CCLKCFG & 0x000000FF)

/******************************************************************************
** Function name:		GetCclk(void)
**
** Descriptions:		Returns the actual PLL Clock 
**
** parameters:			None
** Returned value:		Cclk in Hz Frequency
**
******************************************************************************/
unsigned int GetCclk(void)
{
    unsigned int help=OSCILLATOR_CLOCK_FREQUENCY;

    //return real processor clock speed
    
    if ((PLLCON & 1) != 0){
        help = OSCILLATOR_CLOCK_FREQUENCY / (PLL_N+1);
        help = help * (PLL_M+1) * 2;
        help = help / (CCLKCFG_VAL+1);
    }
    
   
    return help;
}


/******************************************************************************
** Function name:		GetPclk(void)
**
** Descriptions:		Returns the actual Peripheral Clock 
**
** parameters:			None
** Returned value:		pclk in Hz Frequency
**
******************************************************************************/
unsigned int GetPclk(void)
{
    //VPBDIV - determines the relationship between the processor clock (cclk)
    //and the clock used by peripheral devices (pclk).
    unsigned int divider = 1;
    switch (VPBDIV & 3)
    {
        case 0: divider = 4;  break;
        case 1: divider = 1;  break;
        case 2: divider = 2;  break;
    }

    return GetCclk() / divider;
}

