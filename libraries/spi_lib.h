/*
 * spi_lib.h
 *
 *  Created on: Apr 26, 2011
 *      Author: simplifix
 */

#include<avr/io.h>

#ifndef SPI_LIB_H_
#define SPI_LIB_H_

void set_spi_master();//		set spi as master

void set_spi_slave();//			set spi as slave

void set_spi_prescalar(int );//		set prescalar
								//	0-fosc/4
								//	1-fosc/16
								//	2-fosc/64
								//	3-fosc/128

void enable_spiint();			//	enable spi interrupt

void Disable_spiint();			//	disable spi interrupt

void set_spi_lsbfirst();		//	set spi comm to LSB first

void set_spi_msbfirst();		//	set spi comm to MSB first

void set_spi_clkpolarity(int );	//	set spi clock polarity
								//			leading edge		trailing edge
								//	0-			rising				falling
								//	1-			falling				rising

void set_spi_clkphase(int );	//	set spi clock phase
								//			leading edge		trailing edge
								//	0-			sample				setup
								//	1-			setup				sample

#endif /* SPI_LIB_H_ */
