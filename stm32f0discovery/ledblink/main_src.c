#include "hardware.h"

int main(void){
    initHardware();
    int32_t prev = 0;
    while(1){
        if( (millis() - prev) > 500 ){
            prev = millis();
            led_toggle();
        }
    }
    return 0;
}

