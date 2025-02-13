#ifndef __READ_H
#define __READ_H
void read_A(uint16_t flag);
void read_B_1(uint16_t flag_B);
void read_B_2(uint16_t flag_B);
void read_B_3(uint16_t flag_B);
void read_B_1_4(uint16_t flag_C, int led_num, int *led_state);
void led_num_read(int led_num);
void led_state_read(int led_num, int *led_state);
void read_count(double shangyige, int fuhao, double num_1, double result);

void read_B_3_2(int flag_c, int guang, int re);
#endif