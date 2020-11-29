#include <Arduino.h>

#define WATER_SENSOR_PIN  A0
#define MOTOR_POWER_PIN   2U

#define WATER_LEVEL_THRESHOLD 100U
#define FREQUENCY_MS          1000U

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(WATER_SENSOR_PIN, INPUT);
  pinMode(MOTOR_POWER_PIN, OUTPUT);

  Serial.begin(9600);
  Serial.setTimeout(2000);
  while (!Serial) { }
  Serial.println(F("initialized"));
}

void loop()
{
  uint32_t water = analogRead(WATER_SENSOR_PIN);
  if (water < WATER_LEVEL_THRESHOLD) {
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(MOTOR_POWER_PIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(MOTOR_POWER_PIN, LOW);
  }

  Serial.println(String("loop ") + water);

  delay(FREQUENCY_MS);
}
