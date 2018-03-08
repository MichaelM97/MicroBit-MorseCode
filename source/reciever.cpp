/**
 * File: reciever.cpp
 * Author: Michael McCormick
 * Date: 08-03-2018
 * Desc: Basic recieving protocol for morse code sent across 2
 * microbits connected via wires
 * Copyright: University of West of England 2018
 */
/*
#include "reciever.h"

//Used to access microbit functions
MicroBit uBit;

//Timings used for distinguishing between incoming dots/dashs
int DOT_TIME = 250;
int DASH_TIME = 500;

//Used for mapping morsecode to letters
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

//Iterator used to find elements in map
std::map<std::string, char>::iterator mapPos;

char decode_morse(int durationPressed) {
  char returnVar = '?';
  if (durationPressed > 1200) {
    //Then it is noise
  } else if (durationPressed < DOT_TIME + 20) {
    returnVar = '.';
  } else if (durationPressed < DASH_TIME + 20) {
    returnVar = '-';
  }
  return returnVar;
}

char map_morse(std::string inputBuffer) {
  char returnVar = '?';
  mapPos = MORSE_MAP.find(inputBuffer);
  if (mapPos == MORSE_MAP.end()) {
      //If invalid input
  } else {
      returnVar = mapPos->second;
  }
  return returnVar;
}
*/
