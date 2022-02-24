#include<avr/io.h>
#include<timer0.h>



void set_timer0_normal()
{
	TCCR0&=~(1<<WGM00);
	TCCR0&=~(1<<WGM01);
	
}



void set_timer0_ctc(int i)
{
	TCCR0&=~(1<<WGM00);
	TCCR0|=(1<<WGM01);
	switch(i)
	{
		case 0:////OC0 disconnected
				TCCR0&=~(1<<COM00);
				TCCR0&=~(1<<COM01);
				break;
		case 1:////toggle OC0 on compare match
				TCCR0|=(1<<COM00);
				TCCR0&=~(1<<COM01);
				break;
		case 2:////clear OC0 on compare match
				TCCR0&=~(1<<COM00);
				TCCR0|=(1<<COM01);
				break;
		case 3:////set OC0 on compare match
				TCCR0|=(1<<COM00);
				TCCR0|=(1<<COM01);
				break;
		default:
				break;
	}
	
}

void set_timer0_PWM(int i)
{
	TCCR0|=(1<<WGM00);
	TCCR0|=(1<<WGM01);
	switch(i)
	{
		case 0:////OC0 disconnected
				TCCR0&=~(1<<COM00);
				TCCR0&=~(1<<COM01);
				break;
		case 1:
				break;
		case 2:////clear OC0 on compare match
				TCCR0&=~(1<<COM00);
				TCCR0|=(1<<COM01);
				break;
		case 3:////set OC0 on compare match
				TCCR0|=(1<<COM00);
				TCCR0|=(1<<COM01);
				break;
		default:
				break;
	}

}


void set_timer0_prescalar(int i)
{
	if(i<8)
	{
		TCCR0&=0b11111000;
		TCCR0|=i;
	}
	else
	{
	}
}



void enable_timer0_overflowint()
{
	TIMSK|=(1<<TOIE0);
	//TIFR|=(1<<TOV0);
}

void enable_timer0_ctcint()
{
	TIMSK|=(1<<OCIE0);
	TIFR|=(1<<OCF0);
}

void disable_timer0_overflowint()
{
	TIMSK&=~(1<<TOIE0);
	TIFR&=~(1<<TOV0);
}

void disable_timer0_ctcint()
{
	TIMSK&=~(1<<OCIE0);
	TIFR&=~(1<<OCF0);
}

void set_timer0value(int i)
{
	TCNT0=i;
}

void set_OCR0value(int i)
{
	OCR0=i;
}

void stop_timer0()
{
	set_timer0_prescalar(0);
}
