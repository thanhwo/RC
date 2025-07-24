#include "TCS3200Servo.h"
TCS3200Servo::TCS3200Servo(uint8_t s0, uint8_t s1, uint8_t s2, uint8_t s3, uint8_t outPin, uint8_t servoPin)
    : _s0(s0), _s1(s1), _s2(s2), _s3(s3), _outPin(outPin), _servoPin(servoPin) {}

void TCS3200Servo::begin() {
    pinMode(_s0, OUTPUT);
    pinMode(_s1, OUTPUT);
    pinMode(_s2, OUTPUT);
    pinMode(_s3, OUTPUT);
    pinMode(_outPin, INPUT);
    digitalWrite(_s0, HIGH);
    digitalWrite(_s1, LOW);
    _servo.attach(_servoPin);
    _servo.write(90); // Đặt vị trí mặc định là 90 độ
}

void TCS3200Servo::readColor() {
    // Đọc RED
    digitalWrite(_s2, LOW);
    digitalWrite(_s3, LOW);
    _red = pulseIn(_outPin, LOW);

    // Đọc GREEN
    digitalWrite(_s2, HIGH);
    digitalWrite(_s3, HIGH);
    _green = pulseIn(_outPin, LOW);

    // Đọc BLUE
    digitalWrite(_s2, LOW);
    digitalWrite(_s3, HIGH);
    _blue = pulseIn(_outPin, LOW);
}

int TCS3200Servo::detectColor() {
    if (_red < _green && _red < _blue) return 0; // RED
    if (_green < _red && _green < _blue) return 1; // GREEN
    if (_red < 150 && _green < 150 && _blue > 180) return 2; // YELLOW
    return -1; // UNKNOWN
}

void TCS3200Servo::controlByColor() {
    int color = detectColor(); // Giả lập màu sắc ngẫu nhiên
    if (color == 0) {
        _servo.write(90);   // Đỏ
    } else if (color == 1) {
        _servo.write(180);  // Xanh lá
    } else if (color == 2) {
        _servo.write(0);    // Vàng
    } else {
        _servo.write(90);   // Không xác định
    }
}
