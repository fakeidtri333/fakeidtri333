#include<avr/io.h>
#include<timer1.h>



void set_timer1_normal()
{
	TCCR1A&=~(1<<WGM10);
	TCCR1A&=~(1<<WGM11);
	TCCR1B&=~(1<<WGM12);
	TCCR1B&=~(1<<WGM13);
}



void set_timer1_ctca(int i)
{
	TCCR1A&=~(1<<WGM10);
	TCCR1A&=~(1<<WGM11);
	TCCR1B|=(1<<WGM12);
	TCCR1B&=~(1<<WGM13);
	switch(i)
	{
		case 0:////OC1 disconnected
				TCCR1A&=~(1<<COM1A0);
				TCCR1A&=~(1<<COM1A1);
				break;
		case 1:////toggle OC1A on compare match
				TCCR1A|=(1<<COM1A0);
				TCCR1A&=~(1<<COM1A1);
				break;
		case 2:////clear OC1A on compare match
				TCCR1A&=~(1<<COM1A0);
				TCCR1A|=(1<<COM1A1);
				break;
		case 3:////set OC1A on compare match
				TCCR1A|=(1<<COM1A0);
				TCCR1A|=(1<<COM1A1);
				break;
		default:
				break;
	}
	
}


void set_timer1_ctcb(int i)
{
	TCCR1A&=~(1<<WGM10);
	TCCR1A&=~(1<<WGM11);
	TCCR1B|=(1<<WGM12);
	TCCR1B&=~(1<<WGM13);
	switch(i)
	{
		case 0:////OC1B disconnected
				TCCR1A&=~(1<<COM1B0);
				TCCR1A&=~(1<<COM1B1);
				break;
		case 1:////toggle OC1B on compare match
				TCCR1A|=(1<<COM1B0);
				TCCR1A&=~(1<<COM1B1);
				break;
		case 2:////clear OC1B on compare match
				TCCR1A&=~(1<<COM1B0);
				TCCR1A|=(1<<COM1B1);
				break;
		case 3:////set OC1B on compare match
				TCCR1A|=(1<<COM1B0);
				TCCR1A|=(1<<COM1B1);
				break;
		default:
				break;
	}
	
}

void set_timer1_PWMb(int i)
{
	TCCR1A|=(1<<WGM10);
			TCCR1A|=(1<<WGM11);
			TCCR1B|=(1<<WGM12);
			TCCR1B|=(1<<WGM13);
	switch(i)
		{
			case 0:////OC1B disconnected
					TCCR1A&=~(1<<COM1B0);
					TCCR1A&=~(1<<COM1B1);
					break;
			case 1:////toggle OC1B on compare match
					TCCR1A|=(1<<COM1B0);
					TCCR1A&=~(1<<COM1B1);
					break;
			case 2:////clear OC1B on compare match
					TCCR1A&=~(1<<COM1B0);
					TCCR1A|=(1<<COM1B1);
					break;
			case 3:////set OC1B on compare match
					TCCR1A|=(1<<COM1B0);
					TCCR1A|=(1<<COM1B1);
					break;
			default:
					break;
		}
}

void set_timer1_PWMa(int i)
{
		TCCR1A|=(1<<WGM10);
		TCCR1A&=~(1<<WGM11);
		TCCR1B|=(1<<WGM12);
		TCCR1B&=~(1<<WGM13);
	switch(i)
		{
			case 0:////OC1B disconnected
					TCCR1A&=~(1<<COM1A0);
					TCCR1A&=~(1<<COM1A1);
					break;
			case 1:////toggle OC1B on compare match
					TCCR1A|=(1<<COM1A0);
					TCCR1A&=~(1<<COM1A1);
					break;
			case 2:////clear OC1B on compare match
					TCCR1A&=~(1<<COM1A0);
					TCCR1A|=(1<<COM1A1);
					break;
			case 3:////set OC1B on compare match
					TCCR1A|=(1<<COM1A0);
					TCCR1A|=(1<<COM1A1);
					break;
			default:
					break;
		}
}

void set_timer1_prescalar(int i)
{
	if(i<8)
	{
		TCCR1B&=0b11111000;
		TCCR1B|=i;
	}
	else
	{
	}
}



void enable_timer1_overflowint()
{
	TIMSK|=(1<<TOIE1);
	TIFR|=(1<<TOV1);
}

void enable_timer1_ctcaint()
{
	TIMSK|=(1<<OCIE1A);
	TIFR|=(1<<OCF1A);
}

void enable_timer1_ctcbint()
{
	TIMSK|=(1<<OCIE1B);
	TIFR|=(1<<OCF1B);
}


void disable_timer1_overflowint()
{
	TIMSK&=~(1<<TOIE1);
	TIFR&=~(1<<TOV1);
}

void disable_timer1_ctcaint()
{
	TIMSK&=~(1<<OCIE1A);
	TIFR&=~(1<<OCF1A);
}

void disable_timer1_ctcbint()
{
	TIMSK&=~(1<<OCIE1B);
	TIFR&=~(1<<OCF1B);
}

void set_timer1value(int i)
{
	TCNT1=i;
}

void set_compare1avalue(int i)
{
	OCR1A=i;
}

void set_compare1bvalue(int i)
{
	OCR1B=i;
}

void stop_timer1()
{
	set_timer1_prescalar(0);
}
