#ifndef TCS3200SERVO_H
#define TCS3200SERVO_H

#include <Arduino.h>
#include <Servo.h>

class TCS3200Servo {
public:
    TCS3200Servo(uint8_t s0, uint8_t s1, uint8_t s2, uint8_t s3, uint8_t outPin, uint8_t servoPin);
    void begin();
    void readColor();
    void controlByColor();
    int detectColor(); 
private:
    uint8_t _s0, _s1, _s2, _s3, _outPin, _servoPin;
    int _red, _green, _blue;
    Servo _servo;
};

#endif