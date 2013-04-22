# ***************************************************************************
#
#      Project     easy1
#      Autor:      Alfred Lohmann
#      Company:    HAW-Hamburg
#      Filename:   startup.s
#      Date:       2008-07-22
#      Auto generated Code with
#      startEasy for ARM
#
#
# ***************************************************************************

# ---------------------------------------------
# Include startup macros
# ---------------------------------------------
                .include "source//startup_generic.s"
                .include "source//Startup_nxp_lpc24xx.s"

# ---------------------------------------------
# Application specific constants
# ---------------------------------------------

# Stack definitions
# size in words!
                .equ    UND_Stack_Size , 8
                .equ    SVC_Stack_Size , 1024
                .equ    ABT_Stack_Size , 8
                .equ    FIQ_Stack_Size , 8
                .equ    IRQ_Stack_Size , 512
 
# ---------------------------------------------
# Hardware specific constants
# ---------------------------------------------

# Checksum, to avoid calling the bootloader after reset
# must be adjusted by user!
                .equ    CheckSum , 0xB9205F88

# ---------------------------------------------
# Import external symbols
# ---------------------------------------------

# reference to main
                .extern main

# reference to linker symbols
                .extern __data_start__
                .extern __data_end__
                .extern __bss_start__
                .extern __bss_end__
                .extern __bss2_start__
                .extern __bss2_end__


# reference to external interrupt handlers
            
                .extern SWI_Handler
                .extern PAbt_Handler
                .extern DAbt_Handler
                .extern Undef_Handler
                .extern FIQ_Handler

# ---------------------------------------------
# export global symbols
# ---------------------------------------------

                .global ResetEntry
                .global _startup
                .global Start_init_s
                .global start

# ---------------------------------------------
# Start of Code
# ---------------------------------------------

                .text
                .arm
                .func   _startup
_startup:
# ---------------------------------------------
# Interrupt vector table at address 0
# ---------------------------------------------
Reset_Vec:      LDR     PC, _ResetEntry
                LDR     PC, _Undef_Addr
                LDR     PC, _SWI_Addr
                LDR     PC, _PAbt_Addr
                LDR     PC, _DAbt_Addr
                .word   CheckSum                		   /* Reserved Vector */
                LDR     PC, [PC,#-0x120]
                LDR     PC, _FIQ_Addr           /* Calling the FIQ handler */

# ---------------------------------------------

_ResetEntry:     .word   ResetEntry
_Undef_Addr:     .word   Undef_Handler
_SWI_Addr:       .word   SWI_Handler
_PAbt_Addr:      .word   PAbt_Handler
_DAbt_Addr:      .word   DAbt_Handler
_FIQ_Addr:       .word   FIQ_Handler

# ---------------------------------------------
# From here HardReset and SoftReset executes
# the same code
# ---------------------------------------------
ResetEntry:
                StartupDelay 20000
Start_init_s:
start:
# ---------------------------------------------
# Micro controller specific code
# Execute only in real HW
# Real HW is detected thru boot rom code
# ---------------------------------------------

				.equ BootRomAdr,0x7ffffff0
				
				ldr r0,=BootRomAdr
				ldr r0,[r0]
				teq r0,#0
				beq SkipControllerSpecificCode

                RegWrite PCLKSEL0, ( 0 | ( 1<<6 ) )
                RegWrite PCLKSEL1, ( 0 | ( 1<<16 ) )
                setup_MAM      __MAM_partly_enabled, 3
                # Clock Source: Main Oszillator 4.000 MHz, use Port 0 and Port 1 as Fast IO.
                RegWrite    SCS, 0x20
                # Wait for external oscillator ready
                RegWait     SCS, 0x40
                # Connect to oscillator
                RegWrite    CLKSRCSEL, 1

                RegWrite	CCLKCFG, 5
                RegWrite	USBCLKCFG, 5
                setup_PLL	71, 1

SkipControllerSpecificCode:
# ---------------------------------------------
# Setup stacks for the operating modes
# ---------------------------------------------

                setup_stack  UND_Stack, UND_Stack_Size, #Mode_UND|I_BIT|F_BIT
                setup_stack  ABT_Stack, ABT_Stack_Size, #Mode_ABT|I_BIT|F_BIT
                setup_stack  FIQ_Stack, FIQ_Stack_Size, #Mode_FIQ|I_BIT|F_BIT
                setup_stack  IRQ_Stack, IRQ_Stack_Size, #Mode_IRQ|I_BIT|F_BIT
                setup_stack  SVC_Stack, SVC_Stack_Size, #Mode_SVC|I_BIT|F_BIT

#  Setup a default Stack Limit (when compiled with -mapcs-stack-check)
                SUB     SL, SP, #SVC_Stack_Size


# enable interrupts
                mrs r1, CPSR
                bic r1, r1, #0x80
                msr CPSR, r1

# ---------------------------------------------
# copy sections
# ---------------------------------------------

            copy_section2 data, _etext, __data_start__, _edata

# ---------------------------------------------
# Micro controller specific code
# ---------------------------------------------



# ---------------------------------------------
# Clear .bss section
# ---------------------------------------------

                clear_section bss, __bss_start__, __bss_end__
                clear_section bss2, __bss2_start__, __bss2_end__

# ---------------------------------------------
# Enter the C code
# ---------------------------------------------

##-- changed for possible return() in main()
##-- else the behavior would be unpredictable
##-- Alfred Lomann   HAW-Hamburg
# Enter the C code
				mov		r0, #0
				mov		r1, #0        
	    		BL      main
	    
##-- should nver return here, but in case we have an
##-- we have an endless loop
.Lloop:
				B		.Lloop

# ---------------------------------------------
# Table with data
# ---------------------------------------------

                stack_adr  UND_Stack
                stack_adr  SVC_Stack
                stack_adr  ABT_Stack
                stack_adr  FIQ_Stack
                stack_adr  IRQ_Stack

        .end


