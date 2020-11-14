#ifndef __HARDWARE_H__
#define __HARDWARE_H__

#include <stdint.h>
#include <stdbool.h>
#include "xprintf.h"
#include "systick.h"

void led_on(void);
void led_off(void);
void led_toggle(void);
bool isBtnOn(void);

void gpio_setup(void);
void pll_clock_up(void);
int initHardware(void);

// LED
#define ON_BOARD_LED_PORT   GPIOA    // PA5 not used as LED
#define ON_BOARD_LED_BIT    GPIO5

// USART
#define RCC_USART           RCC_USART2
#define USART_ID            USART2
#define USART_AF            GPIO_AF7
#define USART_PORT          GPIOA    // PA2 TX
#define USART_TX_BIT        GPIO2
#define USART_RX_BIT        GPIO3    // PA3 RX

/*****************
 User Button
*****************/
#define USER_BTN_PORT       GPIOC    // PC13
#define USER_BTN_BIT        GPIO13

#endif // __HARDWARE_H__

