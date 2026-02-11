//************************* Button Led Blinky **********************************
//  Copyright (c) 2026 Trenser Technology Solutions
//  All Rights Reserved
//******************************************************************************
//
// File     : Led.c
// Summary  : To Blink LED in different patterns
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
#include "CustomGpio.h"
#include "Led.h"
#include "CustomSemaphore.h"
#include "Signals.h"
#include "Process.h"

//******************************* Local Types **********************************

//******************************* Local Constants ******************************

//******************************* Local Variables ******************************
osThreadId LedThreadId1 = 0;
osThreadId LedThreadId2 = 0;

//******************************* Local Functions ******************************

//********************************.LedBlinkyTask1.*******************************
//Purpose : To Blink LED in different patterns
//Inputs  : None
//Outputs : None
//Return  : None
//Notes   : None
//*
void LedBlinkyTask1(void const *pArgument)
{
	osEvent Evt = {0};
	LedThreadId1 = osThreadGetId();

	for(;;)
	{
		printf("Waiting for LED Pattern1 Event...\n");
		ProcessTaskSignalWait(SIGNAL_LED_TOGGLE1, &Evt);

		if(Evt.value.signals == SIGNAL_LED_TOGGLE1)
		{
			LedBlinkPattern1();
		}

		osDelay(1);
	}
}

//********************************.LedBlinkyTask2.*******************************
//Purpose : To Blink LED in different patterns
//Inputs  : None
//Outputs : None
//Return  : None
//Notes   : None
//*
void LedBlinkyTask2(void const *pArgument)
{
	osEvent Evt = {0};
	LedThreadId2 = osThreadGetId();

	for(;;)
	{
		printf("Waiting for LED Pattern2 Event...\n");
		ProcessTaskSignalWait(SIGNAL_LED_TOGGLE2, &Evt);

		if(Evt.value.signals == SIGNAL_LED_TOGGLE2)
		{
			LedBlinkPattern2();
		}

		osDelay(1);
	}
}

//****************************.LedSemaphoreInit.********************************
//Purpose : To initialize semaphore
//Inputs  : None
//Outputs : None
//Return  : Boolean value - Upon success it will return true , else false
//Notes   : None
//*
bool LedSemaphoreInit()
{
	bool blRet = RET_FAILURE;

	blRet = SemaphoreCreate();

	return blRet;
}

//****************************.LedSemaphoreWait.********************************
//Purpose : To wait semaphore
//Inputs  : None
//Outputs : None
//Return  : Boolean value - Upon success it will return true , else false
//Notes   : None
//*
bool LedSemaphoreWait()
{
	bool blRet = RET_FAILURE;

	blRet = SemaphoreWait();

	return blRet;
}

//****************************.LedSemaphoreRelease.*****************************
//Purpose : To Release semaphore
//Inputs  : None
//Outputs : None
//Return  : SemRet - return as per osStatus
//Notes   : None
//*
osStatus LedSemaphoreRelease()
{
	osStatus SemRet = osErrorOS;

	SemRet = SemaphoreRelease();

	return SemRet;
}

//*******************************.LedBlinkPattern1.******************************
//Purpose : To blink led in a pattern
//Inputs  : None
//Outputs : None
//Return  : Boolean value - Upon success it will return true , else false
//Notes   : None
//*
bool LedBlinkPattern1()
{
	bool blRet = RET_FAILURE;

	while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_RESET)
	{
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
		osDelay(100);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
		osDelay(100);
		blRet = RET_SUCCESS;
	}

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);

	return blRet;
}

//*******************************.LedBlinkPattern2.******************************
//Purpose : To blink led in a pattern
//Inputs  : None
//Outputs : None
//Return  : Boolean value - Upon success it will return true , else false
//Notes   : None
//*
bool LedBlinkPattern2()
{
	bool blRet = RET_FAILURE;

	while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_SET)
	{
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
		osDelay(1000);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
		osDelay(1000);
	}

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);

	return blRet;
}
//EOF
