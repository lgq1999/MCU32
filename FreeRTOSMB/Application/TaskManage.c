#include "TaskManage.h"

// ��ʼ������ ����
#define START_TASK_PRIO 1			 // �������ȼ�
#define START_STACK_SIZE 128		 // �����ջ��С
TaskHandle_t StartTask_Handler;		 // ������
void start_task(void *pvParameters); // ������

// ����1 ����
#define TASK1_PRIO 2			// �������ȼ�
#define TASK1_STACK_SIZE 50		// �����ջ��С
TaskHandle_t Task1_Handler;		// ������
void task1(void *pvParameters); // ������

// ����2 ����
#define TASK2_PRIO 3			// �������ȼ�
#define TASK2_STACK_SIZE 50		// �����ջ��С
TaskHandle_t Task2_Handler;		// ������
void task2(void *pvParameters); // ������

// ����3 ����
#define TASK3_PRIO 4			// �������ȼ�
#define TASK3_STACK_SIZE 50		// �����ջ��С
TaskHandle_t Task3_Handler;		// ������
void task3(void *pvParameters); // ������

/*******************************************************************************
 * Function Name  : TaskCreateFunction
 * Description    : ����������
 * Input          : None
 * Output         : None
 * Return         : None
 *******************************************************************************/
void TaskCreateFunction(void)
{
	xTaskCreate((TaskFunction_t)start_task,			 // ������
				(const char *)"start_task",			 // ��������
				(uint16_t)START_STACK_SIZE,			 // �����ջ��С
				(void *)NULL,						 // ���ݸ��������Ĳ���
				(UBaseType_t)START_TASK_PRIO,		 // �������ȼ�
				(TaskHandle_t *)&StartTask_Handler); // ������

}

/*******************************************************************************
 * Function Name  : start_task
 * Description    : ��ʼ������
 * Input          : None
 * Output         : None
 * Return         : None
 *******************************************************************************/

void start_task(void *pvParameters)
{
	taskENTER_CRITICAL(); // �����ٽ���

	// ��������һ

	xTaskCreate((TaskFunction_t)task1,			 // ������
				(const char *)"task1",			 // ��������
				(uint16_t)TASK1_STACK_SIZE,		 // �����ջ��С
				(void *)NULL,					 // ���ݸ��������Ĳ���
				(UBaseType_t)TASK1_PRIO,		 // �������ȼ�
				(TaskHandle_t *)&Task1_Handler); // ������

	// ���������
	xTaskCreate((TaskFunction_t)task2,			 // ������
				(const char *)"task2",			 // ��������
				(uint16_t)TASK2_STACK_SIZE,		 // �����ջ��С
				(void *)NULL,					 // ���ݸ��������Ĳ���
				(UBaseType_t)TASK2_PRIO,		 // �������ȼ�
				(TaskHandle_t *)&Task2_Handler); // ������

	// ����������
	xTaskCreate((TaskFunction_t)task3,			 // ������
				(const char *)"task3",			 // ��������
				(uint16_t)TASK3_STACK_SIZE,		 // �����ջ��С
				(void *)NULL,					 // ���ݸ��������Ĳ���
				(UBaseType_t)TASK3_PRIO,		 // �������ȼ�
				(TaskHandle_t *)&Task3_Handler); // ������

	vTaskDelete(StartTask_Handler); // ɾ����ʼ����
	taskEXIT_CRITICAL();			// �˳��ٽ���
}

/*����һ��ʵ��LED0ÿ500ms��תһ��*/
void task1(void *pvParameters)
{
	while (1)
	{
		LED0_ON();
		vTaskDelay(100);
		LED0_OFF();
		vTaskDelay(100);
	}
}

/*�������ʵ��LED1ÿ1000ms��תһ��*/
void task2(void *pvParameters)
{
	while (1)
	{
		LED1_ON();
		vTaskDelay(1000);
		LED1_OFF();
		vTaskDelay(1000);
	}
}

/*���������жϰ���KEY������KEYɾ��task1*/
void task3(void *pvParameters)
{
	while (1)
	{
		if (1 == Key_scan() && NULL != Task1_Handler)
		{
			vTaskDelete(Task1_Handler); // ɾ������һ
			Task1_Handler = NULL;
		}
		vTaskDelay(10);
	}
}
