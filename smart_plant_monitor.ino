
#include <Wire.h>
#include <Adafruit_MLX90614.h> // IR Sensor Library
#include <LiquidCrystal_I2C.h> // LCD I2C Library

// Initialize MLX90614 sensor
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

// Initialize LCD (I2C address: 0x27, 16 columns, 2 rows)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pin definitions
const int soilMoisturePin = A0;   // Soil moisture sensor
const int lightSensorPin = A1;    // LDR (light sensor)
const int trigPin = 8;            // Ultrasonic sensor TRIG
const int echoPin = 7;            // Ultrasonic sensor ECHO
const int redLEDPin = 10;         // Red LED for obstacle alert
const int buzzerPin = 9;          // Buzzer for dry soil alert

void setup() {
  Serial.begin(9600);

  // Initialize sensors and LCD
  mlx.begin();
  lcd.begin(16, 2); // Specify LCD dimensions
  lcd.backlight();

  pinMode(soilMoisturePin, INPUT);
  pinMode(lightSensorPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  lcd.setCursor(0, 0);
  lcd.print("Smart Plant Mon");
  delay(2000);
  lcd.clear();
}

void loop() {
  float ambientTemp = mlx.readAmbientTempC();
  float objectTemp = mlx.readObjectTempC();
  int soilMoisture = analogRead(soilMoisturePin);
  int lightLevel = analogRead(lightSensorPin);
  int distance = getDistance();

  int soilMoisturePercent = map(soilMoisture, 0, 1023, 0, 100);

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(objectTemp, 1);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Soil: ");
  lcd.print(soilMoisturePercent);
  lcd.print("% ");

  if (distance < 20) {
    digitalWrite(redLEDPin, HIGH);
    lcd.setCursor(12, 0);
    lcd.print("Obs!");
  } else {
    digitalWrite(redLEDPin, LOW);
    lcd.setCursor(12, 0);
    lcd.print("    ");
  }

  if (soilMoisturePercent < 30) {
    lcd.setCursor(12, 1);
    lcd.print("Dry!");
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(buzzerPin, LOW);
    lcd.setCursor(12, 1);
    lcd.print("    ");
  }

  Serial.print("Ambient Temp: ");
  Serial.print(ambientTemp);
  Serial.print("C, Object Temp: ");
  Serial.print(objectTemp);
  Serial.print("C, Soil Moisture: ");
  Serial.print(soilMoisturePercent);
  Serial.print("%, Light Level: ");
  Serial.print(lightLevel);
  Serial.print(", Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(2000);
}

int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;
  return distance;
}
