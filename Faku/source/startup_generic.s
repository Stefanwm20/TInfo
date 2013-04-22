#*****************************************************************************
#*
#*      Project:    Generic include file for ARM startup
#*      Filename:   startup.inc
#*      Date:       11.05.2004
#*      Rights:     Hitex Development Tools GmbH
#*                  Greschbachstr. 12
#*                  76229  Karlsruhe
#*
#****************************************************************************

# *** Startup Code (executed after Reset) ***


# Standard definitions of Mode bits and Interrupt (I & F) flags in PSRs

        .equ    Mode_USR,   0x10
        .equ    Mode_FIQ,   0x11
        .equ    Mode_IRQ,   0x12
        .equ    Mode_SVC,   0x13
        .equ    Mode_ABT,   0x17
        .equ    Mode_UND,   0x1B
        .equ    Mode_SYS,   0x1F
	    .equ	T_BIT, 0x20	   /* when T bit is set, thumb mode active */
        .equ    I_BIT, 0x80        /* when I bit is set, IRQ is disabled */
        .equ    F_BIT, 0x40        /* when F bit is set, FIQ is disabled */
        
# ---------------------------------------------
# Defines for ARM9 TCM supprt
# ---------------------------------------------
        .equ    TCM_SIZE_4k,   0x0C
        .equ    TCM_SIZE_8k,   0x10
        .equ    TCM_SIZE_16k,  0x14
        .equ    TCM_SIZE_32k,  0x18
        .equ    TCM_SIZE_64k,  0x1C
        .equ    TCM_SIZE_128k, 0x20
        .equ    TCM_SIZE_256k, 0x24
        .equ    TCM_SIZE_512k, 0x28
        .equ    TCM_SIZE_1M,   0x2C


# ---------------------------------------------
# macro definition for stack memory reservation
# ---------------------------------------------
# use this macro to setup the stack
            .macro  setup_stack label1, size, mode_bits

            .lcomm  __range_\label1, (\size - 1) * 4
            .global \label1
            .lcomm  \label1, 4

 		    ldr     r0, adr_\label1
            msr     CPSR_c, \mode_bits
            mov     r13, r0

            .endm

# use this macro to define the label for the setup_stack mcaro!
            .macro  stack_adr label1
adr_\label1:
            .word   \label1
            .endm
# ---------------------------------------------
# copy section
# use this macro to copy a section
# parameters:
# - individual name, used to create labels
# - source pointer
# - destination pointer
# - source pointer + length > end address of source
# ---------------------------------------------
            .macro  copy_section sec_name, source, destination, source_end

            ldr     R1, =\source
            ldr     R2, =\destination
            ldr     R3, =\source_end
_cplp_\sec_name:
            cmp     R1, R3
            ldrlo   R0, [R1], #4
            strlo   R0, [R2], #4
            blo     _cplp_\sec_name

            .endm

# ---------------------------------------------
# copy section 2
# use this macro to copy a section
# parameters:
# - individual name, used to create labels
# - source pointer
# - destination pointer
# - destination pointer + length > end address of destination
# ---------------------------------------------
            .macro  copy_section2 sec_name, source, destination, destination_end

            ldr     R1, =\source
            ldr     R2, =\destination
            ldr     R3, =\destination_end
_cplp_\sec_name:
            cmp     R2, R3
            ldrlo   R0, [R1], #4
            strlo   R0, [R2], #4
            blo     _cplp_\sec_name

            .endm

# ---------------------------------------------
# clear section
# use this macro to clear bss sections
# ---------------------------------------------
            .macro  clear_section sec_name, source, source_end

            mov     R0, #0
            ldr     R1, =\source
	        ldr     R2, =\source_end
_cllp_\sec_name:
            cmp     R1, R2
            strlo   R0, [R1], #4
	        blo     _cllp_\sec_name
            .endm

# ---------------------------------------------
# examples how to use the macros
# ---------------------------------------------
# Setup stacks for the operating modes
# ---------------------------------------------

#            setup_stack  UND_Stack, UND_Stack_Size, #Mode_UND|I_BIT|F_BIT
#            setup_stack  SVC_Stack, SVC_Stack_Size, #Mode_SVC|I_BIT|F_BIT
#            setup_stack  ABT_Stack, ABT_Stack_Size, #Mode_ABT|I_BIT|F_BIT
#            setup_stack  FIQ_Stack, FIQ_Stack_Size, #Mode_FIQ|I_BIT|F_BIT
#            setup_stack  IRQ_Stack, IRQ_Stack_Size, #Mode_IRQ|I_BIT|F_BIT
#            setup_stack  USR_Stack, USR_Stack_Size, #Mode_USR

# ---------------------------------------------
# copy sections
# ---------------------------------------------

# copy code into internal ram
#            copy_section code, __code_start__, RAM_Base_Boot, __code_end__

# Relocate .data section (Copy from ROM to RAM)
#            copy_section data, __data_start__, __data_start__+RAM_Base_Boot, __data_end__

# ---------------------------------------------
# Clear .bss section
# ---------------------------------------------

# Clear .bss section (Zero init)
#            clear_section bss, __bss_start__, __bss_end__

# ---------------------------------------------
# startup delay
# use this macro if you are working with an debugger
# the startup delay avoid problems while
# the application start before the debug interface
# becomes controled by the debugger
# ---------------------------------------------

# a goodf choice for the delay value is
# cpu clock / 100 with ATMEL controllers
# cpu clock / 40  with NXP controllers

            .macro  StartupDelay delay_value

            ldr     R1, =\delay_value
            ldr     R2, =0
__StartDelay:
            sub     R1, R1, #1
            cmp     R1, R2
            bhi     __StartDelay

            .endm

# ---------------------------------------------
# Expects an Address and a value.
# The value is written to the Address
# ---------------------------------------------
				.macro RegWrite  Address, Value
				
	            ldr     R1, =\Address
	            ldr     R2, =\Value
				str		R2, [R1]
				
                .endm
                
# ---------------------------------------------
# Expects an Address and a value.
# Read the current value from the address,
# verify if the a bit which is masked by Value
# is set or not
# ---------------------------------------------
				.macro RegWait  Address, Value


                ldr     R1, =\Address
1:              ldr     R2, [R1]
	            and     R2, R2, #\Value
				cmp     R2, #0
				beq     1b

                .endm
                
# ---------------------------------------------
# Expects an Address and a value.
# Read the current value from the address,
# or the value with the register value and
# write the register back.
# is set or not
# ---------------------------------------------
				.macro RegOr  Address, Value


                ldr     R1, =\Address
                ldr     R2, [R1]
	            orr     R2, R2, #\Value
                str     R2, [R1]

                .endm
# ---------------------------------------------
