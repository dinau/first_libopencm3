TARGET_MCU = "stm32/f0 stm32/l1 stm32/f4 stm32/f3"
OPTIMIZE = -Os
LIBOPENCM3 = lib/libopencm3

MODELS := stm32f0discovery stm32f3discovery nucleo_f411re nucleo_l152re

SAMPLE_LED = ledblink
SAMPLE_PWM = softpwm
SAMPLE_RTOS= freertos

all: led pwm rtos

led:
	$(foreach model,$(MODELS), $(call def_make,$(model)/$(SAMPLE_LED)))
pwm:
	$(foreach model,$(MODELS), $(call def_make,$(model)/$(SAMPLE_PWM)))

rtos:
	$(foreach model,$(MODELS), $(call def_make,$(model)/$(SAMPLE_RTOS)))

clean: led_c pwm_c rtos_c

led_c:
	$(foreach model,$(MODELS), $(call def_clean,$(model)/$(SAMPLE_LED) ))
pwm_c:
	$(foreach model,$(MODELS), $(call def_clean,$(model)/$(SAMPLE_PWM) ))
rtos_c:
	$(foreach model,$(MODELS), $(call def_clean,$(model)/$(SAMPLE_RTOS) ))


# definition loop funciton
define def_make
	-@$(MAKE) -C $(1)

endef

define def_clean
	-@$(MAKE) -C $(1) clean

endef

.PHONY: lib submodule


init:
	$(MAKE) -C $(LIBOPENCM3) TARGETS=$(TARGET_MCU) CFLAGS=$(OPTIMIZE)

MAKEFLAGS += --no-print-directory

