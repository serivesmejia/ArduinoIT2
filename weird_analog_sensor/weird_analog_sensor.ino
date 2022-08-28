#define LED 2
#define SENSOR A5

void setup() {
  Serial.begin(9600);
}

void loop() {
  float voltage = analogRead(SENSOR) * (5.0 / 1024.0); 
  int distance = 13 * pow(voltage, -1);
  
  Serial.print("Distance: ");
  Serial.println(distance);

  if(distance <= 15) {
    digitalWrite(LED, HIGH);
    delay(1200);
  } else {
    digitalWrite(LED, LOW);
  }
}
