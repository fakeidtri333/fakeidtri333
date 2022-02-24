/*
 * led.c
 *
 *  Created on: May 7, 2011
 *      Author: simone
 */

#include<avr/io.h>
#include<lcd_lib.h>
#include<ext_interrupt.h>
#include<avr/interrupt.h>
#include<avr/eeprom.h>

int i;///global variable
char a[16];

ISR(INT0_vect)
{
	i++;
	eeprom_write_byte(0,i);
}

ISR(INT1_vect)
{
	i--;
	eeprom_write_byte(0,i);

}

int main()
{
	LCDinit();
	LCDclr();
	i=eeprom_read_byte(0);
	enable_INT0(2);
	enable_INT1(2);
	sei();///enables global interrupts
	while(1)
	{
		sprintf(a,"%3d",i);
		LCDGotoXY(0,0);
		LCDdisplay(a);
	}
	return 0;
}
