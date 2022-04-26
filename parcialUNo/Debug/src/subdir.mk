################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ABM_SalonArcade.c \
../src/Arcade.c \
../src/Salon.c \
../src/parcialUNo.c \
../src/utn.c 

OBJS += \
./src/ABM_SalonArcade.o \
./src/Arcade.o \
./src/Salon.o \
./src/parcialUNo.o \
./src/utn.o 

C_DEPS += \
./src/ABM_SalonArcade.d \
./src/Arcade.d \
./src/Salon.d \
./src/parcialUNo.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


