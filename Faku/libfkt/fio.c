/*****************************************************************************
 *   fio.c:  Fast I/O module file for NXP LPC23xx Family Microprocessors
 *
 *   Copyright(C) 2006, NXP Semiconductor
 *   All rights reserved.
 *
 *   History
 *   2006.07.13  ver 1.00    Prelimnary version, first Release
 *
 ******************************************************************************/

#include "lpc24xx.h"
#include <inttypes.h>
#include "fio.h"

/*****************************************************************************
** Function name:   GPIOInit
**
** Descriptions:    initialize GPIO port
**
** parameters:      port number and port type, Fast I/O or
**                  regular GPIO, direction, Mask
** Returned value:  None
**
*****************************************************************************/
void GPIOInit( uint32_t PortNum, uint32_t PortType, uint32_t PortDir, uint32_t Mask )
{
	if ( (PortType == REGULAR_PORT) && ((PortNum == 0) || (PortNum == 1)) )
	{
		SCS &= ~GPIOM;    /* set GPIOx to use regular I/O */
		if ( PortDir == DIR_OUT )
		{
			(*(volatile unsigned long *)(REGULAR_PORT_DIR_BASE
				+ PortNum * REGULAR_PORT_DIR_INDEX)) |= Mask;
		}
		else
		{
			(*(volatile unsigned long *)(REGULAR_PORT_DIR_BASE
				+ PortNum * REGULAR_PORT_DIR_INDEX)) &= ~Mask;
		}
	}
	else if ( PortType == FAST_PORT )
	{
		if ( (PortNum == 0) || (PortNum == 1) )
		{
			SCS |= GPIOM; /* set GPIOx to use Fast I/O */
		}
		if ( PortDir == DIR_OUT )
		{
			(*(volatile unsigned long *)(HS_PORT_DIR_BASE
				+ PortNum * HS_PORT_DIR_INDEX)) |= Mask;
		}
		else
		{
			(*(volatile unsigned long *)(HS_PORT_DIR_BASE
				+ PortNum * HS_PORT_DIR_INDEX)) &= ~Mask;
		}
	}
	return;
}

/*********************************************************************************
**                            End Of File
*********************************************************************************/
