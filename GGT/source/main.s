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
@ - main program Berechnet den groessten gemeinsamen Teiler
@                zweier Zahlen nach dem Algorithmus von
@                Euklid, die Zahlen stehen in r0 und r1,
@                r3 und r4 sind Arbeitsregister, das Ergebnis
@                kommt in r2
@*******************************************************************
@ History:
@
@     Initial revision 
@*******************************************************************/
	.text
	.align	2	
	.global	main	
main:
	mov r0,#55   @Initialisierung
	mov r1,#121
    mov r3,r0    @ Kopie in die Arbeitsregister
	mov r4,r1
	@ Schleifenkopf
Schlanf:
	cmp r3,r4    @ while (r3!=r4)
	beq Schlende
    @Schleifenrumpf
       @if r3>r4 
	   cmp r3,r4 @r3-r4, C=1 wenn r3>r4
       bcc else
	   @then
	   sub r3,r3,r4 @r3=r3-r4 
       @ Ende ThenZweig
	   b endif
else:            
	   sub r4,r4,r3 @r4=r4-r3 
endif:    @Ende von IfThenElse
       b Schlanf   
Schlende:        @ Ende While (r3!=r4)
       mov r2,r3  @ Ergebnis in r2
@ this ends our main, as we do not have to return  
loop:     
     b	loop

    .end

     
@************************************** EOF *********************************
