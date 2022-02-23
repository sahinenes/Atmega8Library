/*
 * atmega8xx_gpio.c
 *
 * Created: 17.10.2021 13:17:55
 *  Author: Enes
 */ 
#include "atmega8xx_gpio.h"


/*********************************************************************
 * @fn      		  - gpioInit
 *
 * @brief             - GPIO_t input,output,input pull up or external interrupt settings
 *
 * @param[in]         - GPIO_t
 * @param[in]         -
 * @param[in]         -
 *
 * @return            - none
 *
 * @Note              - 
 */
void gpioInit(GPIO_t *pGPIO)
{
	if(pGPIO->GPIO_Mode==GPIO_MODE_INPUT||pGPIO->GPIO_Mode==INPUT)
	{
		SFIOR|=(1<<PUD);
		*pGPIO->DDRx&=~(1<<pGPIO->GPIO_Pin);
		*pGPIO->PORTx|=(1<<pGPIO->GPIO_Pin);

	}
	else if (pGPIO->GPIO_Mode==GPIO_MODE_INPUT_PULLUP||pGPIO->GPIO_Mode==INPUT_PULLUP){ 
	    SFIOR&=~(1<<PUD);
		*pGPIO->DDRx&=~(1<<pGPIO->GPIO_Pin);
		*pGPIO->PORTx|=(1<<pGPIO->GPIO_Pin);
	
	}	
	else if (pGPIO->GPIO_Mode==GPIO_MODE_OUTPUT||pGPIO->GPIO_Mode==OUTPUT){
	    SFIOR|=(1<<PUD);
		*pGPIO->DDRx|=(1<<pGPIO->GPIO_Pin);
		*pGPIO->PORTx&=~(1<<pGPIO->GPIO_Pin);
		}
		
	else if (pGPIO->GPIO_Mode==GPIO_MODE_EXTERNAL_INTERRUPT)
	{
		SFIOR&=~(1<<PUD);
		*pGPIO->DDRx&=~(1<<pGPIO->GPIO_Pin);
		*pGPIO->PORTx|=(1<<pGPIO->GPIO_Pin);
		
	}

}


/*********************************************************************
 * @fn      		  - digitalWrite
 *
 * @brief             - GPIO_t output write low or high
 *
 * @param[in]         - GPIO_t
 * @param[in]         - HIGH ,LOW ,SET ,RESET
 * @param[in]         -
 *
 * @return            - none
 *
 * @Note              - 
 */
void digitalWrite(GPIO_t *pGPIO,uint8_t state)
{
	if (state==ENABLE||state==HIGH)
	{*pGPIO->PORTx|=(1<<pGPIO->GPIO_Pin);}
	else if (state==DISABLE||state==LOW)
    {*pGPIO->PORTx&=~(1<<pGPIO->GPIO_Pin);}	
}

/*********************************************************************
 * @fn      		  - digitalRead
 *
 * @brief             - GPIO_t input read pin
 *
 * @param[in]         - GPIO_t
 * @param[in]         - 
 * @param[in]         -
 *
 * @return            - 0, 1 
 *
 * @Note              - 
 */
uint8_t digitalRead(GPIO_t *pGPIO)
{
	if (*pGPIO->PINx&(1<<pGPIO->GPIO_Pin))
	{return HIGH;}
	else {return LOW;}
}




/*********************************************************************
 * @fn      		  - externalInterrupt
 *
 * @brief             - Interrupt settings
 *
 * @param[in]         - INTx , Interruptx(FALLING,RISING,ANY..)
 * @param[in]         - 
 * @param[in]         -
 *
 * @return            - NONE
 *
 * @Note              - 
 */
void externalInterrupt(uint8_t INTx,uint8_t Interruptx)
{
	SREG|=(1<<7); //Global Interrupt Enable
	if (INTx==INT0)
	{
		GICR|=(1<<INT0);
		MCUCR|=(Interruptx<<0);
		
	}
	else if (INTx==INT1)
	{
		GICR|=(1<<INT1);
		MCUCR|=(Interruptx<<2);
	}
	else
	{
		GICR|=(1<<INT0);
		MCUCR|=(Interruptx<<0);
	}
	
}


/*********************************************************************
 * @fn      		  - gpioInternalPullUp
 *
 * @brief             - Internal Pull-Up resistor eneble
 *
 * @param[in]         - uint8_t -> HIGH or LOW
 * @param[in]         - 
 * @param[in]         -
 *
 * @return            - NONE
 *
 * @Note              - 
 */
void gpioInternalPullUp(uint8_t state)
{
	
	if (state==HIGH)
	{
		SFIOR&=~(1<<PUD);
	}
	else
	{
		SFIOR|=(1<<PUD);
	}
}