//**************************** Button Led Blinky *******************************
//  Copyright (c) 2026 Trenser Technology Solutions
//  All Rights Reserved
//******************************************************************************
//
// File     : CustomTasks.h
// Summary  : Define and Create tasks
// Note     : None
// Author   : Sreelakshmy M.A.
// Date     : 06/02/2026
//
//******************************************************************************
#ifndef _CUSTOM_TASKS_H_
#define _CUSTOM_TASKS_H_

//******************************* Include Files ********************************
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "main.h"
#include "cmsis_os.h"

//***************************** Global Constants *******************************
#define STACK_SIZE		(1024)
#define NAME_SIZE		(50)
#define INSTANCE_NUMBER	(1)

//******************************* Global Types *********************************
typedef struct _THREAD_HANDLER_
{
    osThreadId lThreadId;
    void (*func)(void const * argument);
    const char* pucThreadName;
    osPriority priority;
    void *pStaticTCB;
    uint32_t *pStackBuffer;
    uint32_t stackSize;
} THREAD_HANDLER;

//***************************** Global Variables *******************************
extern StaticTask_t ReadPushButtonTaskTCB;
extern uint32_t ReadPushButtonTaskStack[STACK_SIZE];

extern StaticTask_t ProcessTaskTCB;
extern uint32_t ProcessTaskStack[STACK_SIZE];

//**************************** Forward Declarations ****************************
bool CustomCreateTasks();

#endif //_CUSTOM_TASKS_H_
//EOF
