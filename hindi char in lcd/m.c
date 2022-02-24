
#include<avr/io.h>
#include<util/delay.h>
#include<lcd_lib.h>
#include<avr/pgmspace.h>
const uint8_t backslash[] PROGMEM=
{

0b00011111, // change value according to your hindi charcter
0b00000100,
0b00001110,
0b00010101,
0b00010101,
0b00001101,
0b00000100,
0b00000100

};
int main()
{

	int i=0, j=0;
	char a[16];
	LCDinit();
	LCDclr();
	while(1)
	{
		LCDdefinechar(backslash,0);
		LCDGotoXY(0,0);
		LCDsendChar(0);
		_delay_ms(100);
}
}
