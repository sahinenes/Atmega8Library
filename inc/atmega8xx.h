/*
 * atmega8xx.h
 *
 * Created: 16.10.2021 12:37:11
 *  Author: Abdulkadir,Enes
 *  Datasheet: https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-2486-8-bit-AVR-microcontroller-ATmega8_L_datasheet.pdf
 
 */ 


#ifndef ATMEGA8XX_H_
#define ATMEGA8XX_H_


#ifndef F_CPU
#define F_CPU 8000000
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <avr/sfr_defs.h>
#include <util/delay.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>
#include "interrupt.h"
#include <math.h>

/* Generic */
#define HIGH                    1
#define LOW						0
#define ENABLE                  1
#define DISABLE					0


#define __vo volatile
#define __weak __attribute__((weak))


//Register Summary
#define SREG        *( (__vo uint8_t*)(0x5F))
#define SPH         *( (__vo uint8_t*)(0x5E))
#define SPL         *( (__vo uint8_t*)(0x5D))

//#define Reserved	( (__vo uint8_t*)0x3C)

#define GICR	    *( (__vo uint8_t*)(0x5B))
#define GIFR	    *( (__vo uint8_t*)(0x5A))


#define TIMSK	    *( (__vo uint8_t*)(0x59))
#define TIFR		*( (__vo uint8_t*)(0x58))

#define SPMCR		*( (__vo uint8_t*)(0x57))

#define TWCR		*( (__vo uint8_t*)(0x56))

#define MCUCR		*( (__vo uint8_t*)(0x55))

#define MCUCSR		*( (__vo uint8_t*)(0x54))
#define MCUSR		*( (__vo uint8_t*)(0x54))


/* Timer 0 */
#define TCCR0 		*( (__vo uint8_t*)(0x53))
#define TCNT0		*( (__vo uint8_t*)(0x52))



#define OSCCAL		*( (__vo uint8_t*)(0x51))

#define SFIOR		*( (__vo uint8_t*)(0x50))

/* Timer 1 */
#define TCCR1A		*( (__vo uint8_t*)(0x4F))
#define TCCR1B		*( (__vo uint8_t*)(0x4E))
#define TCNT1H		*( (__vo uint8_t*)(0x4D))
#define TCNT1L		*( (__vo uint8_t*)(0x4C))
#define TCNT1		*( (__vo uint16_t*)(0x4C))
#define OCR1AH		*( (__vo uint8_t*)(0x4B))
#define OCR1AL		*( (__vo uint8_t*)(0x4A))
#define OCR1A		*( (__vo uint16_t*)(0x4A))
#define OCR1BH		*( (__vo uint8_t*)(0x49))
#define OCR1BL		*( (__vo uint8_t*)(0x48))
#define OCR1B		*( (__vo uint16_t*)(0x48))
#define ICR1H		*( (__vo uint8_t*)(0x47))
#define ICR1L		*( (__vo uint8_t*)(0x46))
#define ICR1		*( (__vo uint16_t*)(0x46))
/* Timer 2 */
#define TCCR2		*( (__vo uint8_t*)(0x45))
#define TCNT2		*( (__vo uint8_t*)(0x44))
#define OCR2		*( (__vo uint8_t*)(0x43))


#define ASSR		*( (__vo uint8_t*)(0x42))
#define WDTCR		*( (__vo uint8_t*)(0x41))


#define UBRRH		*( (__vo uint8_t*)(0x40))
#define UCSRC		*( (__vo uint8_t*)(0x40)) 

/* EEPROM Address Register */
#define EEARH		*( (__vo uint8_t*)(0x3F))
#define EEARL		*( (__vo uint8_t*)(0x3E))
#define EEAR		*( (__vo uint8_t*)(0x3E))

/* EEPROM Data Register */
#define EEDR		*( (__vo uint8_t*)(0x3D))


/* EEPROM Control Register */
#define EECR		*( (__vo uint8_t*)(0x3C))


//#define Reserved	( (__vo uint8_t*)0x1B)
//#define Reserved	( (__vo uint8_t*)0x1A)
//#define Reserved	( (__vo uint8_t*)0x19)

