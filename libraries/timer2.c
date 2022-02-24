#include<avr/io.h>
#include<timer2.h>



void set_timer2_normal()
{
	TCCR2&=~(1<<WGM20);
	TCCR2&=~(1<<WGM21);
	
}



void set_timer2_ctc(int i)
{
	TCCR2&=~(1<<WGM20);
	TCCR2|=(1<<WGM21);
	switch(i)
	{
		case 0:////OC0 disconnected
				TCCR2&=~(1<<COM20);
				TCCR2&=~(1<<COM21);
				break;
		case 1:////toggle OC0 on compare match
				TCCR2|=(1<<COM20);
				TCCR2&=~(1<<COM21);
				break;
		case 2:////clear OC0 on compare match
				TCCR2&=~(1<<COM20);
				TCCR2|=(1<<COM21);
				break;
		case 3:////set OC0 on compare match
				TCCR2|=(1<<COM20);
				TCCR2|=(1<<COM21);
				break;
		default:
				break;
	}
	
}



void set_timer2_prescalar(int i)
{
	if(i<8)
	{
		TCCR2&=0b11111000;
		TCCR2|=i;
	}
	else
	{
	}
}



void enable_timer2_overflowint()
{
	TIMSK|=(1<<TOIE2);
	TIFR|=(1<<TOV2);
}

void enable_timer2_ctcint()
{
	TIMSK|=(1<<OCIE2);
	TIFR|=(1<<OCF2);
}

void disable_timer2_overflowint()
{
	TIMSK&=~(1<<TOIE2);
	TIFR&=~(1<<TOV2);
}

void disable_timer2_ctcint()
{
	TIMSK&=~(1<<OCIE2);
	TIFR&=~(1<<OCF2);
}

void set_timer2value(int i)
{
	TCNT2=i;
}

void set_compare2value(int i)
{
	OCR2=i;
}

void stop_timer2()
{
	set_timer2_prescalar(0);
}