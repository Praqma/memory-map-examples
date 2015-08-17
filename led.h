/**********************************************************************
 *
 * Filename:    led.h
 * 
 * Description: Header file for LED device driver.
 *
 * Notes:       
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

#ifndef _LED_H
#define _LED_H


void ledInit(void);
void ledToggle(void);


#endif /* _LED_H */
