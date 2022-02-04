#define LED 13
#define BUTTON 1

void setup() {
  Serial.begin(9600);

  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  digitalWrite(LED, LOW);
  
  if(digitalRead(BUTTON) == HIGH) {
    digitalWrite(LED, HIGH);
    delay(10000);
    digitalWrite(LED, LOW);
    Serial.println("el led se prendio por 10 segundos");
  }
}
