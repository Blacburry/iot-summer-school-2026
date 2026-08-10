const int LDR_PIN = A0;
const int LED_PIN = 2;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LDR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.println("LDR Calibration System Ready.....");
}

void loop() {
  // put your main code here, to run repeatedly:
  int LDR_VALUE = analogRead(LDR_PIN);
  if (LDR_VALUE <= 300) {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("There is not enough light");
  }
  else {
    digitalWrite(LED_PIN, LOW);
    Serial.println("There is enough light");
  }
  delay(350);
}
