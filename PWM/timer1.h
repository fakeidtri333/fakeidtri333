#include<avr/io.h>


void set_timer1_normal();	//sets timer1 to normal operation

void set_timer1_ctca(int i);	//sets timer1 to clear timer on compare mode
							//i=0:OC1A is disconnected
							//i=1:toggle OC1A on compare match
							//i=2:clear OC1A in compare match
							//i=3:set OC1A on compare match

void set_timer1_ctcb(int i);	//sets timer1 to clear timer on compare mode
							//i=0:OC1B is disconnected
							//i=1:toggle OC1B on compare match
							//i=2:clear OC1B in compare match
							//i=3:set OC1B on compare match

void set_timer1_prescalar(int i);//set the prescalar of timer1
								//i=0:timer1 stopped
								//i=1:clk/1
								//i=2:clk/8
								//i=3:clk/64
								//i=4:clk/256
								//i=5:clk/1024
								//i=6:ext clock on falling edge
								//i=7:ext clock on rising edge



void enable_timer1_overflowint();//overflow interrupt is enabled

void enable_timer1_ctcaint();//compare match interrupt is enabled

void enable_timer1_ctcbint();//compare match interrupt is enabled

void disable_timer1_overflowint();//overflow interrupt is disabled

void disable_timer1_ctcaint();//compare match interrupt is disabled

void disable_timer1_ctcbint();//compare match interrupt is disabled

void set_timer1value(int i);//sets TCNT1=i

void set_compare1avalue(int i);//sets OCR1A=i

oid set_compare1bvalue(int i);//sets OCR1B=i

void stop_timer1();//timer1 stopped
