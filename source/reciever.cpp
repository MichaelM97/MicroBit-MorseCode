/**
 * File: reciever.cpp
 * Author: Michael McCormick
 * Date: 07-03-2018
 * Desc: Basic recieving protocol for morse code sent across 2
 * microbits connected via wires
 * Copyright: University of West of England 2018
 */

#include "reciever.h"

char decode_morse(int durationPressed) {
  if (durationPressed > 1200) {
    //Then it is noise
  } else if (durationPressed < DOT_TIME + 20) {
    return '.';
  } else if (durationPressed < DASH_TIME + 20) {
    return '-';
  }
}

char map_morse(std::string inputBuffer) {
  mapPos = MORSE_MAP.find(inputBuffer);
  if (mapPos == MORSE_MAP.end()) { //If invalid input
      return '?';
  } else {
      return mapPos->second;
  }
}
