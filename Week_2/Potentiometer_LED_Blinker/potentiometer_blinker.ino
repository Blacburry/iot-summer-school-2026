const int POT_PIN = A0;
const int LED_PIN[] = {2, 3, 4};
int totalPins = sizeof(LED_PIN)/sizeof(LED_PIN[0]);

void ledBlink(int pin, float t) {
  digitalWrite(pin, HIGH);
  delay(t);
  digitalWrite(pin, LOW);
  delay(t);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(POT_PIN, INPUT);
  for (int i=0; i<totalPins; i++) {
    pinMode(LED_PIN[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int POT_VALUE = analogRead(POT_PIN);
  Serial.println(POT_VALUE);
  if (POT_VALUE == 0) POT_VALUE = 1;
  float time = (5000.0/1024.0)*POT_VALUE;
  if (POT_VALUE > 0 && POT_VALUE <= 341) {
    ledBlink(LED_PIN[0], time);
  }
  else if (POT_VALUE <= 682) {
    ledBlink(LED_PIN[1], time);
  }
  else {
    ledBlink(LED_PIN[2], time);
  }
}
