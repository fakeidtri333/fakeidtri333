#include <avr/io.h>
#include "lcd_lib.h"
#include <util/delay.h>
#include<stdio.h>
#include<adc_lib.h>


int x;
char a[15];
int main(void )
{
	LCDinit();
	LCDclr( );
	ADCinit();// Initializes ADC in 10 bit mode
	while (1)
	{
		x = read_adc(0);// returns the digital value of the analog i/p connected to pin 0 of port A
		LCDGotoXY(0,0);
		sprintf(a,"Value = %d",x);
		LCDdisplay(a);
		_delay_ms(300);
	}
	return 0;
}
