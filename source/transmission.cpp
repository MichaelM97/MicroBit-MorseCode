/**
 * File: transmission.cpp
 * Author: Michael McCormick
 * Date: 07-03-2018
 * Desc: Transmission protocol for morse code sent across 2
 * microbits connected via wires
 * Copyright: University of West of England 2018
 */

#include "transmission.h"

void transmission::_button_A_short(MicroBitEvent) {
	uBit.display.printAsync(DOT_IMAGE);
  MicroBitPin P1(MICROBIT_ID_IO_P1, MICROBIT_PIN_P1, PIN_CAPABILITY_ALL);
  uBit.io.P1.setDigitalValue(1);
  uBit.sleep(DOT_TIME);
  uBit.io.P1.setDigitalValue(0);
  uBit.sleep(300); //Added sleep for diplaying image
  uBit.display.clear();
}

void transmission::on_button_A_long(MicroBitEvent) {
	uBit.display.printAsync(DASH_IMAGE);
  MicroBitPin P1(MICROBIT_ID_IO_P1, MICROBIT_PIN_P1, PIN_CAPABILITY_ALL);
  uBit.io.P1.setDigitalValue(1);
  uBit.sleep(DASH_TIME);
  uBit.io.P1.setDigitalValue(0);
  uBit.sleep(50); //Added sleep for diplaying image
  uBit.display.clear();
}
