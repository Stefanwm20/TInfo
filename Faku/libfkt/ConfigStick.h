/********************************************************************
 * Project:    LPC-Stick
 * File:       ConfigStick.h
 *
 * System:     ARM7TDMI 32 Bit (LPC2468FET208)
 * Compiler:   GCC 4.1.1
 *
 * Date:       2007-09-15
 * Author:     Application@Hitex.de
 *
 * Rights:     Hitex Development Tools GmbH
 *             Greschbachstr. 12
 *             D-76229 Karlsruhe
 ********************************************************************
 * Description:
 *
 * This file is part of the GNU Example "RTOS".
 * This is a small implementation of different features.
 * The application runs in ARM mode with high optimization level.
 *
 ********************************************************************
  * History:
 *
 *    Revision 1.0    2007/09/15      Gx
 *    Initial revision
 *
 *    Revision 1.1    1.07.2008      Alfred Lohmann
 *                                    HAW-Hamburg  TI-Labor
 *    Changed setup to support the TI-Expansion Board
 *    at HAW-Hamburg. 
 *    In config.h the devices used are declared.
 *    UART0 and UART2 are fixed initialized to 19200,8,N,1
 *    The TI-Board is NOT detected automatically.
 *     
 ********************************************************************
 * This is a preliminary version.
 *
 * WARRANTY:  HITEX warrants that the media on which the SOFTWARE is
 * furnished is free from defects in materials and workmanship under
 * normal use and service for a period of ninety (90) days. HITEX entire
 * liability and your exclusive remedy shall be the replacement of the
 * SOFTWARE if the media is defective. This Warranty is void if failure
 * of the media resulted from unauthorized modification, accident, abuse,
 * or misapplication.
 *
 * DISCLAIMER:  OTHER THAN THE ABOVE WARRANTY, THE SOFTWARE IS FURNISHED
 * "AS IS" WITHOUT WARRANTY OF ANY KIND. HITEX DISCLAIMS ALL OTHER WARRANTIES,
 * EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 * NEITHER HITEX NOR ITS AFFILIATES SHALL BE LIABLE FOR ANY DAMAGES ARISING
 * OUT OF THE USE OF OR INABILITY TO USE THE SOFTWARE, INCLUDING DAMAGES FOR
 * LOSS OF PROFITS, BUSINESS INTERRUPTION, OR ANY SPECIAL, INCIDENTAL, INDIRECT
 * OR CONSEQUENTIAL DAMAGES EVEN IF HITEX HAS BEEN ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGES.
 ********************************************************************/
#ifndef _configstick_h
#define _configstick_h

#include <inttypes.h>

