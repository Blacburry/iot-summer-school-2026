const int TMP_PIN = A0;
int ledPins[] = {2, 3, 4, 5};
int totalLEDs = sizeof(ledPins)/sizeof(ledPins[0]);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0, INPUT);
  for (int i=0; i<totalLEDs; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int TMP_VALUE = analogRead(TMP_PIN);
  float temperature = ((TMP_VALUE * (5.0/1024.0))-0.5)*100;
  if (temperature < 0) {
    digitalWrite(ledPins[0], HIGH);
    digitalWrite(ledPins[1], LOW);
  }
  else if (temperature < 20) {
    digitalWrite(ledPins[0], LOW);
    digitalWrite(ledPins[1], HIGH);
    digitalWrite(ledPins[2], LOW);
  }
  else if (temperature < 40){
    digitalWrite(ledPins[1], LOW);
    digitalWrite(ledPins[2], HIGH);
    digitalWrite(ledPins[3], LOW);
  }
  else {
    digitalWrite(ledPins[2], LOW);
    digitalWrite(ledPins[3], HIGH);
  }
  Serial.println(temperature);
  delay(200);
}
