/* Made by audin, 2020/11 */
#ifndef __TPWM_H__
#define __TPWM_H__
#include <stdint.h>

typedef struct _softpwm_t {
    int8_t PWM_PERIOD;  /* msec */
    int8_t DUTY_UPDATE_PERIOD;
    int8_t sbDutyCurrentPos;
    int8_t sbDutyDelta;
    int8_t sbTargetDuty;
    int32_t prev;
    void   (*hi)(void);
    void   (*low)(void);
    int8_t (*exec)(struct _softpwm_t *self,int8_t DUTY_CHANGE_SPEED);
} TSoftPwm;

void   SoftPwm_init(TSoftPwm *this, void(*phi)(void),void(*plow)(void));
int8_t SoftPwm_exec(TSoftPwm *this, int8_t speed);

#endif// __TPWM_H__


