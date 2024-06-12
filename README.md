### VEHICLE SAFETY REMOTE DASHBOARD USING IOT

---

#### Table of Contents
1. [Introduction](#introduction)
2. [Objectives](#objectives)
3. [Software/Hardware Requirements](#softwarehardware-requirements)
4. [Ultrasonic Sensor](#ultrasonic-sensor)
5. [Impact Switch](#impact-switch)
6. [Vehicle Accident Detection using IoT Dashboard](#vehicle-accident-detection-using-iot-dashboard)
7. [Setup and Code](#setup-and-code)
8. [Configuration](#configuration)

---

### Introduction

The **Vehicle Safety Remote Dashboard Using IoT** project aims to build a remote dashboard for vehicle safety monitoring using the NodeMCU microcontroller, an ultrasonic sensor, and an impact switch. The data collected is visualized on the ThingSpeak cloud platform, providing real-time monitoring and alerts for potential accidents.

---

### Objectives

1. **Introduction to Ultrasonic Sensor and Impact Switch**:
   - Understand the working principles and applications.
2. **Build Vehicle Safety Remote Dashboard**:
   - Integrate sensors with NodeMCU.
3. **Visualize Data**:
   - Use ThingSpeak to visualize sensor data.

---

### Software/Hardware Requirements

- **NodeMCU board**: 1 unit
- **Micro USB cable A to B**: 1 unit
- **ThingSpeak account**: 1 unit
- **WiFi router with internet connection**: 1 unit
- **HC-SR04 Ultrasonic Sensor**: 1 unit
- **Impact Switch**: 1 unit
- **Breadboard**: 1 unit
- **Jumper Wires**: 10 units

---

### Ultrasonic Sensor

The **HC-SR04 ultrasonic sensor** is used to measure distance by transmitting and receiving ultrasonic waves.

**Operation**:
- **Transmitter**: Emits ultrasonic waves.
- **Reflection**: Waves hit an object and reflect back.
- **Receiver**: Receives the echo of the waves.
- **Time Measurement**: Calculates the distance based on the travel time of waves.

**Pin Configuration**:
- **VCC**: Connect to NodeMCU 3.3V
- **Trig**: Connect to NodeMCU D1
- **Echo**: Connect to NodeMCU D2
- **GND**: Connect to NodeMCU G

---

### Impact Switch

The **impact switch** is a crash sensor designed to detect sudden impacts or collisions.

**Pin Configuration**:
- **Trig**: Connect to NodeMCU D3
- **VCC**: Connect to NodeMCU 3V
- **GND**: Connect to NodeMCU G

---

### Vehicle Accident Detection using IoT Dashboard

Integrate the ultrasonic sensor and the impact switch with NodeMCU to create a vehicle safety system. The system detects potential accidents and sends data to the ThingSpeak platform.

**Circuit Diagram**:
- **Ultrasonic Sensor Trig Pin** -> NodeMCU D1
- **Ultrasonic Sensor Echo Pin** -> NodeMCU D2
- **Ultrasonic Sensor Vcc Pin** -> NodeMCU 3V3
- **Ultrasonic Sensor Gnd Pin** -> NodeMCU G
- **Impact Sensor Trig Pin** -> NodeMCU D3
- **Impact Sensor Vcc Pin** -> NodeMCU 3V
- **Impact Sensor Gnd Pin** -> NodeMCU G

---

### Setup and Code

Below is an overview of the setup and code for this project:

1. **Include Libraries**: Include the necessary libraries for WiFi and ThingSpeak.
2. **WiFi Configuration**: Set up WiFi credentials.
3. **ThingSpeak Configuration**: Set up ThingSpeak channel details.
4. **Setup Function**: Initialize serial communication, configure pins, and connect to WiFi and ThingSpeak.
5. **Loop Function**: Measure distance using the ultrasonic sensor, check for impacts using the impact switch, and send data to ThingSpeak.

### Configuration

1. **WiFi Credentials**: Enter your WiFi name and password in the corresponding fields:
   ```cpp
   const char* ssid = "Enter your Wifi name";
   const char* password = "Enter your Wifi password";
   ```

2. **ThingSpeak Channel ID**: Enter your Channel ID:
   ```cpp
   unsigned long myChannelNumber = xxxxxx;
   ```

3. **ThingSpeak Write API Key**: Enter your Write API Key:
   ```cpp
   const char * myWriteAPIKey = "Enter your WriteAPI Key";
   ```
API key can be changed if compromised. It is unique to your channel and is used to write data into it.
