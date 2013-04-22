/*!
 *********************************************************************
 *  File:       peripherals_LPC24xx.h
 *
 *  Project:    startEasy for ARM
 *
 *  Company:    Hitex Development Tools GmbH
 *              Greschbachstr. 12
 *              D-76229 Karlsruhe
 *
 *  Author:     Markus Wenz
 *              Joachim Klein
 *
 *  Created:    18.08.2006
 *
 *  Tools:      GNU cross compiler for ARM v4.0.0
 *
 *********************************************************************/


#ifndef _LPC24XX_H_
#define _LPC24XX_H_

#define REG8                    (volatile unsigned char*)
#define REG16                   (volatile unsigned short*)
#define REG32                   (volatile unsigned int*)

/****************************************************
 * PIN Connect Block
 ****************************************************/

#define PINSEL0                 (*(REG32 0xE002C000))
#define PINSEL1                 (*(REG32 0xE002C004))
#define PINSEL2                 (*(REG32 0xE002C008))
#define PINSEL3                 (*(REG32 0xE002C00C))
#define PINSEL4                 (*(REG32 0xE002C010))
#define PINSEL5                 (*(REG32 0xE002C014))
#define PINSEL6                 (*(REG32 0xE002C018))
#define PINSEL7                 (*(REG32 0xE002C01C))
#define PINSEL8                 (*(REG32 0xE002C020))
#define PINSEL9                 (*(REG32 0xE002C024))
#define PINSEL10                (*(REG32 0xE002C028))

/* each PIN could have up to 4 software selectable functions */
#define PINFUNC1                0x00u
#define PINFUNC2                0x01u
#define PINFUNC3                0x02u
#define PINFUNC4                0x03u

#define PINSEL_Input            0x00000000u
#define PINSEL_Output           0x00000000u
#define PINSEL_Function1        0x00000001u
#define PINSEL_Function2        0x00000002u
#define PINSEL_Function3        0x00000003u

#define IO_PX_0                 0x00000001u
#define IO_PX_1                 0x00000002u
#define IO_PX_2                 0x00000004u
#define IO_PX_3                 0x00000008u
#define IO_PX_4                 0x00000010u
#define IO_PX_5                 0x00000020u
#define IO_PX_6                 0x00000040u
#define IO_PX_7                 0x00000080u
#define IO_PX_8                 0x00000100u
#define IO_PX_9                 0x00000200u
#define IO_PX_10                0x00000400u
#define IO_PX_11                0x00000800u
#define IO_PX_12                0x00001000u
#define IO_PX_13                0x00002000u
#define IO_PX_14                0x00004000u
#define IO_PX_15                0x00008000u
#define IO_PX_16                0x00010000u
#define IO_PX_17                0x00020000u
#define IO_PX_18                0x00040000u
#define IO_PX_19                0x00080000u
#define IO_PX_20                0x00100000u
#define IO_PX_21                0x00200000u
#define IO_PX_22                0x00400000u
#define IO_PX_23                0x00800000u
#define IO_PX_24                0x01000000u
#define IO_PX_25                0x02000000u
#define IO_PX_26                0x04000000u
#define IO_PX_27                0x08000000u
#define IO_PX_28                0x10000000u
#define IO_PX_29                0x20000000u
#define IO_PX_30                0x40000000u
#define IO_PX_31                0x80000000u

/****************************************************
 * Power Control
 ****************************************************/

#define PCON                    (*(REG32 0xE01FC0C0))  /* power control */
#define PCONP                   (*(REG32 0xE01FC0C4))  /* interrupt wake */
#define INTWAKE                 (*(REG32 0xE01FC144))  /* power control for peripherals */

/****************************************************
 * System Controls and Status 
 * included Alfred Lohmann HAW-Hamburg
 ****************************************************/
 
#define SCS            (*(REG32 0xE01FC1A0))
 
/****************************************************
 * Bit masks for Interrupt wake register
 ****************************************************/

#define INTW_EXT0               (0x00000001u << 0)
#define INTW_EXT1               (0x00000001u << 1)
#define INTW_EXT2               (0x00000001u << 2)
#define INTW_EXT3               (0x00000001u << 3)
#define INTW_ETH                (0x00000001u << 4)
#define INTW_USB                (0x00000001u << 5)
#define INTW_CAN                (0x00000001u << 6)
#define INTW_GPIO               (0x00000001u << 7)
#define INTW_BOD                (0x00000001u << 14)
#define INTW_RTC                (0x00000001u << 15)

/****************************************************
 * peripheral Bit masks for peripherals power control
 ****************************************************/

#define PCON_TIM0               0x00000001u
#define PCON_TIM1               0x00000002u
#define PCON_UART0              0x00000004u
#define PCON_UART1              0x00000008u
#define PCON_ENET               0x40000000u

/****************************************************
 * Vectored Interrupt Controller (VIC)
 ****************************************************/

#define VIC_Base                0xFFFFF000

#define VICIRQStatus            (*(REG32 0xFFFFF000))
#define VICFIQStatus            (*(REG32 0xFFFFF004))
#define VICRawIntr              (*(REG32 0xFFFFF008))
#define VICIntSelect            (*(REG32 0xFFFFF00C))
#define VICIntEnable            (*(REG32 0xFFFFF010))
#define VICIntEnClr             (*(REG32 0xFFFFF014))
#define VICSoftInt              (*(REG32 0xFFFFF018))
#define VICSoftIntClr           (*(REG32 0xFFFFF01C))
#define VICProtection           (*(REG32 0xFFFFF020))
#define VICSWPriorityMask       (*(REG32 0xFFFFF024))

#define VICVectAddr             (*(REG32  0xFFFFFF00))

#define VICVectAddr0            (*(REG32  0xFFFFF100))
#define VICVectAddr1            (*(REG32  0xFFFFF104))
#define VICVectAddr2            (*(REG32  0xFFFFF108))
#define VICVectAddr3            (*(REG32  0xFFFFF10C))
#define VICVectAddr4            (*(REG32  0xFFFFF110))
#define VICVectAddr5            (*(REG32  0xFFFFF114))
#define VICVectAddr6            (*(REG32  0xFFFFF118))
#define VICVectAddr7            (*(REG32  0xFFFFF11C))
#define VICVectAddr8            (*(REG32  0xFFFFF120))
#define VICVectAddr9            (*(REG32  0xFFFFF124))
#define VICVectAddr10           (*(REG32  0xFFFFF128))
#define VICVectAddr11           (*(REG32  0xFFFFF12C))
#define VICVectAddr12           (*(REG32  0xFFFFF130))
#define VICVectAddr13           (*(REG32  0xFFFFF134))
#define VICVectAddr14           (*(REG32  0xFFFFF138))
#define VICVectAddr15           (*(REG32  0xFFFFF13C))
#define VICVectAddr16           (*(REG32  0xFFFFF140))
#define VICVectAddr17           (*(REG32  0xFFFFF144))
#define VICVectAddr18           (*(REG32  0xFFFFF148))
#define VICVectAddr19           (*(REG32  0xFFFFF14C))
#define VICVectAddr20           (*(REG32  0xFFFFF150))
#define VICVectAddr21           (*(REG32  0xFFFFF154))
#define VICVectAddr22           (*(REG32  0xFFFFF158))
#define VICVectAddr23           (*(REG32  0xFFFFF15C))
#define VICVectAddr24           (*(REG32  0xFFFFF160))
#define VICVectAddr25           (*(REG32  0xFFFFF164))
#define VICVectAddr26           (*(REG32  0xFFFFF168))
#define VICVectAddr27           (*(REG32  0xFFFFF16C))
#define VICVectAddr28           (*(REG32  0xFFFFF170))
#define VICVectAddr29           (*(REG32  0xFFFFF174))
#define VICVectAddr30           (*(REG32  0xFFFFF178))
#define VICVectAddr31           (*(REG32  0xFFFFF17C))

