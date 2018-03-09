/*

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
