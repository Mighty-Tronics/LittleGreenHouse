
# Little Green House – Arduino Firmware

This repository contains the Arduino source code for the **Little Green House (LG)**, an open-source indoor greenhouse controller. The firmware runs on an ATmega328P-based microcontroller (e.g., Arduino Nano) and automates plant care using sensors, actuators, and a real-time clock.

## 🌿 Features

- Automatic watering via peristaltic pump based on soil moisture
- Humidity and temperature monitoring
- Light duration tracking and LED control
- Real-time clock (RTC) for scheduled operations
- OLED screen display with current status
- Button-controlled configuration and manual triggers
- Serial interface for calibration and setup

## 🧩 Hardware Requirements

- Arduino Nano or ATmega328P-compatible board
- Soil moisture sensor
- DHT22 temperature/humidity sensor
- Light sensor (LDR or similar)
- RTC module (DS3231 recommended)
- Peristaltic pump (with driver)
- OLED 128x64 display (I2C)
- Push buttons (x3)

## 📂 File Structure

- `LittleGreenHouse.ino`: Main Arduino sketch
- `functions/*.ino`: Modularized code (triggers, setup, display, etc.)
- `lib/`: Optional custom libraries (if applicable)
- `doc/`: Additional documentation (pinout, logic, visuals)

## ⚙️ How to Upload

1. Open `LittleGreenHouse.ino` in the Arduino IDE.
2. Select **Arduino Nano** as board (or matching MCU).
3. Select the appropriate COM port.
4. Upload and monitor via serial at 9600 baud.

## 🔧 Serial Commands

The firmware supports simple serial commands for:
- Setting time and date
- Adjusting humidity/light thresholds
- Manual pump/light activation
- Debugging sensors

(See `doc/commands.md` or eBook for full list.)

## 📜 License

This firmware is released under the **MIT License**. Feel free to use, modify, and distribute it freely under open source principles.

## 🌱 About

Part of the [Little Green House](https://github.com/...) open hardware ecosystem by **Mighty Tronics**, this firmware brings life to the smart greenhouse controller.
