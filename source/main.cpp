/**
 * File: main.cpp
 * Author: Michael McCormick
 * Date: 07-03-2018
 * Desc: Basic transmission/recieving protocol for morse code sent across 2
 * microbits connected via wires. Implements a basic encryption cypher.
 * Copyright: University of West of England 2018
 */
#include "MicroBit.h"
#include "transmission.h"
#include "reciever.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string>

//Used to access microbit
MicroBit uBit;

int main()
{
    //Initialise the micro:bit runtime.
    uBit.init();

    //Instances for classes
    transmission t;
    reciever r;

    //Listen for button presses
		uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_CLICK, t.on_button_A_short);
		uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_LONG_CLICK, t.on_button_A_long);

/*
    //Wait for input
    int startTime = (int)uBit.systemTime();
    int pressedTime = 0;
    int durationPressed = 0;

    //Get pin 2 input length
    pressedTime = 0;
    MicroBitPin P2(MICROBIT_ID_IO_P2, MICROBIT_PIN_P2, PIN_CAPABILITY_ALL);
    while (P2.getDigitalValue == 1) {
      if (pressedTime == 0) {
        pressedTime = (int)uBit.systemTime();
        uBit.display.print("1");
      }
    }
    durationPressed = (int)uBit.systemTime() - pressedTime;
    uBit.sleep(10);

    //If there has been an input, add to buffer
    if (pressedTime != 0) {
      if (durationPressed > 1200) {
        //Then it is noise
      } else if (durationPressed < DOT_TIME + 20) {
        inputBuffer += '.';
      } else if (durationPressed < DASH_TIME + 20) {
        inputBuffer += '-';
      }
      pressedTime = 0;
      startTime = (int)uBit.systemTime();
      uBit.display.print("2");
    }

    //If the input has ended
    if ((inputBuffer.length() > 0) && (uBit.systemTime() - startTime > 1200)){
      uBit.display.print("3");
      mapPos = MORSE_MAP.find(inputBuffer);
      if (mapPos == MORSE_MAP.end()) { //If invalid input
          uBit.display.print("?");
          uBit.sleep(700);
          uBit.display.clear();
      } else {
          uBit.display.print(mapPos->second);
          uBit.sleep(700);
          uBit.display.clear();
      }
    }
*/

    // If main exits, there may still be other fibers running or
    // registered event handlers etc.
    // Simply release this fiber, which will mean we enter the
    // scheduler. Worse case, we then
    // sit in the idle task forever, in a power efficient sleep.
    release_fiber();
}
