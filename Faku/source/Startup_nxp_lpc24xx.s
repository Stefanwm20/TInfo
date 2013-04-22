#****************************************************************************
#
#      Project     template for NXP LPC24xx
#      Autor:      Joachim Klein
#      Company:    Hitex Development Tools GmbH
#      Filename:   Startup_nxp_lpc24xx.s
#      Date:       2007-02-27
#
#
#***************************************************************************

# This file provide some special definitions and macros
# which brings advantages with a NXP lpc2xxx device

# Phase Locked Loop (PLL) definitions
        .equ    PLL_BASE,       0xE01FC080  /* PLL Base Address */
        .equ    SCS,	        0xE01FC1A0  /* System Control and Status */
        .equ    PCLKSEL0,       0xE01FC1A8  /* Peripheral Clock Selection register 0 */
        .equ    PCLKSEL1,       0xE01FC1AC  /* Peripheral Clock Selection register 1 */
        .equ    PCON,       	0xE01FC0C0  /* Power Control Register */
        .equ    INTWAKE,       	0xE01FC144  /* Interrupt Wakeup Register */
        .equ    PCONP,       	0xE01FC0C4  /* Power Control for Peripherals Register */
        .equ    CCLKCFG,	    0xE01FC104  /* CPU Clock Fonfiguration	*/
        .equ    USBCLKCFG,		0xE01FC108  /* USB Clock Fonfiguration	*/
        .equ    CLKSRCSEL,		0xE01FC10C  /* Clock Source Select */

        .equ    PLLCON_OFS,     0x00        /* PLL Control Offset 		0xE01FC080 */
        .equ    PLLCFG_OFS,     0x04        /* PLL Configuration Offset 0xE01FC084 */
        .equ    PLLSTAT_OFS,    0x08        /* PLL Status Offset 		0xE01FC088 */
        .equ    PLLFEED_OFS,    0x0C        /* PLL Feed Offset 			0xE01FC08C */


        .equ    PLLCON_PLLE,    (1<<0)      /* PLL Enable 	*/
        .equ    PLLCON_PLLC,    (1<<1)      /* PLL Connect  */
        .equ    PLLCFG_MSEL,    (0x1F<<0)   /* PLL Multiplier */
        .equ    PLLCFG_PSEL,    (0x03<<5)   /* PLL Divider */
        .equ    PLLSTAT_PLOCK,  (1<<26)     /* PLL Lock Status */

        .equ    VICVECT,        0xFFFFF030
        .equ    REMAP_REG,      0xE01FC040      /* remap register */

# Constants for EMC configuration
        .equ    EMC_base,       0xFFE00000
        .equ    WP_Disabled,    0x00000000
        .equ    WP_Enabled,     0x04000000
        .equ    MW_8,           0x00000000
        .equ    MW_16,          0x10000000
        .equ    MW_32,          0x20000000
        .equ    RBLE_Disabled,  0x00000000
        .equ    RBLE_Enabled,   0x00000400
        .equ    PINSEL2,        0xE002C014
        .equ    DBW_None,       0x30
        .equ    DBW_8,          0x00
        .equ    DBW_16,         0x10
        .equ    DBW_32,         0x20
        .equ    CS1_Disabled,   0x0
        .equ    CS1_Enabled,    0x800
        .equ    CS2_Disabled,   0x0
        .equ    CS2_Enabled,    0x4000
        .equ    CS3_Disabled,   0x0
        .equ    CS3_Enabled,    0x10000
        .equ    WE_Disabled,    0x0
        .equ    WE_Enabled,     0x100
        .equ    AL_None,        0x0
        .equ    AL_A3_2,        0x02000000
        .equ    AL_A5_2,        0x04000000
        .equ    AL_A7_2,        0x06000000
        .equ    AL_A11_2,       0x08000000
        .equ    AL_A15_2,       0x0A000000
        .equ    AL_A19_2,       0x0C000000
        .equ    AL_A23_2,       0x0E000000




# ---------------------------------------------
# macro definition for PLL setup
# ---------------------------------------------

                .equ __PLLDIV1, 0x00000000
                .equ __PLLDIV2, 0x00000020
                .equ __PLLDIV4, 0x00000040
                .equ __PLLDIV8, 0x00000060

# use this macro to setup the PLL
                .macro  setup_PLL PLL_M, PLL_P

