int pins[] = {2, 3, 4, 5, 6};
int totalPins = sizeof(pins)/sizeof(pins[0]);
void setup () {
  for (int i=0; i<totalPins; i++) {
    pinMode(pins[i], OUTPUT);
  }
}

void loop() {
  int randomLED = random(0,5);
  int randomONDelay = random(200, 2000);
  int randomOFFDelay = random(200, 2000);
  digitalWrite(pins[randomLED], HIGH);
  delay(randomONDelay);
  digitalWrite(pins[randomLED], LOW);
  delay(randomOFFDelay);
}