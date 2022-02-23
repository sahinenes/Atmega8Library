/*
 * atmega8xx_adc.h
 *
 * Created: 30.10.2021 00:35:25
 *  Author: Enes
 */ 



#ifndef ATMEGA8XX_ADC_H_
#define ATMEGA8XX_ADC_H_


#include "atmega8xx.h"

#define  ADC_REF_AREF 0
#define  ADC_REF_AVCC 1
#define  ADC_REF_RESERVED 2
#define  ADC_REF_2_56V  3


#define  ADC0   0
#define  ADC1   1
#define  ADC2   2
#define  ADC3   3
#define  ADC4   4
#define  ADC5   5
#define  ADC6   6
#define  ADC7   7
#define  ADC1_30V   14
#define  ADC0V   15

#define  ADC_DIVISION_2 1
#define  ADC_DIVISION_4 2
#define  ADC_DIVISION_8 3
#define  ADC_DIVISION_16 4
#define  ADC_DIVISION_32 5
#define  ADC_DIVISION_64 6
#define  ADC_DIVISION_128 7

void adcInit(uint8_t ADCref,uint8_t Channel,uint8_t Division);
uint16_t adcValue();
void adcInterruptEnable();

#endif /* ATMEGA8XX_ADC_H_ */