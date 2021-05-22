#include"FreeRTOS.h"
#include"task.h"
#include"semphr.h"
#include"queue.h"
#include"event_groups.h"

#include <avr/io.h>
#include "USART_RS232_H_file.h"		/* include USART library */
#include "avr/delay.h"

#include "SmartLock.h"

#define TRUE 1


void T1_Authentication( void *pvParameters);
void T2_SmartLock( void *pvParameters);

xSemaphoreHandle		bsRes ;
char STATUS=0;

int main(void) {
	while(!(PINC&(1<<HC_ConnectionStatePin)));
	    SmartLock_Init();
        bsRes= xSemaphoreCreateBinary();
        xTaskCreate(T2_SmartLock,NULL,100,NULL,2,NULL);
		xTaskCreate(T1_Authentication,NULL,1000,NULL,1,NULL);
		/* Start OS or Sched */
		vTaskStartScheduler();
		while(1);
}

void T1_Authentication( void *pvParameters)
{ char trails=0;
	while(1){
		while(!(PINC&(1<<HC_ConnectionStatePin)));
		STATUS=CheckLogin();
		if (STATUS==TRUE)
		{
          xSemaphoreGive(bsRes);
		}
		else
		{   trails++;
		    USART_SendString("Please enter correct username or password\r");
		}
		while(trails>=3)
		{
			Alarm();
		}
 		vTaskDelay(1000);

	}}


//--------------------------------------------------
void T2_SmartLock(void* pvData){
	BaseType_t result = pdFALSE;
	while(1){
		result = xSemaphoreTake(bsRes,1000);
				if(result == pdTRUE){
					SmartLock_Feature();
				}
     		vTaskDelay(1000);

	}
	}




