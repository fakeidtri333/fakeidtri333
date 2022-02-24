################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lcd_lib.c \
../mcu2mcu\ rx.c \
../uart_lib.c 

OBJS += \
./lcd_lib.o \
./mcu2mcu\ rx.o \
./uart_lib.o 

C_DEPS += \
./lcd_lib.d \
./mcu2mcu\ rx.d \
./uart_lib.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -Os -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=4000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

mcu2mcu\ rx.o: ../mcu2mcu\ rx.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -Os -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=4000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"mcu2mcu\ rx.d" -c -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


