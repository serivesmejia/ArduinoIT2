#define RED 13
#define YELLOW 11
#define GREEN 8

#define BUTTON 7

byte button = LOW;

void setup()
{
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  
  pinMode(BUTTON, INPUT);
}

void loop()
{
  button = digitalRead(BUTTON);
  
  if(button == HIGH)
  {
    digitalWrite(GREEN, HIGH);
    
    delay(5000);
   
    digitalWrite(GREEN, LOW);
    digitalWrite(YELLOW, HIGH);
    
    delay(2000);
    
    digitalWrite(YELLOW, LOW);
    digitalWrite(RED, HIGH);
    
    delay(7000);
    
    digitalWrite(RED, LOW);
  }
}
