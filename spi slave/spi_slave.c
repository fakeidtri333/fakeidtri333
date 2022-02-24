/*
 * spi_master.c
 *
 *  Created on: May 1, 2011
 *      Author: BRiCS
 */

#include <avr/io.h>
#include<util/delay.h>
void main()
{
	char d;
	LCDinit();
	LCDclr();
	set_spi_prescalar(3);
	set_spi_slave();
	set_spi_lsbfirst();
	set_spi_clkpolarity(1);
	set_spi_clkphase(1);
	while(1)
	{
		d=sendchar_spi('A');
		LCDGotoXY(0,0);
		LCDsendChar(d);
	}
}
