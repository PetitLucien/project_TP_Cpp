#include "Ecran.hpp"

Ecran::Ecran(uint8_t Xmessage, uint8_t Ymessage, 
             uint8_t Xguess, uint8_t Yguess, 
             uint8_t Xprompt, uint8_t Yprompt)
    : display(PB_9, PB_8)  // Example I2C pins, replace as needed
{
    coordMessage[0] = Xmessage;
    coordMessage[1] = Ymessage;
    coordGuess[0] = Xguess;
    coordGuess[1] = Yguess;
    coordPrompt[0] = Xprompt;
    coordPrompt[1] = Yprompt;

    // Initialize display
    display.begin(16, 2);  
}

Ecran::~Ecran() {
    // Cleanup if needed
}

void Ecran::writeMessage(string message) {
    Ecran::setLastMessage(message);
    display.setCursor(coordMessage[0], coordMessage[1]);
    display.print(message);
}

void Ecran::writeGuess(string guess) {
    Ecran::setLastGuess(guess);
    display.setCursor(coordGuess[0], coordGuess[1]);
    display.print(guess);
}

void Ecran::writePrompt(string prompt) {
    Ecran::setLastPrompt(prompt);
    display.setCursor(coordPrompt[0], coordPrompt[1]);
    display.print(prompt);
}

void Ecran::clearDisplay() {
    display.clear();  // Assumes the rgb_lcd class has a clear() method
}

void Ecran::clearMessage() {
    display.clear();
    Ecran::writeGuess(getLastGuess());
    Ecran::writePrompt(getLastPrompt());
}

void Ecran::clearGuess() {
   display.clear();
    Ecran::writeMessage(getLastMessage());
    Ecran::writePrompt(getLastPrompt());
}

void Ecran::clearPrompt() {
    display.clear();
    Ecran::writeGuess(getLastGuess());
    Ecran::writeMessage(getLastMessage());
}