// stm32
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/usart.h>

#include "hardware.h"


void led_green_on(void) {
    gpio_set(LED_GREEN_PORT,LED_GREEN_BIT);
}

void led_green_off(void) {
    gpio_clear(LED_GREEN_PORT,LED_GREEN_BIT);
}

void led_toggle(void) {
    gpio_toggle(LED_GREEN_PORT,LED_GREEN_BIT);
}
void led_blue_on(void) {
    gpio_set(LED_BLUE_PORT,LED_BLUE_BIT);
}

void led_blue_off(void) {
    gpio_clear(LED_BLUE_PORT,LED_BLUE_BIT);
}

void gpio_setup(void) {
	rcc_periph_clock_enable(RCC_GPIOA);
	rcc_periph_clock_enable(RCC_GPIOC);
    rcc_periph_clock_enable(RCC_USART);

	gpio_mode_setup(LED_GREEN_PORT,GPIO_MODE_OUTPUT, GPIO_PUPD_NONE,  LED_GREEN_BIT);
	gpio_mode_setup(LED_BLUE_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE,  LED_BLUE_BIT);

	gpio_mode_setup(USER_BTN_PORT, GPIO_MODE_INPUT,  GPIO_PUPD_PULLUP,USER_BTN_BIT);
}

/******************
  PLL clock up
******************/
// (HSI RC=8MHz)
/* set system clock to 48MHz with PLL */
void pll_clock_up(void) {
    rcc_clock_setup_in_hsi_out_48mhz();
}

