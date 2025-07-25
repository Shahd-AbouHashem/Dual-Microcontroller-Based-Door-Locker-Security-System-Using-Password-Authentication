/*******************************************************************************
 *
 * Module: Human Interface
 *
 * File Name: humaninterface.h
 *
 * Created on: Oct 31, 2024
 *
 * Author: Shahd Diploma 90
 *
 *******************************************************************************/

#ifndef APP_HUMANINTERFACE_HUMANINTERFACE_H_
#define APP_HUMANINTERFACE_HUMANINTERFACE_H_

/*******************************************************************************
 *                                Includes                                     *
 *******************************************************************************/
#include "../../LIB/std_types.h"

/*******************************************************************************
 *                              Macro Definitions                              *
 *******************************************************************************/
#define LOCK_DELAY_TIME  pdMS_TO_TICKS(1000)  /**< Time to lock the interface */
#define DELAY_TIME    	 pdMS_TO_TICKS(500)  /**< General delay time */
#define PASS_TIME_TO_WAIT	60

/*******************************************************************************
 *                              Function Prototypes                            *
 *******************************************************************************/

/**
 * @brief Human Interface task for handling user interactions.
 *
 * This function runs in a FreeRTOS task to manage the human interface
 * and process user inputs or outputs.
 *
 * @param pvParameters Pointer to task parameters.
 */
void HI_task(void *pvParameters);

#endif /* APP_HUMANINTERFACE_HUMANINTERFACE_H_ */
