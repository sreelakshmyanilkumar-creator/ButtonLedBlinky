################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CustomDrivers/source/CustomGpio.c \
../CustomDrivers/source/CustomSemaphore.c \
../CustomDrivers/source/CustomStart.c \
../CustomDrivers/source/CustomTasks.c \
../CustomDrivers/source/Led.c \
../CustomDrivers/source/MessageQueue.c \
../CustomDrivers/source/Process.c \
../CustomDrivers/source/PushButton.c 

OBJS += \
./CustomDrivers/source/CustomGpio.o \
./CustomDrivers/source/CustomSemaphore.o \
./CustomDrivers/source/CustomStart.o \
./CustomDrivers/source/CustomTasks.o \
./CustomDrivers/source/Led.o \
./CustomDrivers/source/MessageQueue.o \
./CustomDrivers/source/Process.o \
./CustomDrivers/source/PushButton.o 

C_DEPS += \
./CustomDrivers/source/CustomGpio.d \
./CustomDrivers/source/CustomSemaphore.d \
./CustomDrivers/source/CustomStart.d \
./CustomDrivers/source/CustomTasks.d \
./CustomDrivers/source/Led.d \
./CustomDrivers/source/MessageQueue.d \
./CustomDrivers/source/Process.d \
./CustomDrivers/source/PushButton.d 


# Each subdirectory must supply rules for building sources it contributes
CustomDrivers/source/%.o CustomDrivers/source/%.su CustomDrivers/source/%.cyclo: ../CustomDrivers/source/%.c CustomDrivers/source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3 -I"D:/Training_Folder/TASK_4_RTOS/Programs/FreeRtosButtonLED/ButtonLedBlinky/CustomDrivers/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-CustomDrivers-2f-source

clean-CustomDrivers-2f-source:
	-$(RM) ./CustomDrivers/source/CustomGpio.cyclo ./CustomDrivers/source/CustomGpio.d ./CustomDrivers/source/CustomGpio.o ./CustomDrivers/source/CustomGpio.su ./CustomDrivers/source/CustomSemaphore.cyclo ./CustomDrivers/source/CustomSemaphore.d ./CustomDrivers/source/CustomSemaphore.o ./CustomDrivers/source/CustomSemaphore.su ./CustomDrivers/source/CustomStart.cyclo ./CustomDrivers/source/CustomStart.d ./CustomDrivers/source/CustomStart.o ./CustomDrivers/source/CustomStart.su ./CustomDrivers/source/CustomTasks.cyclo ./CustomDrivers/source/CustomTasks.d ./CustomDrivers/source/CustomTasks.o ./CustomDrivers/source/CustomTasks.su ./CustomDrivers/source/Led.cyclo ./CustomDrivers/source/Led.d ./CustomDrivers/source/Led.o ./CustomDrivers/source/Led.su ./CustomDrivers/source/MessageQueue.cyclo ./CustomDrivers/source/MessageQueue.d ./CustomDrivers/source/MessageQueue.o ./CustomDrivers/source/MessageQueue.su ./CustomDrivers/source/Process.cyclo ./CustomDrivers/source/Process.d ./CustomDrivers/source/Process.o ./CustomDrivers/source/Process.su ./CustomDrivers/source/PushButton.cyclo ./CustomDrivers/source/PushButton.d ./CustomDrivers/source/PushButton.o ./CustomDrivers/source/PushButton.su

.PHONY: clean-CustomDrivers-2f-source

