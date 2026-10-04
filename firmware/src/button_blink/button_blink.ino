#define BUTTON_PIN 19
#define LED_PIN 4

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int state = digitalRead(BUTTON_PIN);
  if (state == LOW) {
    digitalWrite(LED_PIN, HIGH);   // pressed
  } else {
    digitalWrite(LED_PIN, LOW);    // released
  }
  Serial.println(state);
}