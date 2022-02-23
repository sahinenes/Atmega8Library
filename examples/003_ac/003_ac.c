/*
 * Atmega8LibExamples.cpp
 *
 * Created: 12.01.2022 21:53:40
 * Author : Enes
 */ 


#include "inc/atmega8xx_gpio.h"
#include "inc/atmega8xx_ac.h"

int main(void)
{
 
 		GPIO_t led;
 		led.DDRx=DDRC;
 		led.PORTx=PORTC;
 		led.PINx=PINC;
 		led.GPIO_Mode=GPIO_MODE_OUTPUT;
 		led.GPIO_Pin=2;
 		gpioInit(&led);                          // led init -> PORTC -> Pin 2
		 
		 
		analogComparatorInit(AC_NEGATIVE_INPUT_AIN1,DISABLE); // analog comparator negative input AIN1 and interrupt disable
		
		
 		

		 
		 
    while (1) 
    {
			
			if (analogComparatorValue())		  //if comparator value is true
			{
				digitalWrite(&led,HIGH);		 //  PORTC Pin 2 (led) state 1 (high)
			}
			else
			{
				digitalWrite(&led,LOW);		   //  PORTC Pin 2 (led) state 0 (low)
			}

		

		
		
    }
}

