//************************* Button Led Blinky **********************************
//  Copyright (c) 2026 Trenser Technology Solutions
//  All Rights Reserved
//******************************************************************************
//
// File     : CustomTasks.c
// Summary  : Define and Create tasks
// Note     : None
// Author   : Sreelakshmy M.A.
// Date     : 06/02/2026
//
//******************************************************************************

//******************************* Include Files ********************************
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include "CustomStart.h"
#include "CustomTasks.h"
#include "PushButton.h"
#include "Process.h"
#include "Led.h"

//******************************* Local Types **********************************

//******************************* Local Constants ******************************

//******************************* Local Variables ******************************
StaticTask_t stReadPushButtonTaskTCB = {0};
uint32_t ulReadPushButtonTaskStack[STACK_SIZE] = {0};

StaticTask_t stProcessTaskTCB = {0};
uint32_t ulProcessTaskStack[STACK_SIZE] = {0};

StaticTask_t stLedBlinkyTaskTCB = {0};
uint32_t ulLedBlinkyTaskStack[STACK_SIZE] = {0};

THREAD_HANDLER ThreadHandler[] = {
    {
        .lThreadId = NULL,
        .func = ReadPushButtonTask,
        .pucThreadName = "ReadPushButtonTask",
        .priority = osPriorityNormal,
        .pStaticTCB = &stReadPushButtonTaskTCB,
        .pStackBuffer = ulReadPushButtonTaskStack,
        .stackSize = STACK_SIZE
    },
    {
        .lThreadId = NULL,
        .func = ProcessTask,
        .pucThreadName = "ProcessTask",
        .priority = osPriorityNormal,
        .pStaticTCB = &stProcessTaskTCB,
        .pStackBuffer = ulProcessTaskStack,
        .stackSize = STACK_SIZE
    },
    {
        .lThreadId = NULL,
        .func = LedBlinkyTask,
        .pucThreadName = "LedBlinkyTask",
        .priority = osPriorityLow,
        .pStaticTCB = &stLedBlinkyTaskTCB,
        .pStackBuffer = ulLedBlinkyTaskStack,
        .stackSize = STACK_SIZE
    }
};
//******************************* Local Functions ******************************

//******************************.CustomCreateTasks.*****************************
//Purpose : Initializing the GPIOs used, Creating the all the tasks required
//Inputs  : None
//Outputs : None
//Return  : Boolean value - Upon success it will return true , else false
//Notes   : None
//*
bool CustomCreateTasks()
{
	bool blRet = RET_SUCCESS;
    uint8_t ucMaxThreadCount = 0;
    osThreadDef_t ThreadConf = {0};
    ucMaxThreadCount = sizeof(ThreadHandler)/sizeof(ThreadHandler[0]);

    printf("Creating Tasks\n");

    for (uint8_t ucIndex = 0; ucIndex < ucMaxThreadCount; ucIndex++)
    {
    	memset(&ThreadConf,'0' ,sizeof(osThreadDef_t));

    	ThreadConf.name = (char*)ThreadHandler[ucIndex].pucThreadName;
    	ThreadConf.pthread = (os_pthread)ThreadHandler[ucIndex].func;
    	ThreadConf.stacksize = ThreadHandler[ucIndex].stackSize;
    	ThreadConf.instances = INSTANCE_NUMBER;
    	ThreadConf.buffer = ThreadHandler[ucIndex].pStackBuffer;
    	ThreadConf.controlblock = ThreadHandler[ucIndex].pStaticTCB;
    	ThreadHandler[ucIndex].lThreadId = osThreadCreate(&ThreadConf, NULL);

    	if(ThreadHandler[ucIndex].lThreadId == NULL)
    	{
    		printf("Error: Failed to create task: %s\n", ThreadConf.name);
    		blRet = RET_FAILURE;
    	}
    	else
    	{
    		printf("Task Created - %s\n", ThreadConf.name);
    	}
    }

	return blRet;
}
//EOF
