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
uint8_t timer0ReadTCNT0()
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
void timer0WriteTCNT0(uint8_t value)
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

/* TIMER1 START */





void timer1Init(uint8_t prescaler,uint8_t mode,uint8_t interrupt)
{
	
	TCCR1A=(mode&0x03);
	TCCR1B=((mode&&0xc0)<<3);
	TIMSK=interrupt;
	TCCR1B|=prescaler<<0;
}


void timer1_writeTCNT1( unsigned int i )
{
	unsigned char sreg;
	
	/* Save Global Interrupt Flag */
	sreg = SREG;
	/* Disable interrupts */
	cli();
	/* Set TCNT1 to i */
	TCNT1 = i;
	/* Restore Global Interrupt Flag */
	SREG = sreg;
}

unsigned int timer1_readTCNT1()
{
	unsigned char sreg;
	unsigned int i;
	/* Save Global Interrupt Flag */
	sreg = SREG;
	/* Disable interrupts */
	cli();
	/* Read TCNT1 into i */
	i = TCNT1;
	/* Restore Global Interrupt Flag */
	SREG = sreg;
	return i;
}

void timer1_writeOCR1A(unsigned int i)
{
		unsigned char sreg;
		
		/* Save Global Interrupt Flag */
		sreg = SREG;
		/* Disable interrupts */
		cli();
		/* Set TCNT1 to i */
		OCR1A = i;
		/* Restore Global Interrupt Flag */
		SREG = sreg;
}
unsigned int timer1_readORC1A()
{
		unsigned char sreg;
		unsigned int i;
		/* Save Global Interrupt Flag */
		sreg = SREG;
		/* Disable interrupts */
		cli();
		/* Read TCNT1 into i */
		i = OCR1A;
		/* Restore Global Interrupt Flag */
		SREG = sreg;
		return i;
}
void timer1_writeOCR1B(unsigned int i)
{
		unsigned char sreg;
		
		/* Save Global Interrupt Flag */
		sreg = SREG;
		/* Disable interrupts */
		cli();
		/* Set TCNT1 to i */
		OCR1B = i;
		/* Restore Global Interrupt Flag */
		SREG = sreg;
}
unsigned int timer1_readORC1B()
{
		unsigned char sreg;
		unsigned int i;
		/* Save Global Interrupt Flag */
		sreg = SREG;
		/* Disable interrupts */
		cli();
		/* Read TCNT1 into i */
		i = OCR1B;
		/* Restore Global Interrupt Flag */
		SREG = sreg;
		return i;
}
void timer1_writeICR1(unsigned int i)
{
		unsigned char sreg;
		
		/* Save Global Interrupt Flag */
		sreg = SREG;
		/* Disable interrupts */
		cli();
		/* Set TCNT1 to i */
		ICR1 = i;
		/* Restore Global Interrupt Flag */
		SREG = sreg; 
}
unsigned int timer1_readICR()
{
		unsigned char sreg;
		unsigned int i;
		/* Save Global Interrupt Flag */
		sreg = SREG;
		/* Disable interrupts */
		cli();
		/* Read TCNT1 into i */
		i = ICR1;
		/* Restore Global Interrupt Flag */
		SREG = sreg;
		return i;	
}


/* TIMER1 END */