/* Port B */
#define PORTB		( (__vo uint8_t*)(0x38))
#define DDRB		( (__vo uint8_t*)(0x37))
#define PINB		( (__vo uint8_t*)(0x36))

/* Port C */
#define PORTC		( (__vo uint8_t*)(0x35))
#define DDRC		( (__vo uint8_t*)(0x34))
#define PINC		( (__vo uint8_t*)(0x33))

/* Port D */
#define PORTD		( (__vo uint8_t*)(0x32))
#define DDRD		( (__vo uint8_t*)(0x31))
#define PIND		( (__vo uint8_t*)(0x30))

/* SPI */
#define SPDR		*( (__vo uint8_t*)(0x2F))
#define SPSR		*( (__vo uint8_t*)(0x2E))
#define SPCR		*( (__vo uint8_t*)(0x2D))

/* USART */
#define UDR			*( (__vo uint8_t*)(0x2C))
#define UCSRA		*( (__vo uint8_t*)(0x2B))
#define UCSRB		*( (__vo uint8_t*)(0x2A))
#define UBRRL		*( (__vo uint8_t*)(0x29))

/*  analog comparator */
#define ACSR		*( (__vo uint8_t*)(0x28))


/* ADC */
#define ADMUX		*( (__vo uint8_t*)(0x27))
#define ADCSRA		*( (__vo uint8_t*)(0x26))
#define ADCH		*( (__vo uint8_t*)(0x25))
#define ADCL		*( (__vo uint8_t*)(0x24))
#define ADCW		*( (__vo uint16_t*)(0x24))


/*TWI stands for "Two Wire Interface" or "TWI Was I2C(tm)"*/
#define TWDR		*( (__vo uint8_t*)(0x23))
#define TWAR		*( (__vo uint8_t*)(0x22))
#define TWSR		*( (__vo uint8_t*)(0x21))
#define TWBR		*( (__vo uint8_t*)(0x20))


//Generic Macros
#define ENABLE 				1
#define DISABLE 			0
#define SET 				ENABLE
#define RESET 				DISABLE
#define GPIO_PIN_SET        SET
#define GPIO_PIN_RESET      RESET
#define FLAG_RESET			RESET
#define FLAG_SET 			SET


/* Bit numbers */

/* GIMSK / GICR */
#define INT1	7
#define INT0	6
#define IVSEL	1
#define IVCE	0

/* GIFR */
#define INTF1	7
#define INTF0	6

/* TIMSK */
#define OCIE2	7
#define TOIE2	6
#define TICIE1	5
#define OCIE1A	4
#define OCIE1B	3
#define TOIE1	2
/* bit 1 reserved (OCIE0?) */
#define TOIE0	0

/* TIFR */
#define OCF2	7
#define TOV2	6
#define ICF1	5
#define OCF1A	4
#define OCF1B	3
#define TOV1	2
/* bit 1 reserved (OCF0?) */
#define TOV0	0

/* SPMCR */
#define SPMIE	7
#define RWWSB	6
/* bit 5 reserved */
#define RWWSRE	4
#define BLBSET	3
#define PGWRT	2
#define PGERS	1
#define SPMEN	0

/* TWCR */
#define TWINT	7
#define TWEA	6
#define TWSTA	5
#define TWSTO	4
#define TWWC	3
#define TWEN	2
/* bit 1 reserved (TWI_TST?) */
#define TWIE	0

/* TWAR */
#define TWA6    7
#define TWA5    6
#define TWA4    5
#define TWA3    4
#define TWA2    3
#define TWA1    2
#define TWA0    1
#define TWGCE	0

/* TWSR */
#define TWS7	7
#define TWS6	6
#define TWS5	5
#define TWS4	4
#define TWS3	3
/* bit 2 reserved */
#define TWPS1	1
#define TWPS0	0

/* MCUCR */
#define SE	7
#define SM2	6
#define SM1	5
#define SM0	4
#define ISC11	3
#define ISC10	2
#define ISC01	1
#define ISC00	0

