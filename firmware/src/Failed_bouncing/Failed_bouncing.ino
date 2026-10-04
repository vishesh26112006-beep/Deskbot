#define BUTTON_PIN 19

int lastState = HIGH;
int pressCount = 0;

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  int state = digitalRead(BUTTON_PIN);

  if (lastState == HIGH && state == LOW) {   // falling edge = press
    pressCount++;
    Serial.print("Presses: ");
    Serial.println(pressCount);
  }
  lastState = state;
}