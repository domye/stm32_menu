#ifndef __LED_H
#define __LED_H
void led_init();
void led(uint8_t pinNumber, FunctionalState newState);
void led_all_off(void);
void led_all_on(void);
#endif
