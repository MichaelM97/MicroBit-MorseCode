/**
 * File: transmission.h
 * Author: Michael McCormick
 * Date: 07-03-2018
 * Desc: Header file for transmission.cpp
 * Copyright: University of West of England 2018
 */

//Libraries
#include "MicroBit.h"

//Function prototypes
class transmission {
  public:
    void on_button_A_short(MicroBitEvent); //Handles dot output
    void on_button_A_long(MicroBitEvent); //Handles dash output

  private:
    //Used to access microbit functions
    MicroBit uBit;

    //Timings used for distinguishing between dot/dash transmissions
    int DOT_TIME = 250;
    int DASH_TIME = 500;

    //Images used for displaying dot/dash
    MicroBitImage DOT_IMAGE("0,0,0,0,0\n0,0,0,0,0\n0,0,255,0,0\n0,0,0,0,0\n0,0,0,0,0\n");
    MicroBitImage DASH_IMAGE("0,0,0,0,0\n0,0,0,0,0\n0,255,255,255,0\n0,0,0,0,0\n0,0,0,0,0\n");
}
