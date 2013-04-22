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
*****************************************************************************/

#ifndef syscalls_h
#define syscalls_h

#include <reent.h>
#include <stdlib.h>
#include <sys/stat.h>

#define LF     0x0A
#define CR     0x0D

int uart0Putch (int ch);
int uart0Getch(void);

_ssize_t _write_r ( struct _reent *r, 
                    int file, 
                    const void *ptr, 
                    size_t len);
                    
_ssize_t _read_r( struct _reent *r, 
                  int file, 
                  void *ptr, 
                  size_t len);       

void* _sbrk_r( struct _reent *_s_r, 
               ptrdiff_t nbytes );

#endif
