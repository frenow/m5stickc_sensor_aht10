#include "M5StickCPlus2.h"
#include "Wire.h"
#include <Adafruit_AHTX0.h>
Adafruit_AHTX0 aht;

void setup() {
  M5.begin();  // 
  M5.Lcd.setTextSize(3);
  M5.Lcd.setRotation(3);
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.print("SENSOR AHT10");  
  
  Wire.begin(0, 26);

  Serial.begin(9600);
  Serial.println("Adafruit AHT10/AHT20 demo!");
    
  if (! aht.begin()) {
    Serial.println("Could not find AHT? Check wiring");
    while (1) delay(10);
  }
  Serial.println("AHT10 or AHT20 found");

}

void loop() {
  //M5.Lcd.clear();  
  sensors_event_t humidity, temp;
  aht.getEvent(&humidity, &temp);// populate temp and humidity objects with fresh data
  Serial.print("Temperature: "); Serial.print(temp.temperature); Serial.println(" degrees C");
  Serial.print("Humidity: "); Serial.print(humidity.relative_humidity); Serial.println("% rH");

  M5.Lcd.setCursor(0, 50);
  M5.Lcd.printf("T: %f oC H: %f rH", temp.temperature, humidity.relative_humidity);

  delay(5000);

}