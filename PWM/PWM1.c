/*
 * spi_master.c
 *
 *  Created on: May 1, 2011
 *      Author: BRiCS
 */

#include <avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>


void main()
{
	DDRD=0xff;
	char buff[16];
	LCDinit();
	LCDclr();
	set_timer1_prescalar(1);
	OCR1A=255;
	set_timer1_PWMa(2);
	while(1)
	{
		OCR1A++;
		_delay_ms(100);
		if(OCR1A>254)
			OCR1A=0;
		sprintf(buff,"%3d",OCR1A);
		LCDGotoXY(0,1);
		LCDstring(buff,strlen(buff));

	}
}

