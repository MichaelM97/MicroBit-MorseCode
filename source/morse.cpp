/**
 * File: morse.cpp
 * Author: Michael McCormick
 * Date: 09-03-2018
 * Desc:
 * Copyright: University of West of England 2018
 */

#include "MicroBit.h"
#include "morse.h"

MorseClass::MorseClass() {
  //Constructor
}

char MorseClass::getLetter(string morseCode) {
  char returnVar = '?';
  mapItr = morseMap.find(morseCode);
  if (mapItr == morseMap.end()) {
      //If invalid input
  } else {
      returnVar = mapItr->second;
  }
  return returnVar;
}

string MorseClass::getMorse(char letter) {
  string returnVar = "?";
  for (mapItr = morseMap.begin(); mapItr != morseMap.end(); ++mapItr) {
    if (letter == mapItr->second) {
      returnVar = mapItr->first;
      break;
    }
  }
  return returnVar;
}

char MorseClass::encrypt(char letter) {
  char returnVar = '?';
  uint64_t iteratorPos;
  //Loop through map to find letter position
  for (mapItr = morseMap.begin(); mapItr != morseMap.end(); ++mapItr) {
    if (letter == mapItr->second) {
        //Cycle through map to find new position
        for (int i = 0; i < ENCRYPTION_KEY; i++) {
          ++mapItr;
          iteratorPos = std::distance(morseMap.begin(), mapItr);
          if (iteratorPos > morseMap.size()) {
            mapItr = morseMap.begin(); //Reset map iterator to begining if too large
          }
        }
        returnVar = mapItr->second;
      break;
    }
  }
  return returnVar;
}

char MorseClass::decrypt(char letter) {
  char returnVar = '?';
  uint64_t iteratorPos;
  //Loop through map to find letter position
  for (mapItr = morseMap.begin(); mapItr != morseMap.end(); ++mapItr) {
    if (letter == mapItr->second) {
        //Cycle through map to find new position
        for (int i = 0; i < ENCRYPTION_KEY; i++) {
          --mapItr;
          iteratorPos = std::distance(morseMap.begin(), mapItr);
          if (iteratorPos < morseMap.size()) {
            mapItr = morseMap.end(); //Reset map iterator to end if too small
          }
        }
        returnVar = mapItr->second;
      break;
    }
  }
  return returnVar;
}
