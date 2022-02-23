/*
 * atmega8xx_i2c.h
 *
 * Created: 20.12.2021 18:03:35
 *  Author: Enes
 */ 


#ifndef ATMEGA8XX_i2cH_
#define ATMEGA8XX_i2cH_

#include "atmega8xx.h"

#define SCL_CLK 100000L						
#define BITRATE(TWSR)	((F_CPU/SCL_CLK)-16)/(2*pow(4,(TWSR&((1<<TWPS0)|(1<<TWPS1))))) 


void i2cInit();							
uint8_t  i2cStart(char);						
uint8_t  i2cRepeated_Start(char);			
void i2cStop();								
void i2cStart_Wait(char);						
uint8_t  i2cWrite(char);					
char i2cRead_Ack();							
char i2cRead_Nack();							




#endif /* ATMEGA8XX_i2cH_ */