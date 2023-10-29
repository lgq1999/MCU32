#include "TaskManage.h"

void Hardware_Init()
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);  //设置系统中断优先级分组4
	LED_Init();
	KEY_Init();
}

int main(void)
{
	Hardware_Init();
	TaskCreateFunction();  	//创建任务
	vTaskStartScheduler();  // 开启任务调度
	return 0;
}