/* Basic settings */
/* defines for PORT 0 configuration */
/* pinsel0 */
#define BASE_FUNCT_PORT0_0    (PINSEL_Input     << 0)   /* n.c. */
#define BASE_FUNCT_PORT0_1    (PINSEL_Input     << 2)   /* n.c. */
#define BASE_FUNCT_PORT0_2    (PINSEL_Function1 << 4)   /* UART0 - FTDI */
#define BASE_FUNCT_PORT0_3    (PINSEL_Function1 << 6)   /* UART0 - FTDI */
#define BASE_FUNCT_PORT0_4    (PINSEL_Output    << 8)   /* LED0 (red) */
#define BASE_FUNCT_PORT0_5    (PINSEL_Input     << 10)  /* n.c. */
#define BASE_FUNCT_PORT0_6    (PINSEL_Input     << 12)  /* n.c. */
#define BASE_FUNCT_PORT0_7    (PINSEL_Input     << 14)  /* n.c. */
#define BASE_FUNCT_PORT0_8    (PINSEL_Input     << 16)  /* n.c. */
#define BASE_FUNCT_PORT0_9    (PINSEL_Input     << 18)  /* n.c. */
#define BASE_FUNCT_PORT0_10   (PINSEL_Input     << 20)  /* n.c. */
#define BASE_FUNCT_PORT0_11   (PINSEL_Input     << 22)  /* n.c. */
#define BASE_FUNCT_PORT0_12   (PINSEL_Function3 << 24)  /* Ext Board detection (ADC) */
#define BASE_FUNCT_PORT0_13   (PINSEL_Input     << 26)  /* n.c. */
#define BASE_FUNCT_PORT0_14   (PINSEL_Input     << 28)  /* n.c. */
#define BASE_FUNCT_PORT0_15   (PINSEL_Input     << 30)  /* n.c. */
/* pinsel1 */
#define BASE_FUNCT_PORT0_16   (PINSEL_Input     << 0)   /* n.c. */
#define BASE_FUNCT_PORT0_17   (PINSEL_Input     << 2)   /* n.c. */
#define BASE_FUNCT_PORT0_18   (PINSEL_Input     << 4)   /* n.c. */
#define BASE_FUNCT_PORT0_19   (PINSEL_Input     << 6)   /* n.c. */
#define BASE_FUNCT_PORT0_20   (PINSEL_Input     << 8)   /* n.c. */
#define BASE_FUNCT_PORT0_21   (PINSEL_Input     << 10)  /* n.c. */
#define BASE_FUNCT_PORT0_22   (PINSEL_Input     << 12)  /* n.c. */
#define BASE_FUNCT_PORT0_23   (PINSEL_Input     << 14)  /* n.c. */
#define BASE_FUNCT_PORT0_24   (PINSEL_Input     << 16)  /* n.c. */
#define BASE_FUNCT_PORT0_25   (PINSEL_Output    << 18)  /* LED1 (green) Anode */
#define BASE_FUNCT_PORT0_26   (PINSEL_Input     << 20)  /* n.c. */
#define BASE_FUNCT_PORT0_27   (PINSEL_Output    << 22)  /* LED1 (green) Cathode */
#define BASE_FUNCT_PORT0_28   (PINSEL_Input     << 24)  /* n.c. */
#define BASE_FUNCT_PORT0_29   (PINSEL_Input     << 26)  /* n.c. */
#define BASE_FUNCT_PORT0_30   (PINSEL_Input     << 28)  /* n.c. */
#define BASE_FUNCT_PORT0_31   (PINSEL_Input     << 30)  /* n.c. */
/* defines for PORT 1 configuration */
/* pinsel2 */
#define BASE_FUNCT_PORT1_0    (PINSEL_Input     << 0)   /* n.c. */
#define BASE_FUNCT_PORT1_1    (PINSEL_Input     << 2)   /* n.c. */
#define BASE_FUNCT_PORT1_2    (PINSEL_Input     << 4)   /* n.c. */
#define BASE_FUNCT_PORT1_3    (PINSEL_Input     << 6)   /* n.c. */
#define BASE_FUNCT_PORT1_4    (PINSEL_Input     << 8)   /* n.c. */
#define BASE_FUNCT_PORT1_5    (PINSEL_Input     << 10)  /* n.c. */
#define BASE_FUNCT_PORT1_6    (PINSEL_Input     << 12)  /* n.c. */
#define BASE_FUNCT_PORT1_7    (PINSEL_Input     << 14)  /* n.c. */
#define BASE_FUNCT_PORT1_8    (PINSEL_Input     << 16)  /* n.c. */
#define BASE_FUNCT_PORT1_9    (PINSEL_Input     << 18)  /* n.c. */
#define BASE_FUNCT_PORT1_10   (PINSEL_Input     << 20)  /* n.c. */
#define BASE_FUNCT_PORT1_11   (PINSEL_Input     << 22)  /* n.c. */
#define BASE_FUNCT_PORT1_12   (PINSEL_Input     << 24)  /* n.c. */
#define BASE_FUNCT_PORT1_13   (PINSEL_Input     << 26)  /* n.c. */
#define BASE_FUNCT_PORT1_14   (PINSEL_Input     << 28)  /* n.c. */
#define BASE_FUNCT_PORT1_15   (PINSEL_Input     << 30)  /* n.c. */
/* pinsel3 */
#define BASE_FUNCT_PORT1_16   (PINSEL_Input     << 0)   /* n.c. */
#define BASE_FUNCT_PORT1_17   (PINSEL_Input     << 2)   /* n.c. */
#define BASE_FUNCT_PORT1_18   (PINSEL_Input     << 4)   /* n.c. */
#define BASE_FUNCT_PORT1_19   (PINSEL_Input     << 6)   /* n.c. */
#define BASE_FUNCT_PORT1_20   (PINSEL_Input     << 8)   /* n.c. */
#define BASE_FUNCT_PORT1_21   (PINSEL_Input     << 10)  /* n.c. */
#define BASE_FUNCT_PORT1_22   (PINSEL_Input     << 12)  /* n.c. */
#define BASE_FUNCT_PORT1_23   (PINSEL_Input     << 14)  /* n.c. */
#define BASE_FUNCT_PORT1_24   (PINSEL_Input     << 16)  /* n.c. */
#define BASE_FUNCT_PORT1_25   (PINSEL_Input     << 18)  /* n.c. */
#define BASE_FUNCT_PORT1_26   (PINSEL_Input     << 20)  /* n.c. */
#define BASE_FUNCT_PORT1_27   (PINSEL_Input     << 22)  /* n.c. */
#define BASE_FUNCT_PORT1_28   (PINSEL_Input     << 24)  /* n.c. */
#define BASE_FUNCT_PORT1_29   (PINSEL_Input     << 26)  /* n.c. */
#define BASE_FUNCT_PORT1_30   (PINSEL_Input     << 28)  /* n.c. */
#define BASE_FUNCT_PORT1_31   (PINSEL_Input     << 30)  /* n.c. */
/* defines for PORT 2 configuration */
/* pinsel4 */
#define BASE_FUNCT_PORT2_0    (PINSEL_Input     << 0)   /* n.c. */
#define BASE_FUNCT_PORT2_1    (PINSEL_Input     << 2)   /* n.c. */
#define BASE_FUNCT_PORT2_2    (PINSEL_Input     << 4)   /* n.c. */
#define BASE_FUNCT_PORT2_3    (PINSEL_Input     << 6)   /* n.c. */
#define BASE_FUNCT_PORT2_4    (PINSEL_Input     << 8)   /* n.c. */
#define BASE_FUNCT_PORT2_5    (PINSEL_Input     << 10)  /* n.c. */
#define BASE_FUNCT_PORT2_6    (PINSEL_Input     << 12)  /* n.c. */
#define BASE_FUNCT_PORT2_7    (PINSEL_Input     << 14)  /* n.c. */
#define BASE_FUNCT_PORT2_8    (PINSEL_Input     << 16)  /* n.c. */
#define BASE_FUNCT_PORT2_9    (PINSEL_Input     << 18)  /* n.c. */
#define BASE_FUNCT_PORT2_10   (PINSEL_Input     << 20)  /* n.c. */
#define BASE_FUNCT_PORT2_11   (PINSEL_Input     << 22)  /* n.c. */
#define BASE_FUNCT_PORT2_12   (PINSEL_Input     << 24)  /* n.c. */
#define BASE_FUNCT_PORT2_13   (PINSEL_Input     << 26)  /* n.c. */
#define BASE_FUNCT_PORT2_14   (PINSEL_Input     << 28)  /* n.c. */
#define BASE_FUNCT_PORT2_15   (PINSEL_Input     << 30)  /* n.c. */
/* pinsel5 */
#define BASE_FUNCT_PORT2_16   (PINSEL_Input     << 0)   /* n.c. */
#define BASE_FUNCT_PORT2_17   (PINSEL_Input     << 2)   /* n.c. */
#define BASE_FUNCT_PORT2_18   (PINSEL_Input     << 4)   /* n.c. */
#define BASE_FUNCT_PORT2_19   (PINSEL_Input     << 6)   /* n.c. */
#define BASE_FUNCT_PORT2_20   (PINSEL_Input     << 8)   /* n.c. */
#define BASE_FUNCT_PORT2_21   (PINSEL_Input     << 10)  /* n.c. */
#define BASE_FUNCT_PORT2_22   (PINSEL_Input     << 12)  /* n.c. */
#define BASE_FUNCT_PORT2_23   (PINSEL_Input     << 14)  /* n.c. */
#define BASE_FUNCT_PORT2_24   (PINSEL_Input     << 16)  /* n.c. */
#define BASE_FUNCT_PORT2_25   (PINSEL_Input     << 18)  /* n.c. */
#define BASE_FUNCT_PORT2_26   (PINSEL_Input     << 20)  /* n.c. */
#define BASE_FUNCT_PORT2_27   (PINSEL_Input     << 22)  /* n.c. */
#define BASE_FUNCT_PORT2_28   (PINSEL_Input     << 24)  /* n.c. */
#define BASE_FUNCT_PORT2_29   (PINSEL_Input     << 26)  /* n.c. */
#define BASE_FUNCT_PORT2_30   (PINSEL_Input     << 28)  /* n.c. */
#define BASE_FUNCT_PORT2_31   (PINSEL_Input     << 30)  /* n.c. */

