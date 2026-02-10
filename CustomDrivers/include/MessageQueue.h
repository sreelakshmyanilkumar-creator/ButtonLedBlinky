//**************************** Button Led Blinky *******************************
//  Copyright (c) 2026 Trenser Technology Solutions
//  All Rights Reserved
//******************************************************************************
//
// File     : MessageQueue.h
// Summary  : Message queue wrapper
// Note     : None
// Author   : Sreelakshmy M.A.
// Date     : 09/02/2026
//
//******************************************************************************
#ifndef _MESSAGE_QUEUE_H_
#define _MESSAGE_QUEUE_H_

//******************************* Include Files ********************************
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "CustomTasks.h"

//******************************* Global Types *********************************

//***************************** Global Constants *******************************
#define QUEUE_SIZE (10)
//***************************** Global Variables *******************************
extern osStaticMessageQDef_t ReadPushButtonQueueTCB;
extern uint32_t ReadPushButtonQueueStack[QUEUE_SIZE];

//**************************** Forward Declarations ****************************
bool MessageQueueCreate(osThreadId PushButtonThreadId);
bool MessageQueuePut(GPIO_PinState *GpioPinState);
bool MessageQueueGet(osEvent *stEvent);

#endif //_MESSAGE_QUEUE_H_
//EOF
