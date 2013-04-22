/* Compiler:  	GNU
 *
 * Date:      	10. 1. 2011
 * Author:    	Alfred Lohmann
 *
 *          	HAW-Hamburg
 *              Labor für technische Informatik
 *            	Berliner Tor  7
 *            	D-20099 Hamburg
 ********************************************************************
 * Description:
 *
 * - low level console io
 * - good old DOS version
 ********************************************************************
 * History:
 *
 *     Initial revision 
 ********************************************************************/
#include <inttypes.h>
#include <config.h>
#include "conio.h"

#ifdef UART0_SUPPORT
extern volatile uint16_t uart0_rx_insert_idx, uart0_rx_extract_idx;
#endif

int uart0Getch(void);
int uart0Putch(int c);

int getch (void){
	int c;
	
	do {
		c = uart0Getch();
	}while(c == -1);
 
	return c;	
}


int getche (void){
	int c;
	int retval;

	do {
		c = uart0Getch();
	}while(c == -1);
 
	do{
		retval = uart0Putch(c);
	}while(retval == -1); 
	
	return c;	

}


int kbhit (void){

	if (uart0_rx_insert_idx == uart0_rx_extract_idx)	// check if character is available
		return -1;										// no character available	
	else
		return 0;										// character available
	
}


int putch (int c){
	int retval;

	do{
		retval = uart0Putch(c);
	}while(retval == -1); 

	return c;	
}
