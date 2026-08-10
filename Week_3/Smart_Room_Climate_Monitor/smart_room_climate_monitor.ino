#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

#define DHTPIN 14
#define DHTTYPE DHT22
#define LED_PIN 18
#define BUZZER_PIN 12

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

DHT dht(DHTPIN, DHTTYPE);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  dht.begin();

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("OLED initialization failed"));
    for (;;);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(15, 20);
  display.println("Weather Station");
  display.setCursor(20, 35);
  display.println("Starting up...");
  display.display();
  delay(2000);
}

void loop() {
  float temp = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temp) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Display temperature and humidity on OLED
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("HOSTEL WEATHER");
  display.println("---------------------");

  display.setCursor(0, 20);
  display.print("Temp:     ");
  display.print(temp, 1);
  display.println(" C");

  display.setCursor(0, 35);
  display.print("Humidity: ");
  display.print(humidity, 1);
  display.println(" %");

  // Check alert condition: Temp > 38°C OR Humidity > 80%
  if (temp > 38.0 || humidity > 80.0) {
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);

    display.setCursor(0, 52);
    display.print("STATUS: ");
    display.println("ALERT!");
  } else {
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);

    display.setCursor(0, 52);
    display.print("STATUS: ");
    display.println("NORMAL");
  }

  display.display();
  delay(2000);
}