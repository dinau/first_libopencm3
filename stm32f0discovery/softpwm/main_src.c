#include "hardware.h"
#include "TSoftPwm.h"
#include "disp_info.h"

int main(void) {
    TSoftPwm pwm1,pwm2;
    int i = 0;
    int32_t prev = 0;

    initHardware();
    SoftPwm_init( &pwm1,led_green_on,led_green_off);
    SoftPwm_init( &pwm2,led_blue_on, led_blue_off);

    while(1){
        regInfoCore();
        SoftPwm_exec(&pwm1,2);
        SoftPwm_exec(&pwm2,4);
    }
    return 0;
}

