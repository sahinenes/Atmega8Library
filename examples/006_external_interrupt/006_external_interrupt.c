/*
 * Atmega8LibExamples.cpp
 *
 * Created: 12.01.2022 21:53:40
 * Author : Enes
 */ 



#include "inc/atmega8xx_gpio.h"
#include "interrupt.h"


GPIO_t led,button;

int main(void)
{

	
	
	button.DDRx=DDRD;
	button.GPIO_Mode=GPIO_MODE_EXTERNAL_INTERRUPT;
	button.GPIO_Pin=0;
	button.PINx=PIND;
	button.PORTx=PORTD;
	
	gpioInit(&button);			 // button init -> PORTD -> Pin 0 -> INT0
	externalInterrupt(INT0,INTERRUPT_RISING);
	
	sei();
	

	
	led.DDRx=DDRC;
	led.GPIO_Mode=GPIO_MODE_OUTPUT;
	led.GPIO_Pin=2;
	led.PINx=PINC;
	led.PORTx=PORTC;
	
	gpioInit(&led);			 // led init -> PORTC -> Pin 2
	
	

	
	
	
	

	
	while (1)
	{
		
	}

}

ISR (INT0_vect)
{
	
	if (digitalRead(&led)==HIGH)
	{
		digitalWrite(&led,LOW);
	}
	else
	{
		digitalWrite(&led,HIGH);
	}
}