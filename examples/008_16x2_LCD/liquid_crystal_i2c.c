/*
 * liquid_crystal_i2c.c
 *
 * Created: 21.01.2022 20:21:59
 *  Author: Enes
 */ 






#include "liquid_crystal_i2c.h"


LCD_t LCD_init(uint8_t address, uint8_t columns, uint8_t rows, uint8_t dotSize)
{
	LCD_t device;
	
	device.Address=address;
	device.Columns=columns;
	device.Rows=rows;
	device.Backlight = LCD_NOBACKLIGHT;
	device.DisplayControl= LCD_CURSOROFF | LCD_DISPLAYON | LCD_BLINKOFF;
	device.DisplayFunction= LCD_4BITMODE | LCD_1LINE | LCD_5x8DOTS;
	
	// Initialize to default text direction (for roman languages)
	device.DisplayMode = LCD_ENTRYLEFT | LCD_ENTRYSHIFTDECREMENT;
	
	
	if (rows > 1) {
		device.DisplayFunction |= LCD_2LINE;
	}

	// for some 1 line displays you can select a 10 pixel high font
	if ((dotSize != 0) && (rows == 1)) {
		device.DisplayFunction |= LCD_5x10DOTS;
	}
	
	// SEE PAGE 45/46 FOR INITIALIZATION SPECIFICATION!
	// according to datasheet, we need at least 40ms after power rises above 2.7V
	// before sending commands. Arduino can turn on way befer 4.5V so we'll wait 50
	_delay_ms(50);
	
	// Now we pull both RS and R/W low to begin commands
	LCD_transmitI2C(&device, LCD_NOBACKLIGHT);	// reset expanderand turn backlight off (Bit 8 =1)
	_delay_ms(1000);
	
	// second try
	LCD_writeDevice4Bits(&device, 0x03 << 4);
	_delay_us(4500); // wait min 4.1ms
	
	// third go!
	LCD_writeDevice4Bits(&device, 0x03 << 4);
	_delay_us(150); // wait min 150 mics
	
	// finally, set to 4-bit interface
	LCD_writeDevice4Bits(&device, 0x02 << 4);

	// set # lines, font size, etc.
	LCD_sendCommand(&device, LCD_FUNCTIONSET | device.DisplayFunction);
	
	// turn the display on with no cursor or blinking default
	LCD_turnOnDisplay(&device);
	
	// clear it off
	LCD_clear(&device);
	
	// set the entry mode
	LCD_sendCommand(&device, LCD_ENTRYMODESET | device.DisplayMode);
	
	LCD_returnHome(&device);

	return device;
	
}

void LCD_clear(LCD_t* device)
{
	LCD_sendCommand(device, LCD_CLEARDISPLAY); // clear display, set cursor position to zero
	_delay_us(2000);  // this command takes a long time!

	LCD_setCursor(device, 0, 0);
}



void LCD_setCursor(LCD_t* device, uint8_t row, uint8_t column)
{
	uint8_t row_offsets[] = { 0x00, 0x40, 0x14, 0x54 };

	LCD_sendCommand(device, LCD_SETDDRAMADDR | (column + row_offsets[row]));
	
}

void LCD_returnHome(LCD_t* device)
{
	LCD_sendCommand(device, LCD_RETURNHOME);  // set cursor position to zero
	_delay_us(2000);  // this command takes a long time!
};



void LCD_turnOnBacklight(struct LCD_t* device)
{
	device->Backlight = LCD_BACKLIGHT;
	LCD_transmitI2C(device, 0);
}

void LCD_turnOffBacklight(struct LCD_t* device)
{
	device->Backlight = LCD_NOBACKLIGHT;
	LCD_transmitI2C(device, 0);
}


void LCD_print(struct LCD_t* device, char * value)
{
	char letter = *value;

	while(letter != 0x00)
	{
		LCD_writeDeviceByte(device, letter, LCD_REGISTER_SELECT_BIT);
		letter = *(++value);
	}
};

void LCD_turnOnDisplay(LCD_t* device)
{
	device->DisplayControl |= LCD_DISPLAYON;
	LCD_sendCommand(device, LCD_DISPLAYCONTROL | device->DisplayControl);
};

void LCD_turnOffDisplay(LCD_t* device)
{
	device->DisplayControl &= ~LCD_DISPLAYON;
	LCD_sendCommand(device, LCD_DISPLAYCONTROL | device->DisplayControl);
};







// send command

void LCD_sendCommand(LCD_t* device, uint8_t command)
{
	LCD_writeDeviceByte(device, command, 0);
}

void LCD_writeDeviceByte(LCD_t* device, uint8_t value, uint8_t mode)
{
	uint8_t highnib= value & 0xf0;
	uint8_t lownib= (value<<4) & 0xf0;

	LCD_writeDevice4Bits(device, highnib | mode);
	LCD_writeDevice4Bits(device, lownib | mode);
};

void LCD_writeDevice4Bits(LCD_t* device, uint8_t value)
{
	LCD_transmitI2C(device, value);
	LCD_writeDevicePulse(device, value);
};

void LCD_writeDevicePulse(LCD_t* device, uint8_t value)
{
	LCD_transmitI2C(device, value | LCD_ENABLE_BIT);
	_delay_us(2);

	LCD_transmitI2C(device, value & ~LCD_ENABLE_BIT);
	_delay_us(50);
};

void LCD_transmitI2C(LCD_t* device, uint8_t value)
{
	I2C_Start_Wait(device->Address);
	I2C_Write(value | device->Backlight);
	I2C_Stop();
	
};
