#include<avr/io.h>
#include<util/delay.h>

#define alarm_pin 7
#define alarm_port PORTD
#define alarm_ddr DDRD

#define lock_pin1 4
#define lock_pin2 5
#define lock_port PORTD
#define lock_ddr DDRD


#define keypad_port PORTA
#define keypad_ddr DDRA
#define keypad_pin PINA


char buff[16];
char pass[16]="jjjj";
char password[]="12345";
int k,key,n=0,key_status=0;



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
	keypad_ddr=0x00;
	keypad_port=0xff;
	lock_ddr|=(1<<lock_pin1)|(1<<lock_pin2);
	lock_port|=(1<<lock_pin1)|(1<<lock_pin2);

	alarm_ddr|=(1<<alarm_pin);
	alarm_port|=(1<<alarm_pin);

	LCDinit();
	LCDclr();
	while(1)
	{
		k=get_key();
		define_key();
		sprintf(buff,"Enter Password");
		//sprintf(buff,"%3d %3d",k,key_status);

		LCDGotoXY(0,0);
		LCDstring(buff,strlen(buff));
		LCDGotoXY(0,1);
		LCDstring("***********",n);
		//LCDstring(pass,strlen(pass));
	}
}

void define_key()
{
	if(k==0)
		key_status=0;
	if(key_status==0)
	{
		switch(k)
		{
			case 252:
						pass[n]='1';
						n++;
						key_status=1;
						break;
			case 245:
						pass[n]='2';
						n++;
						key_status=1;
						break;
			case 237:
						pass[n]='3';
						n++;
						key_status=1;
						break;
			case 231:
						pass[n]=')';
						n++;
						key_status=1;
						break;
			case 125:
						pass[n]='4';
						n++;
						key_status=1;
						break;
			case 246:
						pass[n]='5';
						n++;
						key_status=1;
						break;
			case 219:
						pass[n]='6';
						n++;
						key_status=1;
						break;
			case 215:
						n=0;
						LCDclr();
						sprintf(pass,"        ");
						key_status=1;
						break;
			case 190:
						pass[n]='7';
						n++;
						key_status=1;
						break;
			case 189:
						pass[n]='8';
						n++;
						key_status=1;
						break;
			case 187:
						pass[n]='9';
						n++;
						key_status=1;
						break;
			case 183:
						if(n>0)
							n--;
						LCDclr();
						pass[n]=' ';
						key_status=1;
						break;
			case 120:
						pass[n]='*';
						n++;
						key_status=1;
						break;
			case 126:
						pass[n]='0';
						n++;
						key_status=1;
						break;
			case 123:
						pass[n]='#';
						n++;
						key_status=1;
						break;
			case 119:
						n=0;
						if(strncmp(pass,password,5)==0)
						{
							sprintf(pass,"        ");
							LCDclr();
							sprintf(buff," PASSWORD RIGHT");
							LCDGotoXY(0,0);
							LCDstring(buff,strlen(buff));
							trigger_lock();
							LCDclr();
						}
						else
						{

							LCDclr();
							sprintf(buff," PASSWORD WRONG");
							LCDGotoXY(0,0);
							LCDstring(buff,strlen(buff));
							trigger_alarm();
						}
						key_status=1;
						break;
		}
	}
}


void trigger_lock()
{
	lock_port|=(1<<lock_pin1);
	lock_port|=(1<<lock_pin2);
	lock_port&=~(1<<lock_pin1);
	_delay_ms(1000);
	lock_port|=(1<<lock_pin1);
	_delay_ms(5000);
	lock_port&=~(1<<lock_pin2);
	_delay_ms(1000);
	lock_port|=(1<<lock_pin2);
}

void trigger_alarm()
{
	alarm_port|=(1<<alarm_pin);
	while(1)
	{

	}
}
