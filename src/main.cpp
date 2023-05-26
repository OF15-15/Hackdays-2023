#include <Arduino.h>
#include "Grove_I2C_Motor_Driver.h"
#include "Servo.h"

int led[] = {8, 9, 10, 11, 12};
int schiebePoti = A1;
int drehPoti = A0;
int turn;
int pitch;
int b_ang = 40;
int t_ang = 120;
int current_turn;

Servo servoL;
Servo servoR;

void waterOff();

void waterOn();

void setup() {
    Serial.begin(9600);
    Serial.println(__FILE__);
    Motor.begin(0x0f);
    Serial.println("Motor initialized");
    servoL.attach(2);
    servoR.attach(3);
}

void loop() {
    turn = analogRead(drehPoti);
    turn = map(turn, 0, 1023, -128, 128);
    pitch = analogRead(schiebePoti);
    pitch = map(pitch, 0, 722, b_ang, t_ang);
    if (turn > current_turn + 5) {
        Motor.StepperRun(1);
        current_turn++;
    }
    if (turn < current_turn - 5) {
        Motor.StepperRun(-1);
        current_turn--;
    }
    servoL.write(pitch);
    if (millis() % 1000 == 0) {
        Serial.print("turn: ");
        Serial.println(turn);
        Serial.print("pitch: ");
        Serial.println(pitch);
        delay(500);
    }
}


void waterOn() {
    for (int i = 0; i < 5; i++) {
        digitalWrite(led[i], HIGH);
        delay(100);
    }
}

void waterOff() {
    for (int i = 4; i >= 0; i--) {
        digitalWrite(led[i], LOW);
        delay(100);
    }
}