/*
 * spi_lib.c
 *
 *  Created on: Apr 26, 2011
 *      Author: simplifix
 */



#include<avr/io.h>

int spiint=0;
void set_spi_master()
{
	DDRB|=(1<<5);// set mosi pin
	DDRB|=(1<<7);// set sck pin
	DDRB|=(1<<4);///set ss pin
	DDRB&=~(1<<6);// set miso pin
	SPCR|=(1<<MSTR);
	SPCR|=(1<<SPE);
}

void set_spi_slave()
{
	DDRB&=~(1<<5);// set mosi pin
	DDRB&=~(1<<7);// set sck pin
	DDRB&=~(1<<4);// set ss pin
	DDRB|=(1<<6);// set miso pin
	SPCR&=~(1<<MSTR);
	SPCR|=(1<<SPE);
}


unsigned char sendchar_spi(unsigned char data)
{
	if(spiint)
	{
		SPDR=data;
		return 0;
	}
	else
	{
		SPDR=data;
		while ((SPSR & (1<<7))==0);//SPIF
		return SPDR;
	}

}
void set_spi_prescalar(int pre)
{
	int ii,jj;
	ii=pre&0b00000011;
	SPCR&=0b11111100;
	SPCR|=ii;
	jj=pre&0b00000100;
	jj=jj>>2;
	SPSR&=0b11111110;
	SPSR|=jj;
}

void enable_spiint()
{
	SPCR|=(1<<SPIE);
	spiint=1;
}

void Disable_spiint()
{
	SPCR&=~(1<<SPIE);
	spiint=0;
}

void set_spi_lsbfirst()
{
	SPCR|=(1<<DORD);
}

void set_spi_msbfirst()
{
	SPCR&=~(1<<DORD);
}

void set_spi_clkpolarity(int cpol)
{
	cpol=cpol%2;
	SPCR&=~(1<<CPOL);
	SPCR|=(cpol<<CPOL);
}

void set_spi_clkphase(int cpha)
{
	cpha=cpha%2;
	SPCR=~(1<<CPHA);
	SPCR|=(cpha<<CPHA);
}
