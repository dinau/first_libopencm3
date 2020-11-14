#include "hardware.h"
#define LED_MAX   8

int main(void){
    void (*led_toggle[LED_MAX])(void) = {
             led3_toggle  ,led5_toggle
            ,led7_toggle  ,led9_toggle
            ,led10_toggle ,led8_toggle
            ,led6_toggle  ,led4_toggle
    };
    initHardware();

    int32_t prev = 0;
    uint8_t i = 0;
    while(1) {
        if( (millis() - prev) > 1500 ) {
            prev = millis();
            led_toggle[i++]();
            if( i >= LED_MAX){ i = 0;}
        }
    }
    return 0;
}


