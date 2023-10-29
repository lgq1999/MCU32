#include "TaskManage.h"

// 开始任务函数 配置
#define START_TASK_PRIO 1			 // 任务优先级
#define START_STACK_SIZE 128		 // 任务堆栈大小
TaskHandle_t StartTask_Handler;		 // 任务句柄
void start_task(void *pvParameters); // 任务函数

// 任务1 配置
#define TASK1_PRIO 2			// 任务优先级
#define TASK1_STACK_SIZE 50		// 任务堆栈大小
TaskHandle_t Task1_Handler;		// 任务句柄
void task1(void *pvParameters); // 任务函数

// 任务2 配置
#define TASK2_PRIO 3			// 任务优先级
#define TASK2_STACK_SIZE 50		// 任务堆栈大小
TaskHandle_t Task2_Handler;		// 任务句柄
void task2(void *pvParameters); // 任务函数

// 任务3 配置
#define TASK3_PRIO 4			// 任务优先级
#define TASK3_STACK_SIZE 50		// 任务堆栈大小
TaskHandle_t Task3_Handler;		// 任务句柄
void task3(void *pvParameters); // 任务函数

/*******************************************************************************
 * Function Name  : TaskCreateFunction
 * Description    : 创建任务函数
 * Input          : None
 * Output         : None
 * Return         : None
 *******************************************************************************/
void TaskCreateFunction(void)
{
	xTaskCreate((TaskFunction_t)start_task,			 // 任务函数
				(const char *)"start_task",			 // 任务名称
				(uint16_t)START_STACK_SIZE,			 // 任务堆栈大小
				(void *)NULL,						 // 传递给任务函数的参数
				(UBaseType_t)START_TASK_PRIO,		 // 任务优先级
				(TaskHandle_t *)&StartTask_Handler); // 任务句柄

}

/*******************************************************************************
 * Function Name  : start_task
 * Description    : 开始任务函数
 * Input          : None
 * Output         : None
 * Return         : None
 *******************************************************************************/

void start_task(void *pvParameters)
{
	taskENTER_CRITICAL(); // 进入临界区

	// 创建任务一

	xTaskCreate((TaskFunction_t)task1,			 // 任务函数
				(const char *)"task1",			 // 任务名称
				(uint16_t)TASK1_STACK_SIZE,		 // 任务堆栈大小
				(void *)NULL,					 // 传递给任务函数的参数
				(UBaseType_t)TASK1_PRIO,		 // 任务优先级
				(TaskHandle_t *)&Task1_Handler); // 任务句柄

	// 创建任务二
	xTaskCreate((TaskFunction_t)task2,			 // 任务函数
				(const char *)"task2",			 // 任务名称
				(uint16_t)TASK2_STACK_SIZE,		 // 任务堆栈大小
				(void *)NULL,					 // 传递给任务函数的参数
				(UBaseType_t)TASK2_PRIO,		 // 任务优先级
				(TaskHandle_t *)&Task2_Handler); // 任务句柄

	// 创建任务三
	xTaskCreate((TaskFunction_t)task3,			 // 任务函数
				(const char *)"task3",			 // 任务名称
				(uint16_t)TASK3_STACK_SIZE,		 // 任务堆栈大小
				(void *)NULL,					 // 传递给任务函数的参数
				(UBaseType_t)TASK3_PRIO,		 // 任务优先级
				(TaskHandle_t *)&Task3_Handler); // 任务句柄

	vTaskDelete(StartTask_Handler); // 删除开始任务
	taskEXIT_CRITICAL();			// 退出临界区
}

/*任务一：实现LED0每500ms翻转一次*/
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

/*任务二：实现LED1每1000ms翻转一次*/
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

/*任务三：判断按键KEY，按下KEY删除task1*/
void task3(void *pvParameters)
{
	while (1)
	{
		if (1 == Key_scan() && NULL != Task1_Handler)
		{
			vTaskDelete(Task1_Handler); // 删除任务一
			Task1_Handler = NULL;
		}
		vTaskDelay(10);
	}
}
