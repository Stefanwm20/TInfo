/**     \file       interrupt.c
 *
 *      Project:    StartEasy for ARM
 *      \date       07.06.2006
 *       
 *      \author     Hitex Development Tools GmbH
 *                  Greschbachstr. 12
 *                  76229  Karlsruhe
 *
 ****************************************************************************/

#define global extern   /* to declare external variables and functions      */

/* BEGIN USER CODE INCLUDE */

/* END USER CODE INCLUDE */

/* BEGIN USER CODE DEFINES */

/* END USER CODE DEFINES */

void SWI_Handler (void)   __attribute__ ((interrupt ("SWI")));
void PAbt_Handler (void)  __attribute__ ((interrupt ("ABORT")));
void DAbt_Handler (void)  __attribute__ ((interrupt ("ABORT")));
void Undef_Handler (void) __attribute__ ((interrupt ("UNDEF")));
void FIQ_Handler (void)   __attribute__ ((interrupt ("FIQ")));

/* BEGIN USER CODE FUNCTIONS1 */

/* END USER CODE FUNCTIONS1 */

/**
 * \brief Software Interrupt Handler
 *  
 * Usage:
 * Define a macro like this: 
 * #define SWI0 _asm("swi 0x0)
 * Insert the macro into your code.
 * The variable <b>ui_SWIvalue</b> will hold the value 
 * when you reach the USER CODE segment.    
 */
void SWI_Handler (void)
{
    register unsigned int LinkRegister asm ("lr");
    register unsigned int SPSR asm ("r4");
    unsigned int ui_SWIvalue, *LinkAddress;

    asm(" mrs r4, spsr");

    // Check if callee is thumb
    if ((SPSR & 0x20)==0x20)
    {
        // Callee is thumb, calc offset and read immediate
        LinkRegister-=2;
        LinkAddress=(unsigned int*)LinkRegister;
        ui_SWIvalue = *LinkAddress&0xFF;
    }
    else
    {
        // Callee is ARM, calc offset and read immediate
        LinkAddress=(unsigned int*)LinkRegister-4;
        ui_SWIvalue = *LinkAddress&0xFFFFFF;
    }

/* BEGIN USER CODE SWI */

/* END USER CODE SWI */
}

/**
 * \brief Program Abort Handler
 *  
 * This handler is reached after trying to execute an instruction from
 * a memory region where it is not allowed to execute instructions from. 
 * It is highly recommended to define an own handler.        
 */
void PAbt_Handler (void)
{
/* BEGIN USER CODE PABT */
    while(1);
/* END USER CODE PABT */
}

/**
 * \brief Data Abort Handler
 *  
 * This handler is reached after trying to access
 * a memory region where it is not allowed,
 * e. g. if no memory exist at this address.
 * It is highly recommended to define an own handler.    
 */
void DAbt_Handler (void)
{
/* BEGIN USER CODE DABT */
    while(1);
/* END USER CODE DABT */
}

/**
 * \brief Undefined Handler
 *  
 * This handler is reached after trying to execute an undefined intruction.
 * Users can use this feature to implement unknown instructions by a software
 * simulator or, if no undefined instructions are expected do something else.    
 */
void Undef_Handler (void)
{
/* BEGIN USER CODE UNDEF */
    while(1);
/* END USER CODE UNDEF */
}

/**
 * \brief FIQ handler.
 *  
 * The only one.    
 */
void FIQ_Handler (void)
{
/* BEGIN USER CODE FIQ */

/* END USER CODE FIQ */
}

/* BEGIN USER CODE FUNCTIONS2 */

/* END USER CODE FUNCTIONS2 */
