//************************* Button Led Blinky **********************************
//  Copyright (c) 2026 Trenser Technology Solutions
//  All Rights Reserved
//******************************************************************************
//
// File     : Signals.h
// Summary  : For event management
// Note     : None
// Author   : Sreelakshmy M.A.
// Date     : 11/02/2026
//
//******************************************************************************

//******************************* Include Files ********************************
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <stdbool.h>
#include "Signals.h"
#include "CustomStart.h"
#include "CustomTasks.h"

//******************************* Local Types **********************************

//******************************* Local Constants ******************************
#define SIGNAL_ERR		(0x80000000)

//******************************* Local Variables ******************************

//******************************* Local Functions ******************************

//********************************.SignalSet.***********************************
//Purpose : To Set the event signal
//Inputs  : ThreadId - ThreadID
//			Signal - Signal flag
//Outputs : None
//Return  : Boolean value - Upon success it will return true , else false
//Notes   : None
//*
bool SignalSet(osThreadId ThreadId, int32_t Signal)
{
	bool blRet = RET_FAILURE;
	int32_t SigRet = 0;

	SigRet = osSignalSet(ThreadId, Signal);

	if(SigRet != SIGNAL_ERR)
	{
		blRet = RET_SUCCESS;
	}

	return blRet;
}

//**********************************.SignalWait.********************************
//Purpose : To wait for the event signal
//Inputs  : Signal - Signal flag
//			stEvt - osEvent structure variable
//Return  : Boolean value - Upon success it will return true , else false
//Notes   : None
//*
bool SignalWait(int32_t Signal, osEvent* pstEvt)
{
	bool blRet = RET_FAILURE;

	if(pstEvt != NULL)
	{
		*pstEvt = osSignalWait(Signal, osWaitForever);

		if(pstEvt->status == osOK)
		{
			blRet = RET_SUCCESS;
		}
	}

	return blRet;
}

//**********************************.SignalClear.*******************************
//Purpose : To clear event signal
//Inputs  : ThreadId - ThreadID
//			Signal - Signal flag
//Outputs : None
//Return  : Boolean value - Upon success it will return true , else false
//Notes   : None
//*
bool SignalClear(osThreadId ThreadId, int32_t Signal)
{
	bool blRet = RET_FAILURE;
	int32_t SigRet = 0;

	SigRet = osSignalClear(ThreadId, Signal);

	if(SigRet != SIGNAL_ERR)
	{
		blRet = RET_SUCCESS;
	}

	return blRet;
}
//EOF
