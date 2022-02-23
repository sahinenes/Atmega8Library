/*
 * Atmega8LibExamples.cpp
 *
 * Created: 12.01.2022 21:53:40
 * Author : Enes
 */ 


#include "inc/atmega8xx_usart.h"
#include "interrupt.h"


int main(void)
{
	
	USART_t usart;
	usart.characterSize=USART_CHARACTER_8;
	usart.clockPolarity=USART_CLK_PLRTY_RSNG;
	usart.operation=USART_OPERATION_ASYNC;
	usart.parityMode=USART_PARITY_DISABLED;
	usart.stop=USART_STOP_1;
	usart.USARTbaudRate=9600;
	usartInit(&usart);
	
	FILE usart0_str = FDEV_SETUP_STREAM(usartTransmit, NULL, _FDEV_SETUP_WRITE);
	stdout=&usart0_str;
	sei();
	
	printf("usart init");
	
	
	

		
		
 		

		 
		 
    while (1) 
    {


		printf("loop");
		_delay_ms(1000);

		
		
    }
}

