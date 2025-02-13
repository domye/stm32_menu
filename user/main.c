#include "domye.h"

int main(void)
{
    uint16_t flag = 1;
    uint16_t flag_B = 1;

    key_A_init();
    key_B_init();
    OLED_Init();
    OLED_ShowString(30, 30, "欢迎使用!", OLED_8X16);
    OLED_Update();
    delay_s(1);
    while (1)
    {
        int key_value = key_read();
        read_A(flag);
        if (key_value == 1)
        {
            flag--;
            if (flag == 0)
                flag = 4;
        }
        if (key_value == 3)
        {
            flag++;
            if (flag == 5)
                flag = 1;
        }

        if (key_value == 2)
        {
            run_B(flag, flag_B);
        }
    }
}
