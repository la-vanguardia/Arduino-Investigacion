#include "Motor.h"
#include "Motors.h"
#include <TimerOne.h>

#define MOTOR_BOTTOM_LEFT 2
#define MOTOR_BOTTOM_RIGHT 3
#define MOTOR_TOP_LEFT 4
#define MOTOR_TOP_RIGHT 5

#define PULSE 4
#define ONE_MINUTE 60   //tiempo en segundos
#define TIME_INTERRUPT 1 //tiempo en segundos

/* MOTORES CON ARDUINO NANO / UNO  */
/* 
unsigned char pinsPwm[4] = { 9, 10, 5, 6 };
unsigned char pinsBack[4] = {7, 12, 2, 11};
unsigned char pinsForwards[4] = {8, 13, 3, 13};
*/

/* MOTORES CON ARDUINO MEGA */

unsigned char pinsPwm[4] = { 2, 3, 4, 5 };
unsigned char pinsBack[4] = { 22, 24, 26, 28 };
unsigned char pinsForwards[4] = { 23, 25, 27, 29 };
unsigned char pinsInterrupt[4] = { 21, 20, 19, 18 };
unsigned long int counters[4] = { 0 };
double rpmValues[4] = { 0.0 };

unsigned char j = 0, bandera_rpm = 0;
unsigned char dutyCicle = 0;
unsigned char pinSerial = 0, bandera = 0;
unsigned char motorSelected;

Motors motors( pinsPwm, pinsBack, pinsForwards );

void counterMotorBottomLeft(){
  counters[0]++;
}

void counterMotorBottomRight(){
  counters[1]++;
}

void counterMotorTopLeft(){
  counters[2]++;
}

void counterMotorTopRight(){
  counters[3]++;
}

void rpm(){
  unsigned char i;
  for( i=0; i<4; i++){
    rpmValues[i] = counters[i] * ONE_MINUTE / (PULSE * TIME_INTERRUPT);
  }
  bandera_rpm = 1;
}

unsigned char selectMotor( unsigned char pin ){
  unsigned char motorLocation = error;
  switch( pin ){
    case MOTOR_BOTTOM_LEFT:
        motorLocation = bottomLeft;
        break;
    case MOTOR_BOTTOM_RIGHT:
        motorLocation = bottomRight;
        break;
      case MOTOR_TOP_LEFT:
        motorLocation = topLeft;
        break;
    case MOTOR_TOP_RIGHT:
        motorLocation = topRight;
        break;
  }

  return motorLocation;
}

void serialRead(){
  String data = Serial.readStringUntil('\n');
  switch( j ){
    case 0:
      pinSerial = data.toInt();
      j++;
      break;
    case 1:
      bandera = 1;
      j = 0;
      dutyCicle = data.toInt();
      break;
  }
  
}

void setup() {
   Serial.begin( 19200 );
   Serial.println("HOLA, soy el Chacras! UwU");

   motors.setAction( START );
   
   Timer1.initialize( 1000000 );
   Timer1.attachInterrupt( rpm );
   attachInterrupt( digitalPinToInterrupt( pinsInterrupt[0] ) , counterMotorBottomLeft, RISING);
   attachInterrupt( digitalPinToInterrupt( pinsInterrupt[1] ) , counterMotorBottomRight, RISING);
   attachInterrupt( digitalPinToInterrupt( pinsInterrupt[2] ) , counterMotorTopLeft, RISING);
   attachInterrupt( digitalPinToInterrupt( pinsInterrupt[3] ) , counterMotorTopRight, RISING);
   
}

void loop() {
  // put your main code here, to run repeatedly:
  if( Serial.available() > 0 ){
    serialRead();
  }
  if( bandera == 1 ){
    bandera = 0;
    motorSelected = selectMotor( pinSerial );
    motors.setDutyCicle( motorSelected, dutyCicle );
    Serial.println( motorSelected );
    Serial.println( dutyCicle );
  }
  if( bandera_rpm == 1 ){
    bandera_rpm = 0;
    Serial.println( counters[0] );
    Serial.println( counters[1] );
    counters[0] = 0;
    counters[1] = 0;
    Serial.println( "-----" );
  }
  

  
}