/* MCUCSR */
/* bits 7-4 reserved */
#define WDRF	3
#define BORF	2
#define EXTRF	1
#define PORF	0


/* SFIOR */
/* bits 7-5 reserved */
#define ACME	3
#define PUD	2
#define PSR2	1
#define PSR10	0

/* TCCR0 */
/* bits 7-3 reserved */
#define CS02	2
#define CS01	1
#define CS00	0

/* TCCR2 */
#define FOC2	7
#define WGM20	6
#define COM21	5
#define COM20	4
#define WGM21	3
#define CS22	2
#define CS21	1
#define CS20	0

/* ASSR */
/* bits 7-4 reserved */
#define AS2	3
#define TCN2UB	2
#define OCR2UB	1
#define TCR2UB	0

/* TCCR1A */
#define COM1A1	7
#define COM1A0	6
#define COM1B1	5
#define COM1B0	4
#define FOC1A	3
#define FOC1B	2
#define WGM11	1
#define WGM10	0

/* TCCR1B */
#define ICNC1	7
#define ICES1	6
/* bit 5 reserved */
#define WGM13	4
#define WGM12	3
#define CS12	2
#define CS11	1
#define CS10	0

/* WDTCR */
/* bits 7-5 reserved */
#define WDCE	4
#define WDE	3
#define WDP2	2
#define WDP1	1
#define WDP0	0

/* UBRRH */
#define URSEL	7

/* UCSRC */
#define URSEL	7
#define UMSEL	6
#define UPM1	5
#define UPM0	4
#define USBS	3
#define UCSZ1	2
#define UCSZ0	1
#define UCPOL	0

/* PORTB */
#define PB7	7
#define PB6	6
#define PB5	5
#define PB4	4
#define PB3	3
#define PB2	2
#define PB1	1
#define PB0	0

/* DDRB */
#define DDB7	7
#define DDB6	6
#define DDB5	5
#define DDB4	4
#define DDB3	3
#define DDB2	2
#define DDB1	1
#define DDB0	0

/* PINB */
#define PINB7	7
#define PINB6	6
#define PINB5	5
#define PINB4	4
#define PINB3	3
#define PINB2	2
#define PINB1	1
#define PINB0	0

/* PORTC */
#define PC6	 6
#define PC5	 5
#define PC4	 4
#define PC3	 3
#define PC2	 2
#define PC1	 1
#define PC0	 0

/* DDRC */
#define DDC6	6
#define DDC5	5
#define DDC4	4
#define DDC3	3
#define DDC2	2
#define DDC1	1
#define DDC0	0

/* PINC */
#define PINC6	6
#define PINC5	5
#define PINC4	4
#define PINC3	3
#define PINC2	2
#define PINC1	1
#define PINC0	0

/* PORTD */
#define PD7	 7
#define PD6	 6
#define PD5	 5
#define PD4	 4
#define PD3	 3
#define PD2	 2
#define PD1	 1
#define PD0	 0

/* DDRD */
#define DDD7	7
#define DDD6	6
#define DDD5	5
#define DDD4	4
#define DDD3	3
#define DDD2	2
#define DDD1	1
#define DDD0	0

/* PIND */
#define PIND7	7
#define PIND6	6
#define PIND5	5
#define PIND4	4
#define PIND3	3
#define PIND2	2
#define PIND1	1
#define PIND0	0

/* SPSR */
#define SPIF	7
#define WCOL	6
#define SPI2X	0

/* SPCR */
#define SPIE	7
#define SPE	6
#define DORD	5
#define MSTR	4
#define CPOL	3
#define CPHA	2
#define SPR1	1
#define SPR0	0

/* UCSRA */
#define RXC	7
#define TXC	6
#define UDRE 5
#define FE	4
#define DOR	3
#define PE	2
#define U2X	1
#define MPCM	0

/* UCSRB */
#define RXCIE	7
#define TXCIE	6
#define UDRIE	5
#define RXEN	4
#define	TXEN	3
#define UCSZ2	2
#define RXB8	1
#define TXB8	0

