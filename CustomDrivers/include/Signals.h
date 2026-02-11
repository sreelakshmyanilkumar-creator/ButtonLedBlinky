//**************************** Button Led Blinky *******************************
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
#ifndef _SIGNALS_H_
#define _SIGNALS_H_

//******************************* Include Files ********************************
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "CustomTasks.h"

//******************************* Global Types *********************************

//***************************** Global Constants *******************************
#define SIGNAL_LED_TOGGLE1  (0x01)  // Bit 0
#define SIGNAL_LED_TOGGLE2  (0x02)  // Bit 1

//***************************** Global Variables *******************************

//**************************** Forward Declarations ****************************
bool SignalSet(osThreadId ThreadId, int32_t Signal);
bool SignalWait(int32_t Signal, osEvent* Evt);
bool SignalClear(osThreadId ThreadId, int32_t Signal);

#endif //_SIGNALS_H_
//EOF
