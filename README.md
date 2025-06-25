

---

# 🤖 Arduino Maze Solver Robot using 3 Ultrasonic Sensors

A fully autonomous obstacle-avoiding robot that navigates a maze using 3 ultrasonic sensors (front, left, right), controlled by an **Arduino Uno** and **L298N motor driver**. This robot intelligently makes turns, reverses only when extremely close to an obstacle, and uses serial monitoring for real-time debugging.

---

## 🔧 Hardware Components

| Component                 | Quantity  | Description                                   |
| ------------------------- | --------- | --------------------------------------------- |
| Arduino Uno               | 1         | Microcontroller Board                         |
| HC-SR04 Ultrasonic Sensor | 3         | For distance measurement (front, left, right) |
| L298N Motor Driver        | 1         | To drive the gear motors                      |
| Gear Motor                | 2         | DC motors with wheels                         |
| 360° Freewheel Caster     | 1         | For stability and turning support             |
| Jumper Wires              | As needed | For all connections                           |
| Power Source              | 1         | 6xAA battery pack or 7.4V Li-ion battery      |
| Breadboard (Optional)     | 1         | For neat wiring                               |

---

## 🔌 Wiring Instructions

### 🛞 Motors to L298N

* Motor A: `OUT1` → Left motor `+`, `OUT2` → Left motor `-`
* Motor B: `OUT3` → Right motor `+`, `OUT4` → Right motor `-`
* ENA (Enable A): Pin 3 (PWM)
* ENB (Enable B): Pin 11 (PWM)

### 🎯 Ultrasonic Sensors

| Sensor | Trigger | Echo | Arduino Pin                           |
| ------ | ------- | ---- | ------------------------------------- |
| Front  | 9       | A0   | `TRIGGER_PIN_FRONT`, `ECHO_PIN_FRONT` |
| Left   | 10      | A1   | `TRIGGER_PIN_LEFT`, `ECHO_PIN_LEFT`   |
| Right  | 12      | A2   | `TRIGGER_PIN_RIGHT`, `ECHO_PIN_RIGHT` |

### 🧠 Control Pins (L298N)

| L298N Pin | Arduino Pin |
| --------- | ----------- |
| IN1       | 5           |
| IN2       | 6           |
| IN3       | 7           |
| IN4       | 8           |

---

## 🧠 Code Logic Overview

* **Front Sensor**: Detects obstacle straight ahead.

  * If ≤ 3 cm: Reverse for 500ms.
  * If between 3–10 cm: Decide turn direction based on side distances.
* **Left & Right Sensors**:

  * If ≤ 5 cm: Turns away from the obstacle.
* **Normal Behavior**: If all sensors detect clear path (>10 cm), moves forward.

### 📜 Key Thresholds

```
int stopDistance = 10;
int sideStopDistance = 5;
int reverseDistance = 3;
```

---

## 🧪 How to Setup and Upload in Arduino IDE

### ✅ 1. Install Arduino IDE

* Download from [https://www.arduino.cc/en/software](https://www.arduino.cc/en/software)

### ✅ 2. Install NewPing Library

* Go to **Sketch > Include Library > Manage Libraries**
* Search for `NewPing` and install the latest version.

### ✅ 3. Upload Code

* Select **Board**: Arduino Uno
* Select **Port**: COM port where Uno is connected
* Click **Upload**

### ✅ 4. Open Serial Monitor

* Go to **Tools > Serial Monitor** or press `Ctrl + Shift + M`
* Set baud rate to **115200**
* Monitor live distance readings and obstacle detection messages

---

## 🐞 Debugging Tips

| Issue                        | Cause                         | Fix                                 |
| ---------------------------- | ----------------------------- | ----------------------------------- |
| `0 cm` distance consistently | Sensor not connected properly | Check VCC, GND, Trigger, Echo       |
| Only front sensor detects    | Wrong trigger/echo pin        | Recheck `#define` and wiring        |
| Motors not moving            | No power or wrong wiring      | Ensure 7V+ external supply to L298N |
| Turns in wrong direction     | Motor polarity reversed       | Swap OUT1/OUT2 or OUT3/OUT4         |

---

## 🧠 Enhancements You Can Add

* Infrared line sensors for edge detection
* PID-based wall following
* Bluetooth/ESP control override
* LCD display or LED indicators for debugging

---

## 📂 Folder Structure

```
MazeSolverRobot/
├── MazeSolver.ino   # Main Arduino code
├── README.md        # This file
```

---

## 📸 Sample Output on Serial Monitor

```
Front Distance: 12 cm | Left Distance: 25 cm | Right Distance: 22 cm
Path clear, moving FORWARD
Front Distance: 4 cm | Left Distance: 12 cm | Right Distance: 15 cm
Obstacle very close at FRONT! Reversing...
Turning left...
```

---

## Pictures and Diagrams

![1](https://github.com/user-attachments/assets/22ab4885-bfa5-451b-870f-692c70db4ec4)

![Screenshot 2025-06-25 130100](https://github.com/user-attachments/assets/152aad47-572b-4413-9200-380469fceb8a)

![Screenshot 2025-06-25 130112](https://github.com/user-attachments/assets/708147a6-016a-4899-88bf-3ebbd1899860)

![Screenshot 2025-06-25 130140](https://github.com/user-attachments/assets/b9f28638-dd3d-446f-9a4d-e1aa992039e1)

![Screenshot 2025-06-25 130153](https://github.com/user-attachments/assets/2d59b3d5-f4c5-45ce-b66f-ad207506d385)

![Screenshot 2025-06-25 130206](https://github.com/user-attachments/assets/745f6c11-4de1-4fad-bc95-3de5a10e8688)

![Screenshot 2025-06-25 130240](https://github.com/user-attachments/assets/54b213f5-5512-48bf-a71e-2343fb33eb67)


## 📄 License

This project is licensed under the MIT License.

---

