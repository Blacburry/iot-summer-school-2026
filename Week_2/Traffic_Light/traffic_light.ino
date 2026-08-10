const int LED_PINS[] = {3, 4, 5};
int totalPins = sizeof(LED_PINS)/sizeof(LED_PINS[0]);
const int switchPin = 2;

bool checkPedestrianButton(long time) {
  long start = millis();
  
  while (millis() - start <= time) {
    if (digitalRead(2)) return true;
  }
  return false;
}

void triggerPedestrianButton() {
  digitalWrite(LED_PINS[1], LOW);
  digitalWrite(LED_PINS[2], LOW);
  digitalWrite(LED_PINS[0], HIGH);
  delay(3000);
  digitalWrite(LED_PINS[0], LOW);
}

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < totalPins; i++) pinMode(LED_PINS[i], OUTPUT);
  pinMode(switchPin, INPUT);
}

void loop() {
  for (int i = 0; i < totalPins; i++) {
    if (i == 0) {
      digitalWrite(LED_PINS[i], HIGH);
      delay(5000);
      digitalWrite(LED_PINS[i], LOW);
    }
    else if (i == 1) {
      digitalWrite(LED_PINS[i], HIGH);
      if (checkPedestrianButton(2000)) {
        triggerPedestrianButton();
        break;
      }
      digitalWrite(LED_PINS[i], LOW);
    }
    else if (i == 2) {
      digitalWrite(LED_PINS[i], HIGH);
      if (checkPedestrianButton(4000)) {
        triggerPedestrianButton();
        break;
      }
      digitalWrite(LED_PINS[i], LOW);
    }
  }
}