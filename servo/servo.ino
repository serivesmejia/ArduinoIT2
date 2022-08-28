#include <Servo.h>

#define SENSOR A0

Servo servo_9;

void setup()
{
  servo_9.attach(9);
  Serial.begin(9600);
}

void loop()
{
  int sensorValue = analogRead(SENSOR);
  
  Serial.println(sensorValue);
  
  if(sensorValue >= 620) {
    servo_9.write(180);
  } else if(sensorValue >= 540) {
    servo_9.write(90);
  } else {
    servo_9.write(0);
  }
  
  delay(200);
}
