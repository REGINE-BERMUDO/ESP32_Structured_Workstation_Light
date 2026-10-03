# Structured Workstation Light

This ESP32 code uses a potentiometer to control the brightness of an LED using PWM. The potentiometer is connected to GPIO 34, which reads an analog value from 0 to 4095. This value is then converted to an 8-bit PWM duty cycle from 0 to 255.

A push button connected to GPIO 23 acts as an enable control. When the button is pressed, the PWM value from the potentiometer is applied to the LED on GPIO 19. When the button is released, the PWM output is forced to 0, turning the LED off.

GPIO 18 is used as a status LED to indicate when the button is pressed.

## Demo

https://github.com/user-attachments/assets/a3b88eaf-ff6d-442f-8bae-57701d96e21c


## Circuit Diagram
<img width="975" height="597" alt="image" src="https://github.com/user-attachments/assets/c2b0a730-4b8f-40be-b9c6-bfd4230e195d" />

### Hardware Connections

| Component | ESP32 Connection | Function |
|---|---|---|
| LED1 | GPIO 18 | Status LED |
| LED2 | GPIO 19 | PWM-controlled LED |
| Push Button | GPIO 23 | Turns the light ON/OFF |
| Potentiometer | GPIO 34 | Analog input |

## PWM Test Results

| Knob Position | PWM Duty Value | Expected PWM Duty Value |
| ------------- | -------------: | ----------------------: |
| 0%            |              0 |                       0 |
| 25%           |             63 |                   63.75 |
| 50%           |            127 |                   127.5 |
| 75%           |            191 |                  191.25 |
| 100%          |            255 |                     255 |

