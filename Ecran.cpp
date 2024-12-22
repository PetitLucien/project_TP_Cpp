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
    display.setRGB(0,0,255); // set back coler to blue
    display.clear(); 
}

Ecran::~Ecran() {
    // Cleanup if needed
}

void Ecran::writeMessage(string message) {
    int8_t diff{0};
    diff=getLastMessage().size()-message.size();
    Ecran::setLastMessage(message);
    if(diff>0){
        message.append(diff,' ');
    }
       
    display.setCursor(coordMessage[0], coordMessage[1]);
    display.print(message.c_str());
}

void Ecran::writeGuess(string guess) {

    int8_t diff{0};
    diff=getLastGuess().size()-guess.size();
    Ecran::setLastGuess(guess);
    if(diff>0){
        guess.append(diff,' ');
    }

    display.setCursor(coordGuess[0], coordGuess[1]);
    display.print(guess.c_str());
}

void Ecran::writePrompt(string prompt) {
    int8_t diff{0};
    diff=getLastPrompt().size()-prompt.size();
    Ecran::setLastPrompt(prompt);
    if(diff>0){
        prompt.append(diff,' ');
    }
    display.setCursor(coordPrompt[0], coordPrompt[1]);
    display.print(prompt.c_str());
}

void Ecran::clearDisplay() {
    display.clear();  
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