#include <avr/io.h>
#include <util/delay.h>
#include "lcd_lib.h"
#include <stdio.h>
#include<avr/interrupt.h>
#include<timer0.h>
// Declare your global variables here
char A[20]="" ,ms=0,sec=0,min=0,hr=0;
ISR(TIMER0_OVF_vect){
	set_timer0value(10);
	ms++;
	if(ms>10){
		ms=0;sec++;
		if(sec>59){
			sec=0;min++;
			if(min>59){
				min=0;hr++;
				if(hr>23){
					hr=0;
				}
		}
	}
	sprintf(A," <<<%d:%d:%d>>> ",hr,min,sec);
	LCDGotoXY(0,0);
	LCDdisplay(A);
	}
}


int main(void){
	set_timer0value(0);
	set_timer0_normal();
	set_timer0_prescalar(5);
	enable_timer0_overflowint();
	sei();// enable interrupts
	LCDinit();// LCD module initialization
	LCDclr();
	while (1){

	}
}
