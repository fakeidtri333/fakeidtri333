#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/signal.h>
#include <inttypes.h>

#include <util/delay.h>

#define F_OSC 4000000		           /* oscillator-frequency in Hz */
#define UART_BAUD_RATE 4800
#define UART_BAUD_CALC(UART_BAUD_RATE,F_OSC) ((F_OSC)/((UART_BAUD_RATE)*16l)-1)
#define rx_buffersize 100


char rx_buffer[rx_buffersize];
int rx_wrindex,rx_rdindex,rx_overflow;
char rec[rx_buffersize];
char *p;

///////////////////////////////////global variables////////////////


char lcdbuff[16];
int i;
int j;

char input1[]="$PSRF103,04,00,00,01*20",
input2[]="$PSRF103,05,00,00,01*21",
input3[]="$PSRF103,01,00,00,01*25",
input4[]="$PSRF103,02,00,00,01*26",
input5[]="$PSRF103,03,00,00,01*27";

char data[100];
char gga[80];

char loc[15][15];



	char temp[]="l";
	char time[10];
	char lat[8];
	char latloc[2];
	char lon[8];
	char lonloc[2];
	char valid[2];
	char satellite[3];
	
	char latitude[10];
	char longitude[10];


int status=0;

////////////////////////////////////////////////////////////////////


/////////////////////////SPI////////////////////////////////////////

ISR (SPI_STC_vect)
{
	char data;
	data=SPDR;
	// Place your code here
}

void send_spi_char(char dat)
{

    SPDR=dat;
}
  
void send_spi_string(char dat[])
{
    int i;   
	//strcpy(temp,latitude);
	//strcat(temp,longitude);
	for(i=0;i<strlen(dat);i++)
    {
        send_spi_char(dat[i]);
        _delay_ms(10);
    }
}        







////////////////////////////////////////////////////////////////////////////


void usart_putc(unsigned char c) {
   // wait until UDR ready
	while(!(UCSRA & (1 << UDRE)));
	UDR = c;    // send character
	_delay_ms(10);
}

void uart_puts (char *s) {
	//  loop until *s != NULL
	while (*s) {
		usart_putc(*s);
		s++;
	}
}

void init(void) {
	// set baud rate
	UBRRH = (uint8_t)(UART_BAUD_CALC(UART_BAUD_RATE,F_OSC)>>8);
	UBRRL = (uint8_t)UART_BAUD_CALC(UART_BAUD_RATE,F_OSC);

	// Enable receiver and transmitter; enable RX interrupt
	UCSRB = (1 << RXEN) | (1 << TXEN) | (1 << RXCIE);

	//asynchronous 8N1
	UCSRC = (1 << URSEL) | (3 << UCSZ0);
}

// INTERRUPT can be interrupted
// SIGNAL can't be interrupted
SIGNAL (SIG_UART_RECV) { // USART RX interrupt
	
	//cli();
	unsigned char c;
	status=1;
	c = UDR;
	if(rx_wrindex >= rx_buffersize)
	{
		
		rx_overflow=1;
		rx_wrindex=0;
	}
	rx_buffer[rx_wrindex]=c;
	rx_wrindex++;
	status=1;
	//sei();
	
}







int main(void) 
{


	///////////////////master//////////
	PORTB=0x00;
	DDRB=0xB8;
	SPCR=0xD1;
	SPSR=0x00;
	///////////////////////////////////
	
	
	
	_delay_ms(2000);
	init(); // init USART
	LCDinit();
	LCDclr();
	
	
	sei();
	_delay_ms(2000);
	initgps();
	while (1) 
	{
		//sprintf(lcdbuff,"%3d",rx_wrindex);
		//LCDGotoXY(0,0);
		//LCDstring(lcdbuff,strlen(lcdbuff));
		if(rx_overflow)
		{
			cli();
			process();
			split1();
			LCDclr();
			sei();
		}
		else
		{
			
		}
		if(valid[0]!='1')
		{
			sprintf(lcdbuff,"DATA NOT VALID");
			LCDGotoXY(0,3);
			LCDstring(lcdbuff,strlen(lcdbuff));		
			
			LCDGotoXY(0,1);
			LCDstring(latitude,strlen(latitude));
			
			LCDGotoXY(0,2);
			LCDstring(longitude,strlen(longitude));
			
			LCDGotoXY(14,0);
			LCDstring(satellite,strlen(satellite));
			
		}
		
		
		else
		{
			
			
		/*	sprintf(lcdbuff,"DATA VALID");
			LCDGotoXY(0,3);
			LCDstring(lcdbuff,strlen(lcdbuff));
		*/	
			LCDGotoXY(0,0);
			LCDstring(latitude,strlen(latitude));
			
			LCDGotoXY(0,1);
			LCDstring(longitude,strlen(longitude));
			
			LCDGotoXY(14,0);
			LCDstring(satellite,strlen(satellite));
			
			send_spi_char('^');
			_delay_ms(10);
			send_spi_string(latitude);
			send_spi_char('*');
			_delay_ms(10);
			send_spi_string(longitude);
		}
	}
	return 0;
}

void initgps()
{
	if(status)
	{
		sprintf(lcdbuff,"GPS AVALIABLE");
		LCDGotoXY(0,0);
		LCDstring(lcdbuff,strlen(lcdbuff));
		sprintf(lcdbuff,"SENDING COMMANDS");
		LCDGotoXY(0,1);
		LCDstring(lcdbuff,strlen(lcdbuff));
		cli();
		uart_puts(input1);
		usart_putc(0x0d);
		usart_putc(0x0a);
		_delay_ms(2000);
		uart_puts(input2);
		usart_putc(0x0d);
		usart_putc(0x0a);
		_delay_ms(2000);
		uart_puts(input3);
		usart_putc(0x0d);
		usart_putc(0x0a);
		_delay_ms(2000);
		uart_puts(input4);
		usart_putc(0x0d);
		usart_putc(0x0a);
		_delay_ms(2000);
		uart_puts(input5);
		usart_putc(0x0d);
		usart_putc(0x0a);
		_delay_ms(2000);
		sei();
		sprintf(lcdbuff,"initialized");
		LCDGotoXY(0,1);
		LCDstring(lcdbuff,strlen(lcdbuff));
		rx_wrindex=0;
	}
	else
	{
		sprintf(lcdbuff,"GPS NOT AVALIA");
		LCDGotoXY(0,0);
		LCDstring(lcdbuff,strlen(lcdbuff));
		while(1)
		{
		}
		
	}
	LCDclr();
}


void process()
{
	int i=0,j=0;
	rx_wrindex=0;
	rx_overflow=0;
	strcpy(data,rx_buffer);
	for(i=0;i<200;i++)
	if(data[i]=='$')
	{
	/*	sprintf(lcdbuff,"$ found at%3d",i);
		LCDGotoXY(0,0);
		LCDstring(lcdbuff,strlen(lcdbuff));*/
		if(i<100)
		{
			for(j=0;j<80;j++)
			{
				gga[j]=data[i+j];
			}
			
		}
//		LCDGotoXY(0,0);
//		LCDstring(gga,16);
	}
	
}

void split1()
{
	int i=0,j=0,k=0,l=0;
	for(i=0;i<strlen(gga);i++)
	{
		if(gga[i]!=',')
		{
			loc[j][k]=gga[i];
			k++;
		}
		else
		{
			j++;
			k=0;
		}
	}
	
	strcpy(time,loc[1]);
	
	strcpy(latitude,loc[2]);
	strcat(latitude,loc[3]);
	
	strcpy(longitude,loc[4]);
	strcat(longitude,loc[5]);
	
	strcpy(valid,loc[6]);
	
	strcpy(satellite,loc[7]);
	
	
	
}
