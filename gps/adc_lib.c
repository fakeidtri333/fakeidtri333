#include "adc_lib.h"
#include <inttypes.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
int conf;
unsigned int read_adc(unsigned char adc_input)
{
ADMUX|=adc_input;
ADCSRA|=0x40;                 // Start the AD conversion
while ((ADCSRA & 0x10)==0);  // Wait for the AD conversion to complete
ADCSRA|=0x10;
if (conf==8)
	return ADCH;
else 
	return ADCW;
}

int ADCinit(int c){
	if ( c ==8)
		ADMUX=0x20;
	else 
		ADMUX=0x00;
	ADCSRA=0b10000101;
	conf =c;
	return 0;
}
