/*
 * atmega8xx_timer.h
 *
 * Created: 5.12.2021 12:16:57
 *  Author: Enes
 */ 


#ifndef ATMEGA8XX_TIMER_H_
#define ATMEGA8XX_TIMER_H_

#include "atmega8xx.h"
#include "interrupt.h"




/* TIMER0 START */


/* 8-bit timer counter */

/* PRESCALING */
#define TIMER0_PRESCALING_1 1
#define TIMER0_PRESCALING_8 2
#define TIMER0_PRESCALING_64 3
#define TIMER0_PRESCALING_256 4
#define TIMER0_PRESCALING_1024 5
#define TIMER0_PRESCALING_EXTERNAL_FALLING 6
#define TIMER0_PRESCALING_EXTERNAL_RISING 7


/* INTERRUPT */
#define TIMER0_INTERRUPT_DISABLE 0
#define TIMER0_INTERRUPT_ENABLE 1


/* TIMER INIT */
void timer0Init(uint8_t prescaler,uint8_t interrupt);

/* TIMER VALUE */
uint8_t timer0ReadTCNT0();
void timer0WriteTCNT0(uint8_t value);

/* TIMER FLAG */
uint8_t timer0Flag();


/* TIMER0 END */




/* TIMER1 START */


/* PRESCALING */
#define TIMER1_PRESCALING_1 1
#define TIMER1_PRESCALING_8 2
#define TIMER1_PRESCALING_64 3
#define TIMER1_PRESCALING_256 4
#define TIMER1_PRESCALING_1024 5
#define TIMER1_PRESCALING_EXTERNAL_FALLING 6
#define TIMER1_PRESCALING_EXTERNAL_RISING 7



/*look page 97 and 98 Waveform Generation Mode Bit Description*/
/* MODES */

#define TIMER1_MODE_NORMAL   0x00		 /* Normal */
#define TIMER1_MODE_PWM_PC8  0x01		 /* PWM, Phase Correct, 8-bit */
#define TIMER1_MODE_PWM_PC9  0x02		 /* PWM, Phase Correct, 9-bit */
#define TIMER1_MODE_PWM_PC10 0x03		 /* PWM, Phase Correct, 10-bit */
#define TIMER1_MODE_CTC_0	 0x04		 /* CTC (OCR1A) */
#define TIMER1_MODE_FPWM_8   0x05		 /* Fast PWM, 8-bit */
#define TIMER1_MODE_FPWM_9   0x06		 /* Fast PWM, 9-bit */
#define TIMER1_MODE_FPWM_10  0x07		 /* Fast PWM, 10-bit */
#define TIMER1_MODE_PWM_PF_0  0x08		 /* PWM, Phase and Frequency Correct (ICR1) */
#define TIMER1_MODE_PWM_PF_1  0x09		 /* PWM, Phase and Frequency Correct  (OCR1A)*/
#define TIMER1_MODE_PWM_PC_0  0x0A	 /* PWM, Phase Correct (ICR1) */
#define TIMER1_MODE_PWM_PC_1  0x0B	 /* PWM, Phase Correct   (OCR1A) */
#define TIMER1_MODE_CTC_1	  0x0C	 /* CTC   (ICR1) */
#define TIMER1_MODE_RESERVED  0x0D	 /* RESERVED */
#define TIMER1_MOD_FPWM_0	  0x0E	 /* Fast PWM   (ICR1) */
#define TIMER1_MOD_FPWM_1	  0x0F	 /* Fast PWM   (OCR1A) */



/* Interrupt */
#define TIMER1_INTERRUPT_IC 0x20     /* Timer/Counter1, Input Capture Interrupt Enable */
#define TIMER1_INTERRUPT_OCA 0x10    /* Timer/Counter1, Output Compare A Match Interrupt Enable */
#define TIMER1_INTERRUPT_OCB 0x08	 /* Timer/Counter1, Output Compare B Match Interrupt Enable*/
#define TIMER1_INTERRUPT_OF 0x04     /* Timer/Counter1, Overflow Interrupt Enable*/

void timer1Init(uint8_t prescaler,uint8_t mode,uint8_t interrupt);
void timer1_writeTCNT1( unsigned int i );
unsigned int timer1_readTCNT1();
void timer1_writeOCR1A(unsigned int i);
unsigned int timer1_readORC1A();
void timer1_writeOCR1B(unsigned int i);
unsigned int timer1_readORC1B();
void timer1_writeICR1(unsigned int i);
unsigned int timer1_readICR();

/* TIMER1 END */


#endif /* ATMEGA8XX_TİMER_H_ */