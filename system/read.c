#include "domye.h"

/*一级菜单显示*/
void read_A(uint16_t flag)
{
    switch (flag)
    {
    case 1:
        OLED_Clear();
        OLED_ShowImage(7, 4, 60, 60, light);
        OLED_ShowString(75, 20, "灯光", OLED_8X16);
        OLED_Update();
        break;
    case 2:
        OLED_Clear();
        OLED_ShowImage(10, 5, 60, 60, photo);
        OLED_ShowString(83, 20, "照片", OLED_8X16);
        OLED_Update();
        break;
    case 3:
        OLED_Clear();
        OLED_ShowImage(10, 2, 60, 60, tool);
        OLED_ShowString(75, 20, "工具", OLED_8X16);
        OLED_Update();
        break;
    case 4:
        OLED_Clear();
        OLED_ShowImage(4, 4, 60, 60, math);
        OLED_ShowString(65, 23, "待开发", OLED_8X16);
        OLED_Update();
        break;
    }
}

/*第一个二级菜单显示*/
void read_B_1(uint16_t flag_B)
{
    switch (flag_B)
    {
    case 1:
        OLED_Clear();
        OLED_ShowString(67, 0, "返回", OLED_8X16);
        OLED_ShowString(43, 21, "功能1", OLED_8X16);
        OLED_ShowString(19, 42, "功能2", OLED_8X16);
        OLED_ReverseArea(43, 21, 40, 20);
        OLED_Update();
        break;
    case 2:
        OLED_Clear();
        OLED_ShowString(67, 0, "功能1", OLED_8X16);
        OLED_ShowString(43, 21, "功能2", OLED_8X16);
        OLED_ShowString(19, 42, "功能3", OLED_8X16);
        OLED_ReverseArea(43, 21, 40, 20);
        OLED_Update();
        break;
    case 3:
        OLED_Clear();
        OLED_ShowString(67, 0, "功能2", OLED_8X16);
        OLED_ShowString(43, 21, "功能3", OLED_8X16);
        OLED_ShowString(19, 42, "功能4", OLED_8X16);
        OLED_ReverseArea(43, 21, 40, 20);
        OLED_Update();
        break;
    case 4:
        OLED_Clear();
        OLED_ShowString(67, 0, "功能3", OLED_8X16);
        OLED_ShowString(43, 21, "功能4", OLED_8X16);
        OLED_ShowString(19, 42, "返回", OLED_8X16);
        OLED_ReverseArea(43, 21, 40, 20);
        OLED_Update();
        break;
    case 5:
        OLED_Clear();
        OLED_ShowString(67, 0, "功能4", OLED_8X16);
        OLED_ShowString(45, 22, "返回", OLED_8X16);
        OLED_ShowString(19, 42, "功能1", OLED_8X16);
        OLED_ReverseArea(43, 21, 38, 20);
        OLED_Update();
        break;
    }
}

/*第二个二级菜单显示*/
void read_B_2(uint16_t flag_B)
{
    switch (flag_B)
    {
    case 1:
        OLED_Clear();
        OLED_ShowString(0, 0, "photo1", OLED_8X16);
        OLED_ShowString(0, 20, "photo2", OLED_8X16);
        OLED_ShowString(0, 40, "gif1", OLED_8X16);
        OLED_ReverseArea(0, 0, 48, 20);
        OLED_Update();
        break;
    case 2:
        OLED_Clear();
        OLED_ShowString(0, 0, "photo1", OLED_8X16);
        OLED_ShowString(0, 20, "photo2", OLED_8X16);
        OLED_ShowString(0, 40, "gif1", OLED_8X16);
        OLED_ReverseArea(0, 20, 48, 20);
        OLED_Update();
        break;
    case 3:
        OLED_Clear();
        OLED_ShowString(0, 0, "photo2", OLED_8X16);
        OLED_ShowString(0, 20, "gif1", OLED_8X16);
        OLED_ShowString(0, 40, "返回", OLED_8X16);
        OLED_ReverseArea(0, 20, 32, 20);
        OLED_Update();
        break;
    case 4:
        OLED_Clear();
        OLED_ShowString(0, 0, "photo2", OLED_8X16);
        OLED_ShowString(0, 20, "gif1", OLED_8X16);
        OLED_ShowString(0, 40, "返回", OLED_8X16);
        OLED_ReverseArea(0, 40, 32, 20);
        OLED_Update();
        break;
    }
}

