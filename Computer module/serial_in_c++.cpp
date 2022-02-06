#include <iostream>
#include <serialib.h>
using namespace std;

class display_module {
    public:
        serialib serial;
        void connect() {
            serial.openDevice("\\\\.\\COM7", 9600);
        }
        void write_int_as_char(int integer) { //accepts only ints between 0-255
            char write_byte[1] = {(char)integer};
            serial.writeBytes(write_byte, 1);
        }
};


int main() {
    display_module arduino;
    arduino.connect();
    int test_int = 53;
    arduino.write_int_as_char(test_int);
    return 1;
}