#define VICVectPriority0        (*(REG32 0xFFFFF200) )
#define VICVectPriority1        (*(REG32 0xFFFFF204))
#define VICVectPriority2        (*(REG32 0xFFFFF208))
#define VICVectPriority3        (*(REG32 0xFFFFF20C))
#define VICVectPriority4        (*(REG32 0xFFFFF210))
#define VICVectPriority5        (*(REG32 0xFFFFF214))
#define VICVectPriority6        (*(REG32 0xFFFFF218))
#define VICVectPriority7        (*(REG32 0xFFFFF21C))
#define VICVectPriority8        (*(REG32 0xFFFFF220))
#define VICVectPriority9        (*(REG32 0xFFFFF224))
#define VICVectPriority10       (*(REG32 0xFFFFF228))
#define VICVectPriority11       (*(REG32 0xFFFFF22C))
#define VICVectPriority12       (*(REG32 0xFFFFF230))
#define VICVectPriority13       (*(REG32 0xFFFFF234))
#define VICVectPriority14       (*(REG32 0xFFFFF238))
#define VICVectPriority15       (*(REG32 0xFFFFF23C))
#define VICVectPriority16       (*(REG32 0xFFFFF240))
#define VICVectPriority17       (*(REG32 0xFFFFF244))
#define VICVectPriority18       (*(REG32 0xFFFFF248))
#define VICVectPriority19       (*(REG32 0xFFFFF24C))
#define VICVectPriority20       (*(REG32 0xFFFFF250))
#define VICVectPriority21       (*(REG32 0xFFFFF254))
#define VICVectPriority22       (*(REG32 0xFFFFF258))
#define VICVectPriority23       (*(REG32 0xFFFFF25C))
#define VICVectPriority24       (*(REG32 0xFFFFF260))
#define VICVectPriority25       (*(REG32 0xFFFFF264))
#define VICVectPriority26       (*(REG32 0xFFFFF268))
#define VICVectPriority27       (*(REG32 0xFFFFF26C))
#define VICVectPriority28       (*(REG32 0xFFFFF270))
#define VICVectPriority29       (*(REG32 0xFFFFF274))
#define VICVectPriority30       (*(REG32 0xFFFFF278))
#define VICVectPriority31       (*(REG32 0xFFFFF27C))
                           
#define VIC_VectAdr             (*(REG32 (0xFFFFFF00) )) /* current VectorAdr */

#define VIC_SOURCE_WDT          0x00000001u
#define VIC_SOURCE_TIMER0       0x00000010u
#define VIC_SOURCE_TIMER1       0x00000020u
#define VIC_SOURCE_UART0        0x00000040u
#define VIC_SOURCE_UART1        0x00000080u
#define VIC_SOURCE_PWM0_1       0x00000100u
#define VIC_SOURCE_I2C0         0x00000200u
#define VIC_SOURCE_SPI0         0x00000400u
#define VIC_SOURCE_SSP1         0x00000800u
#define VIC_SOURCE_PLL          0x00001000u
#define VIC_SOURCE_RTC          0x00002000u
#define VIC_SOURCE_EINT0        0x00004000u
#define VIC_SOURCE_EINT1        0x00008000u
#define VIC_SOURCE_EINT2        0x00010000u
#define VIC_SOURCE_EINT3        0x00020000u
#define VIC_SOURCE_ADC0         0x00040000u
#define VIC_SOURCE_I2C1         0x00080000u
#define VIC_SOURCE_BOD          0x00100000u
#define VIC_SOURCE_Ethernet     0x00200000u
#define VIC_SOURCE_USB          0x00400000u
#define VIC_SOURCE_CAN          0x00800000u
#define VIC_SOURCE_SD_MMC       0x04000000u
#define VIC_SOURCE_DMA          0x08000000u
#define VIC_SOURCE_Timer2       0x10000000u
#define VIC_SOURCE_Timer3       0x20000000u
#define VIC_SOURCE_UART2        0x10000000u
#define VIC_SOURCE_UART3        0x20000000u
#define VIC_SOURCE_I2C2         0x40000000u
#define VIC_SOURCE_I2S          0x80000000u

#define VIC_CHANNEL_WDT         0u
#define VIC_CHANNEL_TIMER0      4u
#define VIC_CHANNEL_TIMER1      5u
#define VIC_CHANNEL_UART0       6u
#define VIC_CHANNEL_UART1       7u
#define VIC_CHANNEL_PWM0        8u
#define VIC_CHANNEL_I2C         9u
#define VIC_CHANNEL_SPI0        10u
#define VIC_CHANNEL_SPI1        11u
#define VIC_CHANNEL_SSP         11u
#define VIC_CHANNEL_PLL         12u
#define VIC_CHANNEL_RTC         13u
#define VIC_CHANNEL_EINT0       14u
#define VIC_CHANNEL_EINT1       15u
#define VIC_CHANNEL_EINT2       16u
#define VIC_CHANNEL_EINT3       17u
#define VIC_CHANNEL_ADC         18u
#define VIC_CHANNEL_AD0         18u
#define VIC_CHANNEL_I2C1        19u
#define VIC_CHANNEL_BOD         20u

#define VIC_CHANNEL_CAN         19u
#define VIC_CHANNEL_CAN1TX      20u
#define VIC_CHANNEL_CAN2TX      21u
#define VIC_CHANNEL_CAN3TX      22u
#define VIC_CHANNEL_CAN4TX      23u
#define VIC_CHANNEL_CAN1RX      26u
#define VIC_CHANNEL_CAN2RX      26u
#define VIC_CHANNEL_CAN3RX      28u
#define VIC_CHANNEL_CAN4RX      29u

#define VIC_CHANNEL_UART2       28u
#define VIC_CHANNEL_UART3       29u

#define VIC_CHANNEL_ENABLED     0x0020u



/****************************************************
 * Ethernet Controller
 ****************************************************/

/* MAC registers */

#define ETH_MAC1                (*(REG32 0xFFE00000))
#define ETH_MAC2                (*(REG32 0xFFE00004))
#define ETH_IPGT                (*(REG32 0xFFE00008))
#define ETH_IPGR                (*(REG32 0xFFE0000C))
#define ETH_CLRT                (*(REG32 0xFFE00010))
#define ETH_MAXF                (*(REG32 0xFFE00014))
#define ETH_PHYSUPP             (*(REG32 0xFFE00018))
#define ETH_TEST                (*(REG32 0xFFE0001C))

/* MII management & config registers */
#define ETH_MIICFG              (*(REG32 0xFFE00020))
#define ETH_MIICMD              (*(REG32 0xFFE00024))
#define ETH_MIIADR              (*(REG32 0xFFE00028))
#define ETH_MIIWTD              (*(REG32 0xFFE0002C))
#define ETH_MIIRDD              (*(REG32 0xFFE00030))
#define ETH_MIIIND              (*(REG32 0xFFE00034))


#define ETH_SA0                 (*(REG32 0xFFE00040))
#define ETH_SA1                 (*(REG32 0xFFE00044))
#define ETH_SA2                 (*(REG32 0xFFE00048))

/****************************************************
 * Control Register
 ****************************************************/

#define ETH_COMMAND             (*(REG32 0xFFE00100))
#define ETH_STATUS              (*(REG32 0xFFE00104))

#define ETH_RXDESC              (*(REG32 0xFFE00108))
#define ETH_RXSTAT              (*(REG32 0xFFE0010C))
#define ETH_RXDESCRNO           (*(REG32 0xFFE00110))
#define ETH_RXPRODIX            (*(REG32 0xFFE00114))
#define ETH_RXCONSIX            (*(REG32 0xFFE00118))

#define ETH_TXDESC              (*(REG32 0xFFE0011C))
#define ETH_TXSTAT              (*(REG32 0xFFE00120))
#define ETH_TXDESCRNO           (*(REG32 0xFFE00124))
#define ETH_TXPRODIX            (*(REG32 0xFFE00128))
#define ETH_TXCONSIX            (*(REG32 0xFFE0012C))

#define ETH_TSV0                (*(REG32 0xFFE00158))
#define ETH_TSV1                (*(REG32 0xFFE0015C))
#define ETH_RSV                 (*(REG32 0xFFE00160))

#define ETH_FLOWCNTCOUNT        (*(REG32 0xFFE00170))
#define ETH_FLOWCNTSTAT	        (*(REG32 0xFFE00174))
/****************************************************
 * Rx Filter registers
 ****************************************************/

#define ETH_RXFILTERCTL         (*(REG32 0xFFE00200))
#define ETH_RXFILTERWOLSTAT     (*(REG32 0xFFE00204))
#define ETH_RXFILTERWOLCLR      (*(REG32 0xFFE00208))

#define ETH_HASHFILTERL         (*(REG32 0xFFE00210))
#define ETH_HASHFILTERH         (*(REG32 0xFFE00214))

/****************************************************
 * module control registers
 ****************************************************/

#define ETH_INSTSTAT            (*(REG32 0xFFE00FE0))
#define ETH_INTENABLE           (*(REG32 0xFFE00FE4))
#define ETH_INTCLEAR            (*(REG32 0xFFE00FE8))
#define ETH_INTSET              (*(REG32 0xFFE00FEC))

#define ETH_POWERDOWN           (*(REG32 0xFFE00FF4))

/****************************************************
 * GPIO - General Purpose I/O
*****************************************************/

#define GPIO0_Base              0xE0028000
#define GPIO1_Base              0xE0028010
#define FIO0_Base               0x3FFFC000
#define FIO1_Base               0x3FFFC020
#define FIO2_Base               0x3FFFC040
#define FIO3_Base               0x3FFFC060
#define FIO4_Base               0x3FFFC080

/****************************************************
 * GPIO Port 0
 ****************************************************/

#define GPIO0_IOPIN             (*(REG32 (GPIO0_Base + 0x00)))
#define GPIO0_IOSET             (*(REG32 (GPIO0_Base + 0x04)))
#define GPIO0_IODIR             (*(REG32 (GPIO0_Base + 0x08)))
#define GPIO0_IOCLR             (*(REG32 (GPIO0_Base + 0x0C)))

#define IOPIN0                  (*(REG32 (GPIO0_Base + 0x00)))
#define IOSET0                  (*(REG32 (GPIO0_Base + 0x04)))
#define IODIR0                  (*(REG32 (GPIO0_Base + 0x08)))
#define IOCLR0                  (*(REG32 (GPIO0_Base + 0x0C)))

/* GPIO Port 1*/
#define GPIO1_IOPIN             (*(REG32 (GPIO1_Base + 0x00)))
#define GPIO1_IOSET             (*(REG32 (GPIO1_Base + 0x04)))
#define GPIO1_IODIR             (*(REG32 (GPIO1_Base + 0x08)))
#define GPIO1_IOCLR             (*(REG32 (GPIO1_Base + 0x0C)))

/* GPIO Port 1*/
#define IOPIN1                  (*(REG32 (GPIO1_Base + 0x00)))
#define IOSET1                  (*(REG32 (GPIO1_Base + 0x04)))
#define IODIR1                  (*(REG32 (GPIO1_Base + 0x08)))
#define IOCLR1                  (*(REG32 (GPIO1_Base + 0x0C)))

/****************************************************
 * Fast access Input/Output (FGPIO0)
 ****************************************************/

#define FIO0DIR                 (*(REG32 (FIO0_Base + 0x00)))
#define FIO0MASK                (*(REG32 (FIO0_Base + 0x10)))
#define FIO0PIN                 (*(REG32 (FIO0_Base + 0x14)))
#define FIO0SET                 (*(REG32 (FIO0_Base + 0x18)))
#define FIO0CLR                 (*(REG32 (FIO0_Base + 0x1C)))

#define FIO0DIR0                (*(REG8  (FIO0_Base + 0x00)))
#define FIO0MASK0               (*(REG8  (FIO0_Base + 0x10)))
#define FIO0PIN0                (*(REG8  (FIO0_Base + 0x14)))
#define FIO0SET0                (*(REG8  (FIO0_Base + 0x18)))
#define FIO0CLR0                (*(REG8  (FIO0_Base + 0x1C)))

#define FIO0DIR1                (*(REG8  (FIO0_Base + 0x01)))
#define FIO0MASK1               (*(REG8  (FIO0_Base + 0x11)))
#define FIO0PIN1                (*(REG8  (FIO0_Base + 0x15)))
#define FIO0SET1                (*(REG8  (FIO0_Base + 0x19)))
#define FIO0CLR1                (*(REG8  (FIO0_Base + 0x1D)))

#define FIO0DIR2                (*(REG8  (FIO0_Base + 0x02)))
#define FIO0MASK2               (*(REG8  (FIO0_Base + 0x12)))
#define FIO0PIN2                (*(REG8  (FIO0_Base + 0x16)))
#define FIO0SET2                (*(REG8  (FIO0_Base + 0x1A)))
#define FIO0CLR2                (*(REG8  (FIO0_Base + 0x1E)))

#define FIO0DIR3                (*(REG8  (FIO0_Base + 0x03)))
#define FIO0MASK3               (*(REG8  (FIO0_Base + 0x13)))
#define FIO0PIN3                (*(REG8  (FIO0_Base + 0x17)))
#define FIO0SET3                (*(REG8  (FIO0_Base + 0x1B)))
#define FIO0CLR3                (*(REG8  (FIO0_Base + 0x1F)))

#define FIO0DIRL                (*(REG16 (FIO0_Base + 0x00)))
#define FIO0MASKL               (*(REG16 (FIO0_Base + 0x10)))
#define FIO0PINL                (*(REG16 (FIO0_Base + 0x14)))
#define FIO0SETL                (*(REG16 (FIO0_Base + 0x18)))
#define FIO0CLRL                (*(REG16 (FIO0_Base + 0x1C)))

#define FIO0DIRU                (*(REG16 (FIO0_Base + 0x02)))
#define FIO0MASKU               (*(REG16 (FIO0_Base + 0x12)))
#define FIO0PINU                (*(REG16 (FIO0_Base + 0x16)))
#define FIO0SETU                (*(REG16 (FIO0_Base + 0x1A)))
#define FIO0CLRU                (*(REG16 (FIO0_Base + 0x1E)))

/****************************************************
 * Fast access Input/Output (FGPIO1)
 ****************************************************/

#define FIO1DIR                 (*(REG32 (FIO1_Base + 0x00)))
#define FIO1MASK                (*(REG32 (FIO1_Base + 0x10)))
#define FIO1PIN                 (*(REG32 (FIO1_Base + 0x14)))
#define FIO1SET                 (*(REG32 (FIO1_Base + 0x18)))
#define FIO1CLR                 (*(REG32 (FIO1_Base + 0x1C)))

#define FIO1DIR0                (*(REG8  (FIO1_Base + 0x00)))
#define FIO1MASK0               (*(REG8  (FIO1_Base + 0x10)))
#define FIO1PIN0                (*(REG8  (FIO1_Base + 0x14)))
#define FIO1SET0                (*(REG8  (FIO1_Base + 0x18)))
#define FIO1CLR0                (*(REG8  (FIO1_Base + 0x1C)))

#define FIO1DIR1                (*(REG8  (FIO1_Base + 0x01)))
#define FIO1MASK1               (*(REG8  (FIO1_Base + 0x11)))
#define FIO1PIN1                (*(REG8  (FIO1_Base + 0x15)))
#define FIO1SET1                (*(REG8  (FIO1_Base + 0x19)))
#define FIO1CLR1                (*(REG8  (FIO1_Base + 0x1D)))

#define FIO1DIR2                (*(REG8  (FIO1_Base + 0x02)))
#define FIO1MASK2               (*(REG8  (FIO1_Base + 0x12)))
#define FIO1PIN2                (*(REG8  (FIO1_Base + 0x16)))
#define FIO1SET2                (*(REG8  (FIO1_Base + 0x1A)))
#define FIO1CLR2                (*(REG8  (FIO1_Base + 0x1E)))

#define FIO1DIR3                (*(REG8  (FIO1_Base + 0x03)))
#define FIO1MASK3               (*(REG8  (FIO1_Base + 0x13)))
#define FIO1PIN3                (*(REG8  (FIO1_Base + 0x17)))
#define FIO1SET3                (*(REG8  (FIO1_Base + 0x1B)))
#define FIO1CLR3                (*(REG8  (FIO1_Base + 0x1F)))

#define FIO1DIRL                (*(REG16 (FIO1_Base + 0x00)))
#define FIO1MASKL               (*(REG16 (FIO1_Base + 0x10)))
#define FIO1PINL                (*(REG16 (FIO1_Base + 0x14)))
#define FIO1SETL                (*(REG16 (FIO1_Base + 0x18)))
#define FIO1CLRL                (*(REG16 (FIO1_Base + 0x1C)))

#define FIO1DIRU                (*(REG16 (FIO1_Base + 0x02)))
#define FIO1MASKU               (*(REG16 (FIO1_Base + 0x12)))
#define FIO1PINU                (*(REG16 (FIO1_Base + 0x16)))
#define FIO1SETU                (*(REG16 (FIO1_Base + 0x1A)))
#define FIO1CLRU                (*(REG16 (FIO1_Base + 0x1E)))

/****************************************************
 * Fast access Input/Output (FGPIO2)
 ****************************************************/

#define FIO2DIR                 (*(REG32 (FIO2_Base + 0x00)))
#define FIO2MASK                (*(REG32 (FIO2_Base + 0x10)))
#define FIO2PIN                 (*(REG32 (FIO2_Base + 0x14)))
#define FIO2SET                 (*(REG32 (FIO2_Base + 0x18)))
#define FIO2CLR                 (*(REG32 (FIO2_Base + 0x1C)))

