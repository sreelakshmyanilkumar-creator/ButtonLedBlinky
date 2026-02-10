//************************* Button Led Blinky **********************************
//  Copyright (c) 2026 Trenser Technology Solutions
//  All Rights Reserved
//******************************************************************************
//
// File     : PushButton.c
// Summary  : Read push button and status send to process thread
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
#include "CustomTasks.h"
#include "CustomStart.h"
#include "PushButton.h"
#include "MessageQueue.h"

//******************************* Local Types **********************************

//******************************* Local Constants ******************************

//******************************* Local Variables ******************************

//******************************* Local Functions ******************************

//****************************.ReadPushButtonTask.******************************
//Purpose : Read push button status and send to process thread
//Inputs  : None
//Outputs : None
//Return  : None
//Notes   : None
//*
void ReadPushButtonTask(void const *pArgument)
{
  GPIO_PinState lCurrentState = GPIO_PIN_SET;

  osThreadId PushButtonThreadId = osThreadGetId();

  if(PushButtonMessageQueueCreate(PushButtonThreadId) != RET_SUCCESS)
  {
	  printf("PushButtonMessageQueueCreate failed\n");
  }
  else
  {
	  printf("Queue Created Successfully\n");
  }

  printf("Starting ReadPushButtonTask");

  for(;;)
  {
	  lCurrentState = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13);
	   printf("lCurrentState %d\n", lCurrentState);
	   PushButtonMessageQueuePut(&lCurrentState);
	  osDelay(5);
  }
}

//*************************.PushButtonMessageQueueCreate.***********************
//Purpose : Message queue create wrapper
//Inputs  : PushButtonThreadId = Thread ID
//Outputs : None
//Return  : Boolean value - Upon success it will return true , else false
//Notes   : None
//*
bool PushButtonMessageQueueCreate(osThreadId PushButtonThreadId)
{
	bool blRet = RET_FAILURE;

	blRet = MessageQueueCreate(PushButtonThreadId);

	return blRet;
}

//*************************.PushButtonMessageQueuePut.**************************
//Purpose : Message queue create wrapper
//Inputs  : PushButtonState = Gpio state
//Outputs : None
//Return  : Boolean value - Upon success it will return true , else false
//Notes   : None
//*
bool PushButtonMessageQueuePut(GPIO_PinState *PushButtonState)
{
	bool blRet = RET_FAILURE;

	blRet = MessageQueuePut(PushButtonState);

	return blRet;
}

//*************************.PushButtonMessageQueueGet.**************************
//Purpose : Message queue create wrapper
//Inputs  : None
//Outputs : stEvent - queue read value
//Return  : Boolean value - Upon success it will return true , else false
//Notes   : None
//*
bool PushButtonMessageQueueGet(osEvent *stEvent)
{
	bool blRet = RET_FAILURE;

	blRet = MessageQueueGet(stEvent);

	return blRet;
}
//EOF
