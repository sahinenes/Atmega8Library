/*
 * Atmega8Examples.c
 *
 * Created: 24.02.2022 12:55:48
 * Author : Enes
 */ 

#include "atmega8xx_i2c.h"

// send data


int main(void)
{
	
	i2cInit();
	i2cStart(0x04<<1);
	i2cWrite(0x55);
	i2cStop();
    
	
	
    while (1) 
    {
		
	
    }
}