#define FIO2DIR0                (*(REG8  (FIO2_Base + 0x00)))
#define FIO2MASK0               (*(REG8  (FIO2_Base + 0x10)))
#define FIO2PIN0                (*(REG8  (FIO2_Base + 0x14)))
#define FIO2SET0                (*(REG8  (FIO2_Base + 0x18)))
#define FIO2CLR0                (*(REG8  (FIO2_Base + 0x1C)))

#define FIO2DIR1                (*(REG8  (FIO2_Base + 0x01)))
#define FIO2MASK1               (*(REG8  (FIO2_Base + 0x11)))
#define FIO2PIN1                (*(REG8  (FIO2_Base + 0x15)))
#define FIO2SET1                (*(REG8  (FIO2_Base + 0x19)))
#define FIO2CLR1                (*(REG8  (FIO2_Base + 0x1D)))

#define FIO2DIR2                (*(REG8  (FIO2_Base + 0x02)))
#define FIO2MASK2               (*(REG8  (FIO2_Base + 0x12)))
#define FIO2PIN2                (*(REG8  (FIO2_Base + 0x16)))
#define FIO2SET2                (*(REG8  (FIO2_Base + 0x1A)))
#define FIO2CLR2                (*(REG8  (FIO2_Base + 0x1E)))

#define FIO2DIR3                (*(REG8  (FIO2_Base + 0x03)))
#define FIO2MASK3               (*(REG8  (FIO2_Base + 0x13)))
#define FIO2PIN3                (*(REG8  (FIO2_Base + 0x17)))
#define FIO2SET3                (*(REG8  (FIO2_Base + 0x1B)))
#define FIO2CLR3                (*(REG8  (FIO2_Base + 0x1F)))

#define FIO2DIRL                (*(REG16 (FIO2_Base + 0x00)))
#define FIO2MASKL               (*(REG16 (FIO2_Base + 0x10)))
#define FIO2PINL                (*(REG16 (FIO2_Base + 0x14)))
#define FIO2SETL                (*(REG16 (FIO2_Base + 0x18)))
#define FIO2CLRL                (*(REG16 (FIO2_Base + 0x1C)))

#define FIO2DIRU                (*(REG16 (FIO2_Base + 0x02)))
#define FIO2MASKU               (*(REG16 (FIO2_Base + 0x12)))
#define FIO2PINU                (*(REG16 (FIO2_Base + 0x16)))
#define FIO2SETU                (*(REG16 (FIO2_Base + 0x1A)))
#define FIO2CLRU                (*(REG16 (FIO2_Base + 0x1E)))

/****************************************************
 * Fast access Input/Output (FGPIO3)
 ****************************************************/

#define FIO3DIR                 (*(REG32 (FIO3_Base + 0x00)))
#define FIO3MASK                (*(REG32 (FIO3_Base + 0x10)))
#define FIO3PIN                 (*(REG32 (FIO3_Base + 0x14)))
#define FIO3SET                 (*(REG32 (FIO3_Base + 0x18)))
#define FIO3CLR                 (*(REG32 (FIO3_Base + 0x1C)))

#define FIO3DIR0                (*(REG8  (FIO3_Base + 0x00)))
#define FIO3MASK0               (*(REG8  (FIO3_Base + 0x10)))
#define FIO3PIN0                (*(REG8  (FIO3_Base + 0x14)))
#define FIO3SET0                (*(REG8  (FIO3_Base + 0x18)))
#define FIO3CLR0                (*(REG8  (FIO3_Base + 0x1C)))

#define FIO3DIR1                (*(REG8  (FIO3_Base + 0x01)))
#define FIO3MASK1               (*(REG8  (FIO3_Base + 0x11)))
#define FIO3PIN1                (*(REG8  (FIO3_Base + 0x15)))
#define FIO3SET1                (*(REG8  (FIO3_Base + 0x19)))
#define FIO3CLR1                (*(REG8  (FIO3_Base + 0x1D)))

#define FIO3DIR2                (*(REG8  (FIO3_Base + 0x02)))
#define FIO3MASK2               (*(REG8  (FIO3_Base + 0x12)))
#define FIO3PIN2                (*(REG8  (FIO3_Base + 0x16)))
#define FIO3SET2                (*(REG8  (FIO3_Base + 0x1A)))
#define FIO3CLR2                (*(REG8  (FIO3_Base + 0x1E)))

#define FIO3DIR3                (*(REG8  (FIO3_Base + 0x03)))
#define FIO3MASK3               (*(REG8  (FIO3_Base + 0x13)))
#define FIO3PIN3                (*(REG8  (FIO3_Base + 0x17)))
#define FIO3SET3                (*(REG8  (FIO3_Base + 0x1B)))
#define FIO3CLR3                (*(REG8  (FIO3_Base + 0x1F)))

#define FIO3DIRL                (*(REG16 (FIO3_Base + 0x00)))
#define FIO3MASKL               (*(REG16 (FIO3_Base + 0x10)))
#define FIO3PINL                (*(REG16 (FIO3_Base + 0x14)))
#define FIO3SETL                (*(REG16 (FIO3_Base + 0x18)))
#define FIO3CLRL                (*(REG16 (FIO3_Base + 0x1C)))

#define FIO3DIRU                (*(REG16 (FIO3_Base + 0x02)))
#define FIO3MASKU               (*(REG16 (FIO3_Base + 0x12)))
#define FIO3PINU                (*(REG16 (FIO3_Base + 0x16)))
#define FIO3SETU                (*(REG16 (FIO3_Base + 0x1A)))
#define FIO3CLRU                (*(REG16 (FIO3_Base + 0x1E)))

/****************************************************
 * Fast access Input/Output (FGPIO4)
 ****************************************************/
 
#define FIO4DIR                 (*(REG32 (FIO4_Base + 0x00)))
#define FIO4MASK                (*(REG32 (FIO4_Base + 0x10)))
#define FIO4PIN                 (*(REG32 (FIO4_Base + 0x14)))
#define FIO4SET                 (*(REG32 (FIO4_Base + 0x18)))
#define FIO4CLR                 (*(REG32 (FIO4_Base + 0x1C)))

#define FIO4DIR0                (*(REG8  (FIO4_Base + 0x00)))
#define FIO4MASK0               (*(REG8  (FIO4_Base + 0x10)))
#define FIO4PIN0                (*(REG8  (FIO4_Base + 0x14)))
#define FIO4SET0                (*(REG8  (FIO4_Base + 0x18)))
#define FIO4CLR0                (*(REG8  (FIO4_Base + 0x1C)))

#define FIO4DIR1                (*(REG8  (FIO4_Base + 0x01)))
#define FIO4MASK1               (*(REG8  (FIO4_Base + 0x11)))
#define FIO4PIN1                (*(REG8  (FIO4_Base + 0x15)))
#define FIO4SET1                (*(REG8  (FIO4_Base + 0x19)))
#define FIO4CLR1                (*(REG8  (FIO4_Base + 0x1D)))

#define FIO4DIR2                (*(REG8  (FIO4_Base + 0x02)))
#define FIO4MASK2               (*(REG8  (FIO4_Base + 0x12)))
#define FIO4PIN2                (*(REG8  (FIO4_Base + 0x16)))
#define FIO4SET2                (*(REG8  (FIO4_Base + 0x1A)))
#define FIO4CLR2                (*(REG8  (FIO4_Base + 0x1E)))

#define FIO4DIR3                (*(REG8  (FIO4_Base + 0x03)))
#define FIO4MASK3               (*(REG8  (FIO4_Base + 0x13)))
#define FIO4PIN3                (*(REG8  (FIO4_Base + 0x17)))
#define FIO4SET3                (*(REG8  (FIO4_Base + 0x1B)))
#define FIO4CLR3                (*(REG8  (FIO4_Base + 0x1F)))

#define FIO4DIRL                (*(REG16 (FIO4_Base + 0x00)))
#define FIO4MASKL               (*(REG16 (FIO4_Base + 0x10)))
#define FIO4PINL                (*(REG16 (FIO4_Base + 0x14)))
#define FIO4SETL                (*(REG16 (FIO4_Base + 0x18)))
#define FIO4CLRL                (*(REG16 (FIO4_Base + 0x1C)))

#define FIO4DIRU                (*(REG16 (FIO4_Base + 0x02)))
#define FIO4MASKU               (*(REG16 (FIO4_Base + 0x12)))
#define FIO4PINU                (*(REG16 (FIO4_Base + 0x16)))
#define FIO4SETU                (*(REG16 (FIO4_Base + 0x1A)))
#define FIO4CLRU                (*(REG16 (FIO4_Base + 0x1E)))

