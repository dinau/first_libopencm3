// stm32
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/usart.h>

#include "hardware.h"

// on
void led3_on(void)   { gpio_set(LED_PORT,LED3_BIT);   }
void led4_on(void)   { gpio_set(LED_PORT,LED4_BIT);   }
void led5_on(void)   { gpio_set(LED_PORT,LED5_BIT);   }
void led6_on(void)   { gpio_set(LED_PORT,LED6_BIT);   }
void led7_on(void)   { gpio_set(LED_PORT,LED7_BIT);   }
void led8_on(void)   { gpio_set(LED_PORT,LED8_BIT);   }
void led9_on(void)   { gpio_set(LED_PORT,LED9_BIT);   }
void led10_on(void)  { gpio_set(LED_PORT,LED10_BIT);  }
// off
void led3_off(void)  { gpio_clear(LED_PORT,LED3_BIT); }
void led4_off(void)  { gpio_clear(LED_PORT,LED4_BIT); }
void led5_off(void)  { gpio_clear(LED_PORT,LED5_BIT); }
void led6_off(void)  { gpio_clear(LED_PORT,LED6_BIT); }
void led7_off(void)  { gpio_clear(LED_PORT,LED7_BIT); }
void led8_off(void)  { gpio_clear(LED_PORT,LED8_BIT); }
void led9_off(void)  { gpio_clear(LED_PORT,LED9_BIT); }
void led10_off(void) { gpio_clear(LED_PORT,LED10_BIT);}
// toggle
void led3_toggle(void)  { gpio_toggle(LED_PORT,LED3_BIT); }
void led4_toggle(void)  { gpio_toggle(LED_PORT,LED4_BIT); }
void led5_toggle(void)  { gpio_toggle(LED_PORT,LED5_BIT); }
void led6_toggle(void)  { gpio_toggle(LED_PORT,LED6_BIT); }
void led7_toggle(void)  { gpio_toggle(LED_PORT,LED7_BIT); }
void led8_toggle(void)  { gpio_toggle(LED_PORT,LED8_BIT); }
void led9_toggle(void)  { gpio_toggle(LED_PORT,LED9_BIT); }
void led10_toggle(void) { gpio_toggle(LED_PORT,LED10_BIT);}

void gpio_setup(void) {
	rcc_periph_clock_enable(RCC_GPIOA);
	rcc_periph_clock_enable(RCC_GPIOC);
	rcc_periph_clock_enable(RCC_GPIOE);
    rcc_periph_clock_enable(RCC_USART);
	gpio_mode_setup(LED_PORT,      GPIO_MODE_OUTPUT, GPIO_PUPD_NONE
            , LED3_BIT
            | LED4_BIT
            | LED5_BIT
            | LED6_BIT
            | LED7_BIT
            | LED8_BIT
            | LED9_BIT
            | LED10_BIT
            );

	gpio_mode_setup(USER_BTN_PORT, GPIO_MODE_INPUT,  GPIO_PUPD_PULLUP,USER_BTN_BIT);
}

/******************
  PLL clock up
******************/
void pll_clock_up(void) {
	rcc_clock_setup_pll(&rcc_hsi_configs[RCC_CLOCK_HSI_64MHZ]);
}


