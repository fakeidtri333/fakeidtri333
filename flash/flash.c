/*
 * led.c
 *
 *  Created on: May 7, 2011
 *      Author: simone
 */

#include<avr/io.h>
#include<lcd_lib.h>
#include<avr/pgmspace.h>
#include<util/delay.h>

const char  PROGMEM a[5]={1,2,3,4,5};
char b[16];

int main()
{
	int i,j=0;
	LCDinit();
	LCDclr();
	while(1)
	{
		i=pgm_read_byte(a+j);
		sprintf(b,"%d",i);
		LCDGotoXY(0,0);
		LCDdisplay(b);
		j++;
		if(j>=5)j=0;
		_delay_ms(1000);
	}
	return 0;
}
