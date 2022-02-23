/*

  * atmega8xx_ac.cpp
  *Created: 30.10.2021 15:57:46
  *Author: Enes
  
 */


#include "atmega8xx_ac.h"


/*********************************************************************
 * @fn      		  - analogComparatorDisable
 *
 * @brief             - disable analog comparator
 *
 * @param[in]         - none
 * @param[in]         -
 * @param[in]         -
 *
 * @return            - none
 *
 * @Note              - 
 */
void analogComparatorDisable()
{
	ACSR|=(1<<ACD);
}



/*********************************************************************
 * @fn      		  - analogComparatorInit
 *
 * @brief             - init analog comparator, select negative pin
 *
 * @param[in]         - negative input -> ADC0, ADC1, ADC2..7, AIN1
 * @param[in]         - interrupt enable or disable
 * @param[in]         -
 *
 * @return            - none
 *
 * @Note              - 
 */
void analogComparatorInit(uint8_t negativeInput,uint8_t Interrupt)
{
	if (negativeInput==AC_NEGATIVE_INPUT_AIN1)
	{
		SFIOR|=(1<<ACME);
		ADCSRA|=(1<<ADEN);
	}
	else
	{
		SFIOR|=(1<<ACME);
		ADMUX|=(negativeInput<<MUX0);	
	}
	
	if (Interrupt!=AC_INTERRUPT_RESERVED)
	{
		ACSR|=(1<<ACIE);
		ACSR|=(Interrupt<<ACIS0);
	}
	else
	{
		ACSR&=~(1<<ACIE);
	}
}


/*********************************************************************
 * @fn      		  - analogComparatorValue
 *
 * @brief             - get analog compartator value -> 1 or 0
 *
 * @param[in]         - none
 * @param[in]         - 
 * @param[in]         -
 *
 * @return            - 1 or 0 (uint8_t)
 *
 * @Note              - 
 */
uint8_t analogComparatorValue()
{
	if (ACSR & (1<<ACO))
	{
		return 1;	
	}
	return 0;
	
}