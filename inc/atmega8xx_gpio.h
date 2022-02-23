/*
 * atmega8xx_gpio.h
 *
 * Created: 17.10.2021 12:57:49
 *  Author: Enes
 */ 


#ifndef ATMEGA8XX_GPIO_H_
#define ATMEGA8XX_GPIO_H_


#include "atmega8xx.h"

/* GPIO_t Modes */
#define GPIO_MODE_INPUT         0
#define GPIO_MODE_OUTPUT        1
#define GPIO_MODE_INPUT_PULLUP  2
#define GPIO_MODE_EXTERNAL_INTERRUPT 3



#define INPUT			        0
#define OUTPUT                  1
#define INPUT_PULLUP            2




/* Pins */
#define PIN0                    0     
#define PIN1                    1  
#define PIN2                    2  
#define PIN3                    3  
#define PIN4                    4  
#define PIN5                    5  
#define PIN6                    6  
#define PIN7                    7                     


#define INTERRUPT_LOW_LEVEL      0
#define INTERRUPT_LOGICAL_CHANGE 1
#define INTERRUPT_FALLING        2
#define INTERRUPT_RISING         3


/*
GPIOx -> DDRA,DDRB,DDRC...
GPIO_Pin -> PIN0,PIN1,PIN2..
GPIO_Mode -> INPUT,OUTPUT...
GPIO_Port -> PORTA,PORTB..
*/
/* GPIO_t structure */
typedef struct GPIO_t
{
    volatile uint8_t* DDRx;
	uint8_t GPIO_Pin;
	uint8_t GPIO_Mode;
    volatile uint8_t* PORTx;
    volatile uint8_t* PINx;
	
}GPIO_t;



void gpioInit(GPIO_t *pGPIO);


void digitalWrite(GPIO_t *pGPIO,uint8_t state);
uint8_t digitalRead(GPIO_t *pGPIO);

void gpioInternalPullUp(uint8_t state);

void externalInterrupt(uint8_t INTx,uint8_t Interruptx);



#endif /* ATMEGA8XX_GPİO_H_ */