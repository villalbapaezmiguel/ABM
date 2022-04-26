################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Contratacion.c \
../src/Informes.c \
../src/Menu.c \
../src/Pantalla.c \
../src/clase_17_.c \
../src/utn.c 

OBJS += \
./src/Contratacion.o \
./src/Informes.o \
./src/Menu.o \
./src/Pantalla.o \
./src/clase_17_.o \
./src/utn.o 

C_DEPS += \
./src/Contratacion.d \
./src/Informes.d \
./src/Menu.d \
./src/Pantalla.d \
./src/clase_17_.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


