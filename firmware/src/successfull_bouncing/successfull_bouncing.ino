#define BUTTON_PIN 19

const unsigned long DEBOUNCE_MS = 30;

int stableState = HIGH;        // the debounced (trusted) state
int lastReading = HIGH;        // the raw reading from last loop
unsigned long lastChange = 0;  // when the raw reading last changed
int pressCount = 0;

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  int reading = digitalRead(BUTTON_PIN);
  unsigned long now = millis();

  if (reading != lastReading) {
    lastChange = now;          // raw signal moved: restart the timer
    lastReading = reading;
  }

  if (now - lastChange >= DEBOUNCE_MS && reading != stableState) {
    stableState = reading;     // stable long enough: accept it
    if (stableState == LOW) {
      pressCount++;
      Serial.print("Presses: ");
      Serial.println(pressCount);
    }
  }
}