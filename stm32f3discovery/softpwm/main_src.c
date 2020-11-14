#include "hardware.h"
#include "TSoftPwm.h"
#include "disp_info.h"

#define  LED_MAX 8
int main(void){
    TSoftPwm pwm[LED_MAX];
    void (*led[LED_MAX*2])(void)={  led3_on,led3_off   ,led5_on,led5_off
                                   ,led7_on,led7_off   ,led9_on,led9_off
                                   ,led10_on,led10_off ,led8_on,led8_off
                                   ,led6_on,led6_off   ,led4_on,led4_off
    };

    initHardware();
    for(int i=0; i<LED_MAX; i++){
        SoftPwm_init( &pwm[i],led[i*2],led[i*2+1]);
    }
    uint32_t ix = 0;
    while(1) {
        regInfoCore();
        if( 0 == SoftPwm_exec(&pwm[ix] ,3) ){
            ix++;
            ix %= LED_MAX;
        }
    }
    return 0;
}


