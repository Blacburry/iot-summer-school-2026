int blink_count = 1;
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}
void loop() {
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  delay(500);
  Serial.print("Blink Count:");
  Serial.println(blink_count++);
}
