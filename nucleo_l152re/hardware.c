// stm32
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/flash.h>

#include "hardware.h"

void led_on(void) {
    gpio_set(ON_BOARD_LED_PORT,ON_BOARD_LED_BIT);
}

void led_off(void) {
    gpio_clear(ON_BOARD_LED_PORT,ON_BOARD_LED_BIT);
}

void led_toggle(void) {
    gpio_toggle(ON_BOARD_LED_PORT,ON_BOARD_LED_BIT);
}

void gpio_setup(void) {
	rcc_periph_clock_enable(RCC_GPIOA);
	rcc_periph_clock_enable(RCC_GPIOC);
    rcc_periph_clock_enable(RCC_USART);

	gpio_mode_setup(ON_BOARD_LED_PORT,      GPIO_MODE_OUTPUT, GPIO_PUPD_NONE,  ON_BOARD_LED_BIT);

	gpio_mode_setup(USER_BTN_PORT, GPIO_MODE_INPUT,  GPIO_PUPD_PULLUP,USER_BTN_BIT);
}

/******************
  PLL clock up
******************/

void pll_clock_up(void) {
	rcc_clock_setup_pll(&rcc_clock_config[RCC_CLOCK_VRANGE1_HSI_PLL_32MHZ]);
}

