/*
 * led.c
 *
 *  Created on: May 7, 2011
 *      Author: simone
 */

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include<avr/interrupt.h>
#include "lcd_lib.h"
#include <ext_interrupt.h>
char i=0,j=0 ;
char A[20]="";
main(void)
{
	DDRD=0b11110011;
	PORTD=0b00001100;
	LCDinit();
	LCDclr();
	enable_INT0(2);
	enable_INT1(0);
	sei();
	while(1)
	{
		sprintf(A,"%3d",i);
		LCDGotoXY(0,0);
		LCDdisplay(A);
	}
}


ISR(INT0_vect)
{
	i++;
	
	_delay_ms(100);
}


ISR(INT1_vect)
{
	i--;
	
	_delay_ms(100);
}
