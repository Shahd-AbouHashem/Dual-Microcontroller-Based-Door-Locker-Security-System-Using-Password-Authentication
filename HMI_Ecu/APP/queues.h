/*******************************************************************************
 *
 * Module: Queues
 *
 * File Name: queues.h
 *
 * Created on: Oct 31, 2024
 *
 * Author: Shahd Diploma 90
 *
 *******************************************************************************/

#ifndef APP_QUEUES_H_
#define APP_QUEUES_H_

/*******************************************************************************
 *                                Includes                                     *
 *******************************************************************************/
#include "../FreeRTOS/FreeRTOS.h"
#include "../FreeRTOS/queue.h"

/*******************************************************************************
 *                              Global Variables                               *
 *******************************************************************************/

/**
 * @brief Queue handle for receiving data.
 */
extern QueueHandle_t g_xQueueReceive;

/**
 * @brief Queue handle for sending data.
 */
extern QueueHandle_t g_xQueueSend;

#endif /* APP_QUEUES_H_ */
