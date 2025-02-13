#include "stm32f10x.h"
#include "delay.h"
#include "key.h"

/*赋能按键A*/
void key_A_init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15 | GPIO_Pin_13 | GPIO_Pin_12;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
}

/*读取按键值*/
uint8_t key_read(void)
{
    uint8_t key_value = 0;

    // 检查PA15的状态
    if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_15) == 0)
    {
        delay(15); // 延时去抖动
        while (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_15) == 0)
            ;      // 等待按键松开
        delay(15); // 延时去抖
        key_value = 1;
    }

    if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_13) == 0)
    {
        delay(15); // 延时去抖动
        while (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_13) == 0)
            ;      // 等待按键松开
        delay(15); // 延时去抖
        key_value = 2;
    }

    if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_12) == 0)
    {
        delay(15); // 延时去抖动
        while (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_12) == 0)
            ;      // 等待按键松开
        delay(15); // 延时去抖
        key_value = 3;
    }

    return key_value;
}

void key_B_init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure; // 定义结构体变量

    // 使能行和列的GPIO时钟
    RCC_APB2PeriphClockCmd(KEY_MATRIX_H1_PORT_RCC | KEY_MATRIX_H2_PORT_RCC | KEY_MATRIX_H3_PORT_RCC | KEY_MATRIX_H4_PORT_RCC | KEY_MATRIX_L1_PORT_RCC | KEY_MATRIX_L2_PORT_RCC | KEY_MATRIX_L3_PORT_RCC | KEY_MATRIX_L4_PORT_RCC,
                           ENABLE);

    // 行管脚输出配置
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  // 设置推挽输出模式
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // 设置传输速率

    GPIO_InitStructure.GPIO_Pin = KEY_MATRIX_H1_PIN | KEY_MATRIX_H2_PIN | KEY_MATRIX_H3_PIN | KEY_MATRIX_H4_PIN;
    GPIO_Init(KEY_MATRIX_H1_PORT, &GPIO_InitStructure);

    // 列管脚输入配置
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; // 设置上拉输入模式

    GPIO_InitStructure.GPIO_Pin = KEY_MATRIX_L1_PIN | KEY_MATRIX_L2_PIN | KEY_MATRIX_L3_PIN | KEY_MATRIX_L4_PIN;
    GPIO_Init(KEY_MATRIX_L1_PORT, &GPIO_InitStructure);
}

