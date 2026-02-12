//************************* Button Led Blinky **********************************
//  Copyright (c) 2026 Trenser Technology Solutions
//  All Rights Reserved
//******************************************************************************
//
// File     : CustomGpio.c
// Summary  : Initialization of GPIOs
// Note     : None
// Author   : Sreelakshmy M.A.
// Date     : 06/02/2026
//
//******************************************************************************

//******************************* Include Files ********************************
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <stdbool.h>
#include "main.h"
#include "cmsis_os.h"
#include "CustomStart.h"

//******************************* Local Types **********************************

//******************************* Local Constants ******************************

//******************************* Local Variables ******************************

//******************************* Local Functions ******************************
static bool CustomGpioButton();
static bool CustomGpioLed();

//*******************************.CustomGpioInit.*******************************
//Purpose : Initializing the GPIOs used, Creating the all the tasks required
//Inputs  : None
//Outputs : None
//Return  : Boolean value - Upon success it will return true , else false
//Notes   : None
//*
bool CustomGpioInit()
{
	bool blRet = RET_SUCCESS;

	blRet = CustomGpioButton();

	if(blRet == RET_SUCCESS)
	{
		blRet = CustomGpioLed();
	}

	return blRet;
}

//******************************.CustomGpioButton.******************************
//Purpose : Initializing the push button gpio pin with necessary configuration
//Inputs  : None
//Outputs : None
//Return  : Boolean value - Upon success it will return true , else false
//Notes   : None
//*
static bool CustomGpioButton()
{
	bool blRet = RET_FAILURE;
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);

	/*Configure GPIO pin : PC13 */
	GPIO_InitStruct.Pin = GPIO_PIN_13;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
	blRet = RET_SUCCESS;

	return blRet;
}

//*******************************.CustomGpioLed.********************************
//Purpose : Initializing the led  pin with necessary configuration
//Inputs  : None
//Outputs : None
//Return  : Boolean value - Upon success it will return true , else false
//Notes   : None
//*
static bool CustomGpioLed()
{
	bool blRet = RET_FAILURE;
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);

	/*Configure GPIO pin : PA5 */
	GPIO_InitStruct.Pin = GPIO_PIN_5;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	blRet = RET_SUCCESS;

	return blRet;
}
//EOF
