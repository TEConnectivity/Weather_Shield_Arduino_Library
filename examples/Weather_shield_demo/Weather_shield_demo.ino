#include <TEWeatherShield.h>

static TEWeatherShield weatherShield;

void setup() {
  Serial.begin(9600);
  Serial.println("TE Connectivity Sensor Solutions");
  Serial.println("==== Arduino Weather Shield ===="); 
  Serial.println();
}

void measure_htu21d() {
  float temperature;
  float humidity;
  
  Serial.println("============ HTU21D ============");    
  weatherShield.selectHTU21D();

  if (weatherShield.HTU21D.is_connected()) {
    weatherShield.HTU21D.set_i2c_master_mode(htu21_i2c_no_hold);       
    weatherShield.HTU21D.read_temperature_and_relative_humidity(&temperature, &humidity); 
    
    Serial.print("- Temperature : ");
    Serial.print(temperature, 1);
    Serial.print((char)176);
    Serial.println("C");
    
    Serial.print("- Humidity : ");
    Serial.print(humidity, 1);
    Serial.println(" %RH");
    Serial.println();
  }
  else {
    Serial.println("HTU21D is disconnected");
  }
}

void measure_ms5637() {
  float temperature;
  float pressure;
  
  Serial.println("============ MS5637 ============");    
  weatherShield.selectMS5637();

  if (weatherShield.MS5637.is_connected()) {    
    weatherShield.MS5637.read_temperature_and_pressure(&temperature, &pressure);
    
    Serial.print("- Temperature : ");
    Serial.print(temperature, 1);
    Serial.print((char)176);
    Serial.println("C");
    
    Serial.print("- Pressure : ");
    Serial.print(pressure, 1);
    Serial.println (" hPa");
    Serial.println();
  }
  else {
    Serial.println("MS5637 is disconnected");
  }
}

void measure_ms8607() {
  float temperature;
  float pressure;
  float humidity;
  
  Serial.println("============ MS8607 ============");    
  weatherShield.selectMS8607();

  if (weatherShield.MS8607.is_connected()) {    
    weatherShield.MS8607.set_humidity_i2c_master_mode(ms8607_i2c_hold); 
    weatherShield.MS8607.read_temperature_pressure_humidity( &temperature, &pressure, &humidity);
    
    Serial.print("- Tempeature : ");
    Serial.print(temperature);
    Serial.print((char)176);
    Serial.println("C");
    
    Serial.print("- Pressure : ");
    Serial.print(pressure);
    Serial.println(" hPa");
    
    Serial.print("- Humidity : ");
    Serial.print(humidity);
    Serial.println("%RH");
    Serial.println();
  }
  else {
    Serial.println("MS8607 is disconnected");
  }
}

void measure_tsys01() {
  float temperature;
  
  Serial.println("============ TSYS01 ============");    
  weatherShield.selectTSYS01();

  if (weatherShield.TSYS01.is_connected()) {    
    weatherShield.TSYS01.read_temperature(&temperature);
    
    Serial.print("- Temperature : ");
    Serial.print(temperature, 1);
    Serial.print((char)176);
    Serial.println("C");
    Serial.println();
  }
  else {
    Serial.println("TSYS01 is disconnected");
  }
}

void measure_tsd305() {
  float temperature;
  float object_temperature;
  
  Serial.println("============ TSD305 ============");    
  weatherShield.selectTSD305();

  if (weatherShield.TSD305.is_connected()) {    
    weatherShield.TSD305.read_temperature_and_object_temperature(&temperature, &object_temperature);
    
    Serial.print("- Temperature : ");
    Serial.print(temperature, 1);
    Serial.print((char)176);
    Serial.println("C");
    
    Serial.print("- Object Temperature : ");
    Serial.print(object_temperature,1);
    Serial.print((char)176);
    Serial.println("C");
    Serial.println();
  }
  else {
    Serial.println("TSD305 is disconnected");
  }
}

void loop() {    
  measure_htu21d();
  measure_ms5637();
  measure_ms8607();
  measure_tsys01();
  measure_tsd305();
  
  Serial.println("================================");
  Serial.println();
  delay(5000);
}