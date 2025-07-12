 /******************************************************************************
 *
 * Module: KEYPAD
 *
 * File Name: keypad.h
 *
 * Created on: Oct 31, 2024
 *
 * Author: Shahd Diploma 90
 *
 *******************************************************************************/

#ifndef ECU_KEYPAD_KEYPAD_H_
#define ECU_KEYPAD_KEYPAD_H_

#include "../../LIB/std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define SPECIAL_KEYPAD
/*#define STANDARD_KEYPAD*/

/* Keypad configurations for number of rows and columns */
#define KEYPAD_NUM_ROWS                   4
#define KEYPAD_NUM_COLS                   4

/* Keypad Port Configurations */
#define KEYPAD_ROW_PORT_ID                PORTB_ID
#define KEYPAD_FIRST_ROW_PIN_ID           PIN0_ID

#define KEYPAD_COL_PORT_ID                PORTB_ID
#define KEYPAD_FIRST_COL_PIN_ID           PIN4_ID

/* Keypad button logic configurations */
#define KEYPAD_BUTTON_PRESSED            LOGIC_LOW
#define KEYPAD_BUTTON_RELEASED           LOGIC_HIGH

#define KEYPAD_NO_KEY					 0xFF
#define KEYPAD_ENTER_ASCII				 13

/*******************************************************************************
 *                        Type Declarations                                    *
 *******************************************************************************/

typedef uint8 KEYPAD_key_t;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/**
 * @brief Initialize the keypad hardware.
 *
 * This function sets up the keypad rows as input and columns as output, enabling
 * the internal pull-up resistors for the columns.
 */
void KEYPAD_init(void);

#ifdef SPECIAL_KEYPAD
void KEYPAD_setKeys(const uint8 * keysO);
#endif
/**
 * @brief Get the currently pressed key from the keypad.
 *
 * This function checks the state of the keypad and returns the value of the pressed
 * key. If no key is pressed, it returns `KEYPAD_NO_KEY`.
 *
 * @return uint8 Value representing the pressed key or `KEYPAD_NO_KEY`.
 */
uint8 KEYPAD_getPressedKey(void);

/**
 * @brief Get the currently pressed key with blocking behavior.
 *
 * This function will continuously check for a key press until a button is pressed,
 * then returns the corresponding key value.
 *
 * @return uint8 Value representing the pressed key.
 */
uint8 KEYPAD_getPressedKeyBlocking(void);


#endif /* ECU_KEYPAD_KEYPAD_H_ */
