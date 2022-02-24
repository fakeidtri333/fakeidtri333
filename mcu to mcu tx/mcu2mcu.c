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
    DDRB=0xff;
    set_uartbaud(9600);
	while(1)
	{
		sendchar_uart(b);
		_delay_ms(1000);
	}
}
