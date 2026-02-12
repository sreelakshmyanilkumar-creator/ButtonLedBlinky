//************************* Button Led Blinky **********************************
//  Copyright (c) 2026 Trenser Technology Solutions
//  All Rights Reserved
//******************************************************************************
//
// File     : MessageQueue.c
// Summary  : Message queue wrapper
// Note     : None
// Author   : Sreelakshmy M.A.
// Date     : 09/02/2026
//
//******************************************************************************

//******************************* Include Files ********************************
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <stdbool.h>
#include "CustomStart.h"
#include "MessageQueue.h"
#include "CustomTasks.h"

//******************************* Local Types **********************************

//******************************* Local Constants ******************************
#define ITEM_SIZE				(1)
#define QUEUE_TIMEOUT			(0)

//******************************* Local Variables ******************************
osStaticMessageQDef_t ReadPushButtonQueueTCB;
uint32_t ReadPushButtonQueueStack[QUEUE_SIZE];
osMessageQId MessageQueueID = 0;

//******************************* Local Functions ******************************

//******************************.MessageQueueCreate.****************************
//Purpose : To create message queue
//Inputs  : PushButtonThreadId - Thread ID
//Outputs : None
//Return  : Boolean value - Upon success it will return true , else false
//Notes   : None
//*
bool MessageQueueCreate(osThreadId PushButtonThreadId)
{
	bool blRet = RET_FAILURE;
	osMessageQDef_t MessageQueueConf = {0};

	MessageQueueConf.buffer = (uint8_t*)ReadPushButtonQueueStack;
	MessageQueueConf.controlblock = &ReadPushButtonQueueTCB;
	MessageQueueConf.item_sz = ITEM_SIZE;
	MessageQueueConf.queue_sz = QUEUE_SIZE;
	MessageQueueID = osMessageCreate(&MessageQueueConf, PushButtonThreadId);

	if(MessageQueueID != NULL)
	{
		blRet = RET_SUCCESS;
	}

	return blRet;
}

//*****************************.MessageQueuePut.********************************
//Purpose : To write to queue
//Inputs  : GpioPinState - Gpio state for decision make
//Outputs : None
//Return  : Boolean value - Upon success it will return true , else false
//Notes   : None
//*
bool MessageQueuePut(GPIO_PinState *GpioPinState)
{
	bool blRet = RET_FAILURE;

	osMessagePut(MessageQueueID, *GpioPinState, osWaitForever);

	return blRet;
}

//*****************************.MessageQueueGet.********************************
//Purpose : To read from queue
//Inputs  : None
//Outputs : stEvent - queue read value
//Return  : Boolean value - Upon success it will return true , else false
//Notes   : None
//*
bool MessageQueueGet(osEvent *stEvent)
{
	bool blRet = RET_FAILURE;

	*stEvent = osMessageGet(MessageQueueID, QUEUE_TIMEOUT);

	while(stEvent != NULL && stEvent->status == osEventMessage )
	{
		blRet = RET_SUCCESS;
		break;
	}

	return blRet;
}
//EOF
