#include <avr/io.h>
#include <util/delay.h>
#include "lcd_lib.h"
#include<stdio.h>

#include<adc_lib.h>
int main()
{
char A[20]= "     ";
int s1,s2;
DDRD=255;
ADCinit();
LCDinit();
LCDclr();

while(1)
{
  s1=read_adc(4);
  s2=read_adc(5);

  if(s1<850&s2<850)  /// change the value according the sensor value
  PORTD=0b10010000;// forward when both sensor are in white surface

  if(s1>850&s2<850)
  PORTD=0b10100000;// right when one sensor in black & one sensor in white surface

  if(s1<850&s2>850)
  PORTD=0b01010000;// left when one sensor in white & one sensor in black surface

  if(s1>850&s2>850)
  PORTD=0b10010000;// forward when both sensor are in black surface

  sprintf(A, "s1=%d s2=%d ", s1,s2);
  LCDGotoXY(0,0);
  LCDstring(A,14);

}
}
