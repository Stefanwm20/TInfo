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


# System Memory definitions

#  Internal RAM definitions
    .equ    RAM_Size,      0x00004000      /* 16kB */
    .equ    RAM_Base,      0x40000000      /*  */	

	.equ    TopStack,     RAM_Base + RAM_Size

# Stack definitions

	.equ    UND_Stack_Size,     1*4
    .equ    SVC_Stack_Size,    32*4
    .equ    ABT_Stack_Size,     1*4
    .equ    FIQ_Stack_Size,     1*4
    .equ    IRQ_Stack_Size,    32*4
    .equ    USR_Stack_Size,    32*4

# Startup Code must be linked first at Address at which it expects to run.

        .text
	.arm
	.extern main
	.global _app_entry
	.global _ResetEntry
	.global _SoftReset
	.global _HardReset
    .global _startup
    .func   _startup
_startup:
ENTRY:

Reset_Vec:      B       _HardReset
                LDR     PC, Undef_Addr
                LDR     PC, SWI_Addr
                LDR     PC, PAbt_Addr
                LDR     PC, DAbt_Addr
                NOP                            /* Reserved Vector */
                LDR     PC, IRQ_Addr
                LDR     PC, FIQ_Addr

Reset_Addr:     .word   _HardReset
Undef_Addr:     .word   Undef_Handler
SWI_Addr:       .word   SWI_Handler
PAbt_Addr:      .word   PAbt_Handler
DAbt_Addr:      .word   DAbt_Handler
                .word   0                      /* Reserved Address */
IRQ_Addr:       .word   IRQ_Handler
FIQ_Addr:       .word   FIQ_Handler

Undef_Handler:  	B       Undef_Handler
SWI_Handler:    	B       SWI_Handle
PAbt_Handler:   	B       PAbt_Handle
DAbt_Handler:   	B       DAbt_Handle
IRQ_Handler:    	B       IRQ_Handle
FIQ_Handler:    	B       FIQ_Handle

# HardReset Handler
_HardReset:  
_app_entry:

		
		b	_ResetEntry	/* jump to ResetEntry */

PAbt_Handle:
		ldr	r14,=0xFFFF0000		/* load Address PIO base */
		ldr	r1,=0x01000032		/* value for PIO to output (except address lines & P2,9,12,15,22)*/
		ldr	r2,=0x00000022		/* mask  for Data Output */
		ldr	r3,=0x01000012		/* mask for clear all Leds */
		str	r1,[r14,#0x10]		/* output PIO output register*/
		str	r3,[r14,#0x34]		/* reset all LED */
		str	r2,[r14,#0x30]		/* set LED 2,1 PIO output data */
PAbt_Loop:	B	PAbt_Loop

DAbt_Handle:
		ldr	r14,=0xFFFF0000		/* load Address PIO base */
		ldr	r1,=0x01000032		/* value for PIO to output (except address lines & P2,9,12,15,22)*/
		ldr	r2,=0x00000020		/* mask  for Data Output */
		ldr	r3,=0x01000020		/* mask for clear all Leds */
		str	r1,[r14,#0x10]		/* output PIO output register*/
		str	r3,[r14,#0x34]		/* reset all LED */
		str	r2,[r14,#0x30]		/* set LED 3 PIO output data */
DAbt_Loop:	B	DAbt_Loop

IRQ_Handle:
		ldr	r14,=0xFFFF0000		/* load Address PIO base */
		ldr	r1,=0x01000032		/* value for PIO to output (except address lines & P2,9,12,15,22)*/
		ldr	r2,=0x00000022		/* mask  for Data Output */
		ldr	r3,=0x01000020		/* mask for clear all Leds */
		str	r1,[r14,#0x10]		/* output PIO output register*/
		str	r3,[r14,#0x34]		/* reset all LED */
		str	r2,[r14,#0x30]		/* set LED 3, 1 PIO output data */
IRQ_Loop:	B	IRQ_Loop

FIQ_Handle:
		ldr	r14,=0xFFFF0000		/* load Address PIO base */
		ldr	r1,=0x01000032		/* value for PIO to output (except address lines & P2,9,12,15,22)*/
		ldr	r2,=0x00000030		/* mask  for Data Output */
		ldr	r3,=0x01000020		/* mask for clear all Leds */
		str	r1,[r14,#0x10]		/* output PIO output register*/
		str	r3,[r14,#0x34]		/* reset all LED */
		str	r2,[r14,#0x30]		/* set LED 3,2 PIO output data */
FIQ_Loop:	B	FIQ_Loop

SWI_Handle:
		ldr	r14,=0xFFFF0000		/* load Address PIO base */
		ldr	r1,=0x01000032		/* value for PIO to output (except address lines & P2,9,12,15,22)*/
		ldr	r2,=0x00000022		/* mask  for Data Output */
		ldr	r3,=0x01000032		/* mask for clear all Leds */
		str	r1,[r14,#0x22]		/* output PIO output register*/
		str	r3,[r14,#0x34]		/* reset all LED */
		str	r2,[r14,#0x30]		/* set LED 3,2,1 PIO output data */
SWI_Loop:	B	SWI_Loop


# From here HardReset and SoftReset executes the same code */ 

_ResetEntry:

		ldr     r0, =TopStack
# Set up Fast Interrupt Mode and set FIQ Mode Stack
        msr     CPSR_c, #Mode_FIQ|I_BIT|F_BIT
        mov     r13, r0                     
        sub     r0, r0, #FIQ_Stack_Size

# Set up Interrupt Mode and set IRQ Mode Stack
        msr     CPSR_c, #Mode_IRQ|I_BIT|F_BIT
        mov     r13, r0                     
        sub     r0, r0, #IRQ_Stack_Size

# Set up Abort Mode and set Abort Mode Stack
        msr     CPSR_c, #Mode_ABT|I_BIT|F_BIT
        mov     r13, r0                     
        sub     r0, r0, #ABT_Stack_Size

# Set up Undefined Instruction Mode and set Undef Mode Stack
        msr     CPSR_c, #Mode_UND|I_BIT|F_BIT
        mov     r13, r0                     
        sub     r0, r0, #UND_Stack_Size

# Set up Supervisor Mode and set Supervisor Mode Stack
        msr     CPSR_c, #Mode_SVC|I_BIT|F_BIT
        mov     r13, r0                     

#  Enter User Mode and set its Stack Pointer
        msr     CPSR_c, #Mode_USR
        mov     SP, R0

#  Setup a default Stack Limit (when compiled with "-mapcs-stack-check")
        sub     SL, SP, #1<<10         /* 1kB */

# enable interrupts
        mrs r1, CPSR
        bic r1, r1, #0x80
        msr CPSR, r1

# Relocate .data section (Copy from ROM to RAM)
        ldr     R1, =_etext
        ldr     R2, =_data
        ldr     R3, =_edata
LoopRel:
        cmp     R2, R3
        ldrlo   R0, [R1], #4
        strlo   R0, [R2], #4
        blo     LoopRel

# Clear .bss section (Zero init)                
        mov     R0, #0
        ldr     R1, =__bss_start__
        ldr     R2, =__bss_end__
LoopZI: 
        cmp     R1, R2
        strlo   R0, [R1], #4
        blo     LoopZI


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
# Dummy Function
#
# ---------------------------------------------
		.global 	BaseStickConfig
BaseStickConfig:
		mov		pc,lr		/* just a return to caller */	

        .size   _startup, . - _startup
        .endfunc
        .end

