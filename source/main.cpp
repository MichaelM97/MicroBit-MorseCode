/**
 * File: main.cpp
 * Author: Michael McCormick
 * Date: 08-03-2018
 * Desc: Basic transmission/recieving protocol for morse code sent across 2
 * microbits connected via wires. Implements a basic encryption cypher.
 * Copyright: University of West of England 2018
 */
#include "MicroBit.h"
//#include "reciever.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string>

//Used to access microbit
MicroBit uBit;

//Images used for displaying dot/dash
MicroBitImage DOT_IMAGE("0,0,0,0,0\n0,0,0,0,0\n0,0,255,0,0\n0,0,0,0,0\n0,0,0,0,0\n");
MicroBitImage DASH_IMAGE("0,0,0,0,0\n0,0,0,0,0\n0,255,255,255,0\n0,0,0,0,0\n0,0,0,0,0\n");

//Button events
MicroBitButton buttonA(MICROBIT_PIN_BUTTON_A, MICROBIT_ID_BUTTON_A);

//Pin events
MicroBitPin P2(MICROBIT_ID_IO_P2, MICROBIT_PIN_P2, PIN_CAPABILITY_ALL);

//Timings used for distinguishing between dot/dash transmissions
static const int DOT_TIME = 250;
static const int DASH_TIME = 500;

int main()
{
    //Initialise the micro:bit runtime.
    uBit.init();

    //Instances for classes
    //reciever r;

    //Variables
    bool buttonPressed = false;
    uint64_t runningTime, durationPressed;

    //Main infinite loop
    while (1) {

      //Update system up time
      runningTime = uBit.systemTime();

      //Wait for button input
      while (buttonA.isPressed()) {
        buttonPressed = true;
        durationPressed = uBit.systemTime() - runningTime;
      }

      //Process button press
      if (buttonPressed == true) {
        //DOT Output
        if ((durationPressed > 100) && (durationPressed < 400)) {
          uBit.display.printAsync(DOT_IMAGE);
          P2.setDigitalValue(1);
          uBit.sleep(DOT_TIME);
          P2.setDigitalValue(0);
          uBit.sleep(450); //Added sleep for diplaying image
          uBit.display.clear();
        }
        //DASH output
        else if ((durationPressed > 400) && (durationPressed < 900)) {
          uBit.display.printAsync(DASH_IMAGE);
          P2.setDigitalValue(1);
          uBit.sleep(DASH_TIME);
          P2.setDigitalValue(0);
          uBit.sleep(200); //Added sleep for diplaying image
          uBit.display.clear();
        }
        //NOISE
        else if (durationPressed > 900) {
          uBit.display.printAsync("?");
          uBit.sleep(700);
          uBit.display.clear();
        }


        buttonPressed = false;
      }
    }
/*

      //Wait for PIN signal



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


    }


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
