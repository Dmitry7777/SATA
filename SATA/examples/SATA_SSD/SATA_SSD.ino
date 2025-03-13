#include <SATA.h>

// Define mock SATA pins
const int APlus = 2;
const int AMinus = 3;
const int BPlus = 4;
const int BMinus = 5;

// Create a SATA object
SATA ssd(APlus, AMinus, BPlus, BMinus);

void setup() {
    Serial.begin(9600);
    ssd.initialize();
    ssd.boot();

    uint8_t data[5] = {0x01, 0x23, 0x45, 0x67, 0x89};
    ssd.write(0x3000, data, 5);  // Write data to SSD
    ssd.read(0x3000, nullptr, 5);  // Read data from SSD
    ssd.finish();
}

void loop() {
    // Nothing here
}