/* ComBoard Extension settings */
/* defines for PORT 0 configuration */
/* pinsel0 */
#define COM_FUNCT_PORT0_0     (PINSEL_Function1 << 0)   /* CAN interface */
#define COM_FUNCT_PORT0_1     (PINSEL_Function1 << 2)   /* CAN interface */
#define COM_FUNCT_PORT0_2     (PINSEL_Function1 << 4)   /* UART0 - FTDI */
#define COM_FUNCT_PORT0_3     (PINSEL_Function1 << 6)   /* UART0 - FTDI */
#define COM_FUNCT_PORT0_4     (PINSEL_Output    << 8)   /* LED0 (red) */ /* Conn */
#define COM_FUNCT_PORT0_5     (PINSEL_Input     << 10)  /* Conn */
#define COM_FUNCT_PORT0_6     (PINSEL_Input     << 12)  /* n.c. */
#define COM_FUNCT_PORT0_7     (PINSEL_Input     << 14)  /* n.c. */
#define COM_FUNCT_PORT0_8     (PINSEL_Input     << 16)  /* n.c. */
#define COM_FUNCT_PORT0_9     (PINSEL_Input     << 18)  /* n.c. */
#define COM_FUNCT_PORT0_10    (PINSEL_Function1 << 20)  /* UART2 TX */
#define COM_FUNCT_PORT0_11    (PINSEL_Function1 << 22)  /* UART2 RX */
#define COM_FUNCT_PORT0_12    (PINSEL_Input     << 24)  /* n.c. */
#define COM_FUNCT_PORT0_13    (PINSEL_Function1 << 26)  /* n.c. */
#define COM_FUNCT_PORT0_14    (PINSEL_Function2 << 28)  /* n.c. */
#define COM_FUNCT_PORT0_15    (PINSEL_Input     << 30)  /* Conn */
/* pinsel1 */
#define COM_FUNCT_PORT0_16    (PINSEL_Input     << 0)   /* Conn */
#define COM_FUNCT_PORT0_17    (PINSEL_Input     << 2)   /* Conn */
#define COM_FUNCT_PORT0_18    (PINSEL_Input     << 4)   /* Conn */
#define COM_FUNCT_PORT0_19    (PINSEL_Input     << 6)   /* Conn */
#define COM_FUNCT_PORT0_20    (PINSEL_Input     << 8)   /* Conn */
#define COM_FUNCT_PORT0_21    (PINSEL_Input     << 10)  /* MDC */ /* Conn */
#define COM_FUNCT_PORT0_22    (PINSEL_Input     << 12)  /* MDC */ /* Conn */
#define COM_FUNCT_PORT0_23    (PINSEL_Input     << 14)  /* Conn */
#define COM_FUNCT_PORT0_24    (PINSEL_Input     << 16)  /* Conn */
#define COM_FUNCT_PORT0_25    (PINSEL_Input     << 18)  /* Conn */
#define COM_FUNCT_PORT0_26    (PINSEL_Input     << 20)  /* Conn */
#define COM_FUNCT_PORT0_27    (PINSEL_Input     << 22)  /* Conn */
#define COM_FUNCT_PORT0_28    (PINSEL_Input     << 24)  /* Conn */
#define COM_FUNCT_PORT0_29    (PINSEL_Function1 << 26)  /* USB */
#define COM_FUNCT_PORT0_30    (PINSEL_Function1 << 28)  /* USB */
#define COM_FUNCT_PORT0_31    (PINSEL_Function1 << 30)  /* n.c. */
/* defines for PORT 1 configuration */
/* pinsel2 */
#define COM_FUNCT_PORT1_0     (PINSEL_Function1 << 0)   /* RMII */
#define COM_FUNCT_PORT1_1     (PINSEL_Function1 << 2)   /* RMII */
#define COM_FUNCT_PORT1_2     (PINSEL_Input     << 4)   /* MDC */
#define COM_FUNCT_PORT1_3     (PINSEL_Input     << 6)   /* MDC */
#define COM_FUNCT_PORT1_4     (PINSEL_Function1 << 8)   /* RMII */
#define COM_FUNCT_PORT1_5     (PINSEL_Input     << 10)  /* Conn */
#define COM_FUNCT_PORT1_6_old (PINSEL_Function1 << 12)  /* RMII (OLD_EMAC_MODULE_ID) */
#define COM_FUNCT_PORT1_6     (PINSEL_Input     << 12)  /* RMII Rev A*/
#define COM_FUNCT_PORT1_7     (PINSEL_Input     << 14)  /* MDC */ /* Conn */
#define COM_FUNCT_PORT1_8     (PINSEL_Function1 << 16)  /* RMII */
#define COM_FUNCT_PORT1_9     (PINSEL_Function1 << 18)  /* RMII */
#define COM_FUNCT_PORT1_10    (PINSEL_Function1 << 20)  /* RMII */
#define COM_FUNCT_PORT1_11    (PINSEL_Input     << 22)  /* MDC */ /* Conn */
#define COM_FUNCT_PORT1_12    (PINSEL_Input     << 24)  /* MDC */ /* Conn */
#define COM_FUNCT_PORT1_13    (PINSEL_Input     << 26)  /* RMII */
#define COM_FUNCT_PORT1_14    (PINSEL_Function1 << 28)  /* RMII */
#define COM_FUNCT_PORT1_15    (PINSEL_Function1 << 30)  /* RMII */
/* pinsel3 */
#define COM_FUNCT_PORT1_16    (PINSEL_Function1 << 0)   /* RMII */
#define COM_FUNCT_PORT1_17    (PINSEL_Function1 << 2)   /* RMII */
#define COM_FUNCT_PORT1_18    (PINSEL_Function1 << 4)   /* USB */
#define COM_FUNCT_PORT1_19    (PINSEL_Function2 << 6)   /* USB */
#define COM_FUNCT_PORT1_20    (PINSEL_Function2 << 8)   /* Conn */
#define COM_FUNCT_PORT1_21    (PINSEL_Function2 << 10)  /* Conn */
#define COM_FUNCT_PORT1_22    (PINSEL_Function2 << 12)  /* USB */
#define COM_FUNCT_PORT1_23    (PINSEL_Input     << 14)  /* n.c */
#define COM_FUNCT_PORT1_24    (PINSEL_Input     << 16)  /* n.c */
#define COM_FUNCT_PORT1_25    (PINSEL_Input     << 18)  /* n.c */
#define COM_FUNCT_PORT1_26    (PINSEL_Input     << 20)  /* n.c */
#define COM_FUNCT_PORT1_27    (PINSEL_Function2 << 22)  /* USB */
#define COM_FUNCT_PORT1_28    (PINSEL_Input     << 24)  /* n.c */
#define COM_FUNCT_PORT1_29    (PINSEL_Input     << 26)  /* n.c */
#define COM_FUNCT_PORT1_30    (PINSEL_Input     << 28)  /* VUS */
#define COM_FUNCT_PORT1_31    (PINSEL_Input     << 30)  /* n.c */
/* defines for PORT 2 configuration */
/* pinsel4 */
#define COM_FUNCT_PORT2_0     (PINSEL_Input     << 0)   /* Conn */
#define COM_FUNCT_PORT2_1     (PINSEL_Input     << 2)   /* Conn */
#define COM_FUNCT_PORT2_2     (PINSEL_Input     << 4)   /* Conn */
#define COM_FUNCT_PORT2_3     (PINSEL_Input     << 6)   /* Conn */
#define COM_FUNCT_PORT2_4     (PINSEL_Input     << 8)   /* Conn */
#define COM_FUNCT_PORT2_5     (PINSEL_Input     << 10)  /* Conn */
#define COM_FUNCT_PORT2_6     (PINSEL_Input     << 12)  /* n.c. */
#define COM_FUNCT_PORT2_7     (PINSEL_Input     << 14)  /* MDC */ /* Conn */
#define COM_FUNCT_PORT2_8     (PINSEL_Input     << 16)  /* Conn */
#define COM_FUNCT_PORT2_9     (PINSEL_Input     << 18)  /* Conn */
#define COM_FUNCT_PORT2_10    (PINSEL_Input     << 20)  /* n.c. */
#define COM_FUNCT_PORT2_11    (PINSEL_Input     << 22)  /* Conn */
#define COM_FUNCT_PORT2_12    (PINSEL_Input     << 24)  /* MDC */ /* Conn */
#define COM_FUNCT_PORT2_13    (PINSEL_Input     << 26)  /* Conn */
#define COM_FUNCT_PORT2_14    (PINSEL_Input     << 28)  /* n.c. */
#define COM_FUNCT_PORT2_15    (PINSEL_Input     << 30)  /* n.c. */

