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


Adafruit_SSD1306 display(128, 64, &Wire, -1);

inline void OLED_Init() {

  bool status_OLED = display.begin(SSD1306_SWITCHCAPVCC, CREPP_SCREEN_ADDRESS);
   if (!status_OLED) 
  {
    Serial.println("Could not find a valid OLED sensor, check wiring!");
  }
  else
  {
    Serial.println("Found a valid OLED sensor");
  }
  delay(10);
  display.clearDisplay();
  display.setRotation(2);
  display.setTextSize(1);               //Size factor
  display.setCursor(0, 0);              //Set cursor to (0,0)
  display.setTextColor(SSD1306_WHITE);  //White text

}

inline void OLED_Clear()
{
  display.clearDisplay();
  display.setCursor(0, 0); 
  display.display();
}

inline void OLED_Println(String str)
{
  display.println(str);
  display.display();
}

inline void OLED_Print(String str)
{
  display.print(str);
  display.display();
}



#endif