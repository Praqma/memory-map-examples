/**********************************************************************
 *
 * Filename:    pxa255.h
 * 
 * Description: Header file for Intel PXA255 XScale ARM processor.
 *
 * Notes:       This file is specific to the Intel PXA255 XScale
 *              ARM processor.
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

#ifndef _PXA255_H
#define _PXA255_H


/********************************************************
 * Intel PXA255 XScale ARM Processor On-Chip Peripherals
 ********************************************************/

/* Timer Registers */
#define TIMER_0_MATCH_REG           (*((uint32_t volatile *)0x40A00000))
#define TIMER_1_MATCH_REG           (*((uint32_t volatile *)0x40A00004))
#define TIMER_2_MATCH_REG           (*((uint32_t volatile *)0x40A00008))
#define TIMER_3_MATCH_REG           (*((uint32_t volatile *)0x40A0000C))
#define TIMER_COUNT_REG             (*((uint32_t volatile *)0x40A00010))
#define TIMER_STATUS_REG            (*((uint32_t volatile *)0x40A00014))
#define TIMER_INT_ENABLE_REG        (*((uint32_t volatile *)0x40A0001C))

/* Timer Interrupt Enable Register Bit Descriptions */
#define TIMER_0_INTEN               (0x01)
#define TIMER_1_INTEN               (0x02)
#define TIMER_2_INTEN               (0x04)
#define TIMER_3_INTEN               (0x08)

/* Timer Status Register Bit Descriptions */
#define TIMER_0_MATCH               (0x01)
#define TIMER_1_MATCH               (0x02)
#define TIMER_2_MATCH               (0x04)
#define TIMER_3_MATCH               (0x08)

/* Interrupt Controller Registers */
#define INTERRUPT_PENDING_REG       (*((uint32_t volatile *)0x40D00000))
#define INTERRUPT_ENABLE_REG        (*((uint32_t volatile *)0x40D00004))
#define INTERRUPT_TYPE_REG          (*((uint32_t volatile *)0x40D00008))

/* Interrupt Enable Register Bit Descriptions */
#define GPIO_0_ENABLE               (0x00000100)
#define UART_ENABLE                 (0x00400000)
#define TIMER_0_ENABLE              (0x04000000)
#define TIMER_1_ENABLE              (0x08000000)
#define TIMER_2_ENABLE              (0x10000000)
#define TIMER_3_ENABLE              (0x20000000)

/* General Purpose I/O (GPIO) Registers */
#define GPIO_0_LEVEL_REG            (*((uint32_t volatile *)0x40E00000))
#define GPIO_1_LEVEL_REG            (*((uint32_t volatile *)0x40E00004))
#define GPIO_2_LEVEL_REG            (*((uint32_t volatile *)0x40E00008))
#define GPIO_0_DIRECTION_REG        (*((uint32_t volatile *)0x40E0000C))
#define GPIO_1_DIRECTION_REG        (*((uint32_t volatile *)0x40E00010))
#define GPIO_2_DIRECTION_REG        (*((uint32_t volatile *)0x40E00014))
#define GPIO_0_SET_REG              (*((uint32_t volatile *)0x40E00018))
#define GPIO_1_SET_REG              (*((uint32_t volatile *)0x40E0001C))
#define GPIO_2_SET_REG              (*((uint32_t volatile *)0x40E00020))
#define GPIO_0_CLEAR_REG            (*((uint32_t volatile *)0x40E00024))
#define GPIO_1_CLEAR_REG            (*((uint32_t volatile *)0x40E00028))
#define GPIO_2_CLEAR_REG            (*((uint32_t volatile *)0x40E0002C))
#define GPIO_0_FUNC_LO_REG          (*((uint32_t volatile *)0x40E00054))
#define GPIO_0_FUNC_HI_REG          (*((uint32_t volatile *)0x40E00058))


/* UART Interrupt Enable Register Bit Descriptions */
#define UART_PORT_ENABLE            (0x40)

/* UART Config Register (LCR) Bit Descriptions */
#define DATABITS_LENGTH_0           (0x01)
#define DATABITS_LENGTH_1           (0x02)
#define STOP_BITS                   (0x04)
#define PARITY_ENABLE               (0x08)
#define EVEN_PARITY_ENABLE          (0x10)
#define DIVISOR_ACCESS_ENABLE       (0x80)


/* Information on the instruction and data caches can be found in the
 * Intel XScale Core Developer's Manual. */
#define DCACHE_ENABLE()                                                         \
    asm volatile (                                                              \
        "mcr p15, 0, r0, c7, c10, 4;"   /* Drain pending data operations. */    \
        "mcr p15, 0, r0, c1, c0, 0;"    /* Get current control register. */     \
        "orr r0, r0, #5;"               /* Set bit 2 and 0 (bits C and M). */   \
        "mcr p15, 0, r0, c1, c0, 0;"    /* Update the control register. */      \
        :                               /* Output. */                           \
        :                               /* Input. */                            \
        : "r0"                          /* Clobbers. */                         \
        );

#define ICACHE_ENABLE()                                                         \
    asm volatile (                                                              \
        "mcr p15, 0, r0, c1, c0, 0;"    /* Get the control register. */         \
        "orr r0, r0, #0x1000;"          /* Set bit 12 (bit I). */               \
        "mcr p15, 0, r0, c1, c0, 0;"    /* Set the control register. */         \
        :                               /* Output. */                           \
        :                               /* Input. */                            \
        : "r0"                          /* Clobbers. */                         \
        );


#endif /* _PXA255_H */

