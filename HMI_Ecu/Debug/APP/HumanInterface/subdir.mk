################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/HumanInterface/humaninterface.c 

OBJS += \
./APP/HumanInterface/humaninterface.o 

C_DEPS += \
./APP/HumanInterface/humaninterface.d 


# Each subdirectory must supply rules for building sources it contributes
APP/HumanInterface/%.o: ../APP/HumanInterface/%.c APP/HumanInterface/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g3 -gdwarf-2 -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