/* This is the special board at HAW-Hamburg  */
/* Labor für technische Informatik           */
/* TI-Board Extension settings               */
/* defines for PORT 0 configuration */
/* pinsel0 */
#define TI_FUNCT_PORT0_0     (PINSEL_Function1 << 0)   /* CAN interface */
#define TI_FUNCT_PORT0_1     (PINSEL_Function1 << 2)   /* CAN interface */
#define TI_FUNCT_PORT0_2     (PINSEL_Function1 << 4)   /* UART0 - FTDI */
#define TI_FUNCT_PORT0_3     (PINSEL_Function1 << 6)   /* UART0 - FTDI */
#define TI_FUNCT_PORT0_4     (PINSEL_Output    << 8)   /* LED0 (red) */ /* Conn */
#define TI_FUNCT_PORT0_5     (PINSEL_Input     << 10)  /* Conn */
#define TI_FUNCT_PORT0_6     (PINSEL_Input     << 12)  /* n.c. */
#define TI_FUNCT_PORT0_7     (PINSEL_Input     << 14)  /* n.c. */
#define TI_FUNCT_PORT0_8     (PINSEL_Input     << 16)  /* n.c. */
#define TI_FUNCT_PORT0_9     (PINSEL_Input     << 18)  /* n.c. */
#define TI_FUNCT_PORT0_10    (PINSEL_Function1 << 20)  /* UART2 TX */
#define TI_FUNCT_PORT0_11    (PINSEL_Function1 << 22)  /* UART2 RX */
#define TI_FUNCT_PORT0_12    (PINSEL_Function3 << 24)  /* Ext Board detection (ADC) */
#define TI_FUNCT_PORT0_13    (PINSEL_Input     << 26)  /* n.c. */
#define TI_FUNCT_PORT0_14    (PINSEL_Input     << 28)  /* n.c. */
#define TI_FUNCT_PORT0_15    (PINSEL_Input     << 30)  /* n.c. */
/* pinsel1 */
#define TI_FUNCT_PORT0_16    (PINSEL_Input     << 0)   /* n.c. */
#define TI_FUNCT_PORT0_17    (PINSEL_Input     << 2)   /* n.c. */
#define TI_FUNCT_PORT0_18    (PINSEL_Input     << 4)   /* n.c. */
#define TI_FUNCT_PORT0_19    (PINSEL_Input     << 6)   /* n.c. */
#define TI_FUNCT_PORT0_20    (PINSEL_Input     << 8)   /* n.c. */
#define TI_FUNCT_PORT0_21    (PINSEL_Input     << 10)  /* n.c. */
#define TI_FUNCT_PORT0_22    (PINSEL_Input     << 12)  /* n.c. */
#define TI_FUNCT_PORT0_23    (PINSEL_Function1 << 14)  /* ADC 0.0 */
#define TI_FUNCT_PORT0_24    (PINSEL_Function1 << 16)  /* ADC 0.1 */
#define TI_FUNCT_PORT0_25    (PINSEL_Function1 << 18)  /* ADC 0.2 */
#define TI_FUNCT_PORT0_26    (PINSEL_Function2 << 20)  /* AOUT    */
#define TI_FUNCT_PORT0_27    (PINSEL_Output    << 22)  /* LED1 (green) Cathode */
#define TI_FUNCT_PORT0_28    (PINSEL_Input     << 24)  /* n.c. */
#define TI_FUNCT_PORT0_29    (PINSEL_Input     << 26)  /* n.c. */
#define TI_FUNCT_PORT0_30    (PINSEL_Input     << 28)  /* n.c. */
#define TI_FUNCT_PORT0_31    (PINSEL_Input     << 30)  /* n.c. */
/* defines for PORT 1 configuration */
/* pinsel2 */
#define TI_FUNCT_PORT1_0     (PINSEL_Output    << 0)   /* IO Bit (LED) */
#define TI_FUNCT_PORT1_1     (PINSEL_Output    << 2)   /* IO Bit (LED) */
#define TI_FUNCT_PORT1_2     (PINSEL_Output    << 4)   /* IO Bit (LED) */
#define TI_FUNCT_PORT1_3     (PINSEL_Output    << 6)   /* IO Bit (LED) */
#define TI_FUNCT_PORT1_4     (PINSEL_Output    << 8)   /* IO Bit (LED) */
#define TI_FUNCT_PORT1_5     (PINSEL_Output    << 10)  /* IO Bit (LED) */
#define TI_FUNCT_PORT1_6     (PINSEL_Output    << 12)  /* IO Bit (LED) */
#define TI_FUNCT_PORT1_7     (PINSEL_Output    << 14)  /* IO Bit (LED) */
#define TI_FUNCT_PORT1_8     (PINSEL_Input     << 16)  /* IO Bit (LED + Switch) */
#define TI_FUNCT_PORT1_9     (PINSEL_Input     << 18)  /* IO Bit (LED + Switch) */
#define TI_FUNCT_PORT1_10    (PINSEL_Input     << 20)  /* IO Bit (LED + Switch) */
#define TI_FUNCT_PORT1_11    (PINSEL_Input     << 22)  /* IO Bit (LED + Switch) */
#define TI_FUNCT_PORT1_12    (PINSEL_Input     << 24)  /* IO Bit (LED + Switch) */
#define TI_FUNCT_PORT1_13    (PINSEL_Input     << 26)  /* IO Bit (LED + Switch) */
#define TI_FUNCT_PORT1_14    (PINSEL_Input     << 28)  /* IO Bit (LED + Switch) */
#define TI_FUNCT_PORT1_15    (PINSEL_Input     << 30)  /* IO Bit (LED + Switch) */
/* pinsel3 */
#define TI_FUNCT_PORT1_16    (PINSEL_Output     << 0)  /* LCD data bit 0 */
#define TI_FUNCT_PORT1_17    (PINSEL_Output     << 2)  /* LCD data bit 1 */
#define TI_FUNCT_PORT1_18    (PINSEL_Output     << 4)  /* LCD data bit 2 */
#define TI_FUNCT_PORT1_19    (PINSEL_Output     << 6)  /* LCD data bit 3 */
#define TI_FUNCT_PORT1_20    (PINSEL_Output     << 8)  /* LCD RS  */
#define TI_FUNCT_PORT1_21    (PINSEL_Output    << 10)  /* LCD RW  */
#define TI_FUNCT_PORT1_22    (PINSEL_Output    << 12)  /* LCD W   */
#define TI_FUNCT_PORT1_23    (PINSEL_Input     << 14)  /* n.c. */
#define TI_FUNCT_PORT1_24    (PINSEL_Input     << 16)  /* n.c. */
#define TI_FUNCT_PORT1_25    (PINSEL_Input     << 18)  /* n.c. */
#define TI_FUNCT_PORT1_26    (PINSEL_Input     << 20)  /* n.c. */
#define TI_FUNCT_PORT1_27    (PINSEL_Output    << 22)  /* LED 1 */
#define TI_FUNCT_PORT1_28    (PINSEL_Output    << 24)  /* LED 2 */
#define TI_FUNCT_PORT1_29    (PINSEL_Output    << 26)  /* LED 3 */
#define TI_FUNCT_PORT1_30    (PINSEL_Output    << 28)  /* LED 4 */
#define TI_FUNCT_PORT1_31    (PINSEL_Input     << 30)  /* n.c */
/* defines for PORT 2 configuration */
/* pinsel4 */
#define TI_FUNCT_PORT2_0     (PINSEL_Function1  << 0)   /* PWM 1.1 */
#define TI_FUNCT_PORT2_1     (PINSEL_Function1  << 2)   /* PWM 1.2 */
#define TI_FUNCT_PORT2_2     (PINSEL_Function1  << 4)   /* PWM 1.2 */
#define TI_FUNCT_PORT2_3     (PINSEL_Input      << 6)   /* n.c. */
#define TI_FUNCT_PORT2_4     (PINSEL_Input      << 8)   /* n.c. */
#define TI_FUNCT_PORT2_5     (PINSEL_Input     << 10)  /* n.c. */
#define TI_FUNCT_PORT2_6     (PINSEL_Input     << 12)  /* n.c. */
#define TI_FUNCT_PORT2_7     (PINSEL_Input     << 14)  /* n.c. */
#define TI_FUNCT_PORT2_8     (PINSEL_Input     << 16)  /* n.c. */
#define TI_FUNCT_PORT2_9     (PINSEL_Input     << 18)  /* n.c. */
#define TI_FUNCT_PORT2_10    (PINSEL_Input     << 20)  /* n.c. */
#define TI_FUNCT_PORT2_11    (PINSEL_Function1 << 22)  /* EINT 1 */
#define TI_FUNCT_PORT2_12    (PINSEL_Function1 << 24)  /* EIN 2 */
#define TI_FUNCT_PORT2_13    (PINSEL_Input     << 26)  /* n.c. */
#define TI_FUNCT_PORT2_14    (PINSEL_Input     << 28)  /* n.c. */
#define TI_FUNCT_PORT2_15    (PINSEL_Input     << 30)  /* n.c. */



