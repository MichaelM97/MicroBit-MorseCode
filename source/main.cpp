/**
 * File: main.cpp
 * Author: Michael McCormick
 * Date: 07-03-2018
 * Desc: Basic transmission/recieving protocol for morse code sent across 2
 * microbits connected via wires. Implements a basic encryption cypher.
 * Copyright: University of West of England 2018
 */
#include "MicroBit.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string>
#include <map>

MicroBit uBit;

//Global variables
std::string inputBuffer = "";
int DOT_TIME = 250;
int DASH_TIME = 500;

//Global Images
MicroBitImage DOT_IMAGE("0,0,0,0,0\n0,0,0,0,0\n0,0,255,0,0\n0,0,0,0,0\n0,0,0,0,0\n");
MicroBitImage DASH_IMAGE("0,0,0,0,0\n0,0,0,0,0\n0,255,255,255,0\n0,0,0,0,0\n0,0,0,0,0\n");

//Global map
std::map<std::string, char> MORSE_MAP = {
   {".-", 'A'},
   {"-...", 'B'},
   {"-.-.", 'C'},
   {"-..", 'D'},
   {".", 'E'},
   {"..-.", 'F'},
   {"--.", 'G'},
   {"....", 'H'},
   {"..", 'I'},
   {".---", 'J'},
   {"-.-", 'K'},
   {".-..", 'L'},
   {"--", 'M'},
   {"-.", 'N'},
   {"---", 'O'},
   {".--.", 'P'},
   {"--.-", 'Q'},
   {".-.", 'R'},
   {"...", 'S'},
   {"-", 'T'},
   {"..-", 'U'},
   {"...-", 'V'},
   {".--", 'W'},
   {"-..-", 'X'},
   {"-.--", 'Y'},
   {"--..", 'Z'},
   {".----", '1'},
   {"..---", '2'},
   {"...--", '3'},
   {"....-", '4'},
   {"-....", '6'},
   {".....", '5'},
   {"--...", '7'},
   {"---..", '8'},
   {"----.", '9'},
   {"-----", '0'}
};
std::map<std::string, char>::iterator mapPos;

//On short button press, send DOT signal
void on_button_A_short(MicroBitEvent) {
	uBit.display.printAsync(DOT_IMAGE);
  MicroBitPin P1(MICROBIT_ID_IO_P1, MICROBIT_PIN_P1, PIN_CAPABILITY_ALL);
  P1.setDigitalValue(1);
  uBit.sleep(DOT_TIME);
  P1.setDigitalValue(0);
  uBit.sleep(300); //Added sleep for diplaying image
  uBit.display.clear();
}

//On long button press, send DASH signal
void on_button_A_long(MicroBitEvent) {
	uBit.display.printAsync(DASH_IMAGE);
  MicroBitPin P1(MICROBIT_ID_IO_P1, MICROBIT_PIN_P1, PIN_CAPABILITY_ALL);
  P1.setDigitalValue(1);
  uBit.sleep(DASH_TIME);
  P1.setDigitalValue(0);
  uBit.sleep(50); //Added sleep for diplaying image
  uBit.display.clear();
}

int main()
{
    //Initialise the micro:bit runtime.
    uBit.init();

    //Listen for button presses
		uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_CLICK, on_button_A_short);
		uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_LONG_CLICK, on_button_A_long);
    uBit.sleep(10);

    //Wait for input
    int startTime = (int)uBit.systemTime();
    int pressedTime = 0;
    int durationPressed = 0;
    while (1) {
      //Get pin 2 input length
      pressedTime = 0;
      MicroBitPin P2(MICROBIT_ID_IO_P2, MICROBIT_PIN_P2, PIN_CAPABILITY_ALL);
      while (P2.getDigitalValue() == 1) {
        if (pressedTime == 0) {
          pressedTime = (int)uBit.systemTime();
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
      }

      //If the input has ended
      if ((inputBuffer.length() > 0) && (uBit.systemTime() - startTime > 1200)){
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
  }

    // If main exits, there may still be other fibers running or
    // registered event handlers etc.
    // Simply release this fiber, which will mean we enter the
    // scheduler. Worse case, we then
    // sit in the idle task forever, in a power efficient sleep.
    release_fiber();
}
