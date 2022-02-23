/*
 * atmega8xx_ac.h
 *
 * Created: 30.10.2021 15:56:35
 *  Author: Enes
 */ 

/* Analog Comparator */

#ifndef ATMEGA8XX_AC_H_
#define ATMEGA8XX_AC_H_

#include "atmega8xx.h"

/* INTERRUPT SELECT */
#define AC_INTERRUPT_OUTPUT_TOGGLE 0
#define AC_INTERRUPT_RESERVED      1
#define AC_INTERRUPT_FALLING_OUTPUT 2
#define AC_INTERRUPT_RISING_OUTPUT  3



/*NEGAIVE INPUT SELCET*/
#define AC_NEGATIVE_INPUT_ADC0 0
#define AC_NEGATIVE_INPUT_ADC1 1
#define AC_NEGATIVE_INPUT_ADC2 2
#define AC_NEGATIVE_INPUT_ADC3 3
#define AC_NEGATIVE_INPUT_ADC4 4
#define AC_NEGATIVE_INPUT_ADC5 5
#define AC_NEGATIVE_INPUT_ADC6 6
#define AC_NEGATIVE_INPUT_ADC7 7
#define AC_NEGATIVE_INPUT_AIN1 8


void analogComparatorDisable();


void analogComparatorInit(uint8_t negativeInput,uint8_t Interrupt);

uint8_t analogComparatorValue(); 

#endif /* ATMEGA8XX_AC_H_ */