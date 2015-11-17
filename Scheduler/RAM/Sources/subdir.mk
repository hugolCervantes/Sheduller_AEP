################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Exceptions.c" \
"../Sources/IntcInterrupts.c" \
"../Sources/OS_Init.c" \
"../Sources/STM_Timer.c" \
"../Sources/ivor_branch_table.c" \
"../Sources/kernel.c" \
"../Sources/main.c" \
"../Sources/task.c" \

C_SRCS += \
../Sources/Exceptions.c \
../Sources/IntcInterrupts.c \
../Sources/OS_Init.c \
../Sources/STM_Timer.c \
../Sources/ivor_branch_table.c \
../Sources/kernel.c \
../Sources/main.c \
../Sources/task.c \

OBJS += \
./Sources/Exceptions_c.obj \
./Sources/IntcInterrupts_c.obj \
./Sources/OS_Init_c.obj \
./Sources/STM_Timer_c.obj \
./Sources/ivor_branch_table_c.obj \
./Sources/kernel_c.obj \
./Sources/main_c.obj \
./Sources/task_c.obj \

OBJS_QUOTED += \
"./Sources/Exceptions_c.obj" \
"./Sources/IntcInterrupts_c.obj" \
"./Sources/OS_Init_c.obj" \
"./Sources/STM_Timer_c.obj" \
"./Sources/ivor_branch_table_c.obj" \
"./Sources/kernel_c.obj" \
"./Sources/main_c.obj" \
"./Sources/task_c.obj" \

C_DEPS += \
./Sources/Exceptions_c.d \
./Sources/IntcInterrupts_c.d \
./Sources/OS_Init_c.d \
./Sources/STM_Timer_c.d \
./Sources/ivor_branch_table_c.d \
./Sources/kernel_c.d \
./Sources/main_c.d \
./Sources/task_c.d \

OBJS_OS_FORMAT += \
./Sources/Exceptions_c.obj \
./Sources/IntcInterrupts_c.obj \
./Sources/OS_Init_c.obj \
./Sources/STM_Timer_c.obj \
./Sources/ivor_branch_table_c.obj \
./Sources/kernel_c.obj \
./Sources/main_c.obj \
./Sources/task_c.obj \

C_DEPS_QUOTED += \
"./Sources/Exceptions_c.d" \
"./Sources/IntcInterrupts_c.d" \
"./Sources/OS_Init_c.d" \
"./Sources/STM_Timer_c.d" \
"./Sources/ivor_branch_table_c.d" \
"./Sources/kernel_c.d" \
"./Sources/main_c.d" \
"./Sources/task_c.d" \


# Each subdirectory must supply rules for building sources it contributes
Sources/Exceptions_c.obj: ../Sources/Exceptions.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/Exceptions.args" -o "Sources/Exceptions_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/IntcInterrupts_c.obj: ../Sources/IntcInterrupts.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/IntcInterrupts.args" -o "Sources/IntcInterrupts_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/OS_Init_c.obj: ../Sources/OS_Init.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/OS_Init.args" -o "Sources/OS_Init_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/STM_Timer_c.obj: ../Sources/STM_Timer.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/STM_Timer.args" -o "Sources/STM_Timer_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/ivor_branch_table_c.obj: ../Sources/ivor_branch_table.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/ivor_branch_table.args" -o "Sources/ivor_branch_table_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/kernel_c.obj: ../Sources/kernel.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/kernel.args" -o "Sources/kernel_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/main_c.obj: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/main.args" -o "Sources/main_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/task_c.obj: ../Sources/task.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/task.args" -o "Sources/task_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '


