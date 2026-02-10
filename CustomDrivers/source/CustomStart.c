//************************* Button Led Blinky **********************************
//  Copyright (c) 2026 Trenser Technology Solutions
//  All Rights Reserved
//******************************************************************************
//
// File     : CustomStart.c
// Summary  : User Application Start from this file
// Note     : None
// Author   : Sreelakshmy M.A.
// Date     : 06/02/2026
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
#include "CustomTasks.h"

//******************************* Local Types **********************************

//******************************* Local Constants ******************************

//******************************* Local Variables ******************************

//******************************* Local Functions ******************************

//****************************.CustomStartButtonLed.****************************
//Purpose : Initializing the GPIOs used, Creating the all the tasks required
//Inputs  : None
//Outputs : None
//Return  : Boolean value - Upon success it will return true , else false
//Notes   : None
//*
bool CustomStartButtonLed()
{
	bool blRet = RET_FAILURE;

	/*Initialize GPIOs*/
	blRet = CustomGpioInit();
	printf("GPIO initialized successfully\n");

	return blRet;
}
//EOF