/*第三个二级菜单显示*/
void read_B_3(uint16_t flag_B)
{
    switch (flag_B)
    {
    case 1:
        OLED_Clear();
        OLED_ShowString(0, 0, "计算器", OLED_8X16);
        OLED_ShowString(0, 20, "传感器", OLED_8X16);
        OLED_ShowString(0, 40, "功能3", OLED_8X16);
        OLED_ReverseArea(0, 0, 50, 18);
        OLED_Update();
        break;
    case 2:
        OLED_Clear();
        OLED_ShowString(0, 0, "计算器", OLED_8X16);
        OLED_ShowString(0, 20, "传感器", OLED_8X16);
        OLED_ShowString(0, 40, "功能3", OLED_8X16);
        OLED_ReverseArea(0, 20, 50, 18);
        OLED_Update();
        break;
    case 3:
        OLED_Clear();
        OLED_ShowString(0, 0, "传感器", OLED_8X16);
        OLED_ShowString(0, 20, "功能3", OLED_8X16);
        OLED_ShowString(0, 40, "返回", OLED_8X16);
        OLED_ReverseArea(0, 20, 40, 20);
        OLED_Update();
        break;
    case 4:
        OLED_Clear();
        OLED_ShowString(0, 0, "传感器", OLED_8X16);
        OLED_ShowString(0, 20, "功能3", OLED_8X16);
        OLED_ShowString(0, 40, "返回", OLED_8X16);
        OLED_ReverseArea(0, 40, 40, 20);
        OLED_Update();
        break;
    }
}

void read_B_1_4(uint16_t flag_C, int led_num, int *led_state)
{
    OLED_Clear();
    OLED_ReverseArea(41, 0, 2, 63);
    OLED_ReverseArea(83, 0, 2, 63);
    OLED_ReverseArea(0, 32, 84, 2);
    OLED_ShowString(5, 7, "引脚", OLED_8X16);
    OLED_ShowString(47, 7, "状态", OLED_8X16);
    if (led_state[led_num] == 0)
        OLED_ShowString(55, 37, "关", OLED_8X16);
    else
        OLED_ShowString(55, 37, "开", OLED_8X16);
    OLED_ShowString(89, 7, "重置", OLED_8X16);
    OLED_ShowString(89, 37, "返回", OLED_8X16);
    OLED_ShowNum(16, 37, led_num, 1, OLED_8X16);
    switch (flag_C)
    {
    case 1:
        OLED_ReverseArea(16, 37, 8, 16);
        break;
    case 2:
        OLED_ReverseArea(55, 37, 16, 16);
        break;
    case 3:
        OLED_ReverseArea(89, 7, 32, 16);
        break;
    case 4:
        OLED_ReverseArea(89, 37, 32, 16);
        break;
    }

    OLED_Update();
}

void led_num_read(int led_num)
{
    OLED_ClearArea(16, 37, 8, 16);
    OLED_ShowNum(16, 37, led_num, 1, OLED_8X16);
    OLED_ReverseArea(16, 37, 8, 16);
    OLED_Update();
}

void led_state_read(int led_num, int *led_state)
{
    OLED_ClearArea(55, 37, 16, 16);
    if (led_state[led_num] == 0)
        OLED_ShowString(55, 37, "关", OLED_8X16);
    else
        OLED_ShowString(55, 37, "开", OLED_8X16);
    OLED_ReverseArea(55, 37, 16, 16);
    OLED_Update();
}

void read_count(double shangyige, int fuhao, double num_1, double result)
{
    OLED_Clear();
    OLED_ShowFloatNum(20, 0, shangyige, countDigits(shangyige), 3, OLED_8X16);
    OLED_ShowFloatNum(20, 20, num_1, countDigits(num_1), 3, OLED_8X16);
    OLED_ShowString(10, 40, "=", OLED_8X16);
    OLED_ShowFloatNum(20, 40, result, countDigits(result), 5, OLED_8X16);
    switch (fuhao)
    {
    case 14:
        OLED_ShowString(10, 20, "+", OLED_8X16);
        break;
    case 24:
        OLED_ShowString(10, 20, "-", OLED_8X16);
        break;
    case 34:
        OLED_ShowString(10, 20, "*", OLED_8X16);
        break;
    case 44:
        OLED_ShowString(10, 20, "/", OLED_8X16);
        break;
    }
    OLED_Update();
}

void read_B_3_2(int flag_c, int guang, int re)
{
    OLED_Clear();
    OLED_ShowString(0, 0, "光", OLED_8X16);
    OLED_ShowString(0, 20, "热", OLED_8X16);
    OLED_ShowString(0, 40, "返回", OLED_8X16);
    switch (guang)
    {
    case 0:
        OLED_ShowString(30, 0, "关", OLED_8X16);
        break;
    case 1:
        OLED_ShowString(30, 0, "开", OLED_8X16);
        break;
    }

    switch (re)
    {
    case 0:
        OLED_ShowString(30, 20, "关", OLED_8X16);
        break;
    case 1:
        OLED_ShowString(30, 20, "开", OLED_8X16);
        break;
    }

    switch (flag_c)
    {
    case 1:
        OLED_ReverseArea(30, 0, 20, 20);
        break;
    case 2:
        OLED_ReverseArea(30, 20, 20, 20);
        break;
    case 3:
        OLED_ReverseArea(0, 40, 40, 20);
        break;
    }

    OLED_Update();
}
