/*
 * atmega8xx_usart.c
 *
 * Created: 25.10.2021 00:18:49
 *  Author: Enes
 */ 
#include "atmega8xx_usart.h"


volatile static uint8_t rx_buffer[RX_BUFFER_SIZE] = {0};
volatile static uint16_t rx_count = 0;
volatile static uint8_t uart_tx_busy = 1;

/*********************************************************************
 * @fn      		  - usartInit
 *
 * @brief             - USART_t baud rate, clock speed,operation, parity, stop, character size, clock polarity
 *
 * @param[in]         - USART_t
 * @param[in]         -
 * @param[in]         -
 *
 * @return            - none
 *
 * @Note              - 
 */
void usartInit(USART_t* pUSART)
{

	uint8_t speed = 16;
	uint32_t baud;
		

		
	baud = (F_CPU/(pUSART->USARTbaudRate*speed)) - 1;

	UBRRH = (baud & 0x0F00) >> 8;
	UBRRL = (baud & 0x00FF);
	


   	
	
	/* Set frame format */
	
	UCSRC|=(1<<URSEL)|(pUSART->operation<<UMSEL)|(pUSART->parityMode<<UPM0)|(pUSART->stop<<USBS)|(pUSART->clockPolarity<<UCPOL)|(1<<UCSZ0)|(1<<UCSZ1);

	
	
	
	/* Enable Transmit and Recive*/
	UCSRB |= (1 << TXEN) | (1 << RXEN) | (1 << TXCIE) | (1 << RXCIE);

	
   
	


}



/*********************************************************************
 * @fn      		  - usartTransmitChar
 *
 * @brief             - unsigned char 'a', 'b' ...
 *
 * @param[in]         - unsigned char 
 * @param[in]         -
 * @param[in]         -
 *
 * @return            - none
 *
 * @Note              - 
 */
void usartTransmitChar(uint8_t data)
{
	while(uart_tx_busy == 0);
	uart_tx_busy = 0;
	UDR = data;
}



/*********************************************************************
 * @fn      		  - usartTransmit
 *
 * @brief             - transmit string with printf
 *
 * @param[in]         - char data and FILE 
 * @param[in]         -
 * @param[in]         -
 *
 * @return            - 0
 *
 * @Note              - 
 */
int usartTransmit(uint8_t data, FILE *stream )
{
	
	if(data == '\n')
	{
		usartTransmit('\r', stream);
	}	

	usartTransmitChar((uint8_t)data);
	return 0;
}





/*********************************************************************
 * @fn      		  - usartRecive
 *
 * @brief             -  recive data
 *
 * @param[in]         - none
 * @param[in]         -
 * @param[in]         -
 *
 * @return            - none
 *
 * @Note              - 
 */
void usartReceive(uint8_t* data,uint16_t Len)
{

	
   while(Len>0)
   {
	   	static uint16_t rx_read_pos = 0;
	   	
	   	*data = rx_buffer[rx_read_pos];
	   	rx_read_pos++;
	   	rx_count--;
		Len--;
	   	if(rx_read_pos >= RX_BUFFER_SIZE){
		   	rx_read_pos = 0;
	   	}
   }

	
 

}


/*********************************************************************
 * @fn      		  - usartInterruptEnable
 *
 * @brief             -  USART Interrupts enable
 *
 * @param[in]         - Interruptx(TX,RX,DATA EMPTY)
 * @param[in]         -
 * @param[in]         -
 *
 * @return            - NONE
 *
 * @Note              - 
 */
void usartInterruptEnable(uint8_t Interruptx)
{
	SREG=(1<<7); //Global Interrupt Enable
	UCSRB=(1<<Interruptx);
}



ISR( USART_RXC_vect){
	
	volatile static uint16_t rx_write_pos = 0;
	
	rx_buffer[rx_write_pos] = UDR;
	rx_count++;
	rx_write_pos++;
	if(rx_write_pos >= RX_BUFFER_SIZE){
		rx_write_pos = 0;
	}
	
}


ISR(USART_TXC_vect){
	uart_tx_busy = 1;
}
