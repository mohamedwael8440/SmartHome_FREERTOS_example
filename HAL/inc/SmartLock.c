/*
 * SmartHome.c
 *
 *  Created on: Apr 21, 2021
 *      Author: M_WA
 */

#include "SmartLock.h"



void SmartLock_Init(void) {
	USART_Init(9600); /* initialize USART with 9600 baud rate */
	DDRB = 0xff; /* make PORTB as output port */
	DDRC = 0X00;
	LED1_BUZZER_Light_Lock = 0;
	USART_SendString("SmartLock\r");
	_delay_ms(500);
	USART_SendString("Please Login\r");
	_delay_ms(500);
}
char CheckLogin(void) {
	char i = 0;
	char state = 0;
	char username[10][8] = { "test1\r", "test2\r", "test3\r", "test4\r",
			"test5\r", "test6\r", "test7\r", "test8\r", "test9\r", "test10\r" };
     char password[10][8] = { "test1\r", "test2\r", "test3\r", "test4\r",
			"test5\r", "test6\r", "test7\r", "test8\r", "test9\r", "test10\r" };
	 char trails = 0, rxusername[100], rxpassword[100];
	USART_Flush();
	USART_SendString("Enter UserName\r");
	while (!Usart_ReceiveString_Del(rxusername,'\r'));
	USART_SendString("Enter Password\r");
	while (!Usart_ReceiveString_Del(rxpassword,'\r'));

	for (i = 0; i < 10; i++) {
		if (!strcmp(username[i], rxusername)
				&& !strcmp(password[i], rxpassword)) {
			state = 1;
		}
	}

	return state;
}

void Alarm(void) {
	_delay_ms(200);
	LED1_BUZZER_Light_Lock ^= (1 << BuzzerPin) | (1 << LED1pin);

}
void SmartLock_Feature(void) {

	USART_SendString(" Send 1 to turn on/of led\r");
	_delay_ms(300);
	USART_SendString(" 2 to lock/unlock the door\r");
	_delay_ms(300);
	USART_SendString(" 3 to exit\r");
	char Feature = 0;
	while (Feature != '3') {
		switch (Feature) {
		case LIGHT:
		    LED1_BUZZER_Light_Lock ^= (1 << Light);
			Feature = USART_RxChar();
			break;
		case LOCK:
		    LED1_BUZZER_Light_Lock ^= (1 << LockRelay);
			Feature = USART_RxChar();
			break;
		default:
			Feature = USART_RxChar();
			break;
		}
	}
}

