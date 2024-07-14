# Pump Automation and Control Device
## Overview
This project involves the design and development of a pump automation and control device using NodeMCU with custom firmware. The device features a custom control board with buttons for manual/auto mode switching and pump on/off functionality, LED indicators, and an ultrasonic sensor for water level monitoring. It is integrated with the Blynk platform for IoT connectivity and remote monitoring.

## Features
- **Manual/Auto Mode Switching:** Toggle between manual and automatic operation modes using a dedicated button.
- **Pump On/Off Control:** Control the pump operation with a separate on/off button.
- **LED Indicators:** Visual feedback for mode status and pump operation.
- **Water Level Monitoring:** Ultrasonic sensor to measure and monitor water levels in real-time.
- **Remote Monitoring and Control:** Blynk integration for IoT connectivity, allowing remote monitoring and control via the Blynk app.
## Firmware Setup
- Install the Arduino IDE from Arduino website.
- Install the ESP8266 Board Package in the Arduino IDE.
- Install the following libraries: Blynk,NewPing (for ultrasonic sensor)
- Open the provided PumpControl.ino sketch in Arduino IDE.
- Configure the Blynk credentials in the sketch.
- Upload the sketch to the NodeMCU.
