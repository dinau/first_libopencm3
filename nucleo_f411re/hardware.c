// stm32
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/flash.h>

#include "hardware.h"

void led_on(void) {
    gpio_set(LED_PORT,LED_BIT);
}

void led_off(void) {
    gpio_clear(LED_PORT,LED_BIT);
}

void led_toggle(void) {
    gpio_toggle(LED_PORT,LED_BIT);
}

void gpio_setup(void) {
	rcc_periph_clock_enable(RCC_GPIOA);
	rcc_periph_clock_enable(RCC_GPIOC);
    rcc_periph_clock_enable(RCC_USART);

	gpio_mode_setup(LED_PORT,      GPIO_MODE_OUTPUT, GPIO_PUPD_NONE,  LED_BIT);

	gpio_mode_setup(USER_BTN_PORT, GPIO_MODE_INPUT,  GPIO_PUPD_PULLUP,USER_BTN_BIT);
}

/******************
  PLL clock up
******************/
// (HSI RC=16MHz)
/* set system clock to 96MHz with PLL */
const struct rcc_clock_scale rcc_hsi_config = {
		.pllm = 16,
#if   (SYSTEM_CLOCK==96000000) || (SYSTEM_CLOCK==48000000)
		.plln = 384,
#elif SYSTEM_CLOCK==84000000
		.plln = 336,
#elif (SYSTEM_CLOCK==32000000) || (SYSTEM_CLOCK==64000000)
		.plln = 256,
#else
    #error Specify SYSTEM_CLOCK value
#endif
#if   (SYSTEM_CLOCK==48000000) || (SYSTEM_CLOCK==32000000)
		.pllp = 8,
#else
		.pllp = 4,
#endif
		.pllq = 8,
		.pllr = 0,
		.pll_source = RCC_CFGR_PLLSRC_HSI_CLK,
		.hpre =  RCC_CFGR_HPRE_DIV_NONE,
		.ppre1 = RCC_CFGR_PPRE_DIV_2,
		.ppre2 = RCC_CFGR_PPRE_DIV_NONE,
		.voltage_scale = PWR_SCALE3,
		.flash_config = FLASH_ACR_DCEN | FLASH_ACR_ICEN |
				FLASH_ACR_LATENCY_3WS,
		.ahb_frequency  = SYSTEM_CLOCK,
		.apb1_frequency = SYSTEM_CLOCK / 2,
		.apb2_frequency = SYSTEM_CLOCK,
};

void pll_clock_up(void) {
	//rcc_clock_setup_pll(&rcc_hsi_configs[RCC_CLOCK_3V3_84MHZ]);
	rcc_clock_setup_pll(&rcc_hsi_config);
}

