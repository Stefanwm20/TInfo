/******************************************************************************
 *
 * $RCSfile: $
 * $Revision: $
 *
 * This module provides interface routines to the LPC ARM UARTs.
 * Copyright 2004, R O SoftWare
 * No guarantees, warrantees, or promises, implied or otherwise.
 * May be used for hobby or commercial purposes provided copyright
 * notice remains intact.
 *
 *   History
 *
 *   19.6.2008   ver 1.1           Alfred Lohmann  HAW-Hamburg   
 *
 *   Version for NXP LPC-Stick (Hitex) and the TI-Board at HAW-Hamburg
 *   - Changed identifiert to be compatible wtih lpc24xx.h
 *   - Changed to use UART0 and UART2
 *   - UART0 and UART2 are fixed to 19200,8,N,1
 *   -_changed buffersize check from modulo to bitwise and
 *     buffersize has to be power of 2 (2,4,8,16,32,64....) !!!
 *   
 *
 *****************************************************************************/
#include <limits.h>
#include <inttypes.h>
#include "ConfigStick.h"
#include "lpc24xx.h"
#include "uart.h"
#include "lpcUART.h"
#include "armVIC.h"

#if defined(UART0_TX_INT_MODE) || defined(UART0_RX_INT_MODE) || \
    defined(UART2_TX_INT_MODE) || defined(UART2_RX_INT_MODE)

#include "uartISR.h"
#endif

#ifdef UART0_SUPPORT
#ifdef UART0_RX_INT_MODE
volatile uint8_t  uart0_rx_buffer[UART0_RX_BUFFER_SIZE];
volatile uint16_t uart0_rx_insert_idx, uart0_rx_extract_idx;
#endif

#ifdef UART0_TX_INT_MODE
volatile uint8_t  uart0_tx_buffer[UART0_TX_BUFFER_SIZE];
volatile uint16_t uart0_tx_insert_idx, uart0_tx_extract_idx;
volatile int      uart0_tx_running;
#endif
#endif

#ifdef UART2_SUPPORT
#ifdef UART2_RX_INT_MODE
volatile uint8_t  uart2_rx_buffer[UART2_RX_BUFFER_SIZE];
volatile uint16_t uart2_rx_insert_idx, uart2_rx_extract_idx;
#endif

#ifdef UART2_TX_INT_MODE
volatile uint8_t  uart2_tx_buffer[UART2_TX_BUFFER_SIZE];
volatile uint16_t uart2_tx_insert_idx, uart2_tx_extract_idx;
volatile int      uart2_tx_running;
#endif
#endif

#ifdef UART0_SUPPORT

/******************************************************************************
 *
 * Function Name: uart0Init()
 *
 * Description:  
 *    This function initializes the UART for async mode
 *
 * Calling Sequence: 
 *    baudrate divisor - use UART_BAUD macro
 *    mode - see typical modes (uart.h)
 *    fmode - see typical fmodes (uart.h)
 *
 * Returns:
 *    void
 *
 * NOTE: uart0Init(UART_BAUD(9600), UART_8N1, UART_FIFO_8);
 *
 *****************************************************************************/
void uart0Init(uint16_t baud, uint8_t mode, uint8_t fmode)
{
  // set port pins for UART0
  //PINSEL0 = (PINSEL0 & ~UART0__PINMASK) | UART0__PINSEL;
  PINSEL0 |= COM_FUNCT_PORT0_2;
  PINSEL0 |= COM_FUNCT_PORT0_3;
  UART0_IER = 0x00;                         // disable all interrupts
  UART0_IIR;                                // clear interrupt ID
  UART0_RBR;                                // clear receive register
  UART0_LSR;                                // clear line status register

  // set the baudrate
  UART0_LCR = ULCR_DLAB_ENABLE;             // select divisor latches 
  //UART0_DLL = (uint8_t)baud;                // set for baud low byte
  //UART0_DLM = (uint8_t)(baud >> 8);         // set for baud high byte
#if (UART0_BAUDRATE == 115200)
   UART0_DLL = (unsigned int)17;
   UART0_DLM = (unsigned int)0;
   UART0_FDR = (unsigned int)(8 | (15 << 4) );
#endif
#if (UART0_BAUDRATE == 19200)
   UART0_DLL = (unsigned int)125;
   UART0_DLM = (unsigned int)0;
   UART0_FDR = (unsigned int)(1 | (4 << 4) );
#endif   
  //-- disable access to divisor latch regs (enable access to xmit/rcv fifos
  //-- and int enable regs)
  UART0_LCR = USART_DIVISOR_LATCH_DISABLED;
  // set the number of characters and other
  // user specified operating parameters
  UART0_FCR = USART_FIFO_ENABLE | USART_RX_RESET | USART_TX_RESET | USART_RX_TRIGGER_1;
  UART0_LCR = USART_STOP_BIT_1 | USART_PARITY_None | USART_WORD_LENGTH8;

#if defined(UART0_TX_INT_MODE) || defined(UART0_RX_INT_MODE)
  // initialize the interrupt vector
  VICVectPriority6 = 3u;
  VICVectAddr6 = (unsigned int)uart0ISR;
  /* enable selected interrupts */
  VICIntEnable |= VIC_SOURCE_UART0;
  VICVectAddr6 = (uint32_t)uart0ISR;    // address of the ISR

#ifdef UART0_TX_INT_MODE
  // initialize the transmit data queue
  uart0_tx_extract_idx = uart0_tx_insert_idx = 0;
  uart0_tx_running = 0;
#endif

#ifdef UART0_RX_INT_MODE
  // initialize the receive data queue
  uart0_rx_extract_idx = uart0_rx_insert_idx = 0;

  // enable receiver interrupts
  UART0_IER = USART_IER_RX_DATA; 
#endif
#endif
}

/******************************************************************************
 *
 * Function Name: uart0Putch()
 *
 * Description:  
 *    This function puts a character into the UART output queue for
 *    transmission.
 *
 * Calling Sequence: 
 *    character to be transmitted
 *
 * Returns:
 *    ch on success, -1 on error (queue full)
 *
 *****************************************************************************/
int uart0Putch(int ch)
{
#ifdef UART0_TX_INT_MODE
  uint16_t temp;
  unsigned cpsr;

  temp = (uart0_tx_insert_idx + 1) & UART0_TX_BUFFER_MASK;

  if (temp == uart0_tx_extract_idx)
    return -1;                          // no room

  cpsr = disableIRQ();                  // disable global interrupts
  UART0_IER &= ~UIER_ETBEI;                 // disable TX interrupts
  restoreIRQ(cpsr);                     // restore global interrupts

  // check if in process of sending data
  if (uart0_tx_running)
    {
    // add to queue
    uart0_tx_buffer[uart0_tx_insert_idx] = (uint8_t)ch;
    uart0_tx_insert_idx = temp;
    }
  else
    {
    // set running flag and write to output register
    uart0_tx_running = 1;
    UART0_THR = (uint8_t)ch;
    }

  cpsr = disableIRQ();                  // disable global interrupts
  UART0_IER |= UIER_ETBEI;                  // enable TX interrupts
  restoreIRQ(cpsr);                     // restore global interrupts
#else
  while (!(U0LSR & ULSR_THRE))          // wait for TX buffer to empty
    continue;                           // also either WDOG() or swap()

  UART0_THR = (uint8_t)ch;
#endif
  return (uint8_t)ch;
}

/******************************************************************************
 *
 * Function Name: uart0Space()
 *
 * Description:  
 *    This function gets the available space in the transmit queue
 *
 * Calling Sequence: 
 *    void
 *
 * Returns:
 *    available space in the transmit queue
 *
 *****************************************************************************/
uint16_t uart0Space(void)
{
#ifdef UART0_TX_INT_MODE
  int space;

  if ((space = (uart0_tx_extract_idx - uart0_tx_insert_idx)) <= 0)
    space += UART0_TX_BUFFER_SIZE;

  return (uint16_t)(space - 1);
#else
  return USHRT_MAX;
#endif
}

/******************************************************************************
 *
 * Function Name: uart0Puts()
 *
 * Description:  
 *    This function writes a NULL terminated 'string' to the UART output
 *    queue, returning a pointer to the next character to be written.
 *
 * Calling Sequence: 
 *    address of the string
 *
 * Returns:
 *    a pointer to the next character to be written
 *    (\0 if full string is written)
 *
 *****************************************************************************/
const char *uart0Puts(const char *string)
{
  register char ch;

  while ((ch = *string) && (uart0Putch(ch) >= 0))
    string++;

  return string;
}

/******************************************************************************
 *
 * Function Name: uart0Write()
 *
 * Description:  
 *    This function writes 'count' characters from 'buffer' to the UART
 *    output queue.
 *
 * Calling Sequence: 
 *    
 *
 * Returns:
 *    0 on success, -1 if insufficient room, -2 on error
 *    NOTE: if insufficient room, no characters are written.
 *
 *****************************************************************************/
int uart0Write(const char *buffer, uint16_t count)
{
#ifdef UART0_TX_INT_MODE
  if (count > uart0Space())
    return -1;
#endif
  while (count && (uart0Putch(*buffer++) >= 0))
    count--;

  return (count ? -2 : 0);
}

/******************************************************************************
 *
 * Function Name: uart0TxEmpty()
 *
 * Description:
 *    This function returns the status of the UART transmit data
 *    registers.
 *
 * Calling Sequence: 
 *    void
 *
 * Returns:
 *    FALSE - either the tx holding or shift register is not empty
 *   !FALSE - if both the tx holding & shift registers are empty
 *
 *****************************************************************************/
int uart0TxEmpty(void)
{
  return (UART0_LSR & (ULSR_THRE | ULSR_TEMT)) == (ULSR_THRE | ULSR_TEMT);
}

/******************************************************************************
 *
 * Function Name: uart0TxFlush()
 *
 * Description:  
 *    This function removes all characters from the UART transmit queue
 *    (without transmitting them).
 *
 * Calling Sequence: 
 *    void
 *
 * Returns:
 *    void
 *
 *****************************************************************************/
void uart0TxFlush(void)
{
#ifdef UART0_TX_INT_MODE
  unsigned cpsr;

  UART0_FCR |= UFCR_TX_FIFO_RESET;          // clear the TX fifo

  // "Empty" the transmit buffer.
  cpsr = disableIRQ();                  // disable global interrupts
  UART0_IER &= ~UIER_ETBEI;                 // disable TX interrupts
  restoreIRQ(cpsr);                     // restore global interrupts
  uart0_tx_insert_idx = uart0_tx_extract_idx = 0;
#else
  UART0_FCR |= UFCR_TX_FIFO_RESET;          // clear the TX fifo
#endif
}

/******************************************************************************
 *
 * Function Name: uart0Getch()
 *
 * Description:  
 *    This function gets a character from the UART receive queue
 *
 * Calling Sequence: 
 *    void
 *
 * Returns:
 *    character on success, -1 if no character is available
 *
 *****************************************************************************/
int uart0Getch(void)
{
#ifdef UART0_RX_INT_MODE
  uint8_t ch;

  if (uart0_rx_insert_idx == uart0_rx_extract_idx) // check if character is available
    return -1;

  ch = uart0_rx_buffer[uart0_rx_extract_idx++]; // get character, bump pointer
  uart0_rx_extract_idx &= UART0_RX_BUFFER_MASK; // limit the pointer
  return ch;
#else
  if (UART0_LSR & ULSR_RDR)                 // check if character is available
    return UART0_RBR;                       // return character

  return -1;
#endif
}

#endif


#ifdef UART2_SUPPORT

/******************************************************************************
 *
 * Function Name: uart2Init()
 *
 * Description:  
 *    This function initializes the UART for async mode
 *
 * Calling Sequence: 
 *    baudrate divisor - use UART_BAUD macro
 *    mode - see typical modes (uart.h)
 *    fmode - see typical fmodes (uart.h)
 *
 * Returns:
 *    void
 *
 * NOTE: uart2Init(UART_BAUD(9600), UART_8N1, UART_FIFO_8);
 *
 *****************************************************************************/
void uart2Init(uint16_t baud, uint8_t mode, uint8_t fmode)
{
  // set port pins for UART2
  //PINSEL0 = (PINSEL0 & ~UART2__PINMASK) | UART2__PINSEL;
  PINSEL0 |= COM_FUNCT_PORT0_10;
  PINSEL0 |= COM_FUNCT_PORT0_11;
  
  UART2_IER = 0x00;                         // disable all interrupts
  UART2_IIR;                                // clear interrupt ID
  UART2_RBR;                                // clear receive register
  UART2_LSR;                                // clear line status register

  // set the baudrate
  UART2_LCR = ULCR_DLAB_ENABLE;             // select divisor latches 
  //UART2_DLL = (uint8_t)baud;                // set for baud low byte
  //UART2_DLM = (uint8_t)(baud >> 8);         // set for baud high byte
#if (UART2_BAUDRATE == 115200)
   UART2_DLL = (unsigned int)17;
   UART2_DLM = (unsigned int)0;
   UART2_FDR = (unsigned int)(8 | (15 << 4) );
#endif
#if (UART2_BAUDRATE == 19200)
   UART2_DLL = (unsigned int)125;
   UART2_DLM = (unsigned int)0;
   UART2_FDR = (unsigned int)(1 | (4 << 4) );
#endif   
  // set the number of characters and other
  // user specified operating parameters
  //UART2_LCR = (mode & ~ULCR_DLAB_ENABLE);
  //UART2_FCR = fmode;
  //-- disable access to divisor latch regs (enable access to xmit/rcv fifos
  //-- and int enable regs)
  UART2_LCR = USART_DIVISOR_LATCH_DISABLED;
  // set the number of characters and other
  // user specified operating parameters
  UART2_FCR = USART_FIFO_ENABLE | USART_RX_RESET | USART_TX_RESET | USART_RX_TRIGGER_1;
  UART2_LCR = USART_STOP_BIT_1 | USART_PARITY_None | USART_WORD_LENGTH8;

#if defined(UART2_TX_INT_MODE) || defined(UART2_RX_INT_MODE)
  // initialize the interrupt vector
   VICVectPriority28 = 3u;
   VICVectAddr28 = (uint32_t)uart2ISR;
   /* enable selected interrupts */
   VICIntEnable |= VIC_SOURCE_UART2;
#ifdef UART2_TX_INT_MODE
  uart2_tx_extract_idx = uart2_tx_insert_idx = 0;
  uart2_tx_running = 0;
#endif

#ifdef UART2_RX_INT_MODE
  // initialize data queues
  uart2_rx_extract_idx = uart2_rx_insert_idx = 0;

  // enable receiver interrupts
  UART2_IER = UIER_ERBFI;
#endif
#endif
}

/******************************************************************************
 *
 * Function Name: uart2Putch()
 *
 * Description:  
 *    This function puts a character into the UART output queue for
 *    transmission.
 *
 * Calling Sequence: 
 *    ch - character to be transmitted
 *
 * Returns:
 *    ch on success, -1 on error (queue full)
 *
 *****************************************************************************/
int uart2Putch(int ch)
{
#ifdef UART2_TX_INT_MODE
  uint16_t temp;
  unsigned cpsr;

  temp = (uart2_tx_insert_idx + 1) & UART2_TX_BUFFER_MASK;

  if (temp == uart2_tx_extract_idx)
    return -1;                          // no room

  cpsr = disableIRQ();                  // disable global interrupts
  UART2_IER &= ~UIER_ETBEI;                 // disable TX interrupts
  restoreIRQ(cpsr);                     // restore global interrupts

  // check if in process of sending data
  if (uart2_tx_running)
    {
    // add to queue
    uart2_tx_buffer[uart2_tx_insert_idx] = (uint8_t)ch;
    uart2_tx_insert_idx = temp;
    }
  else
    {
    // set running flag and write to output register
    uart2_tx_running = 1;
    UART2_THR = (uint8_t)ch;
    }

  cpsr = disableIRQ();                  // disable global interrupts
  UART2_IER |= UIER_ETBEI;              // enable TX interrupts
  restoreIRQ(cpsr);                     // restore global interrupts
#else
  while (!(UART2_LSR & ULSR_THRE))      // wait for TX buffer to empty
    continue;                           // also either WDOG() or swap()

  UART2_THR = (uint8_t)ch;
#endif
  return (uint8_t)ch;
}

/******************************************************************************
 *
 * Function Name: uart2Space()
 *
 * Description:  
 *    This function gets the available space in the transmit queue
 *
 * Calling Sequence: 
 *    void
 *
 * Returns:
 *    available space in the transmit queue
 *
 *****************************************************************************/
uint16_t uart2Space(void)
{
#ifdef UART2_TX_INT_MODE
  int space;

  if ((space = (uart2_tx_extract_idx - uart2_tx_insert_idx)) <= 0)
    space += UART2_TX_BUFFER_SIZE;

  return (uint16_t)(space - 1);
#else
  return USHRT_MAX;
#endif
}

/******************************************************************************
 *
 * Function Name: uart2Puts()
 *
 * Description:  
 *    This function writes a NULL terminated 'string' to the UART output
 *    queue, returning a pointer to the next character to be written.
 *
 * Calling Sequence: 
 *    address of the string
 *
 * Returns:
 *    a pointer to the next character to be written
 *    (\0 if full string is written)
 *
 *****************************************************************************/
const char *uart2Puts(const char *string)
{
  register char ch;

  while ((ch = *string) && (uart2Putch(ch) >= 0))
    string++;

  return string;
}

/******************************************************************************
 *
 * Function Name: uart2Write()
 *
 * Description:  
 *    This function writes 'count' characters from 'buffer' to the UART
 *    output queue.
 *
 * Calling Sequence: 
 *    
 *
 * Returns:
 *    0 on success, -1 if insufficient room, -2 on error
 *    NOTE: if insufficient room, no characters are written.
 *
 *****************************************************************************/
int uart2Write(const char *buffer, uint16_t count)
{
#ifdef UART2_TX_INT_MODE
  if (count > uart2Space())
    return -1;
#endif
  while (count && (uart2Putch(*buffer++) >= 0))
    count--;

  return (count ? -2 : 0);
}

/******************************************************************************
 *
 * Function Name: uart2TxEmpty()
 *
 * Description:
 *    This function returns the status of the UART transmit data
 *    registers.
 *
 * Calling Sequence: 
 *    void
 *
 * Returns:
 *    FALSE - either the tx holding or shift register is not empty
 *   !FALSE - if both the tx holding & shift registers are empty
 *
 *****************************************************************************/
int uart2TxEmpty(void)
{
  return (UART2_LSR & (ULSR_THRE | ULSR_TEMT)) == (ULSR_THRE | ULSR_TEMT);
}

/******************************************************************************
 *
 * Function Name: uart2TxFlush()
 *
 * Description:  
 *    This function removes all characters from the UART transmit queue
 *    (without transmitting them).
 *
 * Calling Sequence: 
 *    void
 *
 * Returns:
 *    void
 *
 *****************************************************************************/
void uart2TxFlush(void)
{
#ifdef UART2_TX_INT_MODE
  unsigned cpsr;

  UART2_FCR |= UFCR_TX_FIFO_RESET;          // clear the TX fifo

  // "Empty" the transmit buffer.
  cpsr = disableIRQ();                  // disable global interrupts
  UART2_IER &= ~UIER_ETBEI;                 // disable TX interrupts
  restoreIRQ(cpsr);                     // restore global interrupts
  uart2_tx_insert_idx = uart2_tx_extract_idx = 0;
#else
  UART2_FCR |= UFCR_TX_FIFO_RESET;          // clear the TX fifo
#endif
}

/******************************************************************************
 *
 * Function Name: uart2Getch()
 *
 * Description:  
 *    This function gets a character from the UART receive queue
 *
 * Calling Sequence: 
 *    void
 *
 * Returns:
 *    character on success, -1 if no character is available
 *
 *****************************************************************************/
int uart2Getch(void)
{
#ifdef UART2_RX_INT_MODE
  uint8_t ch;

  if (uart2_rx_insert_idx == uart2_rx_extract_idx) // check if character is available
    return -1;

  ch = uart2_rx_buffer[uart2_rx_extract_idx++]; // get character, bump pointer
  uart2_rx_extract_idx &= UART2_RX_BUFFER_MASK; // limit the pointer
  return ch;
#else
  if (UART2_LSR & ULSR_RDR)                 // check if character is available
    return UART2_RBR;                       // return character

  return -1;
#endif
}

#endif
