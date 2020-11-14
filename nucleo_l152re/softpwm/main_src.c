#include "hardware.h"
#include "TSoftPwm.h"
#include "disp_info.h"

int main(void){
    TSoftPwm pwm;

    initHardware();
    SoftPwm_init( &pwm,led_on,led_off);

    while(1){
        regInfoCore();
        SoftPwm_exec(&pwm,3);
    }
    return 0;
}

