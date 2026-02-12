//**************************** Button Led Blinky *******************************
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
#ifndef _CUSTOM_SEMAPHORE_H_
#define _CUSTOM_SEMAPHORE_H_

//******************************* Include Files ********************************
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

//******************************* Global Types *********************************

//***************************** Global Constants *******************************

//***************************** Global Variables *******************************

//**************************** Forward Declarations ****************************
bool SemaphoreCreate();
bool SemaphoreWait();
osStatus SemaphoreRelease();

#endif //_CUSTOM_SEMAPHORE_H_
//EOF