/* ACSR */
#define ACD	7
#define ACBG	6
#define ACO	5
#define ACI	4
#define ACIE	3
#define ACIC	2
#define ACIS1	1
#define ACIS0	0

/* ADCSR / ADCSRA */
#define ADEN	7
#define ADSC	6
#define ADFR	5
#define ADIF	4
#define ADIE	3
#define ADPS2	2
#define ADPS1	1
#define ADPS0	0

/* ADMUX */
#define REFS1	7
#define REFS0	6
#define ADLAR	5
/* bit 4 reserved */
#define MUX3	3
#define MUX2	2
#define MUX1	1
#define MUX0	0

/* EEPROM Control Register */
#define EERIE   3
#define EEMWE   2
#define EEWE    1
#define EERE    0

/* Interrupt vectors */

/* External Interrupt Request 0 */
#define INT0_vect_num		1
#define INT0_vect			_VECTOR(1)
#define SIG_INTERRUPT0			_VECTOR(1)

/* External Interrupt Request 1 */
#define INT1_vect_num		2
#define INT1_vect			_VECTOR(2)
#define SIG_INTERRUPT1			_VECTOR(2)

/* Timer/Counter2 Compare Match */
#define TIMER2_COMP_vect_num	3
#define TIMER2_COMP_vect		_VECTOR(3)
#define SIG_OUTPUT_COMPARE2		_VECTOR(3)

/* Timer/Counter2 Overflow */
#define TIMER2_OVF_vect_num		4
#define TIMER2_OVF_vect			_VECTOR(4)
#define SIG_OVERFLOW2			_VECTOR(4)

/* Timer/Counter1 Capture Event */
#define TIMER1_CAPT_vect_num	5
#define TIMER1_CAPT_vect		_VECTOR(5)
#define SIG_INPUT_CAPTURE1		_VECTOR(5)

/* Timer/Counter1 Compare Match A */
#define TIMER1_COMPA_vect_num	6
#define TIMER1_COMPA_vect		_VECTOR(6)
#define SIG_OUTPUT_COMPARE1A		_VECTOR(6)

/* Timer/Counter1 Compare Match B */
#define TIMER1_COMPB_vect_num	7
#define TIMER1_COMPB_vect		_VECTOR(7)
#define SIG_OUTPUT_COMPARE1B		_VECTOR(7)

/* Timer/Counter1 Overflow */
#define TIMER1_OVF_vect_num		8
#define TIMER1_OVF_vect			_VECTOR(8)
#define SIG_OVERFLOW1			_VECTOR(8)

/* Timer/Counter0 Overflow */
#define TIMER0_OVF_vect_num		9
#define TIMER0_OVF_vect			_VECTOR(9)
#define SIG_OVERFLOW0			_VECTOR(9)

/* Serial Transfer Complete */
#define SPI_STC_vect_num		10
#define SPI_STC_vect			_VECTOR(10)
#define SIG_SPI				_VECTOR(10)

/* USART, Rx Complete */
#define USART_RXC_vect_num		11
#define USART_RXC_vect			_VECTOR(11)
#define SIG_UART_RECV			_VECTOR(11)

/* USART Data Register Empty */
#define USART_UDRE_vect_num		12
#define USART_UDRE_vect			_VECTOR(12)
#define SIG_UART_DATA			_VECTOR(12)

/* USART, Tx Complete */
#define USART_TXC_vect_num		13
#define USART_TXC_vect			_VECTOR(13)
#define SIG_UART_TRANS			_VECTOR(13)

/* ADC Conversion Complete */
#define ADC_vect_num		14
#define ADC_vect			_VECTOR(14)
#define SIG_ADC				_VECTOR(14)

/* EEPROM Ready */
#define EE_RDY_vect_num		15
#define EE_RDY_vect			_VECTOR(15)
#define SIG_EEPROM_READY		_VECTOR(15)

/* Analog Comparator */
#define ANA_COMP_vect_num		16
#define ANA_COMP_vect			_VECTOR(16)
#define SIG_COMPARATOR			_VECTOR(16)

/* 2-wire Serial Interface */
#define TWI_vect_num			17
#define TWI_vect			_VECTOR(17)
#define SIG_2WIRE_SERIAL		_VECTOR(17)

