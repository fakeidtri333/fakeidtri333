/*
 * rtc.c
 *
 *  Created on: Jun 9, 2011
 *      Author: simtwo
 */

#include<ds1307.h>
#include<I2C.h>
#include<lcd_lib.h>
#include<avr/io.h>

void main()
{
	int sec,min,hr,ap;
	char lcd_buffer[16];
	LCDinit();
	LCDclr();
	I2CInit();
	ds1307init();
	set_time(0x11,0x59,0x55,0x00);
	while(1)
	{
		read_time(&hr,&min,&sec,&ap);
		sprintf(lcd_buffer,"%2x:%2x:%2x-%d",hr,min,sec,ap);
		LCDGotoXY(0,0);
		LCDstring(lcd_buffer,10);
	}
}
