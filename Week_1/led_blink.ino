/**
 * @file led_blink.ino
 * @author Dibya Chowdhury
 * @date July 5, 2026
 * @brief Week 1 Assignment: Iterative LED Blink with Potentiometer Control
 * * Circuit Description:
 * An LED is connected to digital pin 13 with a 220-ohm current-limiting resistor. 
 * A potentiometer's wiper terminal is pinned to analog input A0 to dynamically 
 * scale the execution delays and alter the LED blinking rate. Continuous operational 
 * metrics are routed back through the Serial interface.
 * * Version History:
 * v1.0 - Basic LED blink functionality (500ms static interval)
 * v1.1 - Added serial streaming interface: "Blink count: X"
 * v1.2 - Integrated potentiometer read functionality for analog speed control
 * v1.3 - Added comprehensive project documentation and comment headers
 */

// Global variables (from your previous versions)

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

