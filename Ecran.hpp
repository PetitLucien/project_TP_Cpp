#ifndef ECRAN_HPP
#define ECRAN_HPP

#include "rgb_lcd.hpp"

class Ecran {
public:
    Ecran(uint8_t Xmessage, uint8_t Ymessage, 
          uint8_t Xguess, uint8_t Yguess, 
          uint8_t Xprompt, uint8_t Yprompt);
    ~Ecran();

    void writeMessage(char* message);
    void writeGuess(char* guess);
    void writePrompt(char* prompt);

private:
    uint8_t coordMessage[2];
    uint8_t coordGuess[2];
    uint8_t coordPrompt[2];
    
    rgb_lcd display;
};

#endif // ECRAN_HPP