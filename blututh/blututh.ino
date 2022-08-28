#define GREEN 2
#define RED 3

void setup() {
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  char value;
  
  if(Serial.available() > 0) {
    value = Serial.read();
  }

  Serial.print(value);
  Serial.print("\n");

  if(value == '1') {
    digitalWrite(GREEN, LOW);
  } else if(value == '0') {
    digitalWrite(GREEN, HIGH);
  }

  
  if(value == '4') {
    digitalWrite(RED, HIGH);
  } else if(value == '3') {
    digitalWrite(RED, LOW);
  }
}
