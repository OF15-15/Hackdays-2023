#include <Arduino.h>

int led[] = {8, 9, 10, 11, 12};
int schiebePoti = A1;
int drehPoti = A0;

void waterOff();
void waterOn();

void setup() {
    Serial.begin(9600);
    Serial.println(__FILE__);
    for (int i = 0; i < 5; i++) {
        pinMode(led[i], OUTPUT);
    }
}

void loop() {
    int schiebePotiVal = analogRead(schiebePoti);
    int drehPotiVal = analogRead(drehPoti);
    Serial.print("Pitch: ");
    Serial.println(schiebePotiVal);
    Serial.print("Turn: ");
    Serial.println(drehPotiVal);
    delay(100);
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