/* Store Program Memory Ready */
#define SPM_RDY_vect_num		18
#define SPM_RDY_vect			_VECTOR(18)
#define SIG_SPM_READY			_VECTOR(18)

#define _VECTORS_SIZE 38




/* Constants */
#define SPM_PAGESIZE 64
#define RAMSTART         (0x60)
#define RAMEND		 0x45F
#define XRAMEND		 RAMEND
#define E2END		 0x1FF
#define E2PAGESIZE   4
#define FLASHEND	 0x1FFF


/* Fuses */

#define FUSE_MEMORY_SIZE 2

/* Low Fuse Byte */
#define FUSE_CKSEL0      (unsigned char)~_BV(0)
#define FUSE_CKSEL1      (unsigned char)~_BV(1)
#define FUSE_CKSEL2      (unsigned char)~_BV(2)
#define FUSE_CKSEL3      (unsigned char)~_BV(3)
#define FUSE_SUT0        (unsigned char)~_BV(4)
#define FUSE_SUT1        (unsigned char)~_BV(5)
#define FUSE_BODEN       (unsigned char)~_BV(6)
#define FUSE_BODLEVEL    (unsigned char)~_BV(7)
#define LFUSE_DEFAULT (FUSE_SUT0 & FUSE_CKSEL3 & FUSE_CKSEL2 & FUSE_CKSEL1)

/* High Fuse Byte */
#define FUSE_BOOTRST     (unsigned char)~_BV(0)
#define FUSE_BOOTSZ0     (unsigned char)~_BV(1)
#define FUSE_BOOTSZ1     (unsigned char)~_BV(2)
#define FUSE_EESAVE      (unsigned char)~_BV(3)
#define FUSE_CKOPT       (unsigned char)~_BV(4)
#define FUSE_SPIEN       (unsigned char)~_BV(5)
#define FUSE_WDTON       (unsigned char)~_BV(6)
#define FUSE_RSTDISBL    (unsigned char)~_BV(7)
#define HFUSE_DEFAULT (FUSE_SPIEN & FUSE_BOOTSZ1 & FUSE_BOOTSZ0)


/* Lock Bits */
#define __LOCK_BITS_EXIST
#define __BOOT_LOCK_BITS_0_EXIST
#define __BOOT_LOCK_BITS_1_EXIST


/* Signature */
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x93
#define SIGNATURE_2 0x07


/* Deprecated items */
#if !defined(__AVR_LIBC_DEPRECATED_ENABLE__)

#pragma GCC system_header

#pragma GCC poison SIG_INTERRUPT0
#pragma GCC poison SIG_INTERRUPT1
#pragma GCC poison SIG_OUTPUT_COMPARE2
#pragma GCC poison SIG_OVERFLOW2
#pragma GCC poison SIG_INPUT_CAPTURE1
#pragma GCC poison SIG_OUTPUT_COMPARE1A
#pragma GCC poison SIG_OUTPUT_COMPARE1B
#pragma GCC poison SIG_OVERFLOW1
#pragma GCC poison SIG_OVERFLOW0
#pragma GCC poison SIG_SPI
#pragma GCC poison SIG_UART_RECV
#pragma GCC poison SIG_UART_DATA
#pragma GCC poison SIG_UART_TRANS
#pragma GCC poison SIG_ADC
#pragma GCC poison SIG_EEPROM_READY
#pragma GCC poison SIG_COMPARATOR
#pragma GCC poison SIG_2WIRE_SERIAL
#pragma GCC poison SIG_SPM_READY

#endif  /* !defined(__AVR_LIBC_DEPRECATED_ENABLE__) */

#define SLEEP_MODE_IDLE (0x00<<4)
#define SLEEP_MODE_ADC (0x01<<4)
#define SLEEP_MODE_PWR_DOWN (0x02<<4)
#define SLEEP_MODE_PWR_SAVE (0x03<<4)
#define SLEEP_MODE_STANDBY (0x06<<4)





#endif /* ATMEGA8XX_H_ */