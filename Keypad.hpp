#ifndef KEYPAD_HPP
#define KEYPAD_HPP

#include "mbed.h"
#include <cstdint>

class Keypad {
private:
    UnbufferedSerial serialInput;
public:
    Keypad(PinName TX, PinName RX):serialInput(TX,RX){} ;
    
    uint16_t getGuess(char* guess);


};

#endif // KEYPAD_HPP