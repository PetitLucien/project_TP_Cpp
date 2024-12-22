#include "Keypad.hpp"



char Keypad::getChar(){
    char c{0};
    if (serialInput.read(&c, 1)) {
        // Echo the input back to the terminal.
       // pc.write(&guess, guess.size());
        switch(c) {
                case 0xE1 :
                    return '1';
                    break;
                case 0xE2 :
                    return '2';
                    break;
                case 0xE3 :
                    return '3';
                    break;
                case 0xE4 :
                    return '4';
                    break;
                case 0xE5 :
                    return '5';
                    break;
                case 0xE6 :
                    return '6';
                    break;
                case 0xE7 :
                    return '7';
                    break;
                case 0xE8 :
                    return '8';
                    break;
                case 0xE9 :
                    return '9';
                    break;
                /*case 0xEA :
                    return '*';
                    break;*/
                case 0xEB :
                    return '0';
                    break;
                case 0xEC :
                    return '#';
                    break;
                default:
                c='#';
                    break;
            }
    }

    return c;
}

uint16_t Keypad::getGuess(std::string &guess) {
    
    while (guess[guess.size()-1]!='#') {
        if (serialInput.readable()) {
            guess.append(1,this->getChar());
        }
    }
    guess.pop_back();
    if(guess.size()==1){guess.append(1,'0');}

    return std::stoi( guess );
    
}