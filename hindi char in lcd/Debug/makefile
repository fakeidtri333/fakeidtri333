################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
sdsadaa.lss \

FLASH_IMAGE += \
sdsadaa.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: sdsadaa.elf secondary-outputs

# Tool invocations
sdsadaa.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,sdsadaa.map -mmcu=atmega16 -o"sdsadaa.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

sdsadaa.lss: sdsadaa.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S sdsadaa.elf  >"sdsadaa.lss"
	@echo 'Finished building: $@'
	@echo ' '

sdsadaa.hex: sdsadaa.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex sdsadaa.elf  "sdsadaa.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: sdsadaa.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 sdsadaa.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) sdsadaa.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
