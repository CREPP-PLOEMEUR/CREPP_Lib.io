#ifndef CREPP_OLED_H
#define CREPP_OLED_H

#include <Arduino.h>
#include <Wire.h>


/*
 * Code for OLED screen on CREPP.io
 */
#define OLED_ADDRESS 0x3C
#define CREPP_SCREEN_ADDRESS 0x3C ///Sometimes 0x3D ou 0x3F


#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


Adafruit_SSD1306 crepp_display(128, 64, &Wire, -1);

inline void OLED_Init() {

  bool status_OLED = crepp_crepp_display.begin(SSD1306_SWITCHCAPVCC, CREPP_SCREEN_ADDRESS);
   if (!status_OLED) 
  {
    Serial.println("Could not find a valid OLED sensor, check wiring!");
  }
  else
  {
    Serial.println("Found a valid OLED sensor");
  }
  delay(10);
  crepp_display.clearDisplay();
  crepp_display.setRotation(2);
  crepp_display.setTextSize(1);               //Size factor
  crepp_display.setCursor(0, 0);              //Set cursor to (0,0)
  crepp_display.setTextColor(SSD1306_WHITE);  //White text

}

inline void OLED_Clear()
{
  crepp_display.clearDisplay();
  crepp_display.setCursor(0, 0); 
  crepp_display.display();
}

inline void OLED_Println(String str)
{
  crepp_display.println(str);
  crepp_display.display();
}

inline void OLED_Print(String str)
{
  crepp_display.print(str);
  crepp_display.display();
}



#endif