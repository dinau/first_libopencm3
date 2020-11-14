#include <libopencmsis/core_cm3.h> // activates the name of SysTick_Handler()
#include <libopencm3/cm3/systick.h>

#ifdef FREERTOS
    #include "FreeRTOS.h"
    #include  "task.h"
#endif

volatile int32_t tickcounter;

int32_t getTickCounter(void) {
    return tickcounter;
}

int32_t millis(void){
#ifdef FREERTOS
    return xTaskGetTickCount();
#else
    return tickcounter;
#endif
}

void wait_ms(int32_t ms) {
   int32_t target = tickcounter + ms;
   while(tickcounter < target){/* just wait */}
}


void initSystick(void) {
#ifndef FREERTOS
    systick_set_frequency(1000,SYSTEM_CLOCK); // 1msec interval
    systick_counter_enable();
    systick_interrupt_enable();
    nvic_set_priority(NVIC_SYSTICK_IRQ,9);  // Set low priority.
#endif
}

#ifndef FREERTOS
void SysTick_Handler() { // original is : void sys_tick_handler()
    tickcounter++;
}
#endif

