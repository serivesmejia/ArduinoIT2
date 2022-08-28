//Challenge 9 2 buttons

#include <Robojax_L298N_DC_motor.h>
// motor 1 settings
#define IN1 2
#define IN2 4
#define ENA 3 // ~this pin must be PWM enabled pin

const int CCW = 2; // do not change
const int CW  = 1; // do not change
#define motor1 1 // do not change
#define motor2 2 // do not change
const int pushButtonDelayTime =200;


//*** Push buttons for motor 1 started 
int motor1Speed =60;// speed of motor 1 in % (60 means 60%)
const int motor1PushButtonDirection = 8;// push button for direcion change
const int motor1PushButtonStop = 9;// push button for START/STOP
const int motor1Minimum =15;//30% is minimum for motor 1
// do not change below this line
int motor1Direction =CCW;//
int motor1StopState=HIGH;//Stope state of motor 1
//*** Push buttons for motor 1 started  ended
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%



// use the line below for single motor
Robojax_L298N_DC_motor motor(IN1, IN2, ENA, true);

// use the line below for two motors
//Robojax_L298N_DC_motor motor(IN1, IN2, ENA, IN3, IN4, ENB, true);

void setup() {
  Serial.begin(115200);
  motor.begin();

  //L298N DC Motor by Robojax.com
  pinMode(motor1PushButtonDirection, INPUT_PULLUP);
  pinMode(motor1PushButtonStop, INPUT_PULLUP);

   
}


void loop() {
  updateState1();//read all push 1 buttons

  if(motor1StopState ==HIGH)
  {
    motor.brake(motor1);     
  }else{
    motor.rotate(motor1, motor1Speed, motor1Direction);    
  }
  //motor.demo(1);

  //motor.rotate(motor1, motor1Speed, CW);//run motor1 at 60% speed in CW direction
 delay(pushButtonDelayTime);
  
}//

/*
 * 
 * updateState1()
 * @brief reads push buttons and updates values
 * @param none
 * @return no return
 * Written by Ahmad Shamshiri for robojax.com
 * on Oct 13, 2019 in Ajax, Ontario, Canada
 */
void updateState1()
{

  if(digitalRead(motor1PushButtonDirection) ==LOW){
      if(motor1Direction ==CW)
      {
        motor1Direction =CCW;// 
        Serial.println("*****Now CCW"); 
      }else{
        motor1Direction =CW;//
        Serial.println("*****Now CC");  
      }

  }  

 
  if(digitalRead(motor1PushButtonStop) ==LOW)
  {
   motor1StopState =1-motor1StopState;// toggle Star/stop
  }  
}//updateState end
