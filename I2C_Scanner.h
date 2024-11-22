#ifndef I2C_SCANNER_H
#define I2C_SCANNER_H

#include <Arduino.h>
#include <Wire.h>


/*
 * Code for I2C Scanner on CREPP.io
 */
#define BME280_ADDRESS 0x3
#define OLED_ADDRESS 0x3C
#define ADS1115_ADDRESS_1 0x48
#define ADS1115_ADDRESS_2 0x49

inline void I2C_Scan() {

  Wire.begin();

  byte error, address;
  int nDevices;

  Serial.println("Scanning device on CREPP.io board...");

  nDevices = 0;
  for(address = 1; address < 127; address++ ) 
  {
    
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0)
    {
      Serial.print("I2C device found at address 0x");
      if (address<16) 
      {
        Serial.print("0");
      }
      Serial.print(address,HEX);
      if(address == OLED_ADDRESS)
      {
        Serial.print(" - OLED screen");
      }
      Serial.println("  !");

      nDevices++;
    }
    else if (error==4) 
    {
      Serial.print("Unknown error at address 0x");
      if (address<16) 
        Serial.print("0");
      Serial.println(address,HEX);
    }    
  }
  if (nDevices == 0)
    Serial.println("No I2C devices found\n");
  else
    Serial.println("done\n");

  delay(1000);           // wait 5 seconds for next scan

}

#endif