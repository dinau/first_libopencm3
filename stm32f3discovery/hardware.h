#ifndef __HARDWARE_H__
#define __HARDWARE_H__

#include <stdint.h>
#include <stdbool.h>
#include "xprintf.h"
#include "systick.h"

void led3_on(void);
void led4_on(void);
void led5_on(void);
void led6_on(void);
void led7_on(void);
void led8_on(void);
void led9_on(void);
void led10_on(void);

void led3_off(void);
void led4_off(void);
void led5_off(void);
void led6_off(void);
void led7_off(void);
void led8_off(void);
void led9_off(void);
void led10_off(void);

void led3_toggle(void);
void led4_toggle(void);
void led5_toggle(void);
void led6_toggle(void);
void led7_toggle(void);
void led8_toggle(void);
void led9_toggle(void);
void led10_toggle(void);

bool isBtnOn(void);

void pll_clock_up(void);
void gpio_setup(void);
int initHardware(void);

// LED
#define LED_PORT  GPIOE
#define LED3_BIT  GPIO9
#define LED4_BIT  GPIO8
#define LED5_BIT  GPIO10
#define LED6_BIT  GPIO15
#define LED7_BIT  GPIO11
#define LED8_BIT  GPIO14
#define LED9_BIT  GPIO12
#define LED10_BIT GPIO13
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
#define USER_BTN_PORT       GPIOA    // PA0
#define USER_BTN_BIT        GPIO0

#endif // __HARDWARE_H__

