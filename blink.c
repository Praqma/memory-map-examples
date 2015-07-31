/**********************************************************************
 *
 * Filename:    blink.c
 * 
 * Description: The Blinking LED program. The embedded systems
 *              equivalent of "Hello, World".
 *
 * Notes:       This file is specific to the Arcom board.
 * 
 * Copyright (c) 2006 Anthony Massa and Michael Barr. All rights reserved.
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
#include "led.h"


/* Number of decrement-and-test cycles. */
#define CYCLES_PER_MS               (9000)


/**********************************************************************
 *
 * Function:    delay_ms
 *
 * Description: Busy-wait for the requested number of milliseconds.
 *
 * Notes:       The number of decrement-and-test cycles per millisecond
 *              was determined through trial and error.  This value is
 *              dependent upon the processor type, speed, compiler, and
 *              the level of optimization.
 *
 * Returns:     None.
 *
 **********************************************************************/
void delay_ms(int milliseconds)
{
    long volatile cycles = (milliseconds * CYCLES_PER_MS);
     
    while (cycles != 0)
        cycles--;
}


/**********************************************************************
 *
 * Function:    main
 *
 * Description: Blink the green LED once a second.
 * 
 * Notes:       
 *
 * Returns:     This routine contains an infinite loop.
 *
 **********************************************************************/
int main(void)
{
    /* Ensure the data and instruction caches are enabled. */
    DCACHE_ENABLE();
    ICACHE_ENABLE();

    /* Configure the green LED control pin. */
    ledInit();

    while (1)
    {
        /* Change the state of the green LED. */
        ledToggle();

        /* Pause for 500 milliseconds. */
        delay_ms(500);
    }

    return 0;
}

