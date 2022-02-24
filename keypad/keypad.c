#include<avr/io.h>
#include<util/delay.h>
#include<lcd_lib.h>
#define keypad_port PORTA
#define keypad_ddr DDRA
#define keypad_pin PINA

int get_key()
{
	keypad_ddr=1;
	_delay_us(10);
	while(keypad_ddr>0)
	{
		keypad_port=~keypad_ddr;_delay_us(10);
		if(keypad_pin!=keypad_port) return keypad_pin;
		keypad_ddr=keypad_ddr<<1;
	}
	return 0;
}

void main()
{
	int k;
	char buff[16];
	keypad_port=0xff;
	keypad_ddr=0x00;
	LCDinit();
	LCDclr();
	while(1)
	{
		k=get_key();
		sprintf(buff,"%3d",k);
		LCDGotoXY(0,0);
		LCDstring(buff,strlen(buff));
	}
}
