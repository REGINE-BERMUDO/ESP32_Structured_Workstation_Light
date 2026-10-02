# Structured Workstation Light
## Demo

https://github.com/user-attachments/assets/a3b88eaf-ff6d-442f-8bae-57701d96e21c


## Circuit Diagram
<img width="975" height="597" alt="image" src="https://github.com/user-attachments/assets/c2b0a730-4b8f-40be-b9c6-bfd4230e195d" />

### Hardware Connections

| Component | ESP32 Connection | Function |
|---|---|---|
| LED/Light | ESP32 GPIO Digital Output | Controls the workstation light |
| Push Button | ESP32 GPIO Digital Input | Turns the light ON/OFF |
| Resistor | LED/Button circuit | Limits current / provides proper input |
| GND | ESP32 GND | Common ground |
| VCC | ESP32 3.3V | Power supply |

## Expected vs. Observed Behavior

| Test | Expected Behavior | Observed Behavior | Result |
|---|---|---|---|
| Button Pressed | Status LED turns ON | Status LED turns ON | ✓ |
| Button Released | Status LED turns OFF and PWM LED remains OFF | Status LED turns OFF and PWM LED remains OFF | ✓ |
| Potentiometer at Minimum | PWM LED brightness is at its lowest level while the button is pressed | PWM LED is OFF or at minimum brightness | ✓ |
| Potentiometer at Maximum | PWM LED reaches maximum brightness while the button is pressed | PWM LED reaches maximum brightness | ✓ |
