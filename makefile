#######################################################################
#
# Filename:    makefile
# 
# Description: Makefile for Blinking LED program.
#
# Copyright (c) 2006 Anthony Massa and Michael Barr.  All rights reserved.
# This code is from the book Programming Embedded Systems, With C and
# GNU Development Tools, 2nd Edition.
# It is provided AS-IS, WITHOUT ANY WARRANTY either expressed or implied.
# You may study, use, and modify it for any non-commercial purpose,
# including teaching and use in open-source projects.
# You may distribute it non-commercially as long as you retain this notice.
# For a commercial use license, or to purchase the book,
# please visit http://www.oreilly.com/catalog/embsys2.
#
#######################################################################


XCC     = arm-none-eabi-gcc # Changed from 'arm-linux-gnueabi-gcc' to match docker container installation
LD      = arm-none-eabi-ld # Changed from 'arm-linux-gnueabi-ld'  to match docker container installation
CFLAGS  = -g -c -Wall \
          -I include
LDFLAGS = -Map blink.map -T viperlite.ld -N


all: blink

led.o: led.c led.h
	$(XCC) $(CFLAGS) led.c

blink.o: blink.c led.h
	$(XCC) $(CFLAGS) blink.c

blink: blink.o led.o viperlite.ld
	$(LD) $(LDFLAGS) -o $@ led.o blink.o

clean:
	-rm -f blink *.o blink.map
