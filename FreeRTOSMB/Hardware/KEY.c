#include "stm32f10x.h"                  // Device header
#include "delay.h"

void KEY_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitTypeDef GPIOA_InitStruct;
	GPIOA_InitStruct.GPIO_Mode =GPIO_Mode_IPU;
	GPIOA_InitStruct.GPIO_Pin =GPIO_Pin_12;
	GPIO_Init(GPIOB, &GPIOA_InitStruct);
}

uint8_t Key_scan(void)
{
	if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12)==0)
	{
		delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12)==0);
		delay_ms(20);
		return 1;
	}
	return 0;
	
}
