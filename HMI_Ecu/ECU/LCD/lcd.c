/******************************************************************************
 *
 * Module: LCD
 *
 * File Name: lcd.c
 *
 * Created on: Oct 31, 2024
 *
 * Author: Shahd Diploma 90
 *
 *******************************************************************************/

/*******************************************************************************
 *                              Includes                                       *
 *******************************************************************************/
#include "lcd.h"
#include "../../MCAL/GPIO/gpio.h"
#include <util/delay.h> /* For the delay functions */
#include <stdlib.h>  /* For itoa functions */

#include "../../LIB/common_macros.h" /* For GET_BIT Macro */

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * Initialize the LCD:
 * 1. Setup the LCD pins directions by use the GPIO driver.
 * 2. Setup the LCD Data Mode 4-bits or 8-bits.
 */
void LCD_init(void)
{
  /* Configure the direction for RS and E pins as output pins */
  GPIO_setupPinDirection(LCD_RS_PORT_ID, LCD_RS_PIN_ID, PIN_OUTPUT);
  GPIO_setupPinDirection(LCD_E_PORT_ID, LCD_E_PIN_ID, PIN_OUTPUT);

  _delay_ms(20); /* LCD Power ON delay always > 15ms */

#if(LCD_DATA_BITS_MODE == 4)
	/* Configure 4 pins in the data port as output pins */
	GPIO_setupPinDirection(LCD_DATA_PORT_ID, LCD_DB4_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT_ID, LCD_DB5_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT_ID, LCD_DB6_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT_ID, LCD_DB7_PIN_ID, PIN_OUTPUT);

	/* Send for 4 bit initialization of LCD  */
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT1);
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT2);

	/* use 2-lines LCD + 4-bits Data Mode + 5*7 dot display Mode */
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE);

#elif(LCD_DATA_BITS_MODE == 8)
  /* Configure the data port as output port */
  GPIO_setupPortDirection(LCD_DATA_PORT_ID, PORT_OUTPUT);

  /* use 2-lines LCD + 8-bits Data Mode + 5*7 dot display Mode */
  LCD_sendCommand(LCD_TWO_LINES_EIGHT_BITS_MODE);

#endif

  LCD_sendCommand(LCD_CURSOR_OFF); /* cursor off */
  LCD_sendCommand(LCD_CLEAR_COMMAND); /* clear LCD at the beginning */
}

/*
 * Description: Sends the specified command to the LCD.
 *
 * @param command: The command to be sent.
 */
void LCD_sendCommand(uint8 command)
{
  GPIO_writePin(LCD_RS_PORT_ID, LCD_RS_PIN_ID, LOGIC_LOW); /* Instruction Mode RS=0 */
  _delay_ms(1); /* delay for processing Tas = 50ns */
  GPIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_HIGH); /* Enable LCD E=1 */
  _delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

#if(LCD_DATA_BITS_MODE == 4)
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB4_PIN_ID, GET_BIT(command, 4));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB5_PIN_ID, GET_BIT(command, 5));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB6_PIN_ID, GET_BIT(command, 6));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB7_PIN_ID, GET_BIT(command, 7));

	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	GPIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */
	GPIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_HIGH); /* Enable LCD E=1 */
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB4_PIN_ID, GET_BIT(command, 0));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB5_PIN_ID, GET_BIT(command, 1));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB6_PIN_ID, GET_BIT(command, 2));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB7_PIN_ID, GET_BIT(command, 3));

	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	GPIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */

#elif(LCD_DATA_BITS_MODE == 8)
  GPIO_writePort(LCD_DATA_PORT_ID, command); /* out the required command to the data bus D0 --> D7 */
  _delay_ms(1); /* delay for processing Tdsw = 100ns */
  GPIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_LOW); /* Disable LCD E=0 */
  _delay_ms(1); /* delay for processing Th = 13ns */
#endif
}

/*
 * Description :
 * Display the required character on the screen
 */
