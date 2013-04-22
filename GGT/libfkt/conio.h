/*
 * conio.h
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is a part of the mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within the package.
 *
 * Low level console I/O functions. Pretty please try to use the ANSI
 * standard ones if you are writing new code.
 *
 */

#ifndef	CONIO_H
#define	CONIO_H

#ifdef	__cplusplus
extern "C" {
#endif

int getch (void);
int getche (void);
int kbhit (void);
int putch (int);
//int ungetch (int);

#ifdef	__cplusplus
}
#endif

#endif	/* Not _CONIO_H_ */
