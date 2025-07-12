/*******************************************************************************
 *
 * Module: Global Variables
 *
 * File Name: globals.h
 *
 * Created on: Oct 31, 2024
 *
 * Author: Shahd Diploma 90
 *
 *******************************************************************************/

#ifndef APP_RTOS_S_H_
#define APP_RTOS_S_H_

/*******************************************************************************
 *                                Includes                                     *
 *******************************************************************************/
#include "../FreeRTOS/FreeRTOS.h"
#include "../FreeRTOS/queue.h"
#include "../FreeRTOS/semphr.h"

/*******************************************************************************
 *                              Global Variables                               *
 *******************************************************************************/

/**
 * @brief Global queue handle for receiving data.
 */
extern QueueHandle_t g_xQueueReceive;

/**
 * @brief Global queue handle for sending data.
 */
extern QueueHandle_t g_xQueueSend;

/**
 * @brief Global semaphore handle for door control synchronization.
 */
extern SemaphoreHandle_t g_doorSemphr;

#endif /* APP_RTOS_S_H_ */
