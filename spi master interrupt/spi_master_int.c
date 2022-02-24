/*
 * spi_master.c
 *
 *  Created on: May 1, 2011
 *      Author: BRiCS
 */

#include <avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>

int i=0;
char d;
ISR (SPI_STC_vect)
{
	i++;
	d=SPDR;
}
void main()
{
	char buff[16];
	LCDinit();
	LCDclr();
	set_spi_master();
	enable_spiint();
	sei();
	while(1)
	{
		sendchar_spi('D');
		LCDGotoXY(0,0);
		LCDsendChar(d);
		sprintf(buff,"i=%3d",i);

		LCDGotoXY(0,1);
		LCDstring(buff,strlen(buff));
		_delay_ms(1000);
	}
}
