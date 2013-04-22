.section .text

.global main

main: 

mov r0, #360	@Dividend
mov r1, #90		@Divisor
mov r2, #0		@shiftnum
mov r3, #0		@qutient

while:
cmp r0,r1		@while (divisor <=dividend)
bcc countup
add r2,#1
mov r1,r1,lsl#1
bcs while

countup:		@End of while-loop


calcq:
				
			
mov r3,r3,lsl#1		@quotient<<1
mov r1,r1,lsr#1		@divisor>>1



cmp r0,r1		@while 2 (dividend<= dividend)
blcs while2
subs r2,#1		@decrementing counter
bcc calcq
beq end			@End condition
bcs calcq





while2:

orr r3,r3,#0x1
sub r0,r0,r1

bx lr


end:

mov r1,r3

loop:
b loop

.end