/******************************************************
*GPIO Interrupts
**************************************************/
#define P00ER                    (*(REG32 0xE0028090))
#define P02ER                    (*(REG32 0xE00280B0))
#define P00EF                    (*(REG32 0xE0028094))
#define P02EF                    (*(REG32 0xE002B400))
#define P00REI                   (*(REG32 0xE0028084))
#define P02REI                   (*(REG32 0xE00280A4))
#define P00CI                    (*(REG32 0xE002808C))
#define P02CI                    (*(REG32 0xE00280AC))

/****************************************************
 * Memory Accelerator Module (MAM) 
 ****************************************************/
 
#define MAMCR                   (*(REG8  0xE01FC000))
#define MAMTIM                  (*(REG8  0xE01FC004))
#define MAMMAP                  (*(REG8  0xE01FC040))

/****************************************************
 * Phase Locked Loop (PLL)
 ****************************************************/

#define PLLCON                   (*(REG32  0xE01FC080))
#define PLLCFG                   (*(REG32  0xE01FC084))
#define PLLSTAT                  (*(REG32 0xE01FC088))
#define PLLFEED                  (*(REG8  0xE01FC08C))
#define CCLKCFG                  (*(REG32 0xE01FC104))
#define USBCLKCFG                (*(REG32 0xE01FC108))
#define SCS                      (*(REG32 0xE01FC1A0))
#define CLKSRCSEL                (*(REG32 0xE01FC10C))
/****************************************************
 * VPB Divider
 ****************************************************/

#define VPBDIV                  (*(REG8  0xE01FC100))

/* Clock Divider */
// #define APBDIV         (*(volatile unsigned long *)(SCB_BASE_ADDR + 0x100))
#define PCLKSEL0       (*(REG32 0xE01FC1A8))
#define PCLKSEL1       (*(REG32 0xE01FC1AC))

/****************************************************
 * External Interrupts
 ****************************************************/

#define EXTINT                  (*(REG8  0xE01FC140))
#define EXTWAKE                 (*(REG8  0xE01FC144))
#define EXTMODE                 (*(REG8  0xE01FC148))
#define EXTPOLAR                (*(REG8  0xE01FC14C))

/****************************************************
 * Timer 0
 ****************************************************/

#define TIMER0_IR               (*(REG32 0xE0004000))
#define TIMER0_TCR              (*(REG32 0xE0004004))
#define TIMER0_TC               (*(REG32 0xE0004008))
#define TIMER0_PR               (*(REG32 0xE000400C))
#define TIMER0_PC               (*(REG32 0xE0004010))
#define TIMER0_MCR              (*(REG32 0xE0004014))
#define TIMER0_MR0              (*(REG32 0xE0004018))
#define TIMER0_MR1              (*(REG32 0xE000401C))
#define TIMER0_MR2              (*(REG32 0xE0004020))
#define TIMER0_MR3              (*(REG32 0xE0004024))
#define TIMER0_CCR              (*(REG32 0xE0004028))
#define TIMER0_CR0              (*(REG32 0xE000402C))
#define TIMER0_CR1              (*(REG32 0xE0004030))
#define TIMER0_CR2              (*(REG32 0xE0004034))
#define TIMER0_CR3              (*(REG32 0xE0004038))
#define TIMER0_EMR              (*(REG32 0xE000403C))

/****************************************************
 * Timer 1
 ****************************************************/

#define TIMER1_IR               (*(REG32 0xE0008000))
#define TIMER1_TCR              (*(REG32 0xE0008004))
#define TIMER1_TC               (*(REG32 0xE0008008))
#define TIMER1_PR               (*(REG32 0xE000800C))
#define TIMER1_PC               (*(REG32 0xE0008010))
#define TIMER1_MCR              (*(REG32 0xE0008014))
#define TIMER1_MR0              (*(REG32 0xE0008018))
#define TIMER1_MR1              (*(REG32 0xE000801C))
#define TIMER1_MR2              (*(REG32 0xE0008020))
#define TIMER1_MR3              (*(REG32 0xE0008024))
#define TIMER1_CCR              (*(REG32 0xE0008028))
#define TIMER1_CR0              (*(REG32 0xE000802C))
#define TIMER1_CR1              (*(REG32 0xE0008030))
#define TIMER1_CR2              (*(REG32 0xE0008034))
#define TIMER1_CR3              (*(REG32 0xE0008038))
#define TIMER1_EMR              (*(REG32 0xE000803C))

/****************************************************
 * Timer 2 
 ****************************************************/

#define TIMER2_IR               (*(REG32 0xE0070000))
#define TIMER2_TCR              (*(REG32 0xE0070004))
#define TIMER2_TC               (*(REG32 0xE0070008))
#define TIMER2_PR               (*(REG32 0xE007000C))
#define TIMER2_PC               (*(REG32 0xE0070010))
#define TIMER2_MCR              (*(REG32 0xE0070014))
#define TIMER2_MR0              (*(REG32 0xE0070018))
#define TIMER2_MR1              (*(REG32 0xE007001C))
#define TIMER2_MR2              (*(REG32 0xE0070020))
#define TIMER2_MR3              (*(REG32 0xE0070024))
#define TIMER2_CCR              (*(REG32 0xE0070028))
#define TIMER2_CR0              (*(REG32 0xE007002C))
#define TIMER2_CR1              (*(REG32 0xE0070030))
#define TIMER2_CR2              (*(REG32 0xE0070034))
#define TIMER2_CR3              (*(REG32 0xE0070038))
#define TIMER2_EMR              (*(REG32 0xE007003C))

/****************************************************
 * Timer 3
 ****************************************************/

#define TIMER3_IR               (*(REG32 0xE0074000))
#define TIMER3_TCR              (*(REG32 0xE0074004))
#define TIMER3_TC               (*(REG32 0xE0074008))
#define TIMER3_PR               (*(REG32 0xE007400C))
#define TIMER3_PC               (*(REG32 0xE0074010))
#define TIMER3_MCR              (*(REG32 0xE0074014))
#define TIMER3_MR0              (*(REG32 0xE0074018))
#define TIMER3_MR1              (*(REG32 0xE007401C))
#define TIMER3_MR2              (*(REG32 0xE0074020))
#define TIMER3_MR3              (*(REG32 0xE0074024))
#define TIMER3_CCR              (*(REG32 0xE0074028))
#define TIMER3_CR0              (*(REG32 0xE007402C))
#define TIMER3_CR1              (*(REG32 0xE0074030))
#define TIMER3_CR2              (*(REG32 0xE0074034))
#define TIMER3_CR3              (*(REG32 0xE0074038))
#define TIMER3_EMR              (*(REG32 0xE007403C))

#define TIMER_MCR_INTERRUPT     0x01u
#define TIMER_MCR_RESTART       0x02u
#define TIMER_MCR_STOP          0x04u

#define TIMER_EMR_EM0           0x01u
#define TIMER_EMR_EM1           0x02u
#define TIMER_EMR_EM2           0x04u
#define TIMER_EMR_EM3           0x08u

#define TIMER_EMR_CLEAR         0x10u
#define TIMER_EMR_SET           0x20u
#define TIMER_EMR_TOGGLE        0x30u

/****************************************************
 * Pulse Width Modulator (PWM0)
 ****************************************************/

#define PWM0_IR                  (*(REG32 0xE0014000))
#define PWM0_TCR                 (*(REG32 0xE0014004))
#define PWM0_TC                  (*(REG32 0xE0014008))
#define PWM0_PR                  (*(REG32 0xE001400C))
#define PWM0_PC                  (*(REG32 0xE0014010))
#define PWM0_MCR                 (*(REG32 0xE0014014))
#define PWM0_MR0                 (*(REG32 0xE0014018))
#define PWM0_MR1                 (*(REG32 0xE001401C))
#define PWM0_MR2                 (*(REG32 0xE0014020))
#define PWM0_MR3                 (*(REG32 0xE0014024))
#define PWM0_MR4                 (*(REG32 0xE0014040))
#define PWM0_MR5                 (*(REG32 0xE0014044))
#define PWM0_MR6                 (*(REG32 0xE0014048))
#define PWM0_CCR                 (*(REG32 0xE0014028))
#define PWM0_CR0                 (*(REG32 0xE001402C))
#define PWM0_CR1                 (*(REG32 0xE0014030))
#define PWM0_CR2                 (*(REG32 0xE0014034))
#define PWM0_CR3                 (*(REG32 0xE0014038))
#define PWM0_EMR                 (*(REG32 0xE001403C))
#define PWM0_PCR                 (*(REG32 0xE001404C))
#define PWM0_LER                 (*(REG32 0xE0014050))

/****************************************************
 * Pulse Width Modulator (PWM1)
 ****************************************************/

