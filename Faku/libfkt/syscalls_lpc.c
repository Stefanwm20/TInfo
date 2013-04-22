/*****************************************************************************
 *   syscalls.c:  IO function for NXP LPC23xx/34xx Family 
 *   Microprocessors and GCC IO
 *
 *   Copyright(C) 2006, NXP Semiconductor
 *   All rights reserved.
 *
 *   History
 *
 *   19.6.2008   ver 1.00           Alfred Lohmann  HAW-Hamburg   
 *
 *   Version for NXP LPC-Stick (Hitex)to support UART0 for printf()...
 *   The implementation uses the UART driver from RO Software.
 *                              
 *
*****************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <reent.h>
#include <sys/stat.h>

#include "lpc24xx.h"
#include "config.h"
#include "syscalls_lpc.h"


_ssize_t _write_r (
    struct _reent *r, 
    int file, 
    const void *ptr, 
    size_t len)
{
	int i;
	const unsigned char *p;
	int retval;
	
	p = (const unsigned char*) ptr;
	
	for (i = 0; i < len; i++) {
		if (*p == '\n' ){
		   do{
		      retval = uart0Putch('\r');
		   }while(retval == -1);   
		}
	    do{
		   retval = uart0Putch(*p);
		}while(retval == -1); 
		p++;  
	}
	
	return len;
}


_ssize_t _read_r(
    struct _reent *r, 
    int file, 
    void *ptr, 
    size_t len) 
{
	int c;
	int  i;
	unsigned char *p;
	int retval;
	
	p = (unsigned char*)ptr;
	
	for (i = 0; i < len; i++) {
	   do {
		  c = uart0Getch();
	   }while(c == -1);
		if (c == 0x0D) {
    		do{
    		   retval = uart0Putch('\r');
    		}while(retval == -1); 
    		do{
    		   retval = uart0Putch('\n');
    		}while(retval == -1); 
    		
			*p='\n';
			i++;
			break;
		}
		*p++ = c;
		do{
		   retval = uart0Putch(c);
		}while(retval == -1); 
	}
	return i;
}


extern unsigned char end[]; /*  end is set in the linker command 	*/
				            /* file and is the end of statically 	*/
				            /* allocated data (thus start of heap).	*/
extern unsigned char _end_of_heap_[];
static unsigned char *heap_ptr = NULL;		/* Points to current end of the heap.	*/
				    
void* _sbrk_r( struct _reent *_s_r, 
               ptrdiff_t nbytes )
{
    
    unsigned char *prev_heap_end;
    
    if ( heap_ptr == NULL) 
            heap_ptr = end;
    
    prev_heap_end = heap_ptr;
    
    if ((heap_ptr + nbytes) > _end_of_heap_){
      return NULL;
    }
  
    heap_ptr += nbytes;
    
    return (void*)prev_heap_end;
    
}
