/*
 * liquid_crystal_i2c.h
 *
 * Created: 21.01.2022 20:22:21
 *  Author: Enes
 */ 


#ifndef LIQUID_CRYSTAL_I2C_H_
#define LIQUID_CRYSTAL_I2C_H_


//DOCS

/*
	https://www.nxp.com/docs/en/data-sheet/PCF8574_PCF8574A.pdf
	https://www.sparkfun.com/datasheets/LCD/HD44780.pdf
	https://github.com/denisgoriachev/liquid_crystal_i2c_avr
*/

#include "atmega8xx.h"
#include "atmega8xx_i2c.h"


#define LCD_I2C_ADRESS 0x4E


// commands
#define LCD_CLEARDISPLAY 0x01
#define LCD_RETURNHOME 0x02
#define LCD_ENTRYMODESET 0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT 0x10
#define LCD_FUNCTIONSET 0x20
#define LCD_SETCGRAMADDR 0x40
#define LCD_SETDDRAMADDR 0x80

// flags for display entry mode
#define LCD_ENTRYRIGHT 0x00
#define LCD_ENTRYLEFT 0x02
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYSHIFTDECREMENT 0x00

// flags for display on/off control
#define LCD_DISPLAYON 0x04
#define LCD_DISPLAYOFF 0x00
#define LCD_CURSORON 0x02
#define LCD_CURSOROFF 0x00
#define LCD_BLINKON 0x01
#define LCD_BLINKOFF 0x00

// flags for display/cursor shift
#define LCD_DISPLAYMOVE 0x08
#define LCD_CURSORMOVE 0x00
#define LCD_MOVERIGHT 0x04
#define LCD_MOVELEFT 0x00

// flags for function set
#define LCD_8BITMODE 0x10
#define LCD_4BITMODE 0x00
#define LCD_2LINE 0x08
#define LCD_1LINE 0x00
#define LCD_5x10DOTS 0x04
#define LCD_5x8DOTS 0x00

// flags for backlight control
#define LCD_BACKLIGHT 0x08
#define LCD_NOBACKLIGHT 0x00


#define LCD_ENABLE_BIT 0b00000100  // Enable bit
#define LCD_READ_WRITE_BIT 0b00000010  // Read/Write bit
#define LCD_REGISTER_SELECT_BIT 0b00000001  // Register select bit

typedef struct LCD_t {
	uint8_t Address;
	uint8_t Columns;
	uint8_t Rows;
	uint8_t Backlight;
	uint8_t DisplayFunction;
	uint8_t DisplayControl;
	uint8_t DisplayMode;
} LCD_t;


struct LCD_t LCD_init(uint8_t address, uint8_t columns, uint8_t rows, uint8_t dotSize);

void LCD_clear(struct LCD_t* device);

void LCD_setCursor(struct LCD_t* device, uint8_t row, uint8_t column);

void LCD_returnHome(struct LCD_t* device);

void LCD_turnOnBacklight(struct LCD_t* device);

void LCD_turnOffBacklight(struct LCD_t* device);

void LCD_print(struct LCD_t* device, char* value);

void LCD_turnOnDisplay(struct LCD_t* device);

void LCD_turnOffDisplay(struct LCD_t* device);



// send data 

void LCD_sendCommand(struct LCD_t* device, uint8_t command);

void LCD_writeDeviceByte(struct LCD_t* device, uint8_t value, uint8_t mode);

void LCD_writeDevice4Bits(struct LCD_t* device, uint8_t value);

void LCD_writeDevicePulse(struct LCD_t* device, uint8_t value);

void LCD_transmitI2C(struct LCD_t* device, uint8_t value);

#endif /* LİQUİD_CRYSTAL_İ2C_H_ */