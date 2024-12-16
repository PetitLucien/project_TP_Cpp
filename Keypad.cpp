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
                    return '2';
                    break;
                case 0xE4 :
                    return '2';
                    break;
                case 0xE5 :
                    return '2';
                    break;
                case 0xE6 :
                    return '2';
                    break;
                case 0xE7 :
                    return '2';
                    break;
                case 0xE8 :
                    return '2';
                    break;
                case 0xE9 :
                    return '2';
                    break;
                case 0xEA :
                    return '*';
                    break;
                case 0xEB :
                    return '0';
                    break;
                case 0xEC :
                    return '#';
                    break;
                default:
                c=0x00;
                    break;
            }
    }

    return c;
}

int16_t Keypad::getGuess(std::string &guess) {
    
    // Read the data to clear the receive interrupt.

    while (guess[guess.size()-1]!='#') {
        if (serialInput.readable()) {
            guess.append(1,this->getChar());
        }
    }
    guess.pop_back();
    return std::stoi( guess );
    
}