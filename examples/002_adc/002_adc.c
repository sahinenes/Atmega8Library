/*
 * Atmega8LibExamples.cpp
 *
 * Created: 12.01.2022 21:53:40
 * Author : Enes
 */ 


#include "inc/atmega8xx_gpio.h"
#include "inc/atmega8xx_adc.h"

int main(void)
{
 
 		GPIO_t led;
 		led.DDRx=DDRC;
 		led.PORTx=PORTC;
 		led.PINx=PINC;
 		led.GPIO_Mode=GPIO_MODE_OUTPUT;
 		led.GPIO_Pin=2;
 		gpioInit(&led);                          // led init -> PORTC -> Pin 2
		 
		 
		adcInit(ADC_REF_AVCC,ADC0,ADC_DIVISION_64);
		
		
 		

		 
		 
    while (1) 
    {
			
			if (adcValue()>=670)
			{
				digitalWrite(&led,HIGH);		 //  PORTC Pin 2 (led) state 1 (high)
			}
			else
			{
				digitalWrite(&led,LOW);		   //  PORTC Pin 2 (led) state 0 (low)
			}

		

		
		
    }
}

