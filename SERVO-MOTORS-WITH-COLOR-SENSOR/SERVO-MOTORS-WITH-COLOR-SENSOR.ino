#include <Wire.h>
#include "Adafruit_TCS34725.h"
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
int johanna = 2; //red led
int cla = 3; //green led
int pos = 0;    // variable to store the servo position

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_614MS, TCS34725_GAIN_1X);

void setup() {
   Serial.begin(9600);

  pinMode(johanna, OUTPUT);
  pinMode(cla, OUTPUT);
  pinMode(aj, OUTPUT);

  if (tcs.begin()) {
    Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1);
  }

  myservo.attach(5);  
}

void loop() {
  uint16_t r, g, b, c, colorTemp, lux;

  tcs.getRawData(&r, &g, &b, &c);
  colorTemp = tcs.calculateColorTemperature_dn40(r, g, b, c);
  lux = tcs.calculateLux(r, g, b);

if ((lux<99) && (r-g>90)) {
  digitalWrite(johanna, HIGH);   
  digitalWrite(cla, LOW);
  digitalWrite(aj, LOW);   
} //ripe
else if ((lux>99) && (r-g<90))  {
  digitalWrite(johanna, LOW);
  digitalWrite(cla, HIGH);  
  digitalWrite(aj, LOW);    
} //unripe
else if ((lux<99) && (r-g<90)) {
  digitalWrite(johanna, LOW);
  digitalWrite(cla, LOW);
  digitalWrite(aj, HIGH);   
} 


  Serial.print("Color Temp: "); Serial.print(colorTemp, DEC); Serial.print(" K - ");
  Serial.print("Lux: "); Serial.print(lux, DEC); Serial.print(" - ");
  Serial.print("R: "); Serial.print(r, DEC); Serial.print(" ");
  Serial.print("G: "); Serial.print(g, DEC); Serial.print(" ");
  Serial.print("B: "); Serial.print(b, DEC); Serial.print(" ");
  Serial.print("C: "); Serial.print(c, DEC); Serial.print(" ");
  Serial.println(" ");
  
  for (pos = 0; pos <= 60; pos += 1) { 
    myservo.write(pos);            
    delay(15);                     
  }
  for (pos = 60; pos >= 0; pos -= 1) { 
    myservo.write(pos);             
    delay(20);                     
  }
}
