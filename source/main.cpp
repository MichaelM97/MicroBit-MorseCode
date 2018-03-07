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
MicroBitImage dot("0,0,0,0,0\n0,0,0,0,0\n0,0,255,0,0\n0,0,0,0,0\n0,0,0,0,0\n");

MicroBitImage dash("0,0,0,0,0\n0,0,0,0,0\n0,255,255,255,0\n0,0,0,0,0\n0,0,0,0,0\n");

std::map<std::string, char> morseCodeMap = {
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

//On short button press (dot)
void on_button_A_short(MicroBitEvent) {
	uBit.display.printAsync(dot);
  uBit.sleep(500);
  uBit.display.clear();
}

//On long button press (dash)
void on_button_A_long(MicroBitEvent) {
	uBit.display.printAsync(dash);
  uBit.sleep(500);
  uBit.display.clear();
}

int main()
{
    //Initialise the micro:bit runtime.
    uBit.init();

    //Listen for button presses
		uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_CLICK, on_button_A_short);
		uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_LONG_CLICK, on_button_A_long);
		uBit.sleep(100);



    // If main exits, there may still be other fibers running or
    // registered event handlers etc.
    // Simply release this fiber, which will mean we enter the
    // scheduler. Worse case, we then
    // sit in the idle task forever, in a power efficient sleep.
    release_fiber();
}
