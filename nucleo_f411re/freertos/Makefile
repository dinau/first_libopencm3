PROJECT			= freertos_$(DEV_NAME)
CFLAGS			+= -DSYSTEM_CLOCK=84000000
CFLAGS			+= -DUSART_BAUDRATE=115200

SHARED_DIR		= . .. ../../lib ../../lib/xprintf
LIB_CSRC        += $(wildcard ../../lib/*.c)
LIB_CSRC        += $(wildcard ../../lib/xprintf/*.c)
CSRC			+= $(wildcard *.c) $(wildcard ../*.c)
CFILES			+= $(notdir $(CSRC)) $(notdir $(LIB_CSRC))
#AFILES			+=

# TODO - you will need to edit these two lines!
DEVICE          = stm32f411ret6
DEV_NAME        = STM32F411
#OOCD_FILE = board/stm32f4discovery.cfg

########################
# Definition of FreeRTOS
########################
CFLAGS        += -DFREERTOS
RTOS_SRC_DIR  = ../../lib/freertos/Source
RTOS_INC_DIR  = $(RTOS_SRC_DIR)/include
RTOS_PORT_DIR = $(RTOS_SRC_DIR)/portable/GCC/ARM_CM4F
RTOS_HEAP_DIR = $(RTOS_SRC_DIR)/portable/MemMang

SHARED_DIR   += $(RTOS_INC_DIR) $(RTOS_PORT_DIR) $(RTOS_SRC_DIR) $(RTOS_HEAP_DIR)
LIB_CSRC     += $(wildcard $(RTOS_SRC_DIR)/*.c)
LIB_CSRC     += $(wildcard $(RTOS_PORT_DIR)/*.c)
LIB_CSRC	 += $(RTOS_HEAP_DIR)/heap_1.c

include ../../common.mk

