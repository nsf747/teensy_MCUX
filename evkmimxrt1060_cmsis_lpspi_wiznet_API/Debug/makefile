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
-include source/Wiznet_Ethernet_Library/Internet/httpServer/subdir.mk
-include source/Wiznet_Ethernet_Library/Internet/TFTP/subdir.mk
-include source/Wiznet_Ethernet_Library/Internet/SNTP/subdir.mk
-include source/Wiznet_Ethernet_Library/Internet/SNMP/subdir.mk
-include source/Wiznet_Ethernet_Library/Internet/MQTT/MQTTPacket/src/subdir.mk
-include source/Wiznet_Ethernet_Library/Internet/MQTT/subdir.mk
-include source/Wiznet_Ethernet_Library/Internet/DNS/subdir.mk
-include source/Wiznet_Ethernet_Library/Internet/DHCP/subdir.mk
-include source/Wiznet_Ethernet_Library/Ethernet/W5500/subdir.mk
-include source/Wiznet_Ethernet_Library/Ethernet/W5300/subdir.mk
-include source/Wiznet_Ethernet_Library/Ethernet/W5200/subdir.mk
-include source/Wiznet_Ethernet_Library/Ethernet/W5100S/subdir.mk
-include source/Wiznet_Ethernet_Library/Ethernet/W5100/subdir.mk
-include source/Wiznet_Ethernet_Library/Ethernet/subdir.mk
-include source/Wiznet_Ethernet_Library/Application/loopback/subdir.mk
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
all: evkmimxrt1060_cmsis_lpspi_wiznet_API.axf

# Tool invocations
evkmimxrt1060_cmsis_lpspi_wiznet_API.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -Xlinker -Map="evkmimxrt1060_cmsis_lpspi_wiznet_API.map" -Xlinker --gc-sections -Xlinker -print-memory-usage -Xlinker --sort-section=alignment -Xlinker --cref -mcpu=cortex-m7 -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -T evkmimxrt1060_cmsis_lpspi_wiznet_API_Debug.ld -o "evkmimxrt1060_cmsis_lpspi_wiznet_API.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) evkmimxrt1060_cmsis_lpspi_wiznet_API.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "evkmimxrt1060_cmsis_lpspi_wiznet_API.axf" ; arm-none-eabi-objdump -x -d "evkmimxrt1060_cmsis_lpspi_wiznet_API.axf" > "evkmimxrt1060_cmsis_lpspi_wiznet_API.dis" ; arm-none-eabi-objcopy -v -O ihex -R .eeprom "evkmimxrt1060_cmsis_lpspi_wiznet_API.axf" "evkmimxrt1060_cmsis_lpspi_wiznet_API.hex" ; # arm-none-eabi-objcopy -v -O binary "evkmimxrt1060_cmsis_lpspi_wiznet_API.axf" "evkmimxrt1060_cmsis_lpspi_wiznet_API.bin" ; # checksum -p MIMXRT1062xxxxA -d "evkmimxrt1060_cmsis_lpspi_wiznet_API.bin"
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets
