#define TOUCH 1
#define BTT_1 2
#define BTT_2 3
#define BTT_3 4

#define LED 9

void setup() {
  Serial.begin(9600);

  pinMode(TOUCH, INPUT);
  pinMode(BTT_1, INPUT);
  pinMode(BTT_2, INPUT);
  pinMode(BTT_3, INPUT);
  
  pinMode(LED, OUTPUT);
}

void loop() {
  byte touch = digitalRead(TOUCH);
  byte btt1 = digitalRead(BTT_1);
  byte btt2 = digitalRead(BTT_2);
  byte btt3 = digitalRead(BTT_3);

  if(btt3 == HIGH) {
    Serial.println("Boton 3");
    delay(100);
    if(touch == HIGH) {
      delay(100);
      Serial.println("Boton touch");
      if(btt2 == HIGH) {
        delay(100);
        Serial.println("Boton 2, codigo correcto");

        digitalWrite(LED, HIGH);
        delay(10000);
        digitalWrite(LED, LOW);
      }
    }
  }
}
