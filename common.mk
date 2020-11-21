CFLAGS			+= --specs=nano.specs
BUILD_DIR		= .BUILD

# You shouldn't have to edit anything below here.
VPATH += $(SHARED_DIR)
INCLUDES += $(patsubst %,-I%, . $(SHARED_DIR))
OPENCM3_DIR     = ../../lib/libopencm3

include $(OPENCM3_DIR)/mk/genlink-config.mk
include ../../rules.mk
include $(OPENCM3_DIR)/mk/genlink-rules.mk

all: $(BUILD_DIR)/$(PROJECT).elf \
     $(BUILD_DIR)/$(PROJECT).bin \
     $(BUILD_DIR)/$(PROJECT).lss \
     $(BUILD_DIR)/$(PROJECT).hex \
	 $(BUILD_DIR)/$(PROJECT).lst2
	@$(SIZE) $(BUILD_DIR)/$(PROJECT).elf

check: cleanall
	$(MAKE) -C ../..
cleanall:
	$(MAKE) -C ../.. clean

# Write to Flash
#ifneq ($(OS),Windows_NT)
ST_PROGM_CLI_EXE=/usr/local/STMicroelectronics/STM32Cube/STM32CubeProgrammer/bin/STM32_Programmer_CLI
#else
ST_PROGM_CLI_EXE = "d:/STM32CubeProgrammer/bin/STM32_Programmer_CLI.exe"
#endif

DEV_INFO = $(shell $(ST_PROGM_CLI_EXE) -c port=SWD | grep -i "device name")

w: all
ifneq (,$(findstring $(DEV_NAME), $(DEV_INFO)))
	$(Q)@echo Device = $(DEV_NAME)
	$(Q)$(ST_PROGM_CLI_EXE) -c port=SWD -d $(BUILD_DIR)/$(PROJECT).hex -hardRst
else
	$(Q)@echo $(DEV_INFO)
	$(Q)@echo Device = ???? $(DEV_NAME)
endif

