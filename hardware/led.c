#include "stm32f10x.h" // 根据你的硬件平台调整头文件
#include "delay.h"

/*赋能灯*/
void led_init()
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); // 使能GPIOA时钟
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
}

void led_all_off(void)
{
    GPIO_SetBits(GPIOA, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7);
}

void led_all_on(void)
{
    GPIO_ResetBits(GPIOA, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7);
}
/*控制LED是否点亮*/
void led(uint8_t pinNumber, FunctionalState newState)
{
    if (pinNumber >= 8)
    {
        // 错误处理：pinNumber超出范围
        return;
    }

    if (newState == ENABLE)
    {
        GPIO_ResetBits(GPIOA, 1 << pinNumber); // 点亮LED
    }
    else
    {
        GPIO_SetBits(GPIOA, 1 << pinNumber); // 熄灭LED
    }
}
