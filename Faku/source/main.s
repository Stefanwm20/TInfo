@ Compiler:  	GNU
@
@ Date:      	22. 4. 2013
@ Author:    	BTI1
@
@          	HAW-Hamburg
@              Labor für technische Informatik
@            	Berliner Tor  7
@            	D-20099 Hamburg
@*******************************************************************
@ Description:
@
@ - main program Fakultaet berechnen
@*******************************************************************
@ History:
@
@     Initial revision 
@*******************************************************************/
	.text
	.align	2	
	.global	main	
main:
	mov r1,#7 @n
	mov r2,#2 @i
	mov r3,#1 @n!
Schlanf:
    mul r3,r2,r3  @Fakultaet=Fakultaet*i
	add r2,r2,#1 @i++
	@ Schleifenende
	cmp r1,r2
	bcs Schlanf
    mov r0,r3 @ Ergebnis in r0
@ this ends our main, as we do not have to return  
loop:     
     b	loop

    .end

     
@************************************** EOF *********************************
