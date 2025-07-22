🔥 Heater Control System – Embedded Systems Project

Internship: Embedded Systems Intern – upliance.ai  
Author: Vamshi Krishna  
Date: July 22, 2025

------------------------------------------------------------
📌 Project Overview

This project demonstrates a temperature-controlled heater system using an Arduino Uno. A DHT22 sensor monitors temperature, an I2C LCD shows system status, and a buzzer alerts during overheating. A simulated heater is controlled using an LED, and all logic is implemented using a software-based state machine.

------------------------------------------------------------
🎯 Objectives

- Measure ambient temperature using DHT22.
- Display temperature and current state on a 16x2 I2C LCD.
- Turn ON/OFF heater (LED) automatically based on thresholds.
- Alert using a buzzer when temperature exceeds the safe limit.
- Use state machine logic to manage transitions and system flow.

------------------------------------------------------------
🧰 Components Used

Component        | Purpose
------------------|----------------------------------------
Arduino Uno      | Main microcontroller
DHT22 Sensor     | Temperature measurement
I2C LCD (16x2)   | Displays temperature and system state
LED              | Simulates heater
Buzzer           | Alerts on overheating
Power Supply     | Powers the circuit
Jumper Wires     | Connects components

------------------------------------------------------------
📡 Communication Protocols

- I2C: For LCD communication (SDA → A4, SCL → A5)
- Digital I/O: For DHT22, buzzer, and LED
- Serial: For debugging and real-time data logs

------------------------------------------------------------
🧠 State Machine Logic

State            | Temperature Range (°C) | Action
------------------|------------------------|------------------------------------
Idle             | Startup                | Heater OFF
Heating          | Temp < 28              | Heater ON
Stabilizing      | 28 ≤ Temp < 32         | Heater ON (near target)
Target Reached   | 32 ≤ Temp < 60         | Heater OFF
Overheat         | Temp ≥ 60              | Heater OFF + Buzzer ON

------------------------------------------------------------
🖥️ LCD Display Logic

- Line 1: Temp: 32.5 C
- Line 2: State: Heating, Idle, etc.

------------------------------------------------------------
🧪 Serial Monitor Output

Temp: 29.2 C | State: Stabilizing

------------------------------------------------------------
🧰 Files Included

Heater_Control_System/  
├── arduino_code.ino                 # Main Arduino code  
├── README.txt                       # This documentation  
├── Design_Report.pdf                # Final system design report  
├── simulation_architecture.drawio   # Simulation block diagram  
├── hardware_architecture.drawio     # Real-world block diagram  
├── wokwi_link.txt                   # Link to Wokwi project  

------------------------------------------------------------
🚀 Future Improvements

- ESP32 Upgrade: Enable Wi-Fi/Bluetooth control via mobile app.
- IoT Connectivity: Use MQTT/Blynk for cloud integration.
- FreeRTOS: Manage tasks with real-time OS support.
- Data Logging: Log sensor readings to SD card or cloud.
- Edge AI: Predict heating needs or detect anomalies.
- Multi-Zone Control: Add multiple sensor zones.
- Real Hardware Control: Replace LED with relay/triac, add safety fuses.

------------------------------------------------------------
✅ Conclusion

This project is a complete embedded system application demonstrating sensor integration, actuator control, state machine logic, and user interface with safety feedback. It serves as a strong foundation for smart appliances or industrial automation.

------------------------------------------------------------
🔗 Useful Links

👉 **Wokwi Simulation**  
https://wokwi.com/projects/437113575167255553

👉 **GitHub Repository**  
https://github.com/VamshiNetha20/Heater-Control-System-Embedded-Systems-Project

👉 **ZIP Download (Code + Docs)**  
https://drive.google.com/file/d/12YN2WSeL2MeOTAI8Nv-A8OhrpZL8-7st/view?usp=drive_link

