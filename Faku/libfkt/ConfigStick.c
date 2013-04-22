/********************************************************************
 * Project:    LPC-Stick
 * File:       ConfigStick.c
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
 * This file is part of the GNU Example "Demo".
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
 *                                   HAW-Hamburg  TI-Labor
 *    Changed setup to support the TI-Expansion Board
 *    at HAW-Hamburg. 
 *    In config.h the devices used are declared.
 *    UART0 and UART2 are fixed initialized to 19200,8,N,1
 *    The TI-Board is NOT detected automatically.
 *
 *    Revision 1.2    9.07.2008      Alfred Lohmann
 *                                   HAW-Hamburg  TI-Labor
 *    The TI-Board is detected automatically and configured
 *
 *    Revision 1.3    11.07.2008     Alfred Lohmann
 *                                   HAW-Hamburg  TI-Labor
 *    The baudrate for UART0 and UART2 is set fixed to 115200 baud
 *
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

//#include "defines.h"
#include "lpc24xx.h"
#include "ConfigStick.h"
#include "config.h"
#include "target_info.h"
#include "portlcd.h"

void uart0Init(uint32_t baud, uint8_t mode, uint8_t fmode);
void uart2Init(uint32_t baud, uint8_t mode, uint8_t fmode);
unsigned enableIRQ(void);

#define MAC_BASE_ADDR       0xFFE00000
#define MAC_MODULEID        (*(volatile unsigned long *)(MAC_BASE_ADDR + 0xFFC)) /* Module ID reg (RO) */
#define OLD_EMAC_MODULE_ID  ((0x3902 << 16) | 0x2000)
/* bit 0 in SCS register, port 0/1 are regular ports when bit 0 
is 0,  fast ports when bit 0 is 1. */
#define GPIOM                          0x00000001

uint32_t Setup_Data = 0;

void Peripheral_Clock_Configuration(void)
{
   //-- full clock rate is desired to select 115200 baud
   PCLKSEL0 |= (uint32_t)0x00040; /* full speed UART0 */
   PCLKSEL1 |= (uint32_t)0x10000; /* full speed UART2 */
}

void Power_Configuration(void)
{
//-- must be enabled , used by CheckHardware()
    PCONP |= (1u<<12);  /* enable ADC */

#ifdef TIMER2_SUPPORT    
    PCONP |= (1u<<22);  /*enable Timer2*/
#endif
#ifdef TIMER3_SUPPORT    
    PCONP |= (1u<<23);  /*enable Timer3*/
#endif
#ifdef UART2_SUPPORT    
    PCONP |= (1u<<24);  /*enable UART2*/
#endif
#ifdef CAN_SUPPORT    
    PCONP |= (1u<<13);  /*enable CAN1*/
#endif    
}

void GPIO_Configuration(uint8_t boardtype)
{
   uint32_t Com_PinSelection2 = COM_PINSEL2;
   uint32_t regVal;
   PCONP |= PCON_ENET;
   /* !!! this causes a setup failure
          MAC_MODULEID is not read correctly */

   regVal = MAC_MODULEID;
   if ( regVal == OLD_EMAC_MODULE_ID )
      Com_PinSelection2 = COM_PINSEL2_old;
      /* P1.6, ETHERNET-TX_CLK, has to be set for ethernet module to address a BUG in
         the engineering
         version, even if this pin is not used for RMII interface. This bug has been fixed,
         and this port pin can be used as GPIO pin in the future release.
         Unfortunately, this MCB2300 board still has the old eng. version LPC23xx chip
         on it. */
   PCONP &= ~PCON_ENET;
   /* external Memory interface : this is obligatory */
   PINSEL6 = MEM_PINSEL6;
   PINSEL7 = MEM_PINSEL7;
   PINSEL8 = MEM_PINSEL8;
   PINSEL9 = MEM_PINSEL9;
   switch (boardtype) {
    case Ext_None : /* base configuration */
               /* setup basic configuration */
               GPIO0_IODIR = Base_FIO0DIR; /* see ConfigStick.h changed due to LPC bug */
               GPIO1_IODIR = Base_FIO1DIR; /* see ConfigStick.h changed due to LPC bug*/
               FIO2DIR = Base_FIO2DIR; /* see ConfigStick.h */
               FIO3DIR = Base_FIO3DIR; /* see ConfigStick.h */
               FIO4DIR = Base_FIO4DIR; /* see ConfigStick.h */
               PINSEL0 = Base_PINSEL0; /* see ConfigStick.h */
               PINSEL1 = Base_PINSEL1; /* see ConfigStick.h */
               PINSEL2 = Base_PINSEL2; /* see ConfigStick.h */
               PINSEL3 = Base_PINSEL3; /* see ConfigStick.h */
               PINSEL4 = Base_PINSEL4; /* see ConfigStick.h */
               PINSEL5 = Base_PINSEL5; /* see ConfigStick.h */
               break;
    case Ext_ComBrd :  /* Comboard extension */
               GPIO0_IODIR = COM_FIO0DIR; /* see ConfigStick.h changed due to LPC bug */
               GPIO1_IODIR = COM_FIO1DIR; /* see ConfigStick.h changed due to LPC bug*/
               FIO2DIR = COM_FIO2DIR; /* see ConfigStick.h */
               FIO3DIR = COM_FIO3DIR; /* see ConfigStick.h */
               FIO4DIR = COM_FIO4DIR; /* see ConfigStick.h */
               PINSEL0 = COM_PINSEL0; /* see ConfigStick.h */
               PINSEL1 = COM_PINSEL1; /* see ConfigStick.h */
               PINSEL2 = Com_PinSelection2; /* see ConfigStick.h */
               PINSEL3 = COM_PINSEL3; /* see ConfigStick.h */
               PINSEL4 = COM_PINSEL4; /* see ConfigStick.h */
               PINSEL5 = COM_PINSEL5; /* see ConfigStick.h */
               break;
    case TI_Board:           /* TI-Board used for GT */
               //SCS |= GPIOM; /* set GPIOx to use Fast I/O */
               PINSEL0 = TI_PINSEL0; /* see ConfigStick.h */
               PINSEL1 = TI_PINSEL1; /* see ConfigStick.h */
               PINSEL2 = TI_PINSEL2; /* see ConfigStick.h */
               PINSEL3 = TI_PINSEL3; /* see ConfigStick.h */
               PINSEL4 = TI_PINSEL4; /* see ConfigStick.h */
               PINSEL5 = TI_PINSEL5; /* see ConfigStick.h */
               GPIO0_IODIR = TI_FIO0DIR; /* see ConfigStick.h changed due to LPC bug */
               GPIO1_IODIR = TI_FIO1DIR; /* see ConfigStick.h changed due to LPC bug*/
               FIO2DIR = TI_FIO2DIR; /* see ConfigStick.h */
               FIO3DIR = TI_FIO3DIR; /* see ConfigStick.h */
               FIO4DIR = TI_FIO4DIR; /* see ConfigStick.h */
               
               break;   
    case Ext_XXBrd :         /* future extension */
    case Ext_POSBrd :        /* POS board extension */
    case Ext_PatchBrd :      /* Patchboard extension */
    case Ext_Unknown :       /* unknown extension */
    default :
               /* setup basic configuration */
               GPIO0_IODIR = Base_FIO0DIR; /* see ConfigStick.h changed due to LPC bug */
               GPIO1_IODIR = Base_FIO1DIR; /* see ConfigStick.h changed due to LPC bug*/
               FIO2DIR = Base_FIO2DIR; /* see ConfigStick.h */
               FIO3DIR = Base_FIO3DIR; /* see ConfigStick.h */
               FIO4DIR = Base_FIO4DIR; /* see ConfigStick.h */
               PINSEL0 = Base_PINSEL0; /* see ConfigStick.h */
               PINSEL1 = Base_PINSEL1; /* see ConfigStick.h */
               PINSEL2 = Base_PINSEL2; /* see ConfigStick.h */
               PINSEL3 = Base_PINSEL3; /* see ConfigStick.h */
               PINSEL4 = Base_PINSEL4; /* see ConfigStick.h */
               PINSEL5 = Base_PINSEL5; /* see ConfigStick.h */
               break;
   }
}



