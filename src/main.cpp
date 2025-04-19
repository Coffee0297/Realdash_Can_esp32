#include "FuelSensor.h"
#include "SpareInputs.h"
#include "config.h"
#include <Arduino.h>
#include <BluetoothSerial.h>

FuelSensor fuelSensor;
SpareInputs spareInputs;
BluetoothSerial SerialBT;

void printCanFrame(const uint8_t* frame) {
    Serial.print("CAN Frame: ");
    for (int i = 0; i < 16; i++) {
        Serial.printf("%02X ", frame[i]);
    }
    Serial.println();
}

void setup() {
    Serial.begin(115200);
    while(!Serial); // Wait for serial port to connect (for debugging)

    Serial.println("Initializing Bluetooth...");
    if(!SerialBT.begin("ESP32-Realdash")) {
        Serial.println("Bluetooth initialization failed!");
        while(1); // Halt on failure
    }
    Serial.println("Bluetooth started. Device name: 'ESP32-Realdash'");

    fuelSensor.begin();
    spareInputs.begin();
}

void loop() {
    // Read sensor values
    uint8_t fuel = fuelSensor.readFuelLevel();
    uint8_t inputs = spareInputs.readInputs();
    
    Serial.printf("Raw values - Fuel: %d, Inputs: 0x%02X\n", fuel, inputs);

    // Construct CAN frame
    uint8_t canFrame[16] = {0};
    uint32_t canId = 0x100;
    
    canFrame[0] = 0x44; canFrame[1] = 0x33; canFrame[2] = 0x22; canFrame[3] = 0x11;
    memcpy(&canFrame[4], &canId, 4);
    canFrame[8] = fuel;
    canFrame[9] = inputs;

    printCanFrame(canFrame); // Debug output
    if (SerialBT.hasClient()) {
        SerialBT.write(canFrame, sizeof(canFrame));
    }

    // Send data only if Bluetooth is connected
    if(SerialBT.hasClient()) {
        size_t bytesSent = SerialBT.write(canFrame, sizeof(canFrame));
        if(bytesSent != sizeof(canFrame)) {
            Serial.printf("Transmission failed! Sent %d/16 bytes\n", bytesSent);
        } else {
            Serial.println("Data sent successfully");
        }
    } else {
        Serial.println("No Bluetooth client connected!");
    }

    delay(500);
}



