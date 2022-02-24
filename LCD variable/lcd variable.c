#include<avr/io.h>
#include<util/delay.h>
#include<lcd_lib.h>
int main()
{
	int i=0, j=0;
	char a[16];
	LCDinit();
	LCDclr();
	while(1)
	{
		sprintf(a,"i=%d  ",i);
		LCDGotoXY(0,0);
		LCDdisplay(a);
		sprintf(a,"j=%2d  ",j);
		LCDGotoXY(0,1);
		LCDdisplay(a);
		_delay_ms(500);
		i++;
		j++;
		if(j>15)
			j=0;
	}
	return 0;
}