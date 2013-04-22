/******************************************************************************
 *
 * $RCSfile: $
 * $Revision: $
 *
 * This module provides the interface definitions for uartISR.c
 * Copyright 2004, R O SoftWare
 * No guarantees, warrantees, or promises, implied or otherwise.
 * May be used for hobby or commercial purposes provided copyright
 * notice remains intact.
 *
 *   History
 *
 *   2008.06.19  ver 1.00    Alfred Lohmann  HAW-Hamburg  
 *   Version for NXP LPC-Stick (Hitex)and TI-expansion board.
 *   Changed identifiers to HITEX lpc24xx.h definitions
 *   !!! Using ISR_ENTRY() and ISR_EXIT() no local variable
 *   !!! in ISR are allowed. Use static variable.
 *                             
 *
 *****************************************************************************/
#ifndef INC_UART_ISR_H
#define INC_UART_ISR_H

#include "uart.h"

#ifndef __IRQ__
#define __IRQ__  __attribute__ ((interrupt ("IRQ")))
#endif

#ifdef UART0_SUPPORT
#if defined(UART0_TX_INT_MODE) || defined(UART0_RX_INT_MODE)
void __IRQ__ uart0ISR(void);
#endif // UART0_TX_INT_MODE || UART0_RX_INT_MODE
#endif // UART0_SUPPORT


#ifdef UART2_SUPPORT
#if defined(UART2_TX_INT_MODE) || defined(UART2_RX_INT_MODE)
void __IRQ__ uart2ISR(void);
#endif // UART2_TX_INT_MODE || UART2_RX_INT_MODE
#endif // UART2_SUPPORT

#endif
