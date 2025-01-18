#ifndef CREPP_BME280_H
#define CREPP_BME280_H

#include <Arduino.h>
#include <Wire.h>


/*
 * Code for BME280 screen on CREPP.io
 */
#define CREPP_BME_ADDRESS 0x76

#include <Adafruit_Sensor.h>
#include "Adafruit_BME280.h"


Adafruit_BME280 crepp_bme;

inline void BME280_Init() {

  bool status_BME = crepp_bme.begin(CREPP_BME_ADDRESS);  

  if (!status_BME) 
  {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
  }
  else
  {
    Serial.println("BME280 initialized!");
  }

}

inline float BME280_Get_Temperature()
{
  return crepp_bme.readTemperature();
}

inline float BME280_Get_Pressure()
{
  return crepp_bme.readPressure() / 100.0F;
}

inline float BME280_Get_Humidity()
{
  return crepp_bme.readHumidity();
}
inline float BME280_Get_Altitude(float localPressure)
{
  return crepp_bme.readAltitude(localPressure); // Adjust to local pressure
}




#endif