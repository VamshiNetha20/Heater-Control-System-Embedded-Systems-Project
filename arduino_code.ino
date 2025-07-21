#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// Pin setup
#define DHT_PIN 2
#define DHT_TYPE DHT22
#define BUZZER_PIN 3
#define HEATER_PIN 4

// Thresholds
#define TEMP_HEATING 28.0
#define TEMP_STABILIZING 32.0
#define TEMP_OVERHEAT 60.0

DHT dht(DHT_PIN, DHT_TYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

// State Machine
enum State {
  IDLE,
  HEATING,
  STABILIZING,
  TARGET_REACHED,
  OVERHEAT
};

State currentState = IDLE;

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(HEATER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(HEATER_PIN, LOW);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("  upliance.ai");
  lcd.setCursor(0, 1);
  lcd.print(" Heater System");
  delay(2000);
  lcd.clear();
}

void loop() {
  float temp = dht.readTemperature();

  if (isnan(temp)) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error");
    Serial.println("DHT Sensor Error");
    delay(2000);
    return;
  }

  // State determination
  if (temp >= TEMP_OVERHEAT) {
    currentState = OVERHEAT;
  } else if (temp >= TEMP_STABILIZING) {
    currentState = TARGET_REACHED;
  } else if (temp >= TEMP_HEATING) {
    currentState = STABILIZING;
  } else {
    currentState = HEATING;
  }

  // Actions based on state
  switch (currentState) {
    case IDLE:
      digitalWrite(HEATER_PIN, LOW);
      digitalWrite(BUZZER_PIN, LOW);
      break;

    case HEATING:
      digitalWrite(HEATER_PIN, HIGH);
      digitalWrite(BUZZER_PIN, LOW);
      break;

    case STABILIZING:
      digitalWrite(HEATER_PIN, HIGH);
      digitalWrite(BUZZER_PIN, LOW);
      break;

    case TARGET_REACHED:
      digitalWrite(HEATER_PIN, LOW);
      digitalWrite(BUZZER_PIN, LOW);
      break;

    case OVERHEAT:
      digitalWrite(HEATER_PIN, LOW);
      digitalWrite(BUZZER_PIN, HIGH);
      break;
  }

  // LCD Output
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("State: ");
  printStateText(currentState);

  // Serial Logging
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print(" C | State: ");
  printStateSerial(currentState);

  delay(2000);
}

void printStateText(State state) {
  switch (state) {
    case IDLE: lcd.print("Idle"); break;
    case HEATING: lcd.print("Heating"); break;
    case STABILIZING: lcd.print("Stabilizing"); break;
    case TARGET_REACHED: lcd.print("Target"); break;
    case OVERHEAT: lcd.print("Overheat"); break;
  }
}

void printStateSerial(State state) {
  switch (state) {
    case IDLE: Serial.println("Idle"); break;
    case HEATING: Serial.println("Heating"); break;
    case STABILIZING: Serial.println("Stabilizing"); break;
    case TARGET_REACHED: Serial.println("Target Reached"); break;
    case OVERHEAT: Serial.println("Overheat!"); break;
  }
}
