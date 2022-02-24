/*
 * hi.c
 *
 *  Created on: Jul 18, 2011
 *      Author: BRiCS
 */

#include<avr/io.h>
#include<util/delay.h>
#include<lcd_lib.h>
#include<adc_lib.h>

int x,y,button,status=0;
int num=0,num1=0,result,operator=0;
void main()
{
	char buff[16];
	DDRD=0xff;
	PORTD=0xff;
	ADCinit();
	LCDinit();
	LCDclr();
	x=read_x();
			y=read_y();
			_delay_ms(1000);
	while(1)
	{
		x=read_x();
		y=read_y();
		button=get_touch();
		get_number();
		sprintf(buff,"%4d %4d %d %d",x,y,button,status);
		LCDGotoXY(0,0);
		LCDdisplay(buff);
		sprintf(buff,"%3d %3d %3d %3d ",num,num1,operator,result);
		LCDGotoXY(0,1);
		LCDdisplay(buff);
	}
}

void get_number()
{
	if(status==0 && button!=0)
	{
		status=1;
		if(button==96)
		{
			switch(operator)
			{
				case 1:
					result=num1+num;
					num=0;num1=0;
					operator=0;
					break;
				case 2:
					result=num1-num;
					num=0;num1=0;
					operator=0;
					break;
				case 3:
					result=num1*num;
					num=0;num1=0;
					operator=0;
					break;
				case 4:
					result=num1/num;
					num=0;num1=0;
					operator=0;
					break;
			}
		}
		else if(button==99)
		{
			num=0;
			num1=0;
			result=0;
			operator=0;
		}
		else if(button==43)
		{
			num1=num;
			num=0;
			operator=1;
		}
		else if(button==45)
		{
			num1=num;
			num=0;
			operator=2;
		}
		else if(button==42)
		{
			num1=num;
			num=0;
			operator=3;
		}
		else if(button==47)
		{
			num1=num;
			num=0;
			operator=4;
		}
		else
		{
			if(button==10)
			{
				num=num*10;
			}
			else if(button>0)
			{
				num=num*10+button;
			}
		}
	}
	if(button==0)
				{
					status=0;
				}
}
int get_touch()
{
	if(x>1000 && y>1000)
	{
		return 0;
	}
	if(y>150 && y<365 && x>745 && x<915 )
	{
		return 1;
	}
	else if(y>365 && y<580 && x>745 && x<915 )
	{
		return 2;
	}
	else if(y>580 && y<780 && x>745 && x<915 )
	{
		return 3;
	}
	else if(y>150 && y<365 && x>515 && x<745 )
		{
			return 4;
		}
	else if(y>365 && y<580 && x>515 && x<745 )
		{
			return 5;
		}
	else if(y>580 && y<780 && x>515 && x<745 )
		{
			return 6;
		}
	else if(y>150 && y<365 && x>290 && x<515 )
		{
			return 7;
		}
	else if(y>365 && y<580 && x>290 && x<515 )
		{
			return 8;
		}
	else if(y>580 && y<780 && x>290 && x<515 )
		{
			return 9;
		}
	else if(y>365 && y<580 && x>100 && x<290 )
		{
			return 10;
		}
	else if(y>150 && y<365 && x>100 && x<290 )
		{
			return 'c';
		}
	else if(y>580 && y<780 && x>100 && x<290 )
		{
			return '/';
		}
	else if(y>780 && y<1000 && x>745 && x<915 )
		{
			return '+';
		}
	else if(y>780 && y<1000 && x>515 && x<745 )
		{
			return '-';
		}
	else if(y>780 && y<1000 && x>290 && x<515 )
		{
			return '*';
		}
	else if(y>780 && y<1000 && x>100 && x<290 )
		{
			return "=";
		}
}


int read_x()
{
	int x;
	DDRA|=(1<<1)|(1<<3);
	DDRA&=~(1<<2);
	DDRA&=~(1<<0);
	PORTA|=(1<<1);
	PORTA&=~(1<<3);
	_delay_ms(1);
	x=read_adc(2);
	return x;
}

int read_y()
{
	int y;
	DDRA|=(1<<0)|(1<<2);
	DDRA&=~(1<<1);
	DDRA&=~(1<<3);
	PORTA|=(1<<0);
	PORTA&=~(1<<2);
	_delay_ms(1);
	y=read_adc(1);
	return y;
}
