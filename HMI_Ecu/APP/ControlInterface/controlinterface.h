/*******************************************************************************
 *
 * Module: Control Interface
 *
 * File Name: controlinterface.h
 *
 * Created on: Oct 31, 2024
 *
 * Author: Shahd Diploma 90
 *
 *******************************************************************************/

#ifndef APP_CONTROLINTERFACE_CONTROLINTERFACE_H_
#define APP_CONTROLINTERFACE_CONTROLINTERFACE_H_

/*******************************************************************************
 *                                Includes                                     *
 *******************************************************************************/
#include "../../LIB/std_types.h"

/*******************************************************************************
 *                              Function Prototypes                            *
 *******************************************************************************/

/**
 * @brief USART task for control interface.
 *
 * This function handles the USART communication task within the FreeRTOS
 * environment, allowing for effective data transmission and reception.
 *
 * @param pvParameters: Parameters passed to the task (not used in this implementation).
 */
void CI_usartTask(void *pvParameters);

#endif /* APP_CONTROLINTERFACE_CONTROLINTERFACE_H_ */
