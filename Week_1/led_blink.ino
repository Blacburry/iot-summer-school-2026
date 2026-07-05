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
int blinkCount = 0;
const int POT_PIN = A0;
const int LED_PIN = 13;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Your Q4 v1.2 logic reading the potentiometer and blinking goes here...
}
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
  if (POT_VALUE == 0) {
    POT_VALUE = 1;
  }
  float time = (5000.0/1024.0)*POT_VALUE;
  digitalWrite(LED_PIN, HIGH);
  delay(time);
  digitalWrite(LED_PIN, LOW);
  delay(time);
}
