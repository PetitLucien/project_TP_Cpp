#ifndef KEYPAD_HPP
#define KEYPAD_HPP

#include "mbed.h"
#include <cstdint>
#include <string>

class Keypad {
private:
    UnbufferedSerial serialInput;
    char getChar();
    
public:
    Keypad(PinName TX, PinName RX):serialInput(TX,RX){} ;
    
    
    int16_t getGuess(std::string &guess);



};

#endif // KEYPAD_HPP