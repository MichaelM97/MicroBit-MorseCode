/**
 * File: reciever.cpp
 * Author: Michael McCormick
 * Date: 07-03-2018
 * Desc: Basic recieving protocol for morse code sent across 2
 * microbits connected via wires
 * Copyright: University of West of England 2018
 */

//Libraries
#include "MicroBit.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string>
#include <map>

//Function prototypes
class reciever {
  public:
    char decode_morse(int durationPressed); //Returns dot or dash depending on input length
    char map_morse(std::string inputBuffer); //Returns letter mapped to morse input

  private:
    //Used to access microbit functions
    MicroBit uBit;

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
}
