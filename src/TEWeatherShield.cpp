#include "TEWeatherShield.h"

TEWeatherShield::TEWeatherShield(void) {}

void TEWeatherShield::begin(void) {
  selectSensor(Sensor_NONE);

  HTU21D.begin();
  MS5637.begin();
  MS8607.begin();
  TSYS01.begin();
  TSD305.begin();
}

void TEWeatherShield::selectSensor(enum TEWeatherShield_Sensor sensor) {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  switch (sensor) {
  case Sensor_HTU21D:
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    delay(5);
    break;
  case Sensor_MS5637:
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    delay(5);
    break;
  case Sensor_MS8607:
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    delay(5);
    break;
  case Sensor_TSYS01:
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    delay(5);
    break;
  case Sensor_TSD305:
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    delay(5);
    break;
  case Sensor_NONE:
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    break;
  }
}

void TEWeatherShield::selectHTU21D() { selectSensor(Sensor_HTU21D); }

void TEWeatherShield::selectMS5637() { selectSensor(Sensor_MS5637); }

void TEWeatherShield::selectMS8607() { selectSensor(Sensor_MS8607); }

void TEWeatherShield::selectTSYS01() { selectSensor(Sensor_TSYS01); }

void TEWeatherShield::selectTSD305() { selectSensor(Sensor_TSD305); }
