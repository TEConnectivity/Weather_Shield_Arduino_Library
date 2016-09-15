#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <htu21d.h>
#include <ms5637.h>
#include <ms8607.h>
#include <tsd305.h>
#include <tsys01.h>

enum TEWeatherShield_Sensor {
  Sensor_HTU21D,
  Sensor_MS5637,
  Sensor_MS8607,
  Sensor_TSYS01,
  Sensor_TSD305,
  Sensor_NONE
};

class TEWeatherShield {
public:
  htu21d HTU21D;
  ms5637 MS5637;
  ms8607 MS8607;
  tsys01 TSYS01;
  tsd305 TSD305;

  TEWeatherShield();

  void selectSensor(enum TEWeatherShield_Sensor sensor);
  void selectHTU21D();
  void selectMS5637();
  void selectMS8607();
  void selectTSYS01();
  void selectTSD305();
};
