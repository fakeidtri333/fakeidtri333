
/*
 * led.c
 *
 *  Created on: May 7, 2011
 *      Author: simone
 */

#include<avr/io.h>
#include<util/delay.h>
#include<lcd_lib.h>
int main()
{
	char a[]="  BRiCS Summer Training 2011";
	LCDinit();
	LCDclr();
	LCDGotoXY(0,0);
	LCDdisplay(a);
	while(1)
	{
		LCDshiftRight(1);
		_delay_ms(400);
	}
	return 0;
}
