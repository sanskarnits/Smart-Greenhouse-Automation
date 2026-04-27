# 🌿 Smart Greenhouse - Embedded Climate Automation System

## 📌 Overview
The **Smart Greenhouse Monitoring System** is an embedded prototype designed to continuously monitor and regulate internal climate conditions for optimal crop growth. Built using an **Arduino Uno R3**, the system acquires real-time temperature and humidity data, displays it on an I2C LCD, and autonomously actuates a cooling mechanism when thermal thresholds are breached. 

This project serves as a scalable foundation for advanced agricultural automation.

## ✨ Key Features
- **Real-Time Data Acquisition:** Continuous sampling of ambient temperature and relative humidity every 2 seconds.
- **Automated Thermal Management:** A 5V relay autonomously triggers a brushless DC cooling fan when the ambient temperature exceeds the **32°C** threshold.
- **Live Data Visualization:** Real-time environmental metrics are displayed on a 16x2 I2C LCD display for immediate user awareness.
- **Fault Tolerance:** Built-in software error handling detects sensor disconnections to prevent false actuation and system crashes.
- **Scalable Architecture:** Designed as a modular prototype for easy future integration of IoT modules (ESP8266/ESP32) for cloud monitoring, as well as additional sensors (e.g., Soil Moisture, MQ135 Gas Sensors).

## 🛠️ Hardware & Technologies Used
- **Microcontroller:** Arduino Uno R3 (ATmega328P)
- **Sensors:** DHT11 Digital Temperature & Humidity Sensor
- **Actuators:** 5V 1-Channel Relay Module (HW-482), 5V Brushless DC Fan
- **Display:** 16x2 LCD with I2C Backpack (PCF8574)
- **Software:** C/C++, Arduino IDE
- **Libraries:** `Wire.h`, `DHT.h` (by Adafruit), `LiquidCrystal_I2C.h`

## 🔌 Circuit Diagram & Pin Mapping

![Circuit Diagram](circuit_diagram.jpeg)

> **⚠️ Disclaimer:** The circuit diagram above is a conceptual visual representation. AI-generated visual schematics may not reflect 100% accurate pin-to-wire connections. For physical hardware assembly and exact wiring, please strictly follow the Pin Mapping table below.

| Component | Arduino Pin |
| :--- | :--- |
| **DHT11 Data Pin** | Digital Pin 2 |
| **Relay Signal Pin (IN)** | Digital Pin 8 |
| **I2C LCD SDA** | Analog Pin A4 |
| **I2C LCD SCL** | Analog Pin A5 |

## 🚀 How to Run the Project
1. Clone this repository to your local machine:
   ```bash
   git clone [https://github.com/your-username/Smart-Greenhouse-Automation.git](https://github.com/your-username/Smart-Greenhouse-Automation.git)
