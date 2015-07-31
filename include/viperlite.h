/**********************************************************************
 *
 * Filename:    viperlite.h
 * 
 * Description: Header file for Arcom Viper-Lite board.
 *
 * Notes:       The constants in this file are specific to the Arcom
 *              board.
 *
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

#ifndef _VIPERLITE_H
#define _VIPERLITE_H


#ifndef TRUE
#define TRUE            1
#endif

#ifndef FALSE
#define FALSE           0
#endif

#ifndef NULL
#define NULL            (void *)0
#endif


/**********************************************************************
 *
 *  Memory Map
 *
 *  NOTE:   RedBoot remaps memory via the MMU. This explains why this map differs
 *          from the memory map in the VIPER-Lite technical manual.
 *          (See file \packages\hal\arm\xscale\viper\current\src\viper_misc.c
 *          function hal_mmu_init).
 *
 *          Base Address   Size  Description
 *          -------------- ----- -----------------------------------
 *            0x00000000     64M   SDRAM
 *            0x08000300     N/A   Ethernet controller
 *            0x50000000     16M   Flash
 *
 **********************************************************************/

#define SDRAM_BASE                      (0x00000000)
#define ETHERNET_CTRL_BASE              (0x08000300)
#define FLASH_BASE                      (0x50000000)


/**********************************************************************
 *  Interrupt Map
 **********************************************************************/

#define ETH_CTRL_INT                    (8)
#define PC104_BUS_INT	                (9)
#define USB_CTRL_INT	                (11)
#define SERIAL2_INT                     (21)
#define SERIAL1_INT                     (22)
#define TIMER0_INT                      (26)
#define TIMER1_INT                      (27)
#define TIMER2_INT                      (28)


/**********************************************************************
 *  Add-on Module GPIO Pin Controls for LEDs
 **********************************************************************/

#define LED_RED                     (0x00100000)
#define LED_YELLOW                  (0x00200000)
#define LED_GREEN                   (0x00400000)


/**********************************************************************
 *  Add-on Module GPIO Pin Controls for Buzzer
 **********************************************************************/

#define BUZZER                      (0x00800000)


/**********************************************************************
 *  Add-on Module Buttons
 **********************************************************************/
#define BUTTON_REG                  (*((uint32_t volatile *)0x14500000))
#define BUTTON_SW0                  (0x01)
#define BUTTON_SW1                  (0x02)
#define BUTTON_SW2                  (0x03)
#define BUTTON_SW3                  (0x08)


#endif /* _VIPERLITE_H */

