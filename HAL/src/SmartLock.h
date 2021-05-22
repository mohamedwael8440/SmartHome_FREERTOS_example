/*
 * SmartHome.h
 *
 *  Created on: Apr 21, 2021
 *      Author: M_WA
 */

#ifndef HAL_MCAL_SMARTHOME_H_
#define HAL_MCAL_SMARTHOME_H_

#include <avr/io.h>
#include "USART_RS232_H_file.h"		/* include USART library */
#include "avr/delay.h"

#define LIGHT '1'
#define LOCK '2'
#define EXIT '3'

#define LED1_BUZZER_Light_Lock PORTB

#define LED1pin  PB0
#define BuzzerPin  PB1
#define Light  PB2
#define LockRelay PB3


#define HC_ConnectionStatePin  PC0

void SmartLock_Init(void);
char CheckLogin(void) ;
void SmartLock_Feature(void);
void Alarm(void);


#endif /* HAL_MCAL_SMARTHOME_H_ */
