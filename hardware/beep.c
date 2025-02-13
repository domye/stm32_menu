#include "stm32f10x.h"
#include "delay.h"

/*赋能蜂鸣器*/
void beep_init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); // 使能GPIOA时钟
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
}

/*控制蜂鸣器*/
void beep(uint32_t frequency, uint32_t duration)
{
    GPIO_SetBits(GPIOB, GPIO_Pin_0); // 设置PB2高电平
    delay(frequency);
    GPIO_ResetBits(GPIOB, GPIO_Pin_0); // 设置PB2低电平
    delay(duration);
}