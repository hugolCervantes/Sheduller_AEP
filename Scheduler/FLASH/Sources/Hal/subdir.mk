################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Hal/Internal_PButt.c" \
"../Sources/Hal/Leds.c" \

C_SRCS += \
../Sources/Hal/Internal_PButt.c \
../Sources/Hal/Leds.c \

OBJS += \
./Sources/Hal/Internal_PButt_c.obj \
./Sources/Hal/Leds_c.obj \

OBJS_QUOTED += \
"./Sources/Hal/Internal_PButt_c.obj" \
"./Sources/Hal/Leds_c.obj" \

C_DEPS += \
./Sources/Hal/Internal_PButt_c.d \
./Sources/Hal/Leds_c.d \

OBJS_OS_FORMAT += \
./Sources/Hal/Internal_PButt_c.obj \
./Sources/Hal/Leds_c.obj \

C_DEPS_QUOTED += \
"./Sources/Hal/Internal_PButt_c.d" \
"./Sources/Hal/Leds_c.d" \


# Each subdirectory must supply rules for building sources it contributes
Sources/Hal/Internal_PButt_c.obj: ../Sources/Hal/Internal_PButt.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/Hal/Internal_PButt.args" -o "Sources/Hal/Internal_PButt_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/Hal/%.d: ../Sources/Hal/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/Hal/Leds_c.obj: ../Sources/Hal/Leds.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/Hal/Leds.args" -o "Sources/Hal/Leds_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '


