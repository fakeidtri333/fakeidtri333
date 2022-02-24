#include <avr/io.h>
#include <util/delay.h>


int  main(void)
{
               // Declare your local variables here
DDRB=255;
DDRC=255;
DDRD=255;
while (1)
{
PORTB=1;_delay_ms(100);
PORTB=2;_delay_ms(100);
PORTB=4;_delay_ms(100);
PORTB=8;_delay_ms(100);
PORTB=16;_delay_ms(100);
PORTB=32;_delay_ms(100);
PORTB=64;_delay_ms(100);
PORTB=128;_delay_ms(100);


PORTC=1;
PORTC=2;
PORTC=4;
PORTC=8;

PORTD=1;_delay_ms(100);
PORTD=2;_delay_ms(100);
PORTD=4;_delay_ms(100);
PORTD=8;_delay_ms(100);
PORTD=16;_delay_ms(100);
PORTD=32;_delay_ms(100);
PORTD=64;_delay_ms(100);
PORTD=128;_delay_ms(100);

   }

}
