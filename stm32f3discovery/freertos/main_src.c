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
    #define LED_MAX  8
    static TSoftPwm pwm[LED_MAX];
    static void (*led[LED_MAX*2])(void)={  led3_on,led3_off   ,led5_on,led5_off
                                          ,led7_on,led7_off   ,led9_on,led9_off
                                          ,led10_on,led10_off ,led8_on,led8_off
                                          ,led6_on,led6_off   ,led4_on,led4_off
    };

    for(int i=0; i<LED_MAX; i++){
        SoftPwm_init( &pwm[i],led[i*2],led[i*2+1]);
    }
    static uint32_t ix = 0;
    while(1) {
        if( 0 == SoftPwm_exec(&pwm[ix] ,3) ){
            ix++;
            ix %= LED_MAX;
        }
    }
}

int main(void) {
    initHardware();
    xTaskCreate( softpwm_tsk, "softpwm_task", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1 , NULL);
    xTaskCreate( print_tsk,   "print_task",   configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 2 , NULL);

    vTaskStartScheduler();

  return 0;
}

