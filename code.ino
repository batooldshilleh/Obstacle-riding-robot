#include <AFMotor.h>

// sensor
const int trig = 2 ;
const int echo = 13 ;


//motor
AF_DCMotor motor1(1,MOTOR12_64KHZ);
AF_DCMotor motor2(2,MOTOR12_64KHZ);
AF_DCMotor motor3(3,MOTOR12_64KHZ);
AF_DCMotor motor4(4,MOTOR12_64KHZ);

//speed 
#define MAX_SPEED 200

long duration , distance ;

void setup(){
  Serial.begin(9600);

  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);

  motor1.setSpeed(MAX_SPEED);
  motor2.setSpeed(MAX_SPEED);
  motor3.setSpeed(MAX_SPEED);
  motor4.setSpeed(MAX_SPEED);
}

void loop(){
  digitalWrite(trig,LOW);
    delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  
  duration = pulseIn(echo,HIGH);
  distance = (duration/2) * 0.0343;

  if (distance < 25){
    
    moveBackward();
    delay(500);

    moveStop();
    delay(200);

    turnRight();

    delay(1000);


  }

  else{
    delay(15);
    moveForward();
  }
}

void moveStop(){
   motor1.run(RELEASE);
   motor2.run(RELEASE);
   motor3.run(RELEASE);
   motor4.run(RELEASE);
}

void moveForward(){
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void moveBackward(){
   motor1.run(BACKWARD);
   motor2.run(BACKWARD);
   motor3.run(BACKWARD);
   motor4.run(BACKWARD);
}

void turnRight(){
   motor1.run(FORWARD);
   motor3.run(FORWARD);
   motor2.run(BACKWARD);
   motor4.run(BACKWARD);
   
}
