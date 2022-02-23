/*
 * atmega8xx_adc.cpp
 *
 * Created: 30.10.2021 00:35:47
 *  Author: Enes
 */ 


#include "atmega8xx_adc.h"




/*********************************************************************
 * @fn      		  - adcInit
 *
 * @brief             - select reference, channel and division
 *
 * @param[in]         - none
 * @param[in]         - 
 * @param[in]         -
 *
 * @return            - 
 *
 * @Note              - 
 */
void adcInit(uint8_t ADCref,uint8_t Channel,uint8_t Division)
{
	ADCSRA|=(1<<ADEN) ;
	ADCSRA|=(Division<<ADPS0);
	
	ADMUX|=(ADCref<<REFS0);
	ADMUX|=(Channel<<MUX0);
}




/*********************************************************************
 * @fn      		  - adcValue
 *
 * @brief             - get analog digital comparator value
 *
 * @param[in]         - none
 * @param[in]         - 
 * @param[in]         -
 *
 * @return            - 16 bits data
 *
 * @Note              - 
 */
uint16_t adcValue()
{
	ADCSRA|= (1<<ADSC);	// Start conversion
	while (ADCSRA &  (1<<ADSC));
	return (uint16_t)ADCW;
	
}




/*********************************************************************
 * @fn      		  - adcInterruptEnable
 *
 * @brief             - enable adc interrupt
 *
 * @param[in]         - none
 * @param[in]         - 
 * @param[in]         -
 *
 * @return            - none
 *
 * @Note              - 
 */
void adcInterruptEnable()
{
	ADCSRA|=(1<<ADIE);
}
