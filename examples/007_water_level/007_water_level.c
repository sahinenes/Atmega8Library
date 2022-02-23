/*
 * Atmega8LibExamples.cpp
 *
 * Created: 12.01.2022 21:53:40
 * Author : Enes
 */ 



#include "inc/atmega8xx_usart.h"
#include "inc/atmega8xx_adc.h"
#include "interrupt.h"


// water level -> ADC0 and UART 

int main(void)
{
	

	
	
	
	USART_t usart;
	usart.characterSize=USART_CHARACTER_8;
	usart.clockPolarity=USART_CLK_PLRTY_RSNG;
	usart.operation=USART_OPERATION_ASYNC;
	usart.parityMode=USART_PARITY_DISABLED;
	usart.stop=USART_STOP_1;
	usart.USARTbaudRate=4800;
	usartInit(&usart);

	FILE usart0_str = FDEV_SETUP_STREAM(usartTransmit, NULL, _FDEV_SETUP_WRITE);
	stdout=&usart0_str;
	
	sei();

	printf("usart init");
	
	adcInit(ADC_REF_AVCC,ADC0,ADC_DIVISION_64);
	
	
	
	
	
	

	
	while (1)
	{
		
		uint16_t adc_value=adcValue();
		
		printf("adc value: %d \n",adc_value);
			
	
		_delay_ms(100);
		
		
	}

}

