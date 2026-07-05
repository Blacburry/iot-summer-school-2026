const int POT_PIN = A0;
const int LED_PIN = 2;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(POT_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int POT_VALUE = analogRead(POT_PIN);
  Serial.println(POT_VALUE);
  float time = (5000.0/1024.0)*POT_VALUE;
  digitalWrite(LED_PIN, HIGH);
  delay(time);
  digitalWrite(LED_PIN, LOW);
  delay(time);
}
