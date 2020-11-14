#ifndef __HARDWARE_H__
#define __HARDWARE_H__

#include <stdint.h>
#include <stdbool.h>
#include "xprintf.h"
#include "systick.h"

void led_green_on(void);
void led_green_off(void);
void led_blue_on(void);
void led_blue_off(void);
void led_toggle(void);

bool isBtnOn(void);

void pll_clock_up(void);
void gpio_setup(void);
int initHardware(void);

// LED
#define LED_GREEN_PORT  GPIOC
#define LED_GREEN_BIT   GPIO9
#define LED_BLUE_PORT   GPIOC
#define LED_BLUE_BIT    GPIO8
// USART
#define RCC_USART       RCC_USART2
#define USART_ID        USART2
#define USART_AF        GPIO_AF7
#define USART_PORT      GPIOA    // PA2 TX
#define USART_TX_BIT    GPIO2
#define USART_RX_BIT    GPIO3    // PA3 RX

/*****************
 User Button
*****************/
#define USER_BTN_PORT   GPIOA    // PA0
#define USER_BTN_BIT    GPIO0

#endif // __HARDWARE_H__

