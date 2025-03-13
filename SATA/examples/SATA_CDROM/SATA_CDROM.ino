#include <SATA.h>

// Define mock SATA pins
const int APlus = 2;
const int AMinus = 3;
const int BPlus = 4;
const int BMinus = 5;

// Create a SATA object
SATA cdrom(APlus, AMinus, BPlus, BMinus);

void setup() {
    Serial.begin(9600);
    cdrom.initialize();
    cdrom.boot();
    cdrom.read(0x2000, nullptr, 20);  // Mock read from CD-ROM
    cdrom.finish();
}

void loop() {
    // Nothing here
}