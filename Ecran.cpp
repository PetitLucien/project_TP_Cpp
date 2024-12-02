#include "Ecran.hpp"

Ecran::Ecran(uint8_t Xmessage, uint8_t Ymessage, 
             uint8_t Xguess, uint8_t Yguess, 
             uint8_t Xprompt, uint8_t Yprompt)
    : display(PinName::P0_3, PinName::P0_4)  // Example I2C pins, replace as needed
{
    coordMessage[0] = Xmessage;
    coordMessage[1] = Ymessage;
    coordGuess[0] = Xguess;
    coordGuess[1] = Yguess;
    coordPrompt[0] = Xprompt;
    coordPrompt[1] = Yprompt;

    // Initialize display
    display.begin(16, 2);  // Example 16x2 LCD, adjust as needed
}

Ecran::~Ecran() {
    // Cleanup if needed
}

void Ecran::writeMessage(char* message) {
    display.setCursor(coordMessage[0], coordMessage[1]);
    display.print(message);
}

void Ecran::writeGuess(char* guess) {
    display.setCursor(coordGuess[0], coordGuess[1]);
    display.print(guess);
}

void Ecran::writePrompt(char* prompt) {
    display.setCursor(coordPrompt[0], coordPrompt[1]);
    display.print(prompt);
}