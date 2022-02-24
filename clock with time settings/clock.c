#include <avr/io.h>
#include <util/delay.h>
#include "lcd_lib.h"
#include <stdio.h>
#include<avr/interrupt.h>
#include<ext_interrupt.h>
#include<timer0.h>
// Declare your global variables here
char A[20]=" " ,ms=0,sec=0,min=0,hr=0,status=0;
ISR(INT0_vect){
if(status==0){}
else if(status==1){ sec++;}
else if(status==2){ min++;}
else if(status==3){ hr++;}
}
ISR(INT1_vect){
status++;
if(status>3)
status=0;
LCDclr();
}
ISR(TIMER0_OVF_vect){
set_timer0value(10);
if(status==0){
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
LCDstring(A,strlen(A));
}
}
if(status==1){
sprintf(A,"Set second=%d ",sec);
LCDGotoXY(0,0);
LCDstring(A,strlen(A));
}
if(status==2){
sprintf(A,"Set minute=%d ",min);
LCDGotoXY(0,0);
LCDstring(A,strlen(A));
}
if(status==3){
sprintf(A,"Set hour=%d ",hr);
LCDGotoXY(0,0);
LCDstring(A,strlen(A));
}
}

int main(void){
PORTD=0b00001100;
enable_INT0(2);
enable_INT1(2); //from high to low
set_timer0value(0);
set_timer0_normal();
set_timer0_prescalar(5);
enable_timer0_overflowint();
LCDinit();// LCD module initialization
LCDclr();
sei();// enable interrupts
while (1){
}
}
