#include <Arduino.h>
#include "TCS3200Servo.h"

TCS3200Servo colorServo(4, 5, 6, 7, 8, 9);

void setup() {
    Serial.begin(9600);
    colorServo.begin();
}

void loop() {
    colorServo.readColor();
    colorServo.detectColor();
    delay(100);
}