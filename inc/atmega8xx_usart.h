/*
 * atmega8xx_usart.h
 *
 * Created: 24.10.2021 01:49:47
 *  Author: Enes
 */ 


#ifndef ATMEGA8XX_USART_H_
#define ATMEGA8XX_USART_H_

#include "atmega8xx.h"



#define RX_BUFFER_SIZE 128



/* USART_t struct */
typedef struct USART_t
{
	uint8_t operation;
	uint8_t parityMode;
	uint8_t stop;
	uint8_t characterSize;
	uint8_t clockPolarity;
	uint32_t USARTbaudRate;
	
}USART_t;




/* OPERATION*/
#define USART_OPERATION_ASYNC 0
#define USART_OPERATION_SYNC  1

/* PARITY MODE */
#define USART_PARITY_DISABLED 0
#define USART_PARITY_RESERVED 1
#define USART_PARITY_EVEN     2
#define USART_PARITY_ODD      3

/* STOP BIT */
#define USART_STOP_1          0
#define USART_STOP_2          1

/* CHARACTER SIZE */
#define USART_CHARACTER_5     0
#define USART_CHARACTER_6     1
#define USART_CHARACTER_7     2
#define USART_CHARACTER_8     3
#define USART_CHARACTER_9     7

/* CLOCK POLARITY */
#define USART_CLK_PLRTY_RSNG  0
#define USART_CLK_PLRTY_FLNG  1


/* INTERRUPT */
#define USART_INTERRUPT_RX    7
#define USART_INTERRUPT_TX    6
#define USART_INTERRUPT_DATA_EMPTY    5 

/*usartInit Init */
void usartInit(USART_t* pUSART);


/*Transmit and Recive Data */
int usartTransmit(uint8_t data, FILE *stream);
void usartReceive(uint8_t* data,uint16_t Len);
void usartInterruptEnable(uint8_t Interruptx);
/* try recive*/

/*

  copy main setup
  
  FILE usart0_str = FDEV_SETUP_STREAM(usartTransmit, NULL, _FDEV_SETUP_WRITE);
  stdout=&usart0_str;
  
  sei();
  
  
  
  use
  printf("Potentiometer value = %u Ohm\n", (uint16_t)potval);
  
  
*/

#endif /* ATMEGA8XX_USART_H_ */