/* fixed settings (every configuration) */
/* defines for PORT 3 configuration */
/* pinsel6 */
#define FUNCT_PORT3_0   (PINSEL_Function1 << 0)
#define FUNCT_PORT3_1   (PINSEL_Function1 << 2)
#define FUNCT_PORT3_2   (PINSEL_Function1 << 4)
#define FUNCT_PORT3_3   (PINSEL_Function1 << 6)
#define FUNCT_PORT3_4   (PINSEL_Function1 << 8)
#define FUNCT_PORT3_5   (PINSEL_Function1 << 10)
#define FUNCT_PORT3_6   (PINSEL_Function1 << 12)
#define FUNCT_PORT3_7   (PINSEL_Function1 << 14)
#define FUNCT_PORT3_8   (PINSEL_Input << 16)
#define FUNCT_PORT3_9   (PINSEL_Input << 18)
#define FUNCT_PORT3_10  (PINSEL_Input << 20)
#define FUNCT_PORT3_11  (PINSEL_Input << 22)
#define FUNCT_PORT3_12  (PINSEL_Input << 24)
#define FUNCT_PORT3_13  (PINSEL_Input << 26)
#define FUNCT_PORT3_14  (PINSEL_Input << 28)
#define FUNCT_PORT3_15  (PINSEL_Input << 30)
/* pinsel7 */
#define FUNCT_PORT3_16  (PINSEL_Input << 0)
#define FUNCT_PORT3_17  (PINSEL_Input << 2)
#define FUNCT_PORT3_18  (PINSEL_Input << 4)
#define FUNCT_PORT3_19  (PINSEL_Input << 6)
#define FUNCT_PORT3_20  (PINSEL_Input << 8)
#define FUNCT_PORT3_21  (PINSEL_Input << 10)
#define FUNCT_PORT3_22  (PINSEL_Input << 12)
#define FUNCT_PORT3_23  (PINSEL_Input << 14)
#define FUNCT_PORT3_24  (PINSEL_Input << 16)
#define FUNCT_PORT3_25  (PINSEL_Input << 18)
#define FUNCT_PORT3_26  (PINSEL_Input << 20)
#define FUNCT_PORT3_27  (PINSEL_Input << 22)
#define FUNCT_PORT3_28  (PINSEL_Input << 24)
#define FUNCT_PORT3_29  (PINSEL_Input << 26)
#define FUNCT_PORT3_30  (PINSEL_Input << 28)
#define FUNCT_PORT3_31  (PINSEL_Input << 30)
/* defines for PORT 4 configuration */
/* pinsel8 */
#define FUNCT_PORT4_0   (PINSEL_Function1 << 0)
#define FUNCT_PORT4_1   (PINSEL_Function1 << 2)
#define FUNCT_PORT4_2   (PINSEL_Function1 << 4)
#define FUNCT_PORT4_3   (PINSEL_Function1 << 6)
#define FUNCT_PORT4_4   (PINSEL_Function1 << 8)
#define FUNCT_PORT4_5   (PINSEL_Function1 << 10)
#define FUNCT_PORT4_6   (PINSEL_Function1 << 12)
#define FUNCT_PORT4_7   (PINSEL_Function1 << 14)
#define FUNCT_PORT4_8   (PINSEL_Function1 << 16)
#define FUNCT_PORT4_9   (PINSEL_Function1 << 18)
#define FUNCT_PORT4_10  (PINSEL_Function1 << 20)
#define FUNCT_PORT4_11  (PINSEL_Function1 << 22)
#define FUNCT_PORT4_12  (PINSEL_Function1 << 24)
#define FUNCT_PORT4_13  (PINSEL_Function1 << 26)
#define FUNCT_PORT4_14  (PINSEL_Function1 << 28)
#define FUNCT_PORT4_15  (PINSEL_Function1 << 30)
/* pinsel9 */
#define FUNCT_PORT4_16  (PINSEL_Function1 << 0)
#define FUNCT_PORT4_17  (PINSEL_Function1 << 2)
#define FUNCT_PORT4_18  (PINSEL_Input     << 4)
#define FUNCT_PORT4_19  (PINSEL_Input     << 6)
#define FUNCT_PORT4_20  (PINSEL_Input     << 8)
#define FUNCT_PORT4_21  (PINSEL_Input     << 10)
#define FUNCT_PORT4_22  (PINSEL_Input     << 12)
#define FUNCT_PORT4_23  (PINSEL_Input     << 14)
#define FUNCT_PORT4_24  (PINSEL_Function1 << 16)
#define FUNCT_PORT4_25  (PINSEL_Function1 << 18)
#define FUNCT_PORT4_26  (PINSEL_Function1 << 20)
#define FUNCT_PORT4_27  (PINSEL_Input     << 22)
#define FUNCT_PORT4_28  (PINSEL_Input     << 24)
#define FUNCT_PORT4_29  (PINSEL_Input     << 26)
#define FUNCT_PORT4_30  (PINSEL_Function1 << 28)
#define FUNCT_PORT4_31  (PINSEL_Function1 << 30)

