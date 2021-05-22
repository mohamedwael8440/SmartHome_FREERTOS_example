################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/src/USART_RS232_C_file.c \
../MCAL/src/uart.c 

OBJS += \
./MCAL/src/USART_RS232_C_file.o \
./MCAL/src/uart.o 

C_DEPS += \
./MCAL/src/USART_RS232_C_file.d \
./MCAL/src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/src/%.o: ../MCAL/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"E:\New folder\Eclipse IDE\WORKSPACE2\SmartLock_RTOS_IMT\FreeRTOS\FreeRTOS\Inc" -I"E:\New folder\Eclipse IDE\WORKSPACE2\SmartLock_RTOS_IMT\FreeRTOS\FreeRTOS\Src" -I"E:\New folder\Eclipse IDE\WORKSPACE2\SmartLock_RTOS_IMT\HAL\inc" -I"E:\New folder\Eclipse IDE\WORKSPACE2\SmartLock_RTOS_IMT\HAL\src" -I"E:\New folder\Eclipse IDE\WORKSPACE2\SmartLock_RTOS_IMT\MCAL\inc" -I"E:\New folder\Eclipse IDE\WORKSPACE2\SmartLock_RTOS_IMT\MCAL\src" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


