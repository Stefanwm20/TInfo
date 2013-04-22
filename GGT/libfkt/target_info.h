/*****************************************************************************
 *   target.h:  Header file for NXP LPC23xx/24xx Family Microprocessors
 *
 *   Copyright(C) 2006, NXP Semiconductor
 *   All rights reserved.
 *
 *   History
 *   2006.09.20  ver 1.00    Prelimnary version, first Release
 *
 *   2008.03.19  ver 1.00    Version for NXP LPC-Stick (Hitex)
 *                           Alfred Lohmann  HAW-Hamburg   
 *
******************************************************************************/
#ifndef __TARGET_H 
#define __TARGET_H

#ifdef __cplusplus
   extern "C" {
#endif


/* PLL input Crystal frequence range 4KHz~20MHz. */
#define Fosc	4000000                           //in Hz
#define OSCILLATOR_CLOCK_FREQUENCY 4000000      //in Hz

unsigned int GetCclk(void);
unsigned int GetPclk(void);

#ifdef __cplusplus
   }
#endif
 
#endif /* end __TARGET_H */
/******************************************************************************
**                            End Of File
******************************************************************************/
