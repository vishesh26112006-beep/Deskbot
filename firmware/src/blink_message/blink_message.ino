#define LED_PIN 4

const unsigned long BLINK_INTERVAL = 500;   // ms
const unsigned long MSG_INTERVAL   = 3000;  // ms

unsigned long lastBlink = 0;
unsigned long lastMsg   = 0;
bool ledState = false;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  unsigned long now = millis();

  // Task 1: blink every 500 ms
  if (now - lastBlink >= BLINK_INTERVAL) {
    lastBlink = now;
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState ? HIGH : LOW);
  }

  // Task 2: print a message every 3 seconds
  if (now - lastMsg >= MSG_INTERVAL) {
    lastMsg = now;
    Serial.print("Alive at ");
    Serial.print(now / 1000);
    Serial.println(" s");
  }
}