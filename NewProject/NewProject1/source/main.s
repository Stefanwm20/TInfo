@ Compiler:  	GNU
@
@ Date:      	8. 4. 2013
@ Author:    	TI1
@
@          	HAW-Hamburg
@              Labor für technische Informatik
@            	Berliner Tor  7
@            	D-20099 Hamburg
@*******************************************************************
@ Description:
@
@ - main program rechnet 13*19
@*******************************************************************
@ History:
@
@     Initial revision 
@*******************************************************************/
	.text
	.align	2	
	.global	main	
main:
	mov r4,#95 @2. Faktor
	mov r3,#93 @1. Faktor F
	mov r5,r3  @Kopie vom 1. Faktor
	mov r6,#8  @ Schleifenzähler
	mov r7,#1  @ Maske zum Bits testen
	mov r0,#0  @Produkt P
sl:	ands   r8,r4,r7  @ Bit von 2.Faktor pruefen
           @ Ergebnis in r8 zur Demo
	addne r0,r0,r5    @ ggf P=P+F
    mov  r7,r7,lsl #1 @ Maske verschieben
    mov  r5,r5,lsl #1 @ 1.Faktor verschieben
    subs r6,r6,#1 @Schleifenzaehler-- & Flags
	bne sl @ beenden wenn Schleifenz. 0 ist
    @ this ends our main, as we do not have to return  
loop:     
     b	loop

    .end

     
@************************************** EOF *********************************
