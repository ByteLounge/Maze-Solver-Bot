

---

# 🤖 Arduino Maze Solver Robot using 3 Ultrasonic Sensors

A fully autonomous obstacle-avoiding robot that navigates a maze using 3 ultrasonic sensors (front, left, right), controlled by an **Arduino Uno** and **L298N motor driver**. This robot intelligently makes turns, reverses only when extremely close to an obstacle, and uses serial monitoring for real-time debugging.

---

## 🚀 Features

- PID-controlled smooth wall-following
- Obstacle detection using 3 ultrasonic sensors
- Smart decision-making (left or right turn)
- Real-time distance logging over Serial Monitor
- Modular and beginner-friendly C++ code
- Configurable threshold values and motor speed

---

## 🛠️ Components Required

| Component                | Quantity |
|--------------------------|----------|
| Arduino Uno              | 1        |
| Ultrasonic Sensor (HC-SR04 or compatible) | 3        |
| L298N Motor Driver       | 1        |
| DC Gear Motors           | 2        |
| 360° Swivel Caster Wheel| 1        |
| Wheels                   | 2        |
| Jumper Wires (M-M/F-M)   | ~20      |
| Power Supply (9V battery or Li-ion pack) | 1        |
| Breadboard (optional)    | 1        |

---

## ⚙️ Wiring Overview

| Ultrasonic Sensor | Arduino Pin |
|-------------------|-------------|
| Left Trigger      | A3          |
| Left Echo         | A0          |
| Front Trigger     | A4          |
| Front Echo        | A1          |
| Right Trigger     | A5          |
| Right Echo        | A2          |

| Motor Driver (L298N) | Arduino Pin |
|----------------------|-------------|
| ENA                  | 10          |
| IN1, IN2             | 2, 3        |
| ENB                  | 11          |
| IN3, IN4             | 4, 5        |

---

## 📦 How to Setup the Maze Solver

### 1. Circuit Assembly

- Connect ultrasonic sensors to analog pins as shown.
- Connect motor driver to digital pins (IN1–IN4 and ENA/ENB).
- Connect power supply to the motor driver (VS and GND).
- Ensure common ground between Arduino and Motor Driver.

### 2. Arduino IDE Setup

#### 🔧 Installation

1. Download and install [Arduino IDE](https://www.arduino.cc/en/software)
2. Install **NewPing** library:  
   - Go to: `Sketch` > `Include Library` > `Manage Libraries`  
   - Search: `NewPing` and install

#### ⬆️ Uploading Code

1. Open the `.ino` file (Maze Solver Code)
2. Select board: `Tools` > `Board` > `Arduino Uno`
3. Select port: `Tools` > `Port` > (e.g., COM3)
4. Click ✅ (Verify) and then ⬇️ (Upload)

#### 🧪 Using Serial Monitor

- Go to `Tools` > `Serial Monitor` or press `Ctrl+Shift+M`
- Set **baud rate** to `115200`
- Use this to:
  - Monitor sensor distances
  - Debug wall-following behavior
  - Check for sensor connection issues

---

## 🧠 Code Overview

### Key Parameters:
```cpp
float P = 0.7, D = 0.5, I = 0.4;  // PID coefficients
int baseSpeed = 70;
int wall_threshold = 13;
int front_threshold = 7;
````

### Functional Flow:

1. **ReadSensors()**: Averages ultrasonic readings for smoother control
2. **walls()**: Sets boolean flags for left/right/front wall detection
3. **pid\_start()**: Uses PID logic to align with both walls (before first turn)
4. **PID()**: Follows either left or right wall after first turn
5. **setDirection()**: Sets motor directions (FORWARD, LEFT, RIGHT, STOP, BACKWARD)

### Decision Logic:

* Before first turn: Aligns with both walls
* After first turn: Follows closer wall (left or right)
* If all sensors read invalid (>100 cm or 0): STOP

---

## ⚔️ Code Comparison: PID Maze Solver vs Basic Obstacle Avoidance

| Feature               | **PID Maze Solver** (Advanced) | **Basic Avoidance Bot** (Simple) |
| --------------------- | ------------------------------ | -------------------------------- |
| PID control           | ✅ Yes                          | ❌ No                             |
| Wall-following        | ✅ Adaptive left/right          | ❌ No                             |
| Obstacle detection    | ✅ 3-way + logic                | ✅ Basic (front/side)             |
| Maze solving          | ✅ Yes                          | ❌ No                             |
| Ease of understanding | ❌ Moderate complexity          | ✅ Beginner-friendly              |
| Speed tuning          | ✅ Precise via PID              | ❌ Fixed turns                    |
| Use-case              | Competitions, complex mazes    | Demonstration, entry-level bots  |

> **Use PID Code** when you want precision, wall-following, and maze solving.
> **Use Basic Code** when testing sensor wiring or teaching beginners about robotics.

---

## 🧪 Troubleshooting

| Issue                         | Solution                                  |
| ----------------------------- | ----------------------------------------- |
| Sensor reads `0` or `>100 cm` | Check trigger/echo pins and power         |
| Motors not moving             | Verify IN1–IN4 wiring and ENA/ENB PWM     |
| Wrong turn direction          | Check motor polarity or motor pin logic   |
| Bot doesn’t detect walls      | Adjust `wall_threshold` and sensor angles |
| PID response too aggressive   | Reduce `P`, `D`, or `I` values            |


---

## 📜 License

This project is licensed under the MIT License.

---

### 🔗 Useful Links

* [Arduino Documentation](https://docs.arduino.cc/)
* [NewPing Library](https://bitbucket.org/teckel12/arduino-new-ping/wiki/Home)
* [L298N Motor Driver Guide](https://lastminuteengineers.com/l298n-dc-stepper-driver-arduino-tutorial/)

---

## Pictures and Diagrams

![1](https://github.com/user-attachments/assets/22ab4885-bfa5-451b-870f-692c70db4ec4)

![Screenshot 2025-06-25 130100](https://github.com/user-attachments/assets/152aad47-572b-4413-9200-380469fceb8a)

![Screenshot 2025-06-25 130112](https://github.com/user-attachments/assets/708147a6-016a-4899-88bf-3ebbd1899860)

![Screenshot 2025-06-25 130140](https://github.com/user-attachments/assets/b9f28638-dd3d-446f-9a4d-e1aa992039e1)

![Screenshot 2025-06-25 130153](https://github.com/user-attachments/assets/2d59b3d5-f4c5-45ce-b66f-ad207506d385)

![Screenshot 2025-06-25 130206](https://github.com/user-attachments/assets/745f6c11-4de1-4fad-bc95-3de5a10e8688)

![Screenshot 2025-06-25 130240](https://github.com/user-attachments/assets/54b213f5-5512-48bf-a71e-2343fb33eb67)

---

## 📄 License

This project is licensed under the MIT License.

---

