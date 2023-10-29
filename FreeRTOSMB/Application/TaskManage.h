#ifndef __TASKMANAGE_H
#define __TASKMANAGE_H

#include "stm32f10x.h"                  // Device header
#include "FreeRTOS.h"
#include "queue.h"
#include "task.h"
#include "delay.h"
#include "LED.h"
#include "KEY.h"

void TaskCreateFunction(void);

#endif
