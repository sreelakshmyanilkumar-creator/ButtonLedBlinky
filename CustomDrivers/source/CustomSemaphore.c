//************************* Button Led Blinky **********************************
//  Copyright (c) 2026 Trenser Technology Solutions
//  All Rights Reserved
//******************************************************************************
//
// File     : CustomSemaphore.c
// Summary  : Semaphore wrapper
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
#include "CustomTasks.h"
#include "CustomSemaphore.h"

//******************************* Local Types **********************************

//******************************* Local Constants ******************************
#define SEM_TIMEOUT (0)
#define SEM_ERROR	(-1)

//******************************* Local Variables ******************************
osStaticSemaphoreDef_t stLedSemaphoreTCB = {0};
osSemaphoreId stLedSemaphoreId = {0};

//******************************* Local Functions ******************************

//****************************.SemaphoreCreate.****************************
//Purpose : To create semaphore
//Inputs  : None
//Outputs : None
//Return  : Boolean value - Upon success it will return true , else false
//Notes   : None
//*
bool SemaphoreCreate()
{
	bool blRet = RET_FAILURE;
	osSemaphoreDef_t stSemaphoreConf = {0};
	stSemaphoreConf.controlblock = (osStaticSemaphoreDef_t *)&stLedSemaphoreTCB;

	stLedSemaphoreId = osSemaphoreCreate(&stSemaphoreConf, 1);

	if(stLedSemaphoreId != NULL)
	{
		printf("Semaphore initialized Successfully\n");
		blRet = RET_SUCCESS;
	}

	return blRet;
}

//****************************.SemaphoreWait.****************************
//Purpose : To wait semaphore
//Inputs  : None
//Outputs : None
//Return  : Boolean value - Upon success it will return true , else false
//Notes   : None
//*
bool SemaphoreWait()
{
	bool blRet = RET_FAILURE;
	int32_t LedSemRet = 0;

	LedSemRet = osSemaphoreWait(stLedSemaphoreId, osWaitForever);

	if(LedSemRet != SEM_ERROR)
	{
		blRet = RET_SUCCESS;
	}

	return blRet;
}

//******************************.SemaphoreRelease.******************************
//Purpose : To Release semaphore
//Inputs  : None
//Outputs : None
//Return  : LedSemaphoreRetStatus - Return error/success in osStatus
//Notes   : None
//*
osStatus SemaphoreRelease()
{
	osStatus LedSemaphoreRetStatus = osErrorOS;

	if (stLedSemaphoreId != NULL)
	{
		LedSemaphoreRetStatus = osSemaphoreRelease(stLedSemaphoreId);
	}

	return LedSemaphoreRetStatus;
}
//EOF