/* set PORT 0-2 configuration */
/* set output PIN's */
/* No Outputs on Port 3 configured */
#define Base_FIO0DIR  (IO_PX_4 | IO_PX_25 | IO_PX_27)
#define Base_FIO1DIR  0
#define Base_FIO2DIR  0
#define Base_FIO3DIR  0
#define Base_FIO4DIR  0
#define BASE_FIO0MASKL        (0x100C)
#define BASE_FIO0MASKU        (0x0A00)
#define BASE_FIO1MASKL        (0x0000)
#define BASE_FIO1MASKU        (0x0000)
#define BASE_FIO2MASKL        (0x0000)
#define BASE_FIO2MASKU        (0xFFFF)
#define Base_PINSEL0 \
              BASE_FUNCT_PORT0_0  | BASE_FUNCT_PORT0_1  | BASE_FUNCT_PORT0_2  | BASE_FUNCT_PORT0_3  | \
              BASE_FUNCT_PORT0_4  | BASE_FUNCT_PORT0_5  | BASE_FUNCT_PORT0_6  | BASE_FUNCT_PORT0_7  | \
              BASE_FUNCT_PORT0_8  | BASE_FUNCT_PORT0_9  | BASE_FUNCT_PORT0_10 | BASE_FUNCT_PORT0_11 | \
              BASE_FUNCT_PORT0_12 | BASE_FUNCT_PORT0_13 | BASE_FUNCT_PORT0_14 | BASE_FUNCT_PORT0_15
#define Base_PINSEL1 \
              BASE_FUNCT_PORT0_16 | BASE_FUNCT_PORT0_17 | BASE_FUNCT_PORT0_18 | BASE_FUNCT_PORT0_19 | \
              BASE_FUNCT_PORT0_20 | BASE_FUNCT_PORT0_21 | BASE_FUNCT_PORT0_22 | BASE_FUNCT_PORT0_23 | \
              BASE_FUNCT_PORT0_24 | BASE_FUNCT_PORT0_25 | BASE_FUNCT_PORT0_26 | BASE_FUNCT_PORT0_27 | \
              BASE_FUNCT_PORT0_28 | BASE_FUNCT_PORT0_29 | BASE_FUNCT_PORT0_30 | BASE_FUNCT_PORT0_31
#define Base_PINSEL2 \
              BASE_FUNCT_PORT1_0  | BASE_FUNCT_PORT1_1  | BASE_FUNCT_PORT1_2  | BASE_FUNCT_PORT1_3  | \
              BASE_FUNCT_PORT1_4  | BASE_FUNCT_PORT1_5  | BASE_FUNCT_PORT1_6  | BASE_FUNCT_PORT1_7  | \
              BASE_FUNCT_PORT1_8  | BASE_FUNCT_PORT1_9  | BASE_FUNCT_PORT1_10 | BASE_FUNCT_PORT1_11 | \
              BASE_FUNCT_PORT1_12 | BASE_FUNCT_PORT1_13 | BASE_FUNCT_PORT1_14 | BASE_FUNCT_PORT1_15
#define Base_PINSEL3 \
              BASE_FUNCT_PORT1_16 | BASE_FUNCT_PORT1_17 | BASE_FUNCT_PORT1_18 | BASE_FUNCT_PORT1_19 | \
              BASE_FUNCT_PORT1_20 | BASE_FUNCT_PORT1_21 | BASE_FUNCT_PORT1_22 | BASE_FUNCT_PORT1_23 | \
              BASE_FUNCT_PORT1_24 | BASE_FUNCT_PORT1_25 | BASE_FUNCT_PORT1_26 | BASE_FUNCT_PORT1_27 | \
              BASE_FUNCT_PORT1_28 | BASE_FUNCT_PORT1_29 | BASE_FUNCT_PORT1_30 | BASE_FUNCT_PORT1_31
#define Base_PINSEL4 \
              BASE_FUNCT_PORT2_0  | BASE_FUNCT_PORT2_1  | BASE_FUNCT_PORT2_2  | BASE_FUNCT_PORT2_3  | \
              BASE_FUNCT_PORT2_4  | BASE_FUNCT_PORT2_5  | BASE_FUNCT_PORT2_6  | BASE_FUNCT_PORT2_7  | \
              BASE_FUNCT_PORT2_8  | BASE_FUNCT_PORT2_9  | BASE_FUNCT_PORT2_10 | BASE_FUNCT_PORT2_11 | \
              BASE_FUNCT_PORT2_12 | BASE_FUNCT_PORT2_13 | BASE_FUNCT_PORT2_14 | BASE_FUNCT_PORT2_15
#define Base_PINSEL5 \
              BASE_FUNCT_PORT2_16 | BASE_FUNCT_PORT2_17 | BASE_FUNCT_PORT2_18 | BASE_FUNCT_PORT2_19 | \
              BASE_FUNCT_PORT2_20 | BASE_FUNCT_PORT2_21 | BASE_FUNCT_PORT2_22 | BASE_FUNCT_PORT2_23 | \
              BASE_FUNCT_PORT2_24 | BASE_FUNCT_PORT2_25 | BASE_FUNCT_PORT2_26 | BASE_FUNCT_PORT2_27 | \
              BASE_FUNCT_PORT2_28 | BASE_FUNCT_PORT2_29 | BASE_FUNCT_PORT2_30 | BASE_FUNCT_PORT2_31

/* set PORT 3 configuration */
/* set output PIN's */
/* No Outputs on Port 3 configured */
#define MEM_PINSEL6 \
              FUNCT_PORT3_0  | FUNCT_PORT3_1  | FUNCT_PORT3_2  | FUNCT_PORT3_3  | \
              FUNCT_PORT3_4  | FUNCT_PORT3_5  | FUNCT_PORT3_6  | FUNCT_PORT3_7  | \
              FUNCT_PORT3_8  | FUNCT_PORT3_9  | FUNCT_PORT3_10 | FUNCT_PORT3_11 | \
              FUNCT_PORT3_12 | FUNCT_PORT3_13 | FUNCT_PORT3_14 | FUNCT_PORT3_15
#define MEM_PINSEL7 \
              FUNCT_PORT3_16 | FUNCT_PORT3_17 | FUNCT_PORT3_18 | FUNCT_PORT3_19 | \
              FUNCT_PORT3_20 | FUNCT_PORT3_21 | FUNCT_PORT3_22 | FUNCT_PORT3_23 | \
              FUNCT_PORT3_24 | FUNCT_PORT3_25 | FUNCT_PORT3_26 | FUNCT_PORT3_27 | \
              FUNCT_PORT3_28 | FUNCT_PORT3_29 | FUNCT_PORT3_30 | FUNCT_PORT3_31
/* set PORT 4 configuration */
/* set output PIN's */
/* No Outputs on Port 4 configured */
#define MEM_PINSEL8 \
              FUNCT_PORT4_0  | FUNCT_PORT4_1  | FUNCT_PORT4_2  | FUNCT_PORT4_3  | \
              FUNCT_PORT4_4  | FUNCT_PORT4_5  | FUNCT_PORT4_6  | FUNCT_PORT4_7  | \
              FUNCT_PORT4_8  | FUNCT_PORT4_9  | FUNCT_PORT4_10 | FUNCT_PORT4_11 | \
              FUNCT_PORT4_12 | FUNCT_PORT4_13 | FUNCT_PORT4_14 | FUNCT_PORT4_15
#define MEM_PINSEL9 \
              FUNCT_PORT4_16 | FUNCT_PORT4_17 | FUNCT_PORT4_18 | FUNCT_PORT4_19 | \
              FUNCT_PORT4_20 | FUNCT_PORT4_21 | FUNCT_PORT4_22 | FUNCT_PORT4_23 | \
              FUNCT_PORT4_24 | FUNCT_PORT4_25 | FUNCT_PORT4_26 | FUNCT_PORT4_27 | \
              FUNCT_PORT4_28 | FUNCT_PORT4_29 | FUNCT_PORT4_30 | FUNCT_PORT4_31

/* ComBoard Extension settings */
#define COM_FIO0DIR  (IO_PX_4 | IO_PX_25 | IO_PX_27)
#define COM_FIO1DIR  0
#define COM_FIO2DIR  0
#define COM_FIO3DIR  0
#define COM_FIO4DIR  0
#define COM_PINSEL0 \
              COM_FUNCT_PORT0_0  | COM_FUNCT_PORT0_1  | COM_FUNCT_PORT0_2  | COM_FUNCT_PORT0_3  | \
              COM_FUNCT_PORT0_4  | COM_FUNCT_PORT0_5  | COM_FUNCT_PORT0_6  | COM_FUNCT_PORT0_7  | \
              COM_FUNCT_PORT0_8  | COM_FUNCT_PORT0_9  | COM_FUNCT_PORT0_10 | COM_FUNCT_PORT0_11 | \
              COM_FUNCT_PORT0_12 | COM_FUNCT_PORT0_13 | COM_FUNCT_PORT0_14 | COM_FUNCT_PORT0_15
#define COM_PINSEL1 \
              COM_FUNCT_PORT0_16 | COM_FUNCT_PORT0_17 | COM_FUNCT_PORT0_18 | COM_FUNCT_PORT0_19 | \
              COM_FUNCT_PORT0_20 | COM_FUNCT_PORT0_21 | COM_FUNCT_PORT0_22 | COM_FUNCT_PORT0_23 | \
              COM_FUNCT_PORT0_24 | COM_FUNCT_PORT0_25 | COM_FUNCT_PORT0_26 | COM_FUNCT_PORT0_27 | \
              COM_FUNCT_PORT0_28 | COM_FUNCT_PORT0_29 | COM_FUNCT_PORT0_30 | COM_FUNCT_PORT0_31
#define COM_PINSEL2 \
              COM_FUNCT_PORT1_0  | COM_FUNCT_PORT1_1  | COM_FUNCT_PORT1_2  | COM_FUNCT_PORT1_3  | \
              COM_FUNCT_PORT1_4  | COM_FUNCT_PORT1_5  | COM_FUNCT_PORT1_6  | COM_FUNCT_PORT1_7  | \
              COM_FUNCT_PORT1_8  | COM_FUNCT_PORT1_9  | COM_FUNCT_PORT1_10 | COM_FUNCT_PORT1_11 | \
              COM_FUNCT_PORT1_12 | COM_FUNCT_PORT1_13 | COM_FUNCT_PORT1_14 | COM_FUNCT_PORT1_15
#define COM_PINSEL2_old \
              COM_FUNCT_PORT1_0  | COM_FUNCT_PORT1_1  | COM_FUNCT_PORT1_2  | COM_FUNCT_PORT1_3  | \
              COM_FUNCT_PORT1_4  | COM_FUNCT_PORT1_5  | COM_FUNCT_PORT1_6_old  | COM_FUNCT_PORT1_7  | \
              COM_FUNCT_PORT1_8  | COM_FUNCT_PORT1_9  | COM_FUNCT_PORT1_10 | COM_FUNCT_PORT1_11 | \
              COM_FUNCT_PORT1_12 | COM_FUNCT_PORT1_13 | COM_FUNCT_PORT1_14 | COM_FUNCT_PORT1_15
#define COM_PINSEL3 \
              COM_FUNCT_PORT1_16 | COM_FUNCT_PORT1_17 | COM_FUNCT_PORT1_18 | COM_FUNCT_PORT1_19 | \
              COM_FUNCT_PORT1_20 | COM_FUNCT_PORT1_21 | COM_FUNCT_PORT1_22 | COM_FUNCT_PORT1_23 | \
              COM_FUNCT_PORT1_24 | COM_FUNCT_PORT1_25 | COM_FUNCT_PORT1_26 | COM_FUNCT_PORT1_27 | \
              COM_FUNCT_PORT1_28 | COM_FUNCT_PORT1_29 | COM_FUNCT_PORT1_30 | COM_FUNCT_PORT1_31
#define COM_PINSEL4 \
              COM_FUNCT_PORT2_0  | COM_FUNCT_PORT2_1  | COM_FUNCT_PORT2_2  | COM_FUNCT_PORT2_3  | \
              COM_FUNCT_PORT2_4  | COM_FUNCT_PORT2_5  | COM_FUNCT_PORT2_6  | COM_FUNCT_PORT2_7  | \
              COM_FUNCT_PORT2_8  | COM_FUNCT_PORT2_9  | COM_FUNCT_PORT2_10 | COM_FUNCT_PORT2_11 | \
              COM_FUNCT_PORT2_12 | COM_FUNCT_PORT2_13 | COM_FUNCT_PORT2_14 | COM_FUNCT_PORT2_15