uint8_t key_B_read(void)
{
    u8 col1, col2, col3, col4;
    u8 key_value = 0;

    GPIO_SetBits(KEY_MATRIX_H1_PORT, KEY_MATRIX_H1_PIN); // 先让L1输出高
    GPIO_SetBits(KEY_MATRIX_H2_PORT, KEY_MATRIX_H2_PIN); // 先让L2输出高
    GPIO_SetBits(KEY_MATRIX_H3_PORT, KEY_MATRIX_H3_PIN); // 先让L3输出高
    GPIO_SetBits(KEY_MATRIX_H4_PORT, KEY_MATRIX_H4_PIN); // 先让L4输出高

    if ((GPIO_ReadInputDataBit(KEY_MATRIX_L1_PORT, KEY_MATRIX_L1_PIN) |
         GPIO_ReadInputDataBit(KEY_MATRIX_L2_PORT, KEY_MATRIX_L2_PIN) |
         GPIO_ReadInputDataBit(KEY_MATRIX_L3_PORT, KEY_MATRIX_L3_PIN) |
         GPIO_ReadInputDataBit(KEY_MATRIX_L4_PORT, KEY_MATRIX_L4_PIN)) == 0)
        return 0; // 如果X1到X4全为零则没有按键按下
    else
    {
        delay(15); // 延时5ms去抖动
        if ((GPIO_ReadInputDataBit(KEY_MATRIX_L1_PORT, KEY_MATRIX_L1_PIN) |
             GPIO_ReadInputDataBit(KEY_MATRIX_L2_PORT, KEY_MATRIX_L2_PIN) |
             GPIO_ReadInputDataBit(KEY_MATRIX_L3_PORT, KEY_MATRIX_L3_PIN) |
             GPIO_ReadInputDataBit(KEY_MATRIX_L4_PORT, KEY_MATRIX_L4_PIN)) == 0)
            return 0;
    }

    // 第1行检测
    GPIO_SetBits(KEY_MATRIX_H1_PORT, KEY_MATRIX_H1_PIN);
    GPIO_ResetBits(KEY_MATRIX_H2_PORT, KEY_MATRIX_H2_PIN);
    GPIO_ResetBits(KEY_MATRIX_H3_PORT, KEY_MATRIX_H3_PIN);
    GPIO_ResetBits(KEY_MATRIX_H4_PORT, KEY_MATRIX_H4_PIN);

    col1 = GPIO_ReadInputDataBit(KEY_MATRIX_L1_PORT, KEY_MATRIX_L1_PIN);
    col2 = GPIO_ReadInputDataBit(KEY_MATRIX_L2_PORT, KEY_MATRIX_L2_PIN);
    col3 = GPIO_ReadInputDataBit(KEY_MATRIX_L3_PORT, KEY_MATRIX_L3_PIN);
    col4 = GPIO_ReadInputDataBit(KEY_MATRIX_L4_PORT, KEY_MATRIX_L4_PIN);

    if (col1 == 1 && col2 == 0 && col3 == 0 && col4 == 0)
        key_value = 11;
    if (col1 == 0 && col2 == 1 && col3 == 0 && col4 == 0)
        key_value = 12;
    if (col1 == 0 && col2 == 0 && col3 == 1 && col4 == 0)
        key_value = 13;
    if (col1 == 0 && col2 == 0 && col3 == 0 && col4 == 1)
        key_value = 14;
    // 等待按键松开
    while (((GPIO_ReadInputDataBit(KEY_MATRIX_L1_PORT, KEY_MATRIX_L1_PIN)) |
            (GPIO_ReadInputDataBit(KEY_MATRIX_L2_PORT, KEY_MATRIX_L2_PIN)) |
            (GPIO_ReadInputDataBit(KEY_MATRIX_L3_PORT, KEY_MATRIX_L3_PIN)) |
            (GPIO_ReadInputDataBit(KEY_MATRIX_L4_PORT, KEY_MATRIX_L4_PIN))) > 0)
        ;

    // 第2行检测
    GPIO_ResetBits(KEY_MATRIX_H1_PORT, KEY_MATRIX_H1_PIN);
    GPIO_SetBits(KEY_MATRIX_H2_PORT, KEY_MATRIX_H2_PIN);
    GPIO_ResetBits(KEY_MATRIX_H3_PORT, KEY_MATRIX_H3_PIN);
    GPIO_ResetBits(KEY_MATRIX_H4_PORT, KEY_MATRIX_H4_PIN);

    col1 = GPIO_ReadInputDataBit(KEY_MATRIX_L1_PORT, KEY_MATRIX_L1_PIN);
    col2 = GPIO_ReadInputDataBit(KEY_MATRIX_L2_PORT, KEY_MATRIX_L2_PIN);
    col3 = GPIO_ReadInputDataBit(KEY_MATRIX_L3_PORT, KEY_MATRIX_L3_PIN);
    col4 = GPIO_ReadInputDataBit(KEY_MATRIX_L4_PORT, KEY_MATRIX_L4_PIN);

    if (col1 == 1 && col2 == 0 && col3 == 0 && col4 == 0)
        key_value = 21;
    if (col1 == 0 && col2 == 1 && col3 == 0 && col4 == 0)
        key_value = 22;
    if (col1 == 0 && col2 == 0 && col3 == 1 && col4 == 0)
        key_value = 23;
    if (col1 == 0 && col2 == 0 && col3 == 0 && col4 == 1)
        key_value = 24;
    // 等待按键松开
    while (((GPIO_ReadInputDataBit(KEY_MATRIX_L1_PORT, KEY_MATRIX_L1_PIN)) |
            (GPIO_ReadInputDataBit(KEY_MATRIX_L2_PORT, KEY_MATRIX_L2_PIN)) |
            (GPIO_ReadInputDataBit(KEY_MATRIX_L3_PORT, KEY_MATRIX_L3_PIN)) |
            (GPIO_ReadInputDataBit(KEY_MATRIX_L4_PORT, KEY_MATRIX_L4_PIN))) > 0)
        ;

    // 第3行检测
    GPIO_ResetBits(KEY_MATRIX_H1_PORT, KEY_MATRIX_H1_PIN);
    GPIO_ResetBits(KEY_MATRIX_H2_PORT, KEY_MATRIX_H2_PIN);
    GPIO_SetBits(KEY_MATRIX_H3_PORT, KEY_MATRIX_H3_PIN);
    GPIO_ResetBits(KEY_MATRIX_H4_PORT, KEY_MATRIX_H4_PIN);

    col1 = GPIO_ReadInputDataBit(KEY_MATRIX_L1_PORT, KEY_MATRIX_L1_PIN);
    col2 = GPIO_ReadInputDataBit(KEY_MATRIX_L2_PORT, KEY_MATRIX_L2_PIN);
    col3 = GPIO_ReadInputDataBit(KEY_MATRIX_L3_PORT, KEY_MATRIX_L3_PIN);
    col4 = GPIO_ReadInputDataBit(KEY_MATRIX_L4_PORT, KEY_MATRIX_L4_PIN);

    if (col1 == 1 && col2 == 0 && col3 == 0 && col4 == 0)
        key_value = 31;
    if (col1 == 0 && col2 == 1 && col3 == 0 && col4 == 0)
        key_value = 32;
    if (col1 == 0 && col2 == 0 && col3 == 1 && col4 == 0)
        key_value = 33;
    if (col1 == 0 && col2 == 0 && col3 == 0 && col4 == 1)
        key_value = 34;
    // 等待按键松开
    while (((GPIO_ReadInputDataBit(KEY_MATRIX_L1_PORT, KEY_MATRIX_L1_PIN)) |
            (GPIO_ReadInputDataBit(KEY_MATRIX_L2_PORT, KEY_MATRIX_L2_PIN)) |
            (GPIO_ReadInputDataBit(KEY_MATRIX_L3_PORT, KEY_MATRIX_L3_PIN)) |
            (GPIO_ReadInputDataBit(KEY_MATRIX_L4_PORT, KEY_MATRIX_L4_PIN))) > 0)
        ;

    // 第4行检测
    GPIO_ResetBits(KEY_MATRIX_H1_PORT, KEY_MATRIX_H1_PIN);
    GPIO_ResetBits(KEY_MATRIX_H2_PORT, KEY_MATRIX_H2_PIN);
    GPIO_ResetBits(KEY_MATRIX_H3_PORT, KEY_MATRIX_H3_PIN);
    GPIO_SetBits(KEY_MATRIX_H4_PORT, KEY_MATRIX_H4_PIN);

    col1 = GPIO_ReadInputDataBit(KEY_MATRIX_L1_PORT, KEY_MATRIX_L1_PIN);
    col2 = GPIO_ReadInputDataBit(KEY_MATRIX_L2_PORT, KEY_MATRIX_L2_PIN);
    col3 = GPIO_ReadInputDataBit(KEY_MATRIX_L3_PORT, KEY_MATRIX_L3_PIN);
    col4 = GPIO_ReadInputDataBit(KEY_MATRIX_L4_PORT, KEY_MATRIX_L4_PIN);

    if (col1 == 1 && col2 == 0 && col3 == 0 && col4 == 0)
        key_value = 41;
    if (col1 == 0 && col2 == 1 && col3 == 0 && col4 == 0)
        key_value = 42;
    if (col1 == 0 && col2 == 0 && col3 == 1 && col4 == 0)
        key_value = 43;
    if (col1 == 0 && col2 == 0 && col3 == 0 && col4 == 1)
        key_value = 44;
    // 等待按键松开
    while (((GPIO_ReadInputDataBit(KEY_MATRIX_L1_PORT, KEY_MATRIX_L1_PIN)) |
            (GPIO_ReadInputDataBit(KEY_MATRIX_L2_PORT, KEY_MATRIX_L2_PIN)) |
            (GPIO_ReadInputDataBit(KEY_MATRIX_L3_PORT, KEY_MATRIX_L3_PIN)) |
            (GPIO_ReadInputDataBit(KEY_MATRIX_L4_PORT, KEY_MATRIX_L4_PIN))) > 0)
        ;

    return key_value;
}
