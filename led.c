/**********************************************************************
 *
 * Filename:    led.c
 * 
 * Description: LED device driver.
 *
 * Notes:       This file is specific to the Arcom board.
 * 
 * Copyright (c) 2006 Anthony Massa and Michael Barr.  All rights reserved.
 * This code is from the book Programming Embedded Systems, With C and
 * GNU Development Tools, 2nd Edition.
 * It is provided AS-IS, WITHOUT ANY WARRANTY either expressed or implied.
 * You may study, use, and modify it for any non-commercial purpose,
 * including teaching and use in open-source projects.
 * You may distribute it non-commercially as long as you retain this notice.
 * For a commercial use license, or to purchase the book,
 * please visit http://www.oreilly.com/catalog/embsys2.
 *
 **********************************************************************/

#include "stdint.h"
#include "pxa255.h"
#include "viperlite.h"
#include "led.h"


#define PIN22_FUNC_GENERAL          (0xFFFFCFFF)


/**********************************************************************
 *
 * Function:    ledInit
 *
 * Description: Initialize the GPIO pin that controls the LED.
 *
 * Notes:       This function is specific to the Arcom board.
 *
 * Returns:     None.
 *
 **********************************************************************/
void ledInit(void)
{
    /* Turn the GPIO pin voltage off, which will light the LED. This should
     * be done before the pins are configured. */
    GPIO_0_CLEAR_REG = LED_GREEN;

    /* Make sure the LED control pin is set to perform general
     * purpose functions. RedBoot may have changed the pin's operation. */
    GPIO_0_FUNC_HI_REG &= PIN22_FUNC_GENERAL;

    /* Set the LED control pin to operate as output. */
    GPIO_0_DIRECTION_REG |= LED_GREEN;
}


/**********************************************************************
 *
 * Function:    ledToggle
 *
 * Description: Toggle the state of one LED.
 *
 * Notes:       This function is specific to the Arcom board.
 *
 * Returns:     None.
 *
 **********************************************************************/
void ledToggle(void)
{
    /* Check the current state of the LED control pin. Then change the
     * state accordingly. */
    if (GPIO_0_LEVEL_REG & LED_GREEN)
        GPIO_0_CLEAR_REG = LED_GREEN;
    else
        GPIO_0_SET_REG = LED_GREEN;
}

