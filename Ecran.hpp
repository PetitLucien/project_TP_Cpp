#ifndef ECRAN_HPP
#define ECRAN_HPP

#include "rgb_lcd.hpp"
#include "string"

class Ecran {
private:
    uint8_t coordMessage[2];
    uint8_t coordGuess[2];
    uint8_t coordPrompt[2];
    string lastMessage;
    string lastGuess;
    string lastPrompt;
    rgb_lcd display;
    void setLastMessage(string message){this->lastMessage=message;};
    void setLastGuess(string guess){this->lastGuess=guess;};
    void setLastPrompt(string prompt){this->lastPrompt=prompt;};
    string getLastMessage(){return this->lastMessage;};
    string getLastGuess(){return this->lastGuess;};
    string getLastPrompt(){return this->lastPrompt;};
    
public:
    Ecran(uint8_t Xmessage, uint8_t Ymessage, 
          uint8_t Xguess, uint8_t Yguess, 
          uint8_t Xprompt, uint8_t Yprompt);
    ~Ecran();

    void writeMessage(string message);
    void writeGuess(string guess);
    void writePrompt(string prompt);
    void clearDisplay();
    void clearMessage();
    void clearGuess();
    void clearPrompt();
};

#endif // ECRAN_HPP