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
    DDRD=0xff;
    LCDinit();
    LCDclr();
	set_uartbaud(9600);
	while(1)
	{
		b=getchar_uart();
		sendchar_uart(b);
		LCDGotoXY(0,0);
		LCDsendChar(b);
		if(b=='w')
			PORTD=0b10100000;
		if(b=='a')
			PORTD=0b10010000;
		if(b=='d')
			PORTD=0b01100000;
		if(b=='s')
			PORTD=0b01010000;
		if(b==' ')
			PORTD=0b11110000;
	}
}
