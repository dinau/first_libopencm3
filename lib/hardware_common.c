// stm32
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/usart.h>

#include "hardware.h"

/******************
  UART
******************/
static void UART_putc(uint8_t c){ usart_send_blocking(USART_ID,c); }

void usart_setup(void) { /* Setup USART parameters. */
    usart_set_baudrate(    USART_ID, USART_BAUDRATE);
    usart_set_databits(    USART_ID, 8);
    usart_set_stopbits(    USART_ID, USART_STOPBITS_1);
    usart_set_mode(        USART_ID, USART_MODE_TX_RX);
    usart_set_parity(      USART_ID, USART_PARITY_NONE);
    usart_set_flow_control(USART_ID, USART_FLOWCONTROL_NONE);

    /* Finally enable the USART. */
    usart_enable(USART_ID);
}

void initSerial(void) { // UART
    /* Setup GPIO pins for USART transmit. */
    gpio_mode_setup(USART_PORT, GPIO_MODE_AF, GPIO_PUPD_NONE  , USART_TX_BIT);// TX
    gpio_mode_setup(USART_PORT, GPIO_MODE_AF, GPIO_PUPD_PULLUP, USART_RX_BIT);// RX

    /* Setup USART pin as alternate function. */
    gpio_set_af(USART_PORT, USART_AF, USART_TX_BIT | USART_RX_BIT);

    usart_setup();
    xfunc_out = UART_putc;
}

bool isBtnOn(void) {
    return 0 == gpio_get(USER_BTN_PORT,USER_BTN_BIT);
}

int initHardware(void) {
	gpio_setup();
    pll_clock_up();
    initSystick();
    initSerial();

	return 0;
}

