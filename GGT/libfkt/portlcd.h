/*****************************************************************************
 *   portlcd.h:  Header file for NXP LPC23xx/24xx Family Microprocessors
 *
 *   Copyright(C) 2006, NXP Semiconductor
 *   All rights reserved.
 *
 *   History
 *   2006.09.20  ver 1.00    Prelimnary version, first Release
 *                           used with Keil MCB2300 board
 *
 *   2008.06.19  ver 1.00    Version for NXP LPC-Stick (Hitex)
 *                           and TI-expansion board
 *                           Alfred Lohmann  HAW-Hamburg   
 *
******************************************************************************/
#ifndef __PORTLCD_H 
#define __PORTLCD_H

//#define USE_FIO		1

#if USE_FIO
#define IO0DIR    FIO0DIR
#define IO0SET    FIO0SET
#define IO0CLR    FIO0CLR
#define IO0PIN    FIO0PIN
#define IO1DIR    FIO1DIR
#define IO1SET    FIO1SET
#define IO1CLR    FIO1CLR
#define IO1PIN    FIO1PIN
#else
#define IO0DIR    IODIR0
#define IO0SET    IOSET0
#define IO0CLR    IOCLR0
#define IO0PIN    IOPIN0
#define IO1DIR    IODIR1
#define IO1SET    IOSET1
#define IO1CLR    IOCLR1
#define IO1PIN    IOPIN1
#endif

//-- on the LPC-Stick TI-Board the LCD-Display is connected as follows
//-- 
//--   22  21  20  |  19  18  17  16 |
//--    |   |   |      ------------ 
//--    |   |   |         DATA
//--    |   |   ------ RS
//--    |   ---------- RW
//--    -------------- E
//--
//-- the backlightswitch is connected to Port 0.31
//--

/* LCD IO definitions */
#define LCD_E     0x00400000            /* Enable control pin                */
#define LCD_RW    0x00200000            /* Read/Write control pin            */
#define LCD_RS    0x00100000            /* Data/Instruction control          */
#define LCD_CTRL  0x00700000            /* Control lines mask                */
#define LCD_DATA  0x000F0000            /* Data lines mask                   */
#define LCD_BACKLIGHT 0x80000000        /* LCD backlight switch              */

#define LCD_DATA_POSITION  16           /* shift to used data bits           */
#define LCD_STATUS_MSB     12           /* shift data to MSB                 */
#define LCD_STATUS_LSB     16           /* shift data to LSB                 */

extern void LCD_init(void);
extern void LCD_load(char *fp, unsigned long cnt);
extern void LCD_gotoxy(unsigned long x, unsigned long y);
extern void LCD_cls(void);
extern void LCD_cur_off(void);
extern void LCD_on(void);
extern void LCD_putc(char c);
extern void LCD_puts(char *sp);
extern void LCD_bargraph(unsigned long val, unsigned long size);

/* Local Function Prototypes */
extern void lcd_delay( unsigned long cnt );
extern void lcd_write( unsigned long c );
extern void lcd_write_4bit( unsigned long c );
extern unsigned long lcd_read_stat( void );
extern void lcd_write_cmd( unsigned long c );
extern void lcd_write_data( unsigned long d );
extern void lcd_wait_busy( void );

#endif /* end __PORTLCD_H */
/*****************************************************************************
**                            End Of File
******************************************************************************/
