#include "mbed.h"
#include "string.h"
// Create a DigitalOutput object to toggle an LED whenever data is received.
static DigitalOut led(LED1);

// Create a UnbufferedSerial object with a default baud rate.
static UnbufferedSerial serial_port(PC_1, PC_0);
static UnbufferedSerial pc(USBTX, USBRX,9600);

string guess;

void on_rx_interrupt()
{    char c;

    // Toggle the LED.
    led = !led;

    // Read the data to clear the receive interrupt.
    if (serial_port.read(&c, 1)) {
        // Echo the input back to the terminal.
        pc.write(&guess, guess.size());
        switch(c) {
                case 0xE1 :
                    pc.write("1", 1);
                    guess.append("1");
                    break;
                case 0xE2 :
                    pc.write("2", 1);
                    guess.append("2");
                    break;
                case 0xE3 :
                    pc.write("3", 1);
                    break;
                case 0xE4 :
                    pc.write("4", 1);
                    break;
                case 0xE5 :
                    pc.write("5", 1);
                    break;
                case 0xE6 :
                    pc.write("6", 1);
                    break;
                case 0xE7 :
                    pc.write("7", 1);
                    break;
                case 0xE8 :
                    pc.write("8", 1);
                    break;
                case 0xE9 :
                    pc.write("9", 1);
                    break;
                case 0xEA :
                    pc.write("*", 1);
                    break;
                case 0xEB :
                    pc.write("0", 1);
                    break;
                case 0xEC :
                    pc.write("\n", 1);
                    break;
                default:
                    break;
            }
    }
    
}

int main(void)
{
    // Set desired properties (9600-8-N-1).
    serial_port.baud(9600);
    serial_port.format(
        /* bits */ 8,
        /* parity */ SerialBase::None,
        /* stop bit */ 1
    );

    // Register a callback to process a Rx (receive) interrupt.
    serial_port.attach(&on_rx_interrupt, SerialBase::RxIrq);
}
