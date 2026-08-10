const int pins[] = {2, 3, 4, 5, 6};
int totalPins = sizeof(pins)/sizeof(pins[0]);

void turnOnLED(int a) {
  digitalWrite(pins[a], HIGH);
  delay(500);
}

void turnOffLED(int a) {
  digitalWrite(pins[a], LOW);
  delay(500);
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int i=0; i<totalPins; i++) {
    pinMode(pins[i], OUTPUT); 
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i=0; i<totalPins; i++) {
      turnOnLED(i);
      turnOffLED(i);
  }
}
