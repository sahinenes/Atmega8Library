/*
 * atmega8xx_timer.c
 *
 * Created: 5.12.2021 12:16:41
 *  Author: Enes
 */ 



#include "atmega8xx_timer.h"



/* TIMER0 START */


/*********************************************************************
 * @fn      		  - timer0Init
 *
 * @brief             - init timer 0
 *
 * @param[in]         - prescaler -> (TIMER0_PRESCALING_1..1024)  interrupt -> enable or disable
 * @param[in]         - 
 * @param[in]         -
 *
 * @return            - NONE
 *
 * @Note              - 
 */
void timer0Init(uint8_t prescaler,uint8_t interrupt)
{
	TCCR0=(prescaler<<0);
	TIMSK=(interrupt<<0);
}



/*********************************************************************
 * @fn      		  - timer0Value
 *
 * @brief             - get timer 0 value
 *
 * @param[in]         - NONE
 * @param[in]         - 
 * @param[in]         -
 *
 * @return            - TCNT0 value
 *
 * @Note              - 
 */
uint8_t timer0GetValue()
{
	return (uint8_t)TCNT0;
}


/*********************************************************************
 * @fn      		  - timer0SetValue
 *
 * @brief             - set timer 0 value
 *
 * @param[in]         - NONE
 * @param[in]         - 
 * @param[in]         -
 *
 * @return            - NONE
 *
 * @Note              - 
 */
timer0SetValue(uint8_t value)
{
	TCNT0=(uint8_t)value;
}




/*********************************************************************
 * @fn      		  - timer0Flag
 *
 * @brief             - get timer 0 flag
 *
 * @param[in]         - NONE
 * @param[in]         - 
 * @param[in]         -
 *
 * @return            - 1 or 0
 *
 * @Note              - 
 */
uint8_t timer0Flag()
{
	return (TIFR & (1<<0));
}


/* TIMER0 END */



