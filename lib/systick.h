#ifndef __SYSTICK_H__
#define __SYSTICK_H__

void initSystick(void);
int32_t getTickCounter(void);
int32_t millis(void);
void wait_ms(int32_t ms);

#endif // __SYSTICK_H__

