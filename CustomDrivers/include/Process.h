//**************************** Button Led Blinky *******************************
//  Copyright (c) 2026 Trenser Technology Solutions
//  All Rights Reserved
//******************************************************************************
//
// File     : Process.h
// Summary  : Main task is to do Decision making
// Note     : None
// Author   : Sreelakshmy M.A.
// Date     : 09/02/2026
//
//******************************************************************************
#ifndef _PROCESS_H_
#define _PROCESS_H_

//******************************* Include Files ********************************
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "CustomTasks.h"

//******************************* Global Types *********************************

//***************************** Global Constants *******************************

//***************************** Global Variables *******************************

//**************************** Forward Declarations ****************************
void ProcessTask(void const * argument);
bool ProcessTaskSignalSet(osThreadId ThreadId, int32_t Signal);
bool ProcessTaskSignalWait(int32_t Signal, osEvent* Evt);
bool ProcessTaskSignalClear(osThreadId ThreadId, int32_t Signal);

#endif //_PROCESS_H_
//EOF
