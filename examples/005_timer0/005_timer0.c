/*
 * Atmega8LibExamples.cpp
 *
 * Created: 12.01.2022 21:53:40
 * Author : Enes
 */ 


#include "inc/atmega8xx_timer.h"
#include "inc/atmega8xx_gpio.h"


GPIO_t led;
uint8_t overflow=0;

int main(void)
{

	
	

	
	led.DDRx=DDRC;
	led.GPIO_Mode=GPIO_MODE_OUTPUT;
	led.GPIO_Pin=2;
	led.PINx=PINC;
	led.PORTx=PORTC;
	
	gpioInit(&led);			 // led init -> PORTC -> Pin 2
	
	

	
	timer0Init(TIMER0_PRESCALING_1024,TIMER0_INTERRUPT_DISABLE);  // timer init -> prescaling 256 -> interrupt disable
	
	
	

	
	while (1)
	{
		
		if (timer0GetValue()>=14)       // prescaler->1024  14 -> 250 ms    30-> 500ms  60->1000ms
		{
			overflow++;
			
			timer0SetValue(0);
			if (overflow>=16)
			{
				if(digitalRead(&led)==HIGH)
				{
					digitalWrite(&led,LOW);
					overflow=0;
				}
				else
				{
					digitalWrite(&led,HIGH);
					overflow=0;
				}
			}
			
		}
		

		

		
		
		
	}
}
