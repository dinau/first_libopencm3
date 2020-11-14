/* Made by audin, 2020/11 */
#include "TSoftPwm.h"
#include "hardware.h"

static int8_t _softPwm( TSoftPwm *p, int8_t DUTY_CHANGE_SPEED ) ; /* speed: 1 ... 9 */

void SoftPwm_init(TSoftPwm *this, void(*phi)(void),void(*plow)(void)){
    this -> sbDutyCurrentPos = 0;
    this -> sbDutyDelta      = 0;
    this -> sbTargetDuty     = 0;
    this -> prev             = 0;
    this -> hi = phi;
    this -> low= plow;
    this -> DUTY_UPDATE_PERIOD = 25;     /* msec */
    this -> PWM_PERIOD         = (127 - 9); /* 63 step  */
    this -> exec = _softPwm;
}

int8_t SoftPwm_exec(TSoftPwm *this, int8_t speed) {
   return this -> exec(this,speed);
}

/*******************
* _softPwm
 *******************/
static int8_t _softPwm( TSoftPwm *p, int8_t DUTY_CHANGE_SPEED ) { /* speed: 1 ... 9 */
    ( p->sbTargetDuty > p->sbDutyCurrentPos++ ) ?  p->hi() : p->low();
    if( p->sbDutyCurrentPos >= p->PWM_PERIOD ){
        p->sbDutyCurrentPos = 0;
        if( ( millis() - p->prev) >= p->DUTY_UPDATE_PERIOD ) {
            p->prev = millis();
            p->sbTargetDuty += p->sbDutyDelta;
            if( p->sbTargetDuty >= p->PWM_PERIOD ) {
                p->sbDutyDelta = -DUTY_CHANGE_SPEED;
            }
            else if(p->sbTargetDuty <= 0){
                p->sbTargetDuty = 0;
                p->sbDutyDelta = DUTY_CHANGE_SPEED;
            }
        }
    }
    return p->sbTargetDuty;
}

