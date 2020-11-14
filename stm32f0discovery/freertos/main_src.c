#include "hardware.h"
#include "TSoftPwm.h"
#include "disp_info.h"

#include "FreeRTOS.h"
#include "task.h"

void print_tsk(void *pvParameters) {
    (void) pvParameters;

    while(1){
        regInfoCore();
        vTaskDelay(1);
    }
}

void softpwm_tsk(void *pvParameters ) {
    (void) pvParameters;

    static TSoftPwm pwm1,pwm2;

    SoftPwm_init( &pwm1,led_green_on,led_green_off);
    SoftPwm_init( &pwm2,led_blue_on, led_blue_off);

    while(1){
        SoftPwm_exec(&pwm1,2);
    }
}

int main(void) {
    initHardware();
    xTaskCreate( softpwm_tsk, "softPwm_task", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1 , NULL);
    xTaskCreate( print_tsk,   "print_task",   configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 2 , NULL);

    vTaskStartScheduler();

  return 0;
}

