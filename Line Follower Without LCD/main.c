#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include<adc_lib.h>
int main()
{
	int s1,s2;

	DDRB=255;
	DDRD=255;
        DDRC=255;
ADCinit();

while(1)
{

	  s1=read_adc(0);

	PORTC=(1<<(s1/128))-1;

	 s2=read_adc(1);

	PORTB=(1<<(s2/128))-1;

	if(s1<600&s2<600)      // Change the value according to your sensor value

	PORTD=0b100100000;// forword when both sensor are in white surface

	if(s1>600&s2<600)

	PORTD=0b10100000;// right when one sensor in black & one sensor in white surface

        if(s1<600&s2>600)

	 PORTD=0b01010000;// left when one sensor in white & one sensor in black surface

        if(s1>600&s2>600)

	 PORTD=0b10010000;// forward when both sensor are in black surface
}
}

