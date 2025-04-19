# ESP32 RealDash CAN Bluetooth Adapter (AZ-Delivery DevKit V4)

![Project Banner](https://img.shields.io/badge/Platform-ESP32-blue) ![License](https://img.shields.io/badge/License-MIT-green) ![PlatformIO](https://img.shields.io/badge/PlatformIO-Compatible-brightgreen)

An ESP32-based project for the **AZ-Delivery DevKit V4** that reads fuel level and digital inputs, packages data into CAN frames, and transmits them via Bluetooth to the [RealDash](https://realdash.net) automotive dashboard app. Optimized for PlatformIO in Visual Studio Code.

## Features
- **AZ-Delivery DevKit V4 Optimized**: Preconfigured for ESP32-WROOM-32 module
- **Fuel Level Monitoring**: 0-100% via analog sensor (12-bit ADC)
- **Digital Input Monitoring**: 6-channel input with pull-up resistors
- **Bluetooth CAN Emulation**: RealDash-compatible protocol over BLE Serial
- **Structured Logging**: Serial debug output at 115200 baud

## Hardware Requirements
| Component               | Specification                   |
|-------------------------|---------------------------------|
| ESP32 Board             | AZ-Delivery DevKit V4           |
| Fuel Sensor Input       | 0.5V-3.0V analog (GPIO34)      |
| Digital Inputs          | 6x GPIOs (32, 33, 25, 26, 27, 14) |
| Bluetooth 4.0+ Device   | Android/iOS running RealDash   |

---

## PlatformIO Configuration (`platformio.ini`)
```ini
[env:az-delivery-devkit-v4]
platform = espressif32
board = az-delivery-devkit-v4
monitor_speed = 115200
framework = arduino

[platformio]
src_dir = src
include_dir = include
