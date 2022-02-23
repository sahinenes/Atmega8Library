/*
 * Atmega8LibExamples.cpp
 *
 * Created: 12.01.2022 21:53:40
 * Author : Enes
 */ 



#include "liquid_crystal_i2c.h"




int main(void)
{
	
	
	
	
	

	
	
	
	
	LCD_t device = LCD_init(0x4E, 16, 2, LCD_5x8DOTS); // intialize 2-lines display

	
	
	LCD_turnOnBacklight(&device); // simply turning on the backlight

	

	
	while (1)
	{
	
	LCD_setCursor(&device,0,0);
	LCD_print(&device, "Hello world!");
	LCD_setCursor(&device,1,0);
	LCD_print(&device,"Enes Sahin");
	
	
	

	

	
		
	}

}

