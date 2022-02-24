#include<avr/io.h>


void set_timer2_normal();	//sets timer0 to normal operation

void set_timer2_ctc(int i);	//sets timer0 to clear timer on compare mode
							//i=0:OC0 is disconnected
							//i=1:toggle OC0 on compare match
							//i=2:clear OC0 in compare match
							//i=3:set OC0 on compare match

void set_timer2_prescalar(int i);//set the prescalar of timer0
								//i=0:timer0 stopped
								//i=1:clk/1
								//i=2:clk/8
								//i=3:clk/32
								//i=4:clk/64
								//i=5:clk/128
								//i=6:clk/256
								//i=7:clk/1024



void enable_timer2_overflowint();//overflow interrupt is enabled

void enable_timer2_ctcint();//compare match interrupt is enabled

void disable_timer2_overflowint();//overflow interrupt is disabled

void disable_timer2_ctcint();//compare match interrupt is disabled

void set_timer2value(int i);//sets TCNT0=i

void set_compare2value(int i);//sets OCR0=i

void stop_timer2();//timer0 stopped
