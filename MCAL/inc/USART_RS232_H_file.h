/*
 * USART_RS232_H_file.h
 * http://www.electronicwings.com
 *
 */ 


#ifndef USART_RS232_H_FILE_H_				/* Define library H file if not defined */
#define USART_RS232_H_FILE_H_

#define F_CPU 8000000UL						/* Define CPU clock Frequency e.g. here its 8MHz */
#define BAUD_PRESCALE (((F_CPU / (BAUDRATE * 16UL))) - 1)	/* Define prescale value */

#include <avr/io.h>							/* Include AVR std. library file */

void USART_Init(unsigned long);				/* USART initialize function */
char USART_RxChar();						/* Data receiving function */
void USART_TxChar(char);					/* Data transmitting function */
void USART_SendString(char*);				/* Send string of USART data function */
uint8_t Usart_ReceiveString_Del( uint8_t* buf,uint8_t delimeter);
void USART_Flush( void );


#endif										/* USART_RS232_H_FILE_H_ */
