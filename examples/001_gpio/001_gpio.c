/*
 * Atmega8LibExamples.cpp
 *
 * Created: 12.01.2022 21:53:40
 * Author : Enes
 */ 


#include "inc/atmega8xx_gpio.h"

int main(void)
{
 
 		GPIO_t led;
 		led.DDRx=DDRC;
 		led.PORTx=PORTC;
 		led.PINx=PINC;
 		led.GPIO_Mode=GPIO_MODE_OUTPUT;
 		led.GPIO_Pin=2;
 		gpioInit(&led);                          // led init -> PORTC -> Pin 2
 		
 		GPIO_t buton;
 		buton.DDRx=DDRD;
 		buton.PORTx=PORTD;
 		buton.PINx=PIND;
 		buton.GPIO_Mode=GPIO_MODE_INPUT;
 		buton.GPIO_Pin=2;
 		gpioInit(&buton);						// buton init -> PORTD -> Pin 2
		 
		 
    while (1) 
    {
		
		
		if (digitalRead(&buton)==LOW)         // if PORTD Pin 2 (buton) state is 0(low) 
		{
			digitalWrite(&led,HIGH);		 //  PORTC Pin 2 (led) state 1 (high)
		}
		else
		{
			digitalWrite(&led,LOW);			//  PORTC Pin 2 (led) state 0 (low)
		}
		
		
    }
}

