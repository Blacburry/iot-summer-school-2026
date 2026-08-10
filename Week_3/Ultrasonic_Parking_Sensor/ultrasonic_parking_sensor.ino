const int trigPin = 2;
const int echoPin = 3;
const int ledPin1 = 4;
const int ledPin2 = 5;
const int buzzer = 6;
long duration;
long distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.0343) / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm");
  Serial.println("");

  if (distance < 10) {
    tone(buzzer, 1000);
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
    delay(200);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
    delay(200);
  }
  else if (distance >= 10 && distance <= 20) {
    digitalWrite(ledPin2, HIGH);
    tone(buzzer, 1000);
    delay(200);
    noTone(buzzer);
    delay(200);
  }
  else if (distance > 20 && distance <= 50) {
    digitalWrite(ledPin1, HIGH);
    tone(buzzer, 1000);
    delay(500);
    noTone(buzzer);
    delay(500);
  }
  else {
    Serial.println("SAFE");
  }

  delay(200);
}
