/*
 * uart.c
 *
 *  Created on: Apr 13, 2011
 *      Author: simone
 */

#include<avr/io.h>
#include <util/delay.h>
#include"lcd_lib.h"
#include <stdio.h>

int main()
{
    char b='*';
    int i=0;
    DDRB=0xff;
    LCDinit();
    LCDclr();
	set_uartbaud(9600);
	while(1)
	{
		b=getchar_uart();
		sendchar_uart(b);
		LCDGotoXY(i,0);
		LCDsendChar(b);
		i++;
		if(i>16)
			i=0;
	}
}
