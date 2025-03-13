#ifndef SATA_H
#define SATA_H

#include <Arduino.h>

class SATA {
public:
    // Constructor to initialize the SATA interface
    SATA(uint8_t APlus, uint8_t AMinus, uint8_t BPlus, uint8_t BMinus);

    // Initialize the SATA device
    void initialize();

    // Read data from the SATA device
    void read(uint32_t address, uint8_t* buffer, uint16_t length);

    // Write data to the SATA device
    void write(uint32_t address, const uint8_t* data, uint16_t length);

    // Format the SATA device
    void format();

    // Set an interrupt for SATA operations
    void setInterrupt(void (*isr)());

    // Delay specific to SATA communication timing
    void sataDelay(uint16_t ms);

    // Boot from SATA device
    void boot();

    // Finish and disconnect the SATA device
    void finish();

private:
    uint8_t _APlus, _AMinus, _BPlus, _BMinus;

    // Low-level communication helper function (mock implementation)
    void sendCommand(uint8_t command, const uint8_t* data, uint16_t length);
};

#endif