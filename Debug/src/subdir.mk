################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/BackgroundSubstractor.cpp \
../src/distances.cpp \
../src/noise_reduction.cpp \
../src/skin_detection.cpp \
../src/test.cpp 

OBJS += \
./src/BackgroundSubstractor.o \
./src/distances.o \
./src/noise_reduction.o \
./src/skin_detection.o \
./src/test.o 

CPP_DEPS += \
./src/BackgroundSubstractor.d \
./src/distances.d \
./src/noise_reduction.d \
./src/skin_detection.d \
./src/test.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/opencv -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


