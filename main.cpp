#include "Pifometre.hpp"
#include "mbed.h"
#include "string.h"
#include "rgb_lcd.hpp"
#include "Keypad.hpp"
#include "CapteurDistance.hpp"

/////
int main(void)
{   
    DigitalIn bp(BUTTON1);
    Pifometre monPifometre;
    monPifometre.StartScreen();
    while (1) {
        
        if(bp==0){
            monPifometre.run();
            ThisThread::sleep_for(10s); 
            monPifometre.StartScreen();
        }
        
    }
   
}
/////*/



/*///////////////// TEST des class//////////////////////
int main() {
    // Initialize display with coordinates
    // Format: X,Y for message, guess, and prompt
    Ecran display(0, 0,  // Message coordinates
                  0, 1,  // Guess coordinates
                  8, 1); // Prompt coordinates
    
    // Initialize keypad with appropriate pins
    // Note: Replace KEYPAD_TX and KEYPAD_RX with your actual pin assignments
    Keypad keypad(PC_1, PC_0);  // Example pins, adjust as needed
    CapteurDistance capteur(A0);

    while (true) {
        printf("Starting display tests...\r\n");
        
        // Test 1: Basic Writing
        printf("Test 1: Basic Writing\r\n");
        display.writeMessage("Hello!");
        display.writeGuess("1234");
        display.writePrompt("Ready");
        ThisThread::sleep_for(2s);
        display.clearDisplay();
        ThisThread::sleep_for(2s);
        
        // Test 2: Message Clear
        printf("Test 2: Message Clear\r\n");
        display.writeMessage("Test Msg");
        display.writeGuess("5678");
        display.writePrompt("Clear");
        ThisThread::sleep_for(2s);
        display.clearMessage();
        ThisThread::sleep_for(2s);
        
        // Test 3: Guess Clear
        printf("Test 3: Guess Clear\r\n");
        display.writeMessage("New Msg");
        display.writeGuess("9012");
        display.writePrompt("Next");
        ThisThread::sleep_for(2s);
        display.clearGuess();
        ThisThread::sleep_for(2s);
        
        // Test 4: Prompt Clear
        printf("Test 4: Prompt Clear\r\n");
        display.writeMessage("Final");
        display.writeGuess("3456");
        display.writePrompt("Done");
        ThisThread::sleep_for(2s);
        display.clearPrompt();
        ThisThread::sleep_for(2s);
        
        
        // Test 5: Special Characters
        printf("Test 5: Special Characters\r\n");
        display.writeMessage("Test #1!");
        display.writeGuess("*123*");
        display.writePrompt("->OK<-");
        ThisThread::sleep_for(2s);
        display.clearDisplay();
        ThisThread::sleep_for(2s);
        
        // Test 6: Rapid Updates
        printf("Test 6: Rapid Updates\r\n");
        for(int i = 0; i < 5; i++) {
            display.writeGuess(std::to_string(i));
            ThisThread::sleep_for(500ms);
        }
        ThisThread::sleep_for(1s);
        display.clearDisplay();
        ThisThread::sleep_for(1s);
        
        // Test 7: Full Display Usage
        printf("Test 7: Full Display Usage\r\n");
        display.writeMessage("Status: OK");
        display.writeGuess("789");
        display.writePrompt("ENTER");
        ThisThread::sleep_for(2s);
        display.clearDisplay();
        ThisThread::sleep_for(2s);   
       
        
        ThisThread::sleep_for(1s);




        printf("Please enter a number on the keypad (end with #):\r\n");
        std::string input = "";
        // Initialize with empty character to enter while loop
        input.append(1, ' ');
        
        capteur.readCapteur();
        printf("Distance mesure: %d cm\r\n", capteur.getDistance());
        




        int16_t number = keypad.getGuess(input);
        printf("Received number: %d\r\n", number);
        printf("Raw input string: %s\r\n", input.c_str());






   
    
        
    }
}
//////////////////////////////////////////////*/