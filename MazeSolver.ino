#include <NewPing.h>

// Sensor pins
#define TRIGGER_PIN_FRONT  9
#define ECHO_PIN_FRONT     A0
#define TRIGGER_PIN_LEFT   10
#define ECHO_PIN_LEFT      A1
#define TRIGGER_PIN_RIGHT  12
#define ECHO_PIN_RIGHT     A2

#define MAX_DISTANCE 100 // Max distance for ping (in cm)

// Motor driver pins
int enA = 3;
int enB = 11;
int in1 = 7;
int in2 = 8;
int in3 = 5;
int in4 = 6;

// Ultrasonic sensor objects
NewPing sonarFront(TRIGGER_PIN_FRONT, ECHO_PIN_FRONT, MAX_DISTANCE);
NewPing sonarLeft(TRIGGER_PIN_LEFT, ECHO_PIN_LEFT, MAX_DISTANCE);
NewPing sonarRight(TRIGGER_PIN_RIGHT, ECHO_PIN_RIGHT, MAX_DISTANCE);

// Speed and thresholds
int baseSpeed = 50;
int stopDistance = 7;
int reverseDistance = 5;
int turnDistance = 6;
int reverseTime = 500;
int turnTime = 600;

void setup() {
    Serial.begin(115200);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    pinMode(enA, OUTPUT);
    pinMode(enB, OUTPUT);
}

void loop() {
    int distanceFront = sonarFront.ping_cm();
    delay(50);
    int distanceLeft = sonarLeft.ping_cm();
    delay(50);
    int distanceRight = sonarRight.ping_cm();

    // Print distances to monitor
    Serial.print("Front: ");
    Serial.print(distanceFront);
    Serial.print(" cm | Left: ");
    Serial.print(distanceLeft);
    Serial.print(" cm | Right: ");
    Serial.print(distanceRight);
    Serial.println(" cm");

    // Check if sensors are reading correctly
    if (distanceFront == 0 || distanceLeft == 0 || distanceRight == 0) {
        Serial.println("Warning: One or more sensors not detecting. Check wiring and connections!");
    }

    // Obstacle avoidance logic
    if (distanceFront > 0 && distanceFront <= reverseDistance) {
        Serial.println("Obstacle too close in FRONT! Reversing...");
        reverseMotors(baseSpeed);
        delay(reverseTime);
    } else if (distanceFront > reverseDistance && distanceFront <= stopDistance) {
        if (distanceLeft > 0 && distanceLeft < distanceRight) {
            Serial.println("Obstacle in FRONT, turning RIGHT (LEFT side closer)");
            turnRight(baseSpeed);
            delay(turnTime);
        } else if (distanceRight > 0 && distanceRight < distanceLeft) {
            Serial.println("Obstacle in FRONT, turning LEFT (RIGHT side closer)");
            turnLeft(baseSpeed);
            delay(turnTime);
        } else {
            Serial.println("Obstacle in FRONT, stopping");
            stopMotors();
        }
    } else if (distanceLeft > 0 && distanceLeft <= turnDistance) {
        Serial.println("Obstacle on LEFT, turning RIGHT (LEFT motor active)");
        turnRight(baseSpeed);
        delay(turnTime);
    } else if (distanceRight > 0 && distanceRight <= turnDistance) {
        Serial.println("Obstacle on RIGHT, turning LEFT (RIGHT motor active)");
        turnLeft(baseSpeed);
        delay(turnTime);
    } else {
        Serial.println("Path clear, moving FORWARD");
        moveForward(baseSpeed);
    }

    delay(100); // Stabilize readings
}

void moveForward(int speed) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enA, speed);
    analogWrite(enB, speed);
}

void stopMotors() {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    analogWrite(enA, 0);
    analogWrite(enB, 0);
}

void reverseMotors(int speed) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enA, speed);
    analogWrite(enB, speed);
}

void turnRight(int speed) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enA, speed);
    analogWrite(enB, speed / 2);
}

void turnLeft(int speed) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enA, speed / 2);
    analogWrite(enB, speed);
}

