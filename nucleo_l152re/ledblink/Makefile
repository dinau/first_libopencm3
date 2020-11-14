PROJECT			= ledblink_$(DEV_NAME)
CFLAGS			+= -DSYSTEM_CLOCK=32000000
CFLAGS			+= -DUSART_BAUDRATE=115200

SHARED_DIR		= . .. ../../lib ../../lib/xprintf
LIB_CSRC        += $(wildcard ../../lib/*.c)
LIB_CSRC        += $(wildcard ../../lib/xprintf/*.c)
CSRC			+= $(wildcard *.c) $(wildcard ../*.c)
CFILES			+= $(notdir $(CSRC)) $(notdir $(LIB_CSRC))
#AFILES			+=

# TODO - you will need to edit these two lines!
DEVICE          = stm32l152ret6
DEV_NAME        = STM32L1
#OOCD_FILE = board/stm32f4discovery.cfg

include ../../common.mk

