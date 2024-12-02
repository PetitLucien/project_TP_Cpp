#include "Keypad.hpp"

Keypad::Keypad(PinName TX, PinName RX)
    : serialInput(TX, RX)
{
    // Additional initialization if needed
}

bool Keypad::getGuess(char* guess) {
    // Implement guess retrieval logic
    // This is a placeholder - you'll need to add actual implementation
    return serialInput.readable();
}