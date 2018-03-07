/**
 * File: main.cpp
 * Author: Michael McCormick
 * Date: 05-02-2018
 * Desc: Basic game that displays randomly generated input sequence
 * and gets user to repeat the same sequence.
 * Copyright: University of West of England 2017
 */
#include "MicroBit.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string>

MicroBit uBit;

int main()
{
    //Initialise the micro:bit runtime.
    uBit.init();

    uBit.display.scroll("Hello World!");

    // If main exits, there may still be other fibers running or
    // registered event handlers etc.
    // Simply release this fiber, which will mean we enter the
    // scheduler. Worse case, we then
    // sit in the idle task forever, in a power efficient sleep.
    release_fiber();
}
