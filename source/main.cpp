/**
 * File: main.cpp
 * Author: Michael McCormick
 * Date: 09-03-2018
 * Desc: Basic transmission/recieving protocol for morse code sent across 2
 * microbits connected via wires. Implements a basic encryption cypher.
 * Copyright: University of West of England 2018
 */
#include "MicroBit.h"
#include "morse.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string>

//Timings used for distinguishing between dot/dash transmissions
#define DOT_TIME 250
#define DASH_TIME 500

using namespace std;

/* Sends the passed morse code transmission (not in morse class as there
were issues with handling pin events) */
void sendTransmission(string transmissionBuffer);

//Used to access microbit
MicroBit uBit;

//Images used for displaying dot/dash
MicroBitImage DOT_IMAGE("0,0,0,0,0\n0,0,0,0,0\n0,0,255,0,0\n0,0,0,0,0\n0,0,0,0,0\n");
MicroBitImage DASH_IMAGE("0,0,0,0,0\n0,0,0,0,0\n0,255,255,255,0\n0,0,0,0,0\n0,0,0,0,0\n");

//Button events
MicroBitButton buttonA(MICROBIT_PIN_BUTTON_A, MICROBIT_ID_BUTTON_A);

//Pin events
MicroBitPin P1(MICROBIT_ID_IO_P1, MICROBIT_PIN_P1, PIN_CAPABILITY_ALL);

int main()
{
    //Initialise the micro:bit runtime.
    uBit.init();

    //Create instance of class
    MorseClass* morse = new MorseClass();

    //Variables
    bool buttonPressed = false;
    uint64_t runningTime, durationPressed, startWaiting, waitingTime;
    string transmissionBuffer;
    char letter;

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
          transmissionBuffer += '.';
          uBit.sleep(700);
          uBit.display.clear();
        }
        //DASH output
        else if ((durationPressed > 400) && (durationPressed < 900)) {
          uBit.display.printAsync(DASH_IMAGE);
          transmissionBuffer += '-';
          uBit.sleep(700);
          uBit.display.clear();
        }
        //NOISE
        else if (durationPressed > 900) {
          uBit.display.printAsync("?");
          uBit.sleep(700);
          uBit.display.clear();
        }
        startWaiting = uBit.systemTime();
        buttonPressed = false;
      }

      //Update time since last input
      waitingTime = runningTime - startWaiting;

      //Input is finished if wait time met
      if ((waitingTime > 1500) && (startWaiting != 0)) {
        //Get letter associated with morse input
        letter = morse->getLetter(transmissionBuffer);
        //Encrypt letter with Caeser cipher
        letter = morse->encrypt(letter);
        //Get morse code for new encrypted letter
        transmissionBuffer = morse->getMorse(letter);
        //Send morse code
        sendTransmission(transmissionBuffer);

        //NEED TO GET LETTER FROM MAP, THEN CIPHER, THEN REVERSE TO MORSE AND SEND

        //Reset variables to allow for new transmissions
        transmissionBuffer.clear();
        startWaiting = 0;
      }




    }


    // If main exits, there may still be other fibers running or
    // registered event handlers etc.
    // Simply release this fiber, which will mean we enter the
    // scheduler. Worse case, we then
    // sit in the idle task forever, in a power efficient sleep.
    release_fiber();
}

void sendTransmission(string transmissionBuffer) {
  //Store dots/dashes to be processed seperatley
  int transmissionLength = transmissionBuffer.length();
  char transmissionArray[transmissionLength + 1];
  strcpy(transmissionArray, transmissionBuffer.c_str());

  //Send morse code across wire attached to pin 1
  for (int i = 0; i < transmissionLength; i++) {
    if (transmissionArray[i] == '.') {
      P1.setDigitalValue(1);
      uBit.sleep(DOT_TIME);
      P1.setDigitalValue(0);
    } else if (transmissionArray[i] == '-') {
      P1.setDigitalValue(1);
      uBit.sleep(DASH_TIME);
      P1.setDigitalValue(0);
    }
  }
}
