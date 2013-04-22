/******************************************************************************
 *
 * $RCSfile: $
 * $Revision: $
 *
 * This module implements the ISRs for the UARTs on the LPC ARMs.
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
#include "lpc24xx.h"
#include "uart.h"
#include "lpcUART.h"
#include "uartISR.h"
#include "armVIC.H"


#ifdef UART0_SUPPORT
void __IRQ__ uart0ISR(void);

#ifdef UART0_RX_INT_MODE
extern volatile uint8_t  uart0_rx_buffer[UART0_RX_BUFFER_SIZE];
extern volatile uint16_t uart0_rx_insert_idx, uart0_rx_extract_idx;
#endif // UART0_RX_INT_MODE

#ifdef UART0_TX_INT_MODE
extern volatile uint8_t  uart0_tx_buffer[UART0_TX_BUFFER_SIZE];
extern volatile uint16_t uart0_tx_insert_idx, uart0_tx_extract_idx;
extern volatile int      uart0_tx_running;
#endif // UART0_TX_INT_MODE

#if defined(UART0_TX_INT_MODE) || defined(UART0_RX_INT_MODE)
/******************************************************************************
 *
 * Function Name: uart0ISR()
 *
 * Description:
 *    This function implements the ISR for UART0.
 *
 * Calling Sequence: 
 *    void
 *
 * Returns:
 *    void
 *
 *****************************************************************************/
void __IRQ__ uart0ISR(void)
{
  static uint8_t iid;
  static uint16_t temp;
  
  // perform proper ISR entry so thumb-interwork works properly
  //-- NO local variables allowed with ISR_ENTRY()
  //-- crashes system
  //ISR_ENTRY();

  // loop until not more interrupt sources
  while (((iid = UART0_IIR) & UIIR_NO_INT) == 0)
    {
    // identify & process the highest priority interrupt
    switch (iid & UIIR_ID_MASK)
      {
      case UIIR_RLS_INT:                // Receive Line Status
        UART0_LSR;                          // read LSR to clear
        break;

#ifdef UART0_RX_INT_MODE
      case UIIR_CTI_INT:                // Character Timeout Indicator
      case UIIR_RDA_INT:                // Receive Data Available
        do
          {
          // calc next insert index & store character
          temp = (uart0_rx_insert_idx + 1) & UART0_RX_BUFFER_MASK;
          uart0_rx_buffer[uart0_rx_insert_idx] = UART0_RBR;

          // check for more room in queue
          if (temp != uart0_rx_extract_idx)
            uart0_rx_insert_idx = temp; // update insert index
          }
        while (UART0_LSR & ULSR_RDR);

        break;
#endif

#ifdef UART0_TX_INT_MODE
      case UIIR_THRE_INT:               // Transmit Holding Register Empty
        while (UART0_LSR & ULSR_THRE)
          {
          // check if more data to send
          if (uart0_tx_insert_idx != uart0_tx_extract_idx)
            {
            UART0_THR = uart0_tx_buffer[uart0_tx_extract_idx++];
            uart0_tx_extract_idx &= UART0_TX_BUFFER_MASK;
            }
          else
            {
            // no
            uart0_tx_running = 0;       // clear running flag
            //-- Enable UART0 rx and disable tx interrupts
            UART0_IER = USART_IER_RX_DATA; 
            break;
            }
          }

        break;
#endif // UART0_TX_INT_MODE


      default:                          // Unknown
        UART0_LSR;
        UART0_RBR;
        break;
      }
    }

  VICVectAddr = 0x00000000;             // clear this interrupt from the VIC
  //ISR_EXIT();                           // recover registers and return
}
#endif // defined(UART0_TX_INT_MODE) || defined(UART0_RX_INT_MODE)
#endif // UART0_SUPPORT


#ifdef UART2_SUPPORT
void __IRQ__ uart2ISR(void);

#ifdef UART2_RX_INT_MODE
extern volatile uint8_t  uart2_rx_buffer[UART2_RX_BUFFER_SIZE];
extern volatile uint16_t uart2_rx_insert_idx, uart2_rx_extract_idx;
#endif // UART2_RX_INT_MODE

#ifdef UART2_TX_INT_MODE
extern volatile uint8_t  uart2_tx_buffer[UART2_TX_BUFFER_SIZE];
extern volatile uint16_t uart2_tx_insert_idx, uart2_tx_extract_idx;
extern volatile int      uart2_tx_running;
#endif // UART2_TX_INT_MODE

#if defined(UART2_TX_INT_MODE) || defined(UART2_RX_INT_MODE)
/******************************************************************************
 *
 * Function Name: uart2ISR()
 *
 * Description:
 *    This function implements the ISR for UART2.
 *
 * Calling Sequence: 
 *    void
 *
 * Returns:
 *    void
 *
 *****************************************************************************/
void __IRQ__ uart2ISR(void)
{
  static uint8_t iid;
  static uint16_t temp; 
	
  // perform proper ISR entry so thumb-interwork works properly
  //-- NO local variables allowed with ISR_ENTRY()
  //-- crashes system
  //ISR_ENTRY();

  // loop until not more interrupt sources
  while (((iid = UART2_IIR) & UIIR_NO_INT) == 0)
    {
    // identify & process the highest priority interrupt
    switch (iid & UIIR_ID_MASK)
      {
      case UIIR_RLS_INT:                // Receive Line Status
        UART2_LSR;                          // read LSR to clear
        break;

#ifdef UART2_RX_INT_MODE
      case UIIR_CTI_INT:                // Character Timeout Indicator
      case UIIR_RDA_INT:                // Receive Data Available
        do
          {
          // calc next insert index & store character
          temp = (uart2_rx_insert_idx + 1) & UART2_RX_BUFFER_MASK;
          uart2_rx_buffer[uart2_rx_insert_idx] = UART2_RBR;

          // check for more room in queue
          if (temp != uart2_rx_extract_idx)
            uart2_rx_insert_idx = temp; // update insert index
          }
        while (UART2_LSR & ULSR_RDR);

        break;
#endif

#ifdef UART2_TX_INT_MODE
      case UIIR_THRE_INT:               // Transmit Holding Register Empty
        while (UART2_LSR & ULSR_THRE)
          {
          // check if more data to send
          if (uart2_tx_insert_idx != uart2_tx_extract_idx)
            {
            UART2_THR = uart2_tx_buffer[uart2_tx_extract_idx++];
            uart2_tx_extract_idx &= UART2_TX_BUFFER_MASK;
            }
          else
            {
            // no
            uart2_tx_running = 0;       // clear running flag
            UART2_IER = UIER_ERBFI;
            break;
            }
          }

        break;
#endif // UART2_TX_INT_MODE

      case UIIR_MS_INT:                 // MODEM Status
        UART2_MSR;                          // read MSR to clear
        break;

      default:                          // Unknown
        UART2_LSR;
        UART2_RBR;
        UART2_MSR;
        break;
      }
    }

  VICVectAddr = 0x00000000;             // clear this interrupt from the VIC
  //ISR_EXIT();                           // recover registers and return
}
#endif // defined(UART2_TX_INT_MODE) || defined(UART2_RX_INT_MODE)
#endif // UART2_SUPPORT