void WDT_Configuration(void)
{
   WDMOD |= 0x0; /*Watchdog Timer as Counter*/


}

#define ADC_CLK			4000000		  /* set to 4.5 Mhz */

uint32_t ADC_get_channel(uint8_t channel)
{
    unsigned int help;
    static unsigned int pclk=0;
    
    if (pclk == 0){
        pclk = GetPclk();
    }
   
    AD0CR = ( 0x01 << channel ) |  /* SEL=1,select channel 0~7 on ADC0 */
 		    ( ( pclk / ADC_CLK - 1 ) << 8 ) |  /* CLKDIV = Fpclk / 1000000 - 1 */ 
		    ( 0 << 16 ) | 		   /* BURST = 0, no BURST, software controlled */
		    ( 0 << 17 ) |  		   /* CLKS = 0, 11 clocks/10 bits */
		    ( 1 << 21 ) |  		   /* PDN = 1, normal operation */
		    ( 0 << 22 ) |  		   /* TEST1:0 = 00 */
		    ( 0 << 24 ) |  		   /* START = 0 A/D conversion stops */
		    ( 0 << 27 );		   /* EDGE = 0 (CAP/MAT singal falling,trigger A/D conversion) */ 

   
   AD0CR |= (1 << 24);             /* Start the game */          
   help = AD0DR;
   while (!(help & ADC_DONE))
      {help = AD0DR;;}
   return (AD0DR&0xFFC0)>>6;
}

void Check_Hardware(void)
{
   uint16_t i = 0;

//   i = Get_ADC(6);
   /* !!! ADC reading of the board resistors failes */
   i = ADC_get_channel(6);
   if (i < Thres_Ext_None)
      Setup_Data = Ext_None;
   else if (i > Thres_Ext_PatchBrd)
      Setup_Data = Ext_PatchBrd;
   else if (i > Thres_Ext_POSBrd)
      Setup_Data = Ext_POSBrd;
   else if (i > Thres_TI_Board)   
      Setup_Data = TI_Board;
   else if (i > Thres_Ext_ComBrd)
       Setup_Data = Ext_ComBrd;
   else
      Setup_Data = Ext_Unknown;
   // Setup_Data = Ext_ComBrd; // test only
   GPIO_Configuration((uint8_t)Setup_Data);
}



void BaseStickConfig(void)
{
   Power_Configuration();
   Peripheral_Clock_Configuration();
   GPIO_Configuration(Ext_None);
   Check_Hardware();
#ifdef UART0_SUPPORT   
  uart0Init(115200, 1, 1);
  enableIRQ();
#endif
#ifdef UART2_SUPPORT   
  uart2Init(115200, 1, 1);
  enableIRQ();
#endif   
#ifdef LCD_SUPPORT 
    LCD_init();
#endif    
  
   IO_CLRPORT = IO_OFF3;
   IO_SETPORT = IO_ON2;
   IO_CLRPORT = IO_OFF; /* red LED off */
}

