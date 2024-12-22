:::mermaid
classDiagram
    class Pifometre {
       -lcd Ecran
       -keypad Keypad
       -capteur CapeteurDistance
       -guessOK bool
       -setguessOk()
       -resetguessOk()
       -getguessOk()
       +Pifometre()
       ~Pifometre()
       +run()
       +DistanceVSguess()
       +Start Screen()
    }

    class Ecran {
        -string lastMessage
        -string lastGuess
        -string lastPrompt
        -rgb_lcd display
        -void setLastMessage(string message)
        -void setLastGuess(string guess)
        -void setLastPrompt(string prompt)
        -const string getLastMessage()
        -const string getLastGuess()
        -const string getLastPrompt()
        +Ecran(uint8_t Xmessage, uint8_t Ymessage, uint8_t Xguess, uint8_t Yguess, uint8_t Xprompt, uint8_t Yprompt)
        +~Ecran()
        +void writeMessage(string message)
        +void writeGuess(string guess)
        +void writePrompt(string prompt)
        +void clearDisplay()
        +void clearMessage()
        +void clearGuess()
        +void clearPrompt()
        
    }

    class rgb_lcd {
        - I2C _i2c
  
        + rgb_lcd(PinName sda, PinName scl)
        + void begin(uint8_t cols, uint8_t rows, uint8_t charsize)
        + void clear()
        + void setCursor(uint8_t, uint8_t)
        + void print(const char* str)
        + void writeChar(char c)
        + void setRGB(uint8_t r, uint8_t g, uint8_t b)
    }
    class I2C ~mbed~{

    }

    class SerialUnbuffer ~mbed~ {
        +SerialUnbuffer(PinName_TX, PinName_RX)
        +read()
        +readable()
    }
    class Keypad{
        -UnbufferedSerial serialInput
        -char getChar()
        +Keypad(PinName TX, PinName RX)
        +uint16_t getGuess(string& guess)
    }
    class AnalogIN~mbed~{
        +AnalogIn(pinname)
        +read_u16()
    }
    class CapteurDistance{
        -capteur AnalogIn
        -distance uint16_t
        -setDistance()
        +CapteurDistance(Pinname)
        ~CapeteurDistance()
        +getDistance() uint16_t
        +readCapteur()

    }

    Pifometre *--  Ecran : contient
    Pifometre *--  CapteurDistance : contient
    Pifometre *--  Keypad : contient
    Ecran *-- rgb_lcd 
    rgb_lcd *-- I2C
    Keypad *-- SerialUnbuffer
    CapteurDistance *-- AnalogIN



:::
