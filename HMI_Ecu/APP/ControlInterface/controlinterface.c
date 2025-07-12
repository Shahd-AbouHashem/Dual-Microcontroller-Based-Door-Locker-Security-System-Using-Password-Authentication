/*******************************************************************************
 *
 * Module: Control Interface
 *
 * File Name: controlinterface.c
 *
 * Created on: Oct 31, 2024
 *
 * Author: Shahd Diploma 90
 *
 *******************************************************************************/

#include "controlinterface.h"
#include "../../FreeRTOS/FreeRTOS.h"
#include "../../FreeRTOS/semphr.h"
#include "../../MCAL/USART/usart.h"
#include "../queues.h"

SemaphoreHandle_t usartReceiveSemphr;


void CI_usartReceiveIntHandl(void) {
    uint8 dataReceive;
    USART_receiveCharNonBlocking(&dataReceive);
    if (xQueueSend(g_xQueueReceive, &dataReceive, (TickType_t)20) == pdPASS) {
         /*Successfully sent the received data to the queue*/
    }
}


void CI_usartTask(void *pvParameters) {
    if (USART_isInit() == FALSE) {
        USART_init(&g_usart);
    }

    USART_setRXCompleteInterruptHandler(CI_usartReceiveIntHandl);

    uint8 dataSend;
    for (;;) {
        if (xQueueReceive(g_xQueueSend, &dataSend, portMAX_DELAY) == pdPASS) {
            while (!USART_sendCharNonBlocking(dataSend))
                ; /*Wait until the character is sent*/
        }
    }
}
