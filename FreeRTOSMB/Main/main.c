#include "TaskManage.h"

void Hardware_Init()
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);  //����ϵͳ�ж����ȼ�����4
	LED_Init();
	KEY_Init();
}

int main(void)
{
	Hardware_Init();
	TaskCreateFunction();  	//��������
	vTaskStartScheduler();  // �����������
	return 0;
}