void LCD_displayCharacter(uint8 data)
{
  GPIO_writePin(LCD_RS_PORT_ID, LCD_RS_PIN_ID, LOGIC_HIGH); /* Data Mode RS=1 */
  _delay_ms(1); /* delay for processing Tas = 50ns */
  GPIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_HIGH); /* Enable LCD E=1 */
  _delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

#if(LCD_DATA_BITS_MODE == 4)
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB4_PIN_ID, GET_BIT(data, 4));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB5_PIN_ID, GET_BIT(data, 5));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB6_PIN_ID, GET_BIT(data, 6));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB7_PIN_ID, GET_BIT(data, 7));

	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	GPIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */
	GPIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_HIGH); /* Enable LCD E=1 */
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB4_PIN_ID, GET_BIT(data, 0));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB5_PIN_ID, GET_BIT(data, 1));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB6_PIN_ID, GET_BIT(data, 2));
	GPIO_writePin(LCD_DATA_PORT_ID, LCD_DB7_PIN_ID, GET_BIT(data, 3));

	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	GPIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */

#elif(LCD_DATA_BITS_MODE == 8)
  GPIO_writePort(LCD_DATA_PORT_ID, data); /* out the required command to the data bus D0 --> D7 */
  _delay_ms(1); /* delay for processing Tdsw = 100ns */
  GPIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_LOW); /* Disable LCD E=0 */
  _delay_ms(1); /* delay for processing Th = 13ns */
#endif
}

/*
 * Description: Displays a string on the LCD.
 *
 * @param Str: Pointer to the string to be displayed.
 */
void LCD_displayString(const char *Str)
{
  uint8 i = 0;
  while (Str[i] != '\0')
    {
      LCD_displayCharacter(Str[i]);
      i++;
    }
  /***************** Another Method ***********************
   while((*Str) != '\0')
   {
   LCD_displayCharacter(*Str);
   Str++;
   }
   *********************************************************/
}

/*
 * Description: Moves the cursor to a specified row and column on the LCD.
 *
 * @param row: The row index (0 or 1).
 * @param col: The column index (0 to 15).
 */
void LCD_moveCursor(uint8 row, uint8 col)
{
  uint8 lcd_memory_address;

  /* Calculate the required address in the LCD DDRAM */
  switch (row)
    {
    case 0:
      lcd_memory_address = col;
      break;
    case 1:
      lcd_memory_address = col + 0x40;
      break;
    case 2:
      lcd_memory_address = col + 0x10;
      break;
    case 3:
      lcd_memory_address = col + 0x50;
      break;
    }
  /* Move the LCD cursor to this specific address */
  LCD_sendCommand(lcd_memory_address | LCD_SET_CURSOR_LOCATION);
}

/*
 * Description: Displays a string at a specified row and column on the LCD.
 *
 * @param row: The row index (0 or 1).
 * @param col: The column index (0 to 15).
 * @param Str: Pointer to the string to be displayed.
 */
void LCD_displayStringRowColumn(uint8 row, uint8 col, const char *Str)
{
  LCD_moveCursor(row, col); /* go to to the required LCD position */
  LCD_displayString(Str); /* display the string */
}

/*
 * Description :
 * Send the clear screen command
 */
void LCD_clearScreen(void)
{
  LCD_sendCommand(LCD_CLEAR_COMMAND); /* Send clear display command */
}

/*
 * Description: Sends the cursor blink command to the LCD.
 */
void LCD_cursorBlink(void)
{
  LCD_sendCommand(LCD_CURSOR_BLINK);
}

/*
 * Description: Displays a decimal value on the LCD.
 *
 * @param data: The integer value to be displayed.
 */
void LCD_displayNumber(sint32 num)
{
  /* Convert the number to a string and display it */
  char buffer[20]; /* Buffer to hold the converted number */
  ltoa(num, buffer, 10); /* Convert number to string in base 10 */
  LCD_displayString(buffer); /* Display the string representation of the number */
}
