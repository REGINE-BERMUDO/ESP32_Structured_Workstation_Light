# Structured Workstation Light
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

