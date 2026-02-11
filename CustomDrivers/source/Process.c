//************************* Button Led Blinky **********************************
//  Copyright (c) 2026 Trenser Technology Solutions
//  All Rights Reserved
//******************************************************************************
//
// File     : Process.c
// Summary  : Main task is to do Decision making
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
#include "PushButton.h"
#include "CustomStart.h"
#include "Led.h"
#include "Signals.h"
#include "Process.h"

//******************************* Local Types **********************************

//******************************* Local Constants ******************************

//******************************* Local Variables ******************************

//******************************* Local Functions ******************************

//****************************.ProcessTask.****************************
//Purpose : Read push button status and send to process thread
//Inputs  : None
//Outputs : None
//Return  : None
//Notes   : None
//*
void ProcessTask(void const *pArgument)
{
  osEvent stEvent = {0};
  GPIO_PinState lCurrentState = GPIO_PIN_SET;
  GPIO_PinState lLastState = GPIO_PIN_SET;

  printf("Starting ProcessTask\n");

  for(;;)
  {
	if(PushButtonMessageQueueGet(&stEvent) != RET_FAILURE)
	{
		lCurrentState = stEvent.value.v;

		if(lCurrentState != lLastState)
		{
			if(lCurrentState == GPIO_PIN_RESET)
			{
				printf("Push Button pressed\n");
				ProcessTaskSignalSet(LedThreadId1, SIGNAL_LED_TOGGLE1);
			}
			else
			{
				printf("Push Button Released\n");
				ProcessTaskSignalSet(LedThreadId2, SIGNAL_LED_TOGGLE2);
			}

			lLastState = lCurrentState;
		}
	}

	 osDelay(5);
  }
}

//******************************.ProcessTaskSignalSet.**************************
//Purpose : To set event signal
//Inputs  : ThreadId - Thread Id of the waiting thread
//			Signal -
//Outputs : None
//Return  : Boolean value - Upon success it will return true , else false
//Notes   : None
//*
bool ProcessTaskSignalSet(osThreadId ThreadId, int32_t Signal)
{
	bool blRet = RET_FAILURE;

	blRet = SignalSet(ThreadId, Signal);

	return blRet;
}

//*****************************.ProcessTaskSignalWait.**************************
//Purpose : To wait for event signal
//Inputs  : None
//Outputs : None
//Return  : Boolean value - Upon success it will return true , else false
//Notes   : None
//*
bool ProcessTaskSignalWait(int32_t Signal, osEvent* Evt)
{
	bool blRet = RET_FAILURE;

	blRet = SignalWait(Signal, Evt);

	return blRet;
}

//*****************************.ProcessTaskSignalClear.*************************
//Purpose : To clear event signal
//Inputs  : None
//Outputs : None
//Return  : Boolean value - Upon success it will return true , else false
//Notes   : None
//*
bool ProcessTaskSignalClear(osThreadId ThreadId, int32_t Signal)
{
	bool blRet = RET_FAILURE;

	blRet = SignalClear(ThreadId, Signal);

	return blRet;
}
//EOF
