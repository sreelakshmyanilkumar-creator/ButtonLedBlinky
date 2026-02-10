//**************************** Button Led Blinky *******************************
//  Copyright (c) 2026 Trenser Technology Solutions
//  All Rights Reserved
//******************************************************************************
//
// File     : Led.h
// Summary  : To Blink LED in different patterns
// Note     : None
// Author   : Sreelakshmy M.A.
// Date     : 09/02/2026
//
//******************************************************************************
#ifndef _LED_H_
#define _LED_H_

//******************************* Include Files ********************************
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "CustomTasks.h"

//******************************* Global Types *********************************

//***************************** Global Constants *******************************

//***************************** Global Variables *******************************

//**************************** Forward Declarations ****************************
void LedBlinkyTask(void const *pArgument);
bool LedSemaphoreInit();
bool LedSemaphoreWait();
osStatus LedSemaphoreRelease();
bool LedBlinkPattern();

#endif //_LED_H_
//EOF
