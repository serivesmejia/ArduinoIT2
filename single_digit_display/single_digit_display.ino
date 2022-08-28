#define A 6
#define B 7
#define C 8
#define D 9
#define E 10
#define F 11
#define G 12

void setup() {
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
}

void loop() {
  allLow();
  digitalWrite(G, HIGH);
  
  delay(1000);
  
  allLow();
  digitalWrite(A, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(F, HIGH);
  
  delay(1000);
  
  allLow();
  digitalWrite(C, HIGH);
  digitalWrite(F, HIGH);
  
  delay(1000);

  allLow();
  digitalWrite(F, HIGH);
  digitalWrite(E, HIGH);
  
  delay(1000);

  allLow();
  digitalWrite(A, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);

  delay(1000);

  allLow();
  digitalWrite(B, HIGH);
  digitalWrite(E, HIGH);

  delay(1000);
  
  allLow();
  digitalWrite(B, HIGH);

  delay(1000);

  allLow();
  digitalWrite(G, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);

  delay(1000);
  
  allLow();
  
  delay(1000);
  
  allLow();
  digitalWrite(E, HIGH);
  
  delay(1000);
}

void allLow() {
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW); 
  digitalWrite(G, LOW);
}