#define PWM1_IR                  (*(REG32 0xE0018000))
#define PWM1_TCR                 (*(REG32 0xE0018004))
#define PWM1_TC                  (*(REG32 0xE0018008))
#define PWM1_PR                  (*(REG32 0xE001800C))
#define PWM1_PC                  (*(REG32 0xE0018010))
#define PWM1_MCR                 (*(REG32 0xE0018014))
#define PWM1_MR0                 (*(REG32 0xE0018018))
#define PWM1_MR1                 (*(REG32 0xE001801C))
#define PWM1_MR2                 (*(REG32 0xE0018020))
#define PWM1_MR3                 (*(REG32 0xE0018024))
#define PWM1_MR4                 (*(REG32 0xE0018040))
#define PWM1_MR5                 (*(REG32 0xE0018044))
#define PWM1_MR6                 (*(REG32 0xE0018048))
#define PWM1_CCR                 (*(REG32 0xE0018028))
#define PWM1_CR0                 (*(REG32 0xE001802C))
#define PWM1_CR1                 (*(REG32 0xE0018030))
#define PWM1_CR2                 (*(REG32 0xE0018034))
#define PWM1_CR3                 (*(REG32 0xE0018038))
#define PWM1_EMR                 (*(REG32 0xE001803C))
#define PWM1_PCR                 (*(REG32 0xE001804C))
#define PWM1_LER                 (*(REG32 0xE0018050))

/****************************************************
 * Universal Asynchronous Receiver
 * Transmitter 0 (UART0)
 ****************************************************/

#define UART0_RBR               (*(REG8  0xE000C000))
#define UART0_THR               (*(REG8  0xE000C000))
#define UART0_IER               (*(REG8  0xE000C004))
#define UART0_IIR               (*(REG8  0xE000C008))
#define UART0_FCR               (*(REG8  0xE000C008))
#define UART0_LCR               (*(REG8  0xE000C00C))
#define UART0_MCR               (*(REG8  0xE000C010))
#define UART0_LSR               (*(REG8  0xE000C014))
#define UART0_MSR               (*(REG8  0xE000C018))
#define UART0_SCR               (*(REG8  0xE000C01C))
#define UART0_DLL               (*(REG8  0xE000C000))
#define UART0_DLM               (*(REG8  0xE000C004))
#define UART0_FDR               (*(REG8  0xE000C028))

/****************************************************
 * Universal Asynchronous Receiver
 * Transmitter 2 (UART0)
 ****************************************************/

#define UART2_RBR               (*(REG8  0xE0078000))
#define UART2_THR               (*(REG8  0xE0078000))
#define UART2_IER               (*(REG8  0xE0078004))
#define UART2_IIR               (*(REG8  0xE0078008))
#define UART2_FCR               (*(REG8  0xE0078008))
#define UART2_LCR               (*(REG8  0xE007800C))
#define UART2_MCR               (*(REG8  0xE0078010))
#define UART2_LSR               (*(REG8  0xE0078014))
#define UART2_MSR               (*(REG8  0xE0078018))
#define UART2_SCR               (*(REG8  0xE007801C))
#define UART2_DLL               (*(REG8  0xE0078000))
#define UART2_DLM               (*(REG8  0xE0078004))
#define UART2_FDR               (*(REG8  0xE0078028))

/****************************************************
 * Universal Asynchronous Receiver
 * Transmitter 3 (UART0)
 ****************************************************/

#define UART3_RBR               (*(REG8  0xE007C000))
#define UART3_THR               (*(REG8  0xE007C000))
#define UART3_IER               (*(REG8  0xE007C004))
#define UART3_IIR               (*(REG8  0xE007C008))
#define UART3_FCR               (*(REG8  0xE007C008))
#define UART3_LCR               (*(REG8  0xE007C00C))
#define UART3_MCR               (*(REG8  0xE007C010))
#define UART3_LSR               (*(REG8  0xE007C014))
#define UART3_MSR               (*(REG8  0xE007C018))
#define UART3_SCR               (*(REG8  0xE007C01C))
#define UART3_DLL               (*(REG8  0xE007C000))
#define UART3_DLM               (*(REG8  0xE007C004))

/****************************************************
 * FCR : Function Control Register
 ****************************************************/

#define USART_FIFO_ENABLE       0x0001u
#define USART_RX_RESET          0x0002u
#define USART_TX_RESET          0x0004u
#define USART_RX_TRIGGER_1      0x0000u
#define USART_RX_TRIGGER_4      0x0040u
#define USART_RX_TRIGGER_8      0x0080u
#define USART_RX_TRIGGER_14     0x00C0u

/****************************************************
 * LSR : Line Status Register
 ****************************************************/

#define USART_LSR_RDR           0x0001u
#define USART_LSR_BI            0x0010u
#define USART_LSR_THRE          0x0020u
#define USART_LSR_TEMT          0x0040u
#define USART_LSR_RXFE          0x0080u

/****************************************************
 * IER : Interrupt Enable Register
 ****************************************************/

#define USART_IER_RX_DATA       0x0001u
#define USART_IER_THRE          0x0002u
#define USART_IER_RX_STATUS     0x0004u
#define USART_IER_ALL           0x0007u

/****************************************************
 * LCR : Line Control Register
 ****************************************************/
 
#define USART_WORD_LENGTH5      0x0000u
#define USART_WORD_LENGTH6      0x0001u
#define USART_WORD_LENGTH7      0x0002u
#define USART_WORD_LENGTH8      0x0003u

#define USART_STOP_BIT_1        0x0000u
#define USART_STOP_BIT_1_5      0x0004u
#define USART_STOP_BIT_2        0x0004u

#define USART_PARITY_None       0x0000u
#define USART_PARITY_ENABLED    0x0008u

#define USART_PARITY_Odd        0x0008u
#define USART_PARITY_Even       0x0018u
#define USART_PARITY_Mark       0x0028u
#define USART_PARITY_Space      0x0038u

#define USART_DIVISOR_LATCH_DISABLED  0x0000u
#define USART_DIVISOR_LATCH_ENABLED   0x0080u

/****************************************************
 * Universal Asynchronous Receiver 
 * Transmitter 1 (UART1) 
 ****************************************************/ 
 
#define UART1_RBR               (*(REG8  0xE0010000))
#define UART1_THR               (*(REG8  0xE0010000))
#define UART1_IER               (*(REG8  0xE0010004))
#define UART1_IIR               (*(REG8  0xE0010008))
#define UART1_FCR               (*(REG8  0xE0010008))
#define UART1_LCR               (*(REG8  0xE001000C))
#define UART1_MCR               (*(REG8  0xE0010010))
#define UART1_LSR               (*(REG8  0xE0010014))
#define UART1_MSR               (*(REG8  0xE0010018))
#define UART1_SCR               (*(REG8  0xE001001C))
#define UART1_DLL               (*(REG8  0xE0010000))
#define UART1_DLM               (*(REG8  0xE0010004))

/****************************************************
 * DAC converter (LPC213x only)
 ****************************************************/ 
 
#define DACR                    (*((REG32 0xE006C000)))
#define DAC_BIAS                0x8000u

/****************************************************
 * I2C Interface 
 ****************************************************/ 

#define I2C_I2CONSET            (*(REG8  0xE001C000))
#define I2C_I2STAT              (*(REG8  0xE001C004))
#define I2C_I2DAT               (*(REG8  0xE001C008))
#define I2C_I2ADR               (*(REG8  0xE001C00C))
#define I2C_I2SCLH              (*(REG16 0xE001C010))
#define I2C_I2SCLL              (*(REG16 0xE001C014))
#define I2C_I2CONCLR            (*(REG8  0xE001C018))

/****************************************************
 * SPI0 (Serial Peripheral Interface 0) 
 ****************************************************/ 

#define SPI0_SPCR               (*(REG8  0xE0020000))
#define SPI0_SPSR               (*(REG8  0xE0020004))
#define SPI0_SPDR               (*(REG8  0xE0020008))
#define SPI0_SPCCR              (*(REG8  0xE002000C))
#define SPI0_SPTCR              (*(REG8  0xE0020010))
#define SPI0_SPTSR              (*(REG8  0xE0020014))
#define SPI0_SPTOR              (*(REG8  0xE0020018))
#define SPI0_SPINT              (*(REG8  0xE002001C))

/****************************************************
 * SPI1 (Serial Peripheral Interface 1) 
 ****************************************************/ 
 
#define SPI1_SPCR               (*(REG8  0xE0030000))
#define SPI1_SPSR               (*(REG8  0xE0030004))
#define SPI1_SPDR               (*(REG8  0xE0030008))
#define SPI1_SPCCR              (*(REG8  0xE003000C))
#define SPI1_SPTCR              (*(REG8  0xE0030010))
#define SPI1_SPTSR              (*(REG8  0xE0030014))
#define SPI1_SPTOR              (*(REG8  0xE0030018))
#define SPI1_SPINT              (*(REG8  0xE003001C))

