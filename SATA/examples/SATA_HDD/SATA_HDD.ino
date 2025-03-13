#include <SATA.h>

// Define mock SATA pins
const int APlus = 2;
const int AMinus = 3;
const int BPlus = 4;
const int BMinus = 5;

// Create a SATA object
SATA hdd(APlus, AMinus, BPlus, BMinus);

void setup() {
    Serial.begin(9600);
    hdd.initialize();
    hdd.boot();

    // Mock data to write
    uint8_t data[10] = {0xDE, 0xAD, 0xBE, 0xEF, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06};
    hdd.write(0x1000, data, 10);

    uint8_t buffer[10];
    hdd.read(0x1000, buffer, 10);

    hdd.format();
    hdd.finish();
}

void loop() {
    // Nothing here
}