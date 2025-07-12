/*******************************************************************************
 *
 * Module: Door Control
 *
 * File Name: door.h
 *
 * Created on: Oct 31, 2024
 *
 * Author: Shahd Diploma 90
 *
 *******************************************************************************/

#ifndef APP_DOOR_DOOR_H_
#define APP_DOOR_DOOR_H_

#include "../../LIB/std_types.h"


#define DOOR_DELAY pdMS_TO_TICKS(15000)



/**
 * @brief Task for managing door operations.
 *
 * This function runs as a FreeRTOS task to handle the logic for door control,
 * including opening, closing, and checking the state of the door.
 *
 * @param pvParameters Pointer to task parameters.
 */
void DOOR_task(void *pvParameters);

#endif /* APP_DOOR_DOOR_H_ */
