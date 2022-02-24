/************************************************************

Libray fuctions to access the popular DS1307 RTC IC with AVR
Microcontroller.

The libray has just two functions. One reads the register whose
address is provided. Other writes to the given register with
given data.Please see DS1307 Datasheet for more info on
the registers.

Requires eXtreme Electronics Low Level I2C Libray.

PLEASE SEE WWW.EXTREMEELECTRONICS.CO.IN FOR DETAILED 
SCHEMATICS,USER GUIDE AND VIDOES.

COPYRIGHT (C) 2008-2009 EXTREME ELECTRONICS INDIA

************************************************************/

#include <avr/io.h>

#include "I2C.h"
#include "ds1307.h"

/***************************************************

Function To Read Internal Registers of DS1307
---------------------------------------------

address : Address of the register
data: value of register is copied to this.


Returns:
0= Failure
1= Success
***************************************************/

uint8_t ds1307read(uint8_t address,uint8_t *data)
{
	uint8_t res;	//result
	
	//Start
	I2CStart();
	
	//SLA+W (for dummy write to set register pointer)
	res=I2CWriteByte(0b11010000);	//DS1307 address + W
	
	//Error
	if(!res)	return FALSE;
	
	//Now send the address of required register
	res=I2CWriteByte(address);
	
	//Error
	if(!res)	return FALSE;
	
	//Repeat Start
	I2CStart();
	
	//SLA + R
	res=I2CWriteByte(0b11010001);	//DS1307 Address + R
	
	//Error
	if(!res)	return FALSE;
	
	//Now read the value with NACK
	res=I2CReadByte(data,0);
	
	//Error
	if(!res)	return FALSE;
	
	//STOP
	I2CStop();
	
	return TRUE;
}

/***************************************************

Function To Write Internal Registers of DS1307
---------------------------------------------

address : Address of the register
data: value to write.


Returns:
0= Failure
1= Success
***************************************************/

uint8_t ds1307write(uint8_t address,uint8_t data)
{
	uint8_t res;	//result
	
	//Start
	I2CStart();
	
	//SLA+W
	res=I2CWriteByte(0b11010000);	//DS1307 address + W
	
	//Error
	if(!res)	return FALSE;
	
	//Now send the address of required register
	res=I2CWriteByte(address);
	
	//Error
	if(!res)	return FALSE;
	
	//Now write the value
	res=I2CWriteByte(data);
	
	//Error
	if(!res)	return FALSE;
	
	//STOP
	I2CStop();
	
	return TRUE;
}
	
	
void set_time(int hr,int min,int sec,int ap)
{
	int temp=0;
	ds1307write(0x00,sec);
	ds1307write(0x01,min);
	hr=hr&0b00011111;
	ap=ap&0b00000001;
	hr|=(1<<6);
	if(ap==1)////PM
	{
		temp=(ap<<5);

	}
	else///AM
	{
		temp=(ap<<5);
	}
	hr=hr|temp;
	ds1307write(0x02,hr);
}


void read_time(int *hr,int *min,int *sec,int *ap)
{
	ds1307read(0x02,hr);
	*hr= *hr & 0b00111111;
	*ap= *hr>>5;
	*hr= *hr & 0b00011111;
	ds1307read(0x01,min);
	*min=*min & 0b01111111;
	ds1307read(0x00,sec);
	*sec=*sec & 0b01111111;
}

void ds1307init()
{
	uint8_t temp;
	ds1307read(0x00,&temp);
	temp&=(~(1<<7));
	ds1307write(0x00,temp);

	//Set 12 Hour Mode
	ds1307read(0x02,&temp);
	//Set 12Hour BIT
	temp|=(0b01000000);
	//Write Back to DS1307
	ds1307write(0x02,temp);
}