#define COM_PINSEL5 \
              BASE_FUNCT_PORT2_16 | BASE_FUNCT_PORT2_17 | BASE_FUNCT_PORT2_18 | BASE_FUNCT_PORT2_19 | \
              BASE_FUNCT_PORT2_20 | BASE_FUNCT_PORT2_21 | BASE_FUNCT_PORT2_22 | BASE_FUNCT_PORT2_23 | \
              BASE_FUNCT_PORT2_24 | BASE_FUNCT_PORT2_25 | BASE_FUNCT_PORT2_26 | BASE_FUNCT_PORT2_27 | \
              BASE_FUNCT_PORT2_28 | BASE_FUNCT_PORT2_29 | BASE_FUNCT_PORT2_30 | BASE_FUNCT_PORT2_31

/* TI-Board Extension settings */
//#define TI_FIO0DIR  (IO_PX_4 | IO_PX_25 | IO_PX_27)
#define TI_FIO0DIR  (IO_PX_4 | IO_PX_27)
// LEDs and Switches
#define TI_FIO1DIR1  (IO_PX_0 | IO_PX_1 | IO_PX_2 | IO_PX_3 | IO_PX_4 | IO_PX_5 | IO_PX_6 | IO_PX_7)
// LCD
#define TI_FIO1DIR2 (IO_PX_16 | IO_PX_17 | IO_PX_18 | IO_PX_19 | IO_PX_20 | IO_PX_21 | IO_PX_22 | IO_PX_27 | IO_PX_28 | IO_PX_29 | IO_PX_30)
#define TI_FIO1DIR  (TI_FIO1DIR1 | TI_FIO1DIR2)
#define TI_FIO2DIR  0
#define TI_FIO3DIR  0
#define TI_FIO4DIR  0
#define TI_PINSEL0 \
              TI_FUNCT_PORT0_0  | TI_FUNCT_PORT0_1  | TI_FUNCT_PORT0_2  | TI_FUNCT_PORT0_3  | \
              TI_FUNCT_PORT0_4  | TI_FUNCT_PORT0_5  | TI_FUNCT_PORT0_6  | TI_FUNCT_PORT0_7  | \
              TI_FUNCT_PORT0_8  | TI_FUNCT_PORT0_9  | TI_FUNCT_PORT0_10 | TI_FUNCT_PORT0_11 | \
              TI_FUNCT_PORT0_12 | TI_FUNCT_PORT0_13 | TI_FUNCT_PORT0_14 | TI_FUNCT_PORT0_15
#define TI_PINSEL1 \
              TI_FUNCT_PORT0_16 | TI_FUNCT_PORT0_17 | TI_FUNCT_PORT0_18 | TI_FUNCT_PORT0_19 | \
              TI_FUNCT_PORT0_20 | TI_FUNCT_PORT0_21 | TI_FUNCT_PORT0_22 | TI_FUNCT_PORT0_23 | \
              TI_FUNCT_PORT0_24 | TI_FUNCT_PORT0_25 | TI_FUNCT_PORT0_26 | TI_FUNCT_PORT0_27 | \
              TI_FUNCT_PORT0_28 | TI_FUNCT_PORT0_29 | TI_FUNCT_PORT0_30 | TI_FUNCT_PORT0_31
#define TI_PINSEL2 \
              TI_FUNCT_PORT1_0  | TI_FUNCT_PORT1_1  | TI_FUNCT_PORT1_2  | TI_FUNCT_PORT1_3  | \
              TI_FUNCT_PORT1_4  | TI_FUNCT_PORT1_5  | TI_FUNCT_PORT1_6  | TI_FUNCT_PORT1_7  | \
              TI_FUNCT_PORT1_8  | TI_FUNCT_PORT1_9  | TI_FUNCT_PORT1_10 | TI_FUNCT_PORT1_11 | \
              TI_FUNCT_PORT1_12 | TI_FUNCT_PORT1_13 | TI_FUNCT_PORT1_14 | TI_FUNCT_PORT1_15
#define TI_PINSEL3 \
              TI_FUNCT_PORT1_16 | TI_FUNCT_PORT1_17 | TI_FUNCT_PORT1_18 | TI_FUNCT_PORT1_19 | \
              TI_FUNCT_PORT1_20 | TI_FUNCT_PORT1_21 | TI_FUNCT_PORT1_22 | TI_FUNCT_PORT1_23 | \
              TI_FUNCT_PORT1_24 | TI_FUNCT_PORT1_25 | TI_FUNCT_PORT1_26 | TI_FUNCT_PORT1_27 | \
              TI_FUNCT_PORT1_28 | TI_FUNCT_PORT1_29 | TI_FUNCT_PORT1_30 | TI_FUNCT_PORT1_31
#define TI_PINSEL4 \
              TI_FUNCT_PORT2_0  | TI_FUNCT_PORT2_1  | TI_FUNCT_PORT2_2  | TI_FUNCT_PORT2_3  | \
              TI_FUNCT_PORT2_4  | TI_FUNCT_PORT2_5  | TI_FUNCT_PORT2_6  | TI_FUNCT_PORT2_7  | \
              TI_FUNCT_PORT2_8  | TI_FUNCT_PORT2_9  | TI_FUNCT_PORT2_10 | TI_FUNCT_PORT2_11 | \
              TI_FUNCT_PORT2_12 | TI_FUNCT_PORT2_13 | TI_FUNCT_PORT2_14 | TI_FUNCT_PORT2_15
#define TI_PINSEL5 \
              BASE_FUNCT_PORT2_16 | BASE_FUNCT_PORT2_17 | BASE_FUNCT_PORT2_18 | BASE_FUNCT_PORT2_19 | \
              BASE_FUNCT_PORT2_20 | BASE_FUNCT_PORT2_21 | BASE_FUNCT_PORT2_22 | BASE_FUNCT_PORT2_23 | \
              BASE_FUNCT_PORT2_24 | BASE_FUNCT_PORT2_25 | BASE_FUNCT_PORT2_26 | BASE_FUNCT_PORT2_27 | \
              BASE_FUNCT_PORT2_28 | BASE_FUNCT_PORT2_29 | BASE_FUNCT_PORT2_30 | BASE_FUNCT_PORT2_31


#define   SWVersion                 0x000000
/* hardware detection */
#define   Ext_None                  0x00
#define   Ext_ComBrd                0x01
#define   Ext_XXBrd                 0x02
#define   Ext_POSBrd                0x03
#define   Ext_PatchBrd              0x04
#define   TI_Board                  0x05
#define   Ext_Unknown               0x10

#define   Thres_Ext_None            0x0050
#define   Thres_Ext_PatchBrd        0x0350
#define   Thres_Ext_POSBrd          0x0250
#define   Thres_TI_Board            0x0150
#define   Thres_Ext_ComBrd          0x00A0

#define  IO_SETPORT    FIO0SET
#define  IO_CLRPORT    FIO0CLR
#define  IO_ON         1<<4
#define  IO_OFF        1<<4
#define  IO_ON2        1<<25
#define  IO_OFF2       1<<25
#define  IO_ON3        1<<27
#define  IO_OFF3       1<<27


void BaseStickConfig(void);
uint32_t ADC_get_channel(uint8_t channel);
void GPIO_Configuration(uint8_t boardtype);
void UART0_Configuration(void);
void UART2_Configuration(void);

#endif

