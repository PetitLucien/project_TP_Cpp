:::mermaid
classDiagram
    class Pifometre {
       
    }

    class Ecran {
        -coordMessage[2] uint8_t
        -coordGuess[2] uint8_t
        -coordPrompt[2] uint8_t
        +Ecran(uint8_t Xmessage,uint8_t Ymessage,uint8_t Xguess, uint8_t Yguess, v Xprompt, uint8_t Yprompt)
        ~Ecran()
        +writeMessage(char* message)
        +writeGuess(char* guess)
        +writePrompt(char* prompt)
        
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
        + void setColor(uint8_t color)
    }
    class I2C ~mbed~{

    }

    class SerialUnbuffer ~mbed~ {
        +SerialUnbuffer(PinName_TX, PinName_RX)
        +read()
        +readable()
    }
    class Keypad{
        keypad SerialUnbuffer
        +getGuess(char*) 
    }
    class AnalogIN~mbed~{
        +AnalogIn(pinname)
        +read_u16()
    }
    class CapteurDistance{
        -capteur AnalogIn
        +CapteurDistance(Pinname)
        ~CapeteurDistance()
        +getDistance() uint16_t
    }

    Pifometre *--  Ecran : contient
    Pifometre *--  CapteurDistance : contient
    Pifometre *--  Keypad : contient
    Ecran *-- rgb_lcd 
    rgb_lcd *-- I2C
    Keypad *-- SerialUnbuffer
    CapteurDistance *-- AnalogIN



:::
