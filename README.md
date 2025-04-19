# ESP32 RealDash CAN Bluetooth Adapter

![Project Banner](https://img.shields.io/badge/Platform-ESP32-blue) ![License](https://img.shields.io/badge/License-MIT-green)

An ESP32-based project that reads fuel level and digital inputs, packages the data into CAN frames, and transmits them over Bluetooth to the [RealDash](https://realdash.net) automotive dashboard app.

## Features
- **Fuel Level Monitoring**: Reads a 0-3.3V analog fuel sensor (e.g., potentiometer) and converts it to a 0-100% value.
- **Digital Inputs**: Monitors up to 6 digital inputs (e.g., switches, sensors) as a bitmask.
- **Bluetooth CAN Emulation**: Transmits data to RealDash using the [RealDash CAN protocol](https://github.com/janimm/RealDash-extras/blob/master/RealDash-CAN/realdash-can-protocol.md) over Bluetooth.
- **Debugging Support**: Serial monitor integration for troubleshooting.

## Hardware Requirements
- **ESP32 Development Board** (e.g., ESP32 DevKit, NodeMCU-32S)
- **Fuel Sensor**: Analog voltage output (0.5V-3.0V range recommended)
- **Digital Inputs**: Up to 6 switches/sensors (connected to GPIOs with pull-up resistors)
- **Bluetooth 4.0+ Device**: Smartphone/tablet running RealDash

### Pin Configuration (From `config.h`)
| Component         | GPIO Pin |
|--------------------|----------|
| Fuel Sensor (ADC)  | 34       |
| Spare Input 1      | 32       |
| Spare Input 2      | 33       |
| Spare Input 3      | 25       |
| Spare Input 4      | 26       |
| Spare Input 5      | 27       |
| Spare Input 6      | 14       |

---

## Installation
1. **Arduino IDE Setup**:
   - Install [ESP32 Arduino Core](https://github.com/espressif/arduino-esp32).
   - Install `BluetoothSerial` library (included with ESP32 core).

2. **Clone Repository**:
   ```bash
   git clone https://github.com/yourusername/esp32-realdash-fuel-monitor.git
