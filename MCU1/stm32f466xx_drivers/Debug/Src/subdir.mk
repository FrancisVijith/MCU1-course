################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/006_spi_tx_testing.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/006_spi_tx_testing.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/006_spi_tx_testing.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/006_spi_tx_testing.o: ../Src/006_spi_tx_testing.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F446RETx -DDEBUG -DNUCLEO_F446RE -c -I"C:/Users/Admin/Documents/MCU1 course/MCU1/stm32f466xx_drivers/Inc" -I"C:/Users/Admin/Documents/MCU1 course/MCU1/stm32f466xx_drivers/drivers/inc" -I../Inc -I"C:/Users/Admin/Documents/MCU1 course/MCU1/stm32f466xx_drivers/drivers/src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/006_spi_tx_testing.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/syscalls.o: ../Src/syscalls.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F446RETx -DDEBUG -DNUCLEO_F446RE -c -I"C:/Users/Admin/Documents/MCU1 course/MCU1/stm32f466xx_drivers/Inc" -I"C:/Users/Admin/Documents/MCU1 course/MCU1/stm32f466xx_drivers/drivers/inc" -I../Inc -I"C:/Users/Admin/Documents/MCU1 course/MCU1/stm32f466xx_drivers/drivers/src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/syscalls.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/sysmem.o: ../Src/sysmem.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F446RETx -DDEBUG -DNUCLEO_F446RE -c -I"C:/Users/Admin/Documents/MCU1 course/MCU1/stm32f466xx_drivers/Inc" -I"C:/Users/Admin/Documents/MCU1 course/MCU1/stm32f466xx_drivers/drivers/inc" -I../Inc -I"C:/Users/Admin/Documents/MCU1 course/MCU1/stm32f466xx_drivers/drivers/src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/sysmem.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

