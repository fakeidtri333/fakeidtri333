################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LED\ display.c 

OBJS += \
./LED\ display.o 

C_DEPS += \
./LED\ display.d 


# Each subdirectory must supply rules for building sources it contributes
LED\ display.o: ../LED\ display.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -Os -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=4000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"LED\ display.d" -c -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