# Valid parameter values:
#       PLL_M   1-32
#       PLL_P   _PLLDIV1, __PLLDIV2, __PLLDIV4, __PLLDIV8

# Example:      setup_PLL   5, __PLLDIV2

# test parameters and abort if they ar out of range

                LDR     R0, =PLL_BASE
                MOV     R1, #0xAA
                MOV     R2, #0x55

# Configure and Enable PLL
                .equ    PLLCFG_Val,     ((\PLL_P<<16)|(\PLL_M))
#                .equ    PLLCFG_Val,     0x00000024
                LDR     R3, =PLLCFG_Val
                STR     R3, [R0, #PLLCFG_OFS]
                MOV     R3, #PLLCON_PLLE
                STR     R3, [R0, #PLLCON_OFS]
                STR     R1, [R0, #PLLFEED_OFS]
                STR     R2, [R0, #PLLFEED_OFS]

# Wait until PLL Locked
__PLL_Loop:     LDR     R3, [R0, #PLLSTAT_OFS]
                ANDS    R3, R3, #PLLSTAT_PLOCK
                BEQ     __PLL_Loop

# Switch to PLL Clock
                MOV     R3, #(PLLCON_PLLE | PLLCON_PLLC)
                STR     R3, [R0, #PLLCON_OFS]
                STR     R1, [R0, #PLLFEED_OFS]
                STR     R2, [R0, #PLLFEED_OFS]

                .endm

# ---------------------------------------------
# macro definition for VPB divider settings
# ---------------------------------------------

                .equ    VPBDIV,          0xE01FC100  /* VPB divider */

# divider values
                .equ    __VPBDIV_4,      0x00    /* divide by 4 */
                .equ    __VPBDIV_2,      0x02    /* divide by 2 */
                .equ    __VPBDIV_1,      0x01    /* divide by 1 */

                .macro  setup_VPBDIV div_value
                LDR     R0, =VPBDIV
                MOV     R1, #\div_value
                STR     R1, [R0]
                .endm

# ---------------------------------------------
# macro definition for Memory Accelerator module
# ---------------------------------------------

                .equ    MAMCR,          0xE01FC000
                .equ    MAMTIM,         0xE01FC004

# use this constants to define the operating mode
                .equ    __MAM_disabled,       0x00
                .equ    __MAM_partly_enabled, 0x01
                .equ    __MAM_fully_enabled,  0x02

# use a value between 1..7 for the number of clock cycles to read the flash
                .macro  setup_MAM       mam_mode, mam_timing
                LDR     R0, =MAMCR
                MOV     R1, #0
                MOV     R2, #\mam_mode
                MOV     R3, #(\mam_timing&0x07)
                STR     R1, [R0]
                STR     R3, [R0, #4]
                STR     R2, [R0]
                .endm
                
# ---------------------------------------------
# macro definition generic interrupt handler
# ---------------------------------------------
# this macro must be inserted direct behind the interrupt vector
# table. The calculated offset is wrong if other location is changed!
# this handler spand time to have a generic behaviour which can be
# used from C without assembler programming.

                .macro  __generic_interrupt_handler irq_label

###################################################
#
# generic interrupt service handler
#
###################################################

\irq_label:
#save work registers
            stmfd        sp!,{r0-r3,lr}

/* load address from VIC hwile interrupts are disabled */
            LDR          r3, [PC, #-0xFFC]
            mrs          r1,spsr
            stmfd        sp!,{r1}

# switch to system-mode, interrupts enabled
            msr          CPSR_c,#Mode_SYS

#  enter ISR, load from VicVECAddr!!
            stmfd        sp!,{lr}
	        bl __NXP_fetch_irq		/* branch to isr */
            ldmfd        sp!,{lr}

# switch back to IRQ-mode, irq disabled
            msr          CPSR_c,#Mode_IRQ|I_BIT

# reset VIC
            mov          r0,#0x0
            ldr          r1,=VICVECT
            str          r0,[r1,#0x0]

# restore work registers and return to saved operating mode
            ldmfd       sp!,{r1}

            msr         SPSR_csxf,r1
            ldmfd       sp!,{r0-r3,lr}
            subs        pc,lr,#4

# use this fetch to branch to the real isr.
# the fetch must be stored here, becausse of the ofset!
__NXP_fetch_irq:
            mov     pc, r3	   /* Vector from VicVECAddr */

            .endm
