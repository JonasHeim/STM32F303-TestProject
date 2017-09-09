################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Timer.c \
../src/_write.c \
../src/console.c \
../src/gpio.c \
../src/interrupt.c \
../src/main.c \
../src/spi.c \
../src/usart.c 

OBJS += \
./src/Timer.o \
./src/_write.o \
./src/console.o \
./src/gpio.o \
./src/interrupt.o \
./src/main.o \
./src/spi.o \
./src/usart.o 

C_DEPS += \
./src/Timer.d \
./src/_write.d \
./src/console.d \
./src/gpio.d \
./src/interrupt.d \
./src/main.d \
./src/spi.d \
./src/usart.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F30X -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f3-stdperiph" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


