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
    bool buttonPressed = false, incomingSignal = false;
    uint64_t runningTime, durationPressed, waiting = 0;
    string transmissionBuffer;
    char letter;

    //Main infinite loop
    while (1) {

      //Update system up time
      runningTime = uBit.systemTime();

      /** HANDLE MORSE TRANSMISSION **/
      //Wait for button input
      while (buttonA.isPressed()) {
        buttonPressed = true;
      }

      //Get the button input duration
      durationPressed = uBit.systemTime() - runningTime;

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
        else if ((durationPressed > 400) && (durationPressed < 800)) {
          uBit.display.printAsync(DASH_IMAGE);
          transmissionBuffer += '-';
          uBit.sleep(700);
          uBit.display.clear();
        }
        //NOISE
        else if (durationPressed > 800) {
          uBit.display.printAsync("!");
          uBit.sleep(700);
          uBit.display.clear();
        }
        //Reset variables to allow for new inputs
        buttonPressed = false;
        waiting = uBit.systemTime();
        //Update system up time
        runningTime = uBit.systemTime();
      }

      //Input is finished if wait time met
      if (((runningTime - waiting) > 2000) && (waiting != 0)) {
        //Get letter associated with morse input
        letter = morse->getLetter(transmissionBuffer);
        if (letter != '?') { //Only if valid morse found
          //Encrypt letter with Caeser cipher
          letter = morse->encrypt(letter);
          //Get morse code for new encrypted letter
          transmissionBuffer = morse->getMorse(letter);
          //Send morse code
          sendTransmission(transmissionBuffer);
          uBit.display.printAsync(">");
          uBit.sleep(700);
          uBit.display.clear();
        } else {
          uBit.display.printAsync("?");
          uBit.sleep(700);
          uBit.display.clear();
        }
        //Reset variables to allow for new transmissions
        transmissionBuffer.clear();
        waiting = 0;
      }

      /** HANDLE INCOMING MORSE **/
      //Wait for signal from Pin 1
      while (P1.getDigitalValue() == 1) {
        incomingSignal = true;
      }

      //Get the incoming signal duration
      durationPressed = uBit.systemTime() - runningTime;

      //Process incoming signal
      if (incomingSignal == true) {
        //DOT input
        if ((durationPressed > 100) && (durationPressed < 400)) {
          transmissionBuffer += '.';
        }
        //DASH input
        else if ((durationPressed > 400) && (durationPressed < 800)) {
          transmissionBuffer += '-';
        }
        //NOISE
        else if (durationPressed > 800) {
          uBit.display.printAsync("!");
          uBit.sleep(700);
          uBit.display.clear();
        }
        //Reset variables to allow for new incoming signals
        incomingSignal = false;
        waiting = uBit.systemTime();
        //Update system up time
        runningTime = uBit.systemTime();
      }

      //Incoming signal is finished if wait time met
      if (((runningTime - waiting) > 2000) && (waiting != 0)) {
        //Get letter associated with morse signal
        letter = morse->getLetter(transmissionBuffer);
        if (letter != '?') { //Only if valid morse found
          //Decrypt letter with Caeser cipher
          letter = morse->decrypt(letter);
        }
        //Display letter to user
        uBit.display.printAsync(letter);
        uBit.sleep(700);
        uBit.display.clear();
        //Reset variables to allow for new transmissions
        transmissionBuffer.clear();
        waiting = 0;
      }

    }

    //Delete class instances and go into power efficient sleep
    delete morse;
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
