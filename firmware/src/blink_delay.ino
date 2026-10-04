#define LED_PIN 4   // D4 = GPIO 4

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);   // LED on
  Serial.println("ON");
  delay(2000);                    // wait half a second

  digitalWrite(LED_PIN, LOW);    // LED off
  Serial.println("OFF");
  delay(2000);
}
