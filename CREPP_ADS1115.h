#ifndef CREPP_ADS1115_H
#define CREPP_ADS1115_H

#include <Arduino.h>
#include <SPI.h>
#include "Adafruit_ADS1X15.h"

/*
 * Code for BME280 screen on CREPP.io
 */

Adafruit_ADS1115 _crepp_ads;


inline void ADS1115_Init(uint8_t address) {

  //I2C_Scan();

  bool status_ADS = _crepp_ads.begin(address);  

  if (!status_ADS) 
  {
    Serial.println("Could not find a valid ADS1115 sensor, check wiring!");
  }

}

inline float ADS1115_Get_Channel_0()
{
  return _crepp_ads.readADC_SingleEnded(0);
}

inline float ADS1115_Get_Channel_1()
{
  return _crepp_ads.readADC_SingleEnded(1);
}

inline float ADS1115_Get_Channel_2()
{
  return _crepp_ads.readADC_SingleEnded(2);
}

inline float ADS1115_Get_Channel_3()
{
  return _crepp_ads.readADC_SingleEnded(3);
}



#endif