
#include<avr/io.h>
#include<util/delay.h>
#include<lcd_lib.h>
#include<adc_lib.h>

void main()
{

	int i,j,k,m,a,b,c,d;

	int D1=" 700  ";
	int D2=" 700 ";
	int D3=" 700  ";
	int D4=" 700  ";
	char A[20]=" ";
	char B[20]=" ";
	DDRD=255;
	LCDinit();
	LCDclr();
	ADCinit();
	while(1)
	{
		i=read_adc(3);
		j=read_adc(4);
		k=read_adc(5);
		m=read_adc(6);
		
	/*	sprintf(A,"i=%d    j=%d     ",i,j);
		LCDGotoXY(0,0);
		LCDdisplay(A);
		_delay_ms(100);
		
		sprintf(B,"k=%d     m=%d     ",k,m);
		LCDGotoXY(0,1);
		LCDdisplay(B,16);*/

		if((i<D1)&(j<D2)&(k>D3)&(m<D4))
		{
			sprintf(A,"* Move Forward*      "        ,i,j);      /// press 2 on both device
			LCDGotoXY(0,0);
			LCDstring(A,20);
            PORTD=0b01010000;
		}
		if((i<D1)&(j>D2)&(k<D3)&(m>D4))
		{
			sprintf(A," *Stop*              "   ,k,m);   // press 5 to off
	    	LCDGotoXY(0,0);
			LCDstring(A,16);
			PORTD=0b00000000;
		}
	   if((i>D1)&(j<D2)&(k<D3)&(m<D4))
	    {
		   sprintf(A,"*Move Backward*          ",i,j);   // press 8 to on
		   LCDGotoXY(0,0);
		   LCDstring(A,20);
		   PORTD=0b10100000;
		}
	  if((i<D1)&(j>D2)&(k>D3)&(m<D4))
		{
		   sprintf(A,"*Move Right*          ",k,m);   // press 6 to on one device
		   LCDGotoXY(0,0);
		   LCDstring(A,16);
    	   PORTD=0b00010000;
		}
		if((i<D1)&(j>D2)&(k<D3)&(m<D4))
		{
			sprintf(A,"*Move Left*             ",k,m);   // press 4 to on another device
		    LCDGotoXY(0,0);
		    LCDstring(A,20);
			PORTD=0b01000000;
		}
	}
}




