# testRC - Arduino TCS3200 & Servo Demo

## Mô tả
Dự án này sử dụng cảm biến màu TCS3200 để nhận diện màu sắc và điều khiển động cơ servo.  
- Khi phát hiện màu đỏ, servo quay 90 độ.
- Khi phát hiện màu xanh lá, servo quay 180 độ.
- Khi phát hiện màu vàng, servo quay 0 độ.

## Phần cứng
- Arduino Uno
- Cảm biến màu TCS3200
- Động cơ Servo
- Dây nối

## Kết nối phần cứng
- S0 → Pin 4 Arduino
- S1 → Pin 5 Arduino
- S2 → Pin 6 Arduino
- S3 → Pin 7 Arduino
- OUT → Pin 8 Arduino
- Servo signal → Pin 9 Arduino

## Cài đặt & sử dụng

1. **Clone dự án về máy:**
    ```sh
    git clone https://github.com/<your-username>/testRC.git
    cd testRC
    ```

2. **Mở bằng PlatformIO (VS Code).**

3. **Nạp code lên Arduino Uno.**

4. **Mở Serial Monitor (9600 baud) để xem kết quả.**

## Thư viện sử dụng
- [Servo](https://registry.platformio.org/libraries/arduino-libraries/Servo)
- Thư viện TCS3200Servo tự viết (trong thư mục `lib/TCS3200Servo`)

## Tác giả
- Thanh Wo
