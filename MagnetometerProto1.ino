#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LIS2MDL.h>

Adafruit_LIS2MDL mag = Adafruit_LIS2MDL(12345); 

void setup(void)
{
  Serial.begin(9600);
}

void loop()
{
  sensors_event_t event;
  mag.getEvent(&event);
  float heading = atan2(event.magnetic.y, event.magnetic.x);
  float declinationAngle = 0.22;
  heading += declinationAngle;
  if (heading < 0) {
    heading += 2 * PI;
  }
  if (heading > 2 * PI) {
    heading -= 2 * PI;
  }
  float headingDegrees = heading * 180 / M_PI;
  Serial.print("Heading : ");
  Serial.print(headingDegrees);
  Serial.println(" degree");
  delay(500);
}
