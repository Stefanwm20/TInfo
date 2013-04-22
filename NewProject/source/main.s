	.text
	.align	2	
	.global	main	
main:
    mov r1,#360	@Dividend
	mov r0,#30	@divisor
    mov r2,#0	@counter
	mov r3,#0	
    mov r4,#1	@shiftnum

loop:

mov r7,r0,lsl#1			@Adding divisor in separate registry
cmp r1,r7			@Comparing if divisor fits into dividend
movpl r0,r0,lsl#1	@Incrementing divisor

movpl r4,r4,lsl#1     @quotient
addeq r3,r4


blmi up1 @Sub-program statement
addne r2,r2,#1		@Adding to the counter for loop
bpl loop

beq e

up1:   @Sub-program entry

sub r1,r1,r0
sub r2,#1	

mov r0,r0
add r3,r4
mov r4,#1
addmi r3,r4
movs r7,#0
bx lr	
    
e:
.end