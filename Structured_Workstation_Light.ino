#include <Arduino.h>

const uint8_t BUTTON_PIN = 23;
const uint8_t POT_PIN = 34;
const uint8_t STATUS_LED_PIN = 18;
const uint8_t PWM_LED_PIN = 19;

bool buttonPressed = false;
int rawInput = 0;
int requestedDuty = 0;
int appliedDuty = 0;

void readInputs();
void processInputs();
void updateOutputs();
int scaleToDuty(int raw);

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(STATUS_LED_PIN, OUTPUT);
  digitalWrite(STATUS_LED_PIN, LOW);
  pinMode(PWM_LED_PIN, OUTPUT);
  digitalWrite(PWM_LED_PIN, LOW);
  analogReadResolution(12);
  analogSetPinAttenuation(POT_PIN, ADC_11db);
  
  while (true) {
    bool pwmReady = ledcAttach(PWM_LED_PIN, 5000, 8);
    ledcWrite(PWM_LED_PIN, 0);

    if (pwmReady) {
      Serial.println("PWM successful.");
      break; 
    }
  }
}

void loop() {
  readInputs();
  processInputs();
  updateOutputs();
  delay(20); // Pause for 20 ms between loop iterations.
}

void readInputs() {
  buttonPressed = (digitalRead(BUTTON_PIN) == LOW);
  rawInput = analogRead(POT_PIN);
  Serial.println(rawInput);
}

// Converts a raw 12-bit ADC reading (0-4095) into an 8-bit PWM duty (0-255).
int scaleToDuty(int raw) {
  uint8_t temporary = map(raw, 0, 4095, 0, 255);
  return constrain(temporary, 0L, 255L);
}

void processInputs() {
  requestedDuty = scaleToDuty(rawInput);
  if (buttonPressed) {
    appliedDuty = requestedDuty;
  } else {
    appliedDuty = 0; // Button released (or PWM failed) -> forced off, regardless of knob.
  }
}

void updateOutputs() {
  digitalWrite(STATUS_LED_PIN, buttonPressed);
  ledcWrite(PWM_LED_PIN, appliedDuty);
}