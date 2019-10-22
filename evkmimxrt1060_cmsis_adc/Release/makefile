################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include xip/subdir.mk
-include utilities/subdir.mk
-include startup/subdir.mk
-include source/subdir.mk
-include drivers/subdir.mk
-include device/subdir.mk
-include component/uart/subdir.mk
-include component/serial_manager/subdir.mk
-include component/lists/subdir.mk
-include board/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: evkmimxrt1060_cmsis_adc.axf

# Tool invocations
evkmimxrt1060_cmsis_adc.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -Xlinker -Map="evkmimxrt1060_cmsis_adc.map" -Xlinker --gc-sections -Xlinker -print-memory-usage -Xlinker --sort-section=alignment -Xlinker --cref -mcpu=cortex-m7 -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -T evkmimxrt1060_iled_blinky_teensy_test_Release.ld -o "evkmimxrt1060_cmsis_adc.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) evkmimxrt1060_cmsis_adc.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "evkmimxrt1060_cmsis_adc.axf" ; arm-none-eabi-objdump -x -d "evkmimxrt1060_cmsis_adc.axf" > "evkmimxrt1060_cmsis_adc.dis" ; arm-none-eabi-objcopy -v -O ihex -R .eeprom "evkmimxrt1060_cmsis_adc.axf" "evkmimxrt1060_cmsis_adc.hex" ; # arm-none-eabi-objcopy -v -O binary "evkmimxrt1060_cmsis_adc.axf" "evkmimxrt1060_cmsis_adc.bin" ; # checksum -p MIMXRT1062xxxxA -d "evkmimxrt1060_cmsis_adc.bin"
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets
