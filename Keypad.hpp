#ifndef KEYPAD_HPP
#define KEYPAD_HPP

#include "SerialUnbuffer.h"

class Keypad {
public:
    Keypad(PinName TX, PinName RX);
    
    bool getGuess(char* guess);

private:
    SerialUnbuffer serialInput;
};

#endif // KEYPAD_HPP