#include<avr/io.h>
#include <util/delay.h>
#include "lcd_lib.h"
#include <stdio.h>
#include<uart_lib.h>
#include<avr/interrupt.h>
int main(void)

{
int flag=0;
	char a[21]="at+cmgs=\"9595458765\"";
	LCDinit();
	LCDclr();
		    set_uartbaud(9600);
			//enable_uart_rxcint();
			//sei();
			while(1)
			{

			if(flag==0){
				LCDGotoXY(0,0);
				LCDstring("Sending Message",15);
//			 _delay_ms(1000);
			 sendstring_uart(a);
			_delay_ms(1);
			 sendchar_uart(0x0D);_delay_ms(1000);
			 sendstring_uart("red ball detected");_delay_ms(1000);
			 sendchar_uart(0x0D);_delay_ms(1000);
			 sendchar_uart(0x1A);_delay_ms(1000);
			 flag=1;			}	}
	
}

