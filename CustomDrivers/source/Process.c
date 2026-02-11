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

  printf("Starting ProcessTask");

  for(;;)
  {
	if(PushButtonMessageQueueGet(&stEvent) != RET_FAILURE)
	{
		lCurrentState = stEvent.value.v;
		printf("lCurrentState %d\n", lCurrentState);

		if(lCurrentState != lLastState)
		{
			if(lCurrentState == GPIO_PIN_RESET)
			{
				printf("Push Button pressed\n");
				LedSemaphoreRelease();
			}
			else
			{
				printf("Push Button Released\n");
			}

			lLastState = lCurrentState;
		}
		else
		{
			printf("same\n");
		}
	}

	 osDelay(5);
  }
}
//EOF
