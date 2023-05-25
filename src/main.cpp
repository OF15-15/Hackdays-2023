#include <Arduino.h>
#include "Grove_I2C_Motor_Driver.h"

int led[] = {8, 9, 10, 11, 12};
int schiebePoti = A1;
int drehPoti = A0;

void waterOff();
void waterOn();

void setup() {
    Serial.begin(9600);
    Serial.println(__FILE__);
    Motor.begin(0x0f);
    Serial.println("Motor initialized");

}

void loop() {
    for(int i =0; i<= 100; i++){
    Motor.StepperRun(-1);
    delay(200);
    }
    Serial.println("loop");

}


void waterOn() {
    for(int i = 0; i<5 ; i++){
        digitalWrite(led[i], HIGH);
        delay(100);
    }
}
void waterOff() {
    for (int i = 4; i>=0; i--) {
        digitalWrite(led[i], LOW);
        delay(100);
    }
}