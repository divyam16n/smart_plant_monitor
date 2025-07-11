
# 🌱 Smart Plant Monitor

An Arduino-based project that uses multiple sensors to monitor plant health and environmental conditions in real-time. This system can display temperature, soil moisture, light intensity, and detect nearby obstacles — helping automate plant care efficiently.

---

## 👨‍🔧 Built By
Divyam Nakra and **Kritagya Singh

---

## 📦 Features

- 🌡️ Object and Ambient Temperature Monitoring (IR Sensor - MLX90614)
- 💧 Soil Moisture Detection
- ☀️ Light Intensity Sensing (LDR)
- 📏 Obstacle Distance Measurement (Ultrasonic Sensor)
- 🚨 Alerts via LED and Buzzer
- 📺 LCD Display for Real-Time Feedback

---

## 🔌 Components Used

- Arduino Uno
- MLX90614 IR Temperature Sensor
- Soil Moisture Sensor
- LDR (Light Dependent Resistor)
- Ultrasonic Sensor (HC-SR04)
- Buzzer
- Red LED
- I2C LCD Display (16x2)
- Jumper Wires and Breadboard

---

## 🖥️ How It Works

- Displays **temperature** and **soil moisture %** on LCD.
- Sounds a **buzzer** when soil is too dry.
- Lights up a **red LED** when an obstacle is closer than 20cm.
- Shows all sensor data via **Serial Monitor** as well.

---

## 🛠️ Libraries Required

- `Adafruit_MLX90614`
- `LiquidCrystal_I2C`
- `Wire`

Install via Arduino Library Manager before uploading.

---

## 💻 Getting Started

1. Connect all components as per your wiring.
2. Install required libraries.
3. Upload `smart_plant_monitor.ino` to your Arduino board.
4. Open Serial Monitor to see live data.

---

## 📃 License

This project is open-source and free to use for educational purposes.
