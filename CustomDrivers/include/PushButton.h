//**************************** Button Led Blinky *******************************
//  Copyright (c) 2026 Trenser Technology Solutions
//  All Rights Reserved
//******************************************************************************
//
// File     : PushButton.h
// Summary  : Read push button and status send to process thread
// Note     : None
// Author   : Sreelakshmy M.A.
// Date     : 09/02/2026
//
//******************************************************************************
#ifndef _PUSH_BUTTON_H_
#define _PUSH_BUTTON_H_

//******************************* Include Files ********************************
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

//******************************* Global Types *********************************

//***************************** Global Constants *******************************

//***************************** Global Variables *******************************

//**************************** Forward Declarations ****************************
void ReadPushButtonTask(void const * argument);
bool PushButtonMessageQueueCreate(osThreadId PushButtonThreadId);
bool PushButtonMessageQueuePut(GPIO_PinState *PushButtonState);
bool PushButtonMessageQueueGet(osEvent *stEvent);

#endif //_PUSH_BUTTON_H_
//EOF
