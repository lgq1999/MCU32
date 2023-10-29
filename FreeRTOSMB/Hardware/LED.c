#include "stm32f10x.h"                  // Device header

void LED_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitTypeDef GPIOA_InitStruct;
	GPIOA_InitStruct.GPIO_Mode =GPIO_Mode_Out_PP;
	GPIOA_InitStruct.GPIO_Pin =GPIO_Pin_0|GPIO_Pin_1;
	GPIOA_InitStruct.GPIO_Speed =GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIOA_InitStruct);
	
	GPIO_SetBits(GPIOA,GPIO_Pin_0|GPIO_Pin_1);	
}

void LED0_OFF(void)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_0);	
}

void LED0_ON(void)
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_0);	
}

void LED1_OFF(void)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_1);	
}

void LED1_ON(void)
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_1);	
}