/****************************************************
 * Real Time Clock 
 ****************************************************/ 

#define RTC_ILR                 (*(REG8  0xE0024000))
#define RTC_CTC                 (*(REG16 0xE0024004))
#define RTC_CCR                 (*(REG8  0xE0024008))
#define RTC_CIIR                (*(REG8  0xE002400C))
#define RTC_AMR                 (*(REG8  0xE0024010))
#define RTC_CTIME0              (*(REG32 0xE0024014))
#define RTC_CTIME1              (*(REG32 0xE0024018))
#define RTC_CTIME2              (*(REG32 0xE002401C))
#define RTC_SEC                 (*(REG8  0xE0024020))
#define RTC_MIN                 (*(REG8  0xE0024024))
#define RTC_HOUR                (*(REG8  0xE0024028))
#define RTC_DOM                 (*(REG8  0xE002402C))
#define RTC_DOW                 (*(REG8  0xE0024030))
#define RTC_DOY                 (*(REG16 0xE0024034))
#define RTC_MON                 (*(REG8  0xE0024038))
#define RTC_YEAR                (*(REG16 0xE002403C))
#define RTC_ALSEC               (*(REG8  0xE0024060))
#define RTC_ALMIN               (*(REG8  0xE0024064))
#define RTC_ALHOUR              (*(REG8  0xE0024068))
#define RTC_ALDOM               (*(REG8  0xE002406C))
#define RTC_ALDOW               (*(REG8  0xE0024070))
#define RTC_ALDOY               (*(REG16 0xE0024074))
#define RTC_ALMON               (*(REG8  0xE0024078))
#define RTC_ALYEAR              (*(REG16 0xE002407C))
#define RTC_PREINT              (*(REG16 0xE0024080))
#define RTC_PREFRAC             (*(REG16 0xE0024084))

#define RTC_BIT_SEC             0x0001u
#define RTC_BIT_MIN             0x0002u
#define RTC_BIT_HOUR            0x0004u
#define RTC_BIT_DOM             0x0008u
#define RTC_BIT_DOW             0x0010u
#define RTC_BIT_DOY             0x0020u
#define RTC_BIT_MON             0x0040u
#define RTC_BIT_YEAR            0x0080u

/****************************************************
 * A/D Converter 
 ****************************************************/ 
#define AD0CR                    (*(REG32 0xE0034000))
#define AD0DR                    (*(REG32 0xE0034004))
#define ADC_DONE                 0x80000000u

/****************************************************
 * Watchdog 
 ****************************************************/

#define WDMOD                   (*(REG8  0xE0000000))
#define WDTC                    (*(REG32 0xE0000004))
#define WDFEED                  (*(REG8  0xE0000008))
#define WDTV                    (*(REG32 0xE000000C))

/****************************************************
 * external memory controllerr (EMC)
 ****************************************************/

#define EMCControl              (*(REG32 0xFFE08000))
#define EMCStatus               (*(REG32 0xFFE08004))
#define EMCConfig               (*(REG32 0xFFE08008))
#define EMCDynamicControl       (*(REG32 0xFFE08020))
#define EMCDynamicRefresh       (*(REG32 0xFFE08024))
#define EMCDynamicReadConfig    (*(REG32 0xFFE08028))
#define EMCDynamicRP            (*(REG32 0xFFE08030))
#define EMCDynamicRAS           (*(REG32 0xFFE08034))
#define EMCDynamicSREX          (*(REG32 0xFFE08038))
#define EMCDynamicAPR           (*(REG32 0xFFE0803C))
#define EMCDynamicDAL           (*(REG32 0xFFE08040))
#define EMCDynamicWR            (*(REG32 0xFFE08044))
#define EMCDynamicRC            (*(REG32 0xFFE08048))
#define EMCDynamicRFC           (*(REG32 0xFFE0804C))
#define EMCDynamicXSR           (*(REG32 0xFFE08050))
#define EMCDynamicRRD           (*(REG32 0xFFE08054))
#define EMCDynamicMRD           (*(REG32 0xFFE08058))
#define EMCDynamicConfig0       (*(REG32 0xFFE08100))
#define EMCDynamicRasCas0       (*(REG32 0xFFE08104))
#define EMCDynamicConfig1       (*(REG32 0xFFE08120))
#define EMCDynamicRasCas1       (*(REG32 0xFFE08124))
#define EMCDynamicConfig2       (*(REG32 0xFFE08140))
#define EMCDynamicRasCas2       (*(REG32 0xFFE08144))
#define EMCDynamicConfig3       (*(REG32 0xFFE08160))
#define EMCDynamicRasCas3       (*(REG32 0xFFE08164))
#define EMCStaticConfig0        (*(REG32 0xFFE08200))
#define EMCStaticWaitWen0       (*(REG32 0xFFE08204))
#define EMCStaticWaitOen0       (*(REG32 0xFFE08208))
#define EMCStaticWaitRd0        (*(REG32 0xFFE0820C))
#define EMCStaticWaitPage0      (*(REG32 0xFFE08210))
#define EMCStaticWaitWr0        (*(REG32 0xFFE08214))
#define EMCStaticWaitTurn0      (*(REG32 0xFFE08218))
#define EMCStaticConfig1        (*(REG32 0xFFE08220))
#define EMCStaticWaitWen1       (*(REG32 0xFFE08224))
#define EMCStaticWaitOen1       (*(REG32 0xFFE08228))
#define EMCStaticWaitRd1        (*(REG32 0xFFE0822C))
#define EMCStaticWaitPage1      (*(REG32 0xFFE08230))
#define EMCStaticWaitWr1        (*(REG32 0xFFE08234))
#define EMCStaticWaitTurn1      (*(REG32 0xFFE08238))
#define EMCStaticConfig2        (*(REG32 0xFFE08240))
#define EMCStaticWaitWen2       (*(REG32 0xFFE08244))
#define EMCStaticWaitOen2       (*(REG32 0xFFE08248))
#define EMCStaticWaitRd2        (*(REG32 0xFFE0824C))
#define EMCStaticWaitPage2      (*(REG32 0xFFE08250))
#define EMCStaticWaitWr2        (*(REG32 0xFFE08254))
#define EMCStaticWaitTurn2      (*(REG32 0xFFE08258))
#define EMCStaticConfig3        (*(REG32 0xFFE08260))
#define EMCStaticWaitWen3       (*(REG32 0xFFE08264))
#define EMCStaticWaitOen3       (*(REG32 0xFFE08268))
#define EMCStaticWaitRd3        (*(REG32 0xFFE0826C))
#define EMCStaticWaitPage3      (*(REG32 0xFFE08270))
#define EMCStaticWaitWr3        (*(REG32 0xFFE08274))
#define EMCStaticWaitTurn3      (*(REG32 0xFFE08278))
#define EMCStaticExtendedWait   (*(REG32 0xFFE08880))

/* CAN CONTROLLERS AND ACCEPTANCE FILTER */
#define CAN_ACCEPT_BASE_ADDR		0xE003C000
#define CAN_AFMR	            (*(REG32 0xE003C000))
#define CAN_SFF_SA 		        (*(REG32 0xE003C004))
#define CAN_SFF_GRP_SA 	        (*(REG32 0xE003C008))
#define CAN_EFF_SA 		        (*(REG32 0xE003C00C))
#define CAN_EFF_GRP_SA 	        (*(REG32 0xE003C010))
#define CAN_EOT 		        (*(REG32 0xE003C014))
#define CAN_LUT_ERR_ADR         (*(REG32 0xE003C018))
#define CAN_LUT_ERR 	        (*(REG32 0xE003C01C))


#define CAN_CENTRAL_BASE_ADDR		0xE0040000  	
#define CAN_TX_SR 	            (*(REG32 0xE0040000))
#define CAN_RX_SR 	            (*(REG32 0xE0040004))
#define CAN_MSR 	            (*(REG32 0xE0040008))


#define CAN1_BASE_ADDR		0xE0044000
#define CAN1MOD 	(*(volatile unsigned long *)(CAN1_BASE_ADDR + 0x00))  	
#define CAN1CMR 	(*(volatile unsigned long *)(CAN1_BASE_ADDR + 0x04))  	
#define CAN1GSR 	(*(volatile unsigned long *)(CAN1_BASE_ADDR + 0x08))  	
#define CAN1ICR 	(*(volatile unsigned long *)(CAN1_BASE_ADDR + 0x0C))  	
#define CAN1IER 	(*(volatile unsigned long *)(CAN1_BASE_ADDR + 0x10))
#define CAN1BTR 	(*(volatile unsigned long *)(CAN1_BASE_ADDR + 0x14))  	
#define CAN1EWL 	(*(volatile unsigned long *)(CAN1_BASE_ADDR + 0x18))  	
#define CAN1SR 		(*(volatile unsigned long *)(CAN1_BASE_ADDR + 0x1C))  	
#define CAN1RFS 	(*(volatile unsigned long *)(CAN1_BASE_ADDR + 0x20))  	
#define CAN1RID 	(*(volatile unsigned long *)(CAN1_BASE_ADDR + 0x24))
#define CAN1RDA 	(*(volatile unsigned long *)(CAN1_BASE_ADDR + 0x28))  	
#define CAN1RDB 	(*(volatile unsigned long *)(CAN1_BASE_ADDR + 0x2C))

#define CAN1_MOD 	               (*(REG32 0xE0044000))
#define CAN1_CMR 	               (*(REG32 0xE0044004))
#define CAN1_GSR 	               (*(REG32 0xE0044008))
#define CAN1_ICR 	               (*(REG32 0xE004400C))
#define CAN1_IER 	               (*(REG32 0xE0044010))
#define CAN1_BTR 	               (*(REG32 0xE0044014))
#define CAN1_EWL 	               (*(REG32 0xE0044018))
#define CAN1_SR 	               (*(REG32 0xE004401C))
#define CAN1_RFS 	               (*(REG32 0xE0044020))
#define CAN1_RID 	               (*(REG32 0xE0044024))
#define CAN1_RDA 	               (*(REG32 0xE0044028))
#define CAN1_RDB 	               (*(REG32 0xE004402C))

/*-----------*/
  	
#define CAN1TFI1 	(*(volatile unsigned long *)(CAN1_BASE_ADDR + 0x30))  	
#define CAN1TID1 	(*(volatile unsigned long *)(CAN1_BASE_ADDR + 0x34))  	
#define CAN1TDA1 	(*(volatile unsigned long *)(CAN1_BASE_ADDR + 0x38))
#define CAN1TDB1 	(*(volatile unsigned long *)(CAN1_BASE_ADDR + 0x3C))  	
#define CAN1TFI2 	(*(volatile unsigned long *)(CAN1_BASE_ADDR + 0x40))  	
#define CAN1TID2 	(*(volatile unsigned long *)(CAN1_BASE_ADDR + 0x44))  	
#define CAN1TDA2 	(*(volatile unsigned long *)(CAN1_BASE_ADDR + 0x48))  	
#define CAN1TDB2 	(*(volatile unsigned long *)(CAN1_BASE_ADDR + 0x4C))
#define CAN1TFI3 	(*(volatile unsigned long *)(CAN1_BASE_ADDR + 0x50))  	
#define CAN1TID3 	(*(volatile unsigned long *)(CAN1_BASE_ADDR + 0x54))  	
#define CAN1TDA3 	(*(volatile unsigned long *)(CAN1_BASE_ADDR + 0x58))  	
#define CAN1TDB3 	(*(volatile unsigned long *)(CAN1_BASE_ADDR + 0x5C))

#define CAN1_TFI1 	            (*(REG32 0xE0044030))
#define CAN1_TID1 	            (*(REG32 0xE0044034))
#define CAN1_TDA1 	            (*(REG32 0xE0044038))
#define CAN1_TDB1 	            (*(REG32 0xE004403C))
#define CAN1_TFI2 	            (*(REG32 0xE0044040))
#define CAN1_TID2 	            (*(REG32 0xE0044044))
#define CAN1_TDA2 	            (*(REG32 0xE0044048))
#define CAN1_TDB2 	            (*(REG32 0xE004404C))
#define CAN1_TFI3 	            (*(REG32 0xE0044050))
#define CAN1_TID3 	            (*(REG32 0xE0044054))
#define CAN1_TDA3 	            (*(REG32 0xE0044058))
#define CAN1_TDB3 	            (*(REG32 0xE004405C))

/*-----------*/

#define CAN2_BASE_ADDR		0xE0048000
#define CAN2MOD 	(*(volatile unsigned long *)(CAN2_BASE_ADDR + 0x00))  	
#define CAN2CMR 	(*(volatile unsigned long *)(CAN2_BASE_ADDR + 0x04))  	
#define CAN2GSR 	(*(volatile unsigned long *)(CAN2_BASE_ADDR + 0x08))  	
#define CAN2ICR 	(*(volatile unsigned long *)(CAN2_BASE_ADDR + 0x0C))  	
#define CAN2IER 	(*(volatile unsigned long *)(CAN2_BASE_ADDR + 0x10))
#define CAN2BTR 	(*(volatile unsigned long *)(CAN2_BASE_ADDR + 0x14))  	
#define CAN2EWL 	(*(volatile unsigned long *)(CAN2_BASE_ADDR + 0x18))  	
#define CAN2SR 		(*(volatile unsigned long *)(CAN2_BASE_ADDR + 0x1C))  	
#define CAN2RFS 	(*(volatile unsigned long *)(CAN2_BASE_ADDR + 0x20))  	
#define CAN2RID 	(*(volatile unsigned long *)(CAN2_BASE_ADDR + 0x24))
#define CAN2RDA 	(*(volatile unsigned long *)(CAN2_BASE_ADDR + 0x28))  	
#define CAN2RDB 	(*(volatile unsigned long *)(CAN2_BASE_ADDR + 0x2C))
  	
#define CAN2TFI1 	(*(volatile unsigned long *)(CAN2_BASE_ADDR + 0x30))  	
#define CAN2TID1 	(*(volatile unsigned long *)(CAN2_BASE_ADDR + 0x34))  	
#define CAN2TDA1 	(*(volatile unsigned long *)(CAN2_BASE_ADDR + 0x38))
#define CAN2TDB1 	(*(volatile unsigned long *)(CAN2_BASE_ADDR + 0x3C))  	
#define CAN2TFI2 	(*(volatile unsigned long *)(CAN2_BASE_ADDR + 0x40))  	
#define CAN2TID2 	(*(volatile unsigned long *)(CAN2_BASE_ADDR + 0x44))  	
#define CAN2TDA2 	(*(volatile unsigned long *)(CAN2_BASE_ADDR + 0x48))  	
#define CAN2TDB2 	(*(volatile unsigned long *)(CAN2_BASE_ADDR + 0x4C))
#define CAN2TFI3 	(*(volatile unsigned long *)(CAN2_BASE_ADDR + 0x50))  	
#define CAN2TID3 	(*(volatile unsigned long *)(CAN2_BASE_ADDR + 0x54))  	
#define CAN2TDA3 	(*(volatile unsigned long *)(CAN2_BASE_ADDR + 0x58))  	
#define CAN2TDB3 	(*(volatile unsigned long *)(CAN2_BASE_ADDR + 0x5C))

/*DMA Controller */
#define GPDMA_INT_STAT           (*(REG32 0xFFE04000))
#define GPDMA_INT_TCSTAT         (*(REG32 0xFFE04004))
#define GPDMA_INT_TCCLR          (*(REG32 0xFFE04008))
#define GPDMA_INT_ERR_STAT       (*(REG32 0xFFE0400C))
#define GPDMA_INT_ERR_CLR        (*(REG32 0xFFE04010))
#define GPDMA_RAW_INT_TCSTAT     (*(REG32 0xFFE04014))
#define GPDMA_RAW_INT_ERR_STAT   (*(REG32 0xFFE04018))
#define GPDMA_ENABLED_CHNS       (*(REG32 0xFFE0401C))
#define GPDMA_SOFT_BREQ          (*(REG32 0xFFE04020))
#define GPDMA_SOFT_SREQ          (*(REG32 0xFFE04024))
#define GPDMA_SOFT_LBREQ         (*(REG32 0xFFE04028))
#define GPDMA_SOFT_LSREQ         (*(REG32 0xFFE0402C))
#define GPDMA_CONFIG             (*(REG32 0xFFE04030))
#define GPDMA_SYNC               (*(REG32 0xFFE04034))

#define GPDMA_CH0_SRC            (*(REG32 0xFFE04100))
#define GPDMA_CH0_DEST           (*(REG32 0xFFE04104))
#define GPDMA_CH0_LLI            (*(REG32 0xFFE04108))
#define GPDMA_CH0_CTRL           (*(REG32 0xFFE0410C))
#define GPDMA_CH0_CFG            (*(REG32 0xFFE04110))


#endif  /* _LPC24xx_H */
