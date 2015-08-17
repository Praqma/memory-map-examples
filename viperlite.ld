/**********************************************************************
 *
 * Filename:    viperlite.ld
 * 
 * Description: GNU linker script file for Arcom board.
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

ENTRY (main)

MEMORY
{
    ram : ORIGIN = 0x00400000, LENGTH = 64M
    rom : ORIGIN = 0x60000000, LENGTH = 16M    /* Change to LENGTH = 32M for larger flash. */
}

SECTIONS
{
    .data :                              /* Initialized data. */ 
    { 
        _DataStart = . ; 
        *(.data) 
        _DataEnd   = . ;

    } >ram
     
    .bss :                               /* Uninitialized data. */
    { 
        _BssStart = . ;
        *(.bss) 
        _BssEnd   = . ;
    } >ram
     
    .text :                              /* The actual instructions. */
    { 
        *(.text) 
    } >ram
}

