#define MOTOR_SPEED 180

#define ECHO 4
#define TRIG 3

#define RED A0

//Right motor
int enableRightMotor=6;
int rightMotorPin1=7;
int rightMotorPin2=8;

//Left motor
int enableLeftMotor=5;
int leftMotorPin1=9;
int leftMotorPin2=10;

int ticksBlocked = 0;

void setup()
{
  //The problem with TT gear motors is that, at very low pwm value it does not even rotate.
  //If we increase the PWM value then it rotates faster and our robot is not controlled in that speed and goes out of line.
  //For that we need to increase the frequency of analogWrite.
  //Below line is important to change the frequency of PWM signal on pin D5 and D6
  //Because of this, motor runs in controlled manner (lower speed) at high PWM value.
  //This sets frequecny as 7812.5 hz.
  TCCR0B = TCCR0B & B11111000 | B00000010 ;
  
  // put your setup code here, to run once:
  pinMode(enableRightMotor, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);
  
  pinMode(enableLeftMotor, OUTPUT);
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);

  rotateMotor(0,0);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  pinMode(RED, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  char value;
  
  if(Serial.available() > 0) {
    value = Serial.read();
  }

  Serial.print(value);
  Serial.print("\n");
  
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);

  delayMicroseconds(10);

  digitalWrite(TRIG, LOW);

  long duration = pulseIn(ECHO, HIGH);
  float distance = duration * 0.034 / 2.0;

  Serial.print("Distance: ");
  Serial.println(distance);

  if(distance < 10) {
    ticksBlocked++;
    Serial.println(ticksBlocked);
    
    if(ticksBlocked >= 20) {
      rotateMotor(0, 0);
    }
  } else {
    ticksBlocked = 0;
    if(value == 'u') {
      rotateMotor(MOTOR_SPEED, -MOTOR_SPEED);
    } else if(value == 'd') {
      rotateMotor(-MOTOR_SPEED, MOTOR_SPEED);
    } else if(value == 'l') {
      rotateMotor(MOTOR_SPEED, MOTOR_SPEED);
    } else if(value == 'r') {
      rotateMotor(-MOTOR_SPEED, -MOTOR_SPEED);
    } else {
      rotateMotor(0, 0);
    }
  }
}


void rotateMotor(int rightMotorSpeed, int leftMotorSpeed)
{
  if((rightMotorSpeed == 0 && rightMotorSpeed != -MOTOR_SPEED) && (leftMotorSpeed == 0 && leftMotorSpeed != MOTOR_SPEED)) {
    digitalWrite(RED, HIGH);
  } else {
    digitalWrite(RED, LOW);
  }
  
  if (rightMotorSpeed < 0)
  {
    digitalWrite(rightMotorPin1,LOW);
    digitalWrite(rightMotorPin2,HIGH);    
  }
  else if (rightMotorSpeed > 0)
  {
    digitalWrite(rightMotorPin1,HIGH);
    digitalWrite(rightMotorPin2,LOW);      
  }
  else
  {
    digitalWrite(rightMotorPin1,LOW);
    digitalWrite(rightMotorPin2,LOW);      
  }

  if (leftMotorSpeed < 0)
  {
    digitalWrite(leftMotorPin1,LOW);
    digitalWrite(leftMotorPin2,HIGH);    
  }
  else if (leftMotorSpeed > 0)
  {
    digitalWrite(leftMotorPin1,HIGH);
    digitalWrite(leftMotorPin2,LOW);      
  }
  else 
  {
    digitalWrite(leftMotorPin1,LOW);
    digitalWrite(leftMotorPin2,LOW);      
  }
  analogWrite(enableRightMotor, abs(rightMotorSpeed));
  analogWrite(enableLeftMotor, abs(leftMotorSpeed));    
}
