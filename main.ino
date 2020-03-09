#include "Motor.h"
#include "Motors.h"

#define MOTORBOTTOMLEFT 2
#define MOTORBOTTOMRIGHT 3
#define MOTORTOPLEFT 4
#define MOTORTOPRIGHT 5

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

unsigned char j = 0;
unsigned char dutyCicle = 0;
unsigned char pinSerial = 0, bandera = 0;
unsigned char motorSelected;

Motors motors( pinsPwm, pinsBack, pinsForwards );


unsigned char selectMotor( unsigned char pin ){
  unsigned char motorLocation = error;
  switch( pin ){
    case MOTORBOTTOMLEFT:
        motorLocation = bottomLeft;
        break;
    case MOTORBOTTOMRIGHT:
        motorLocation = bottomRight;
        break;
      case MOTORTOPLEFT:
        motorLocation = topLeft;
        break;
    case MOTORTOPRIGHT:
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

   motors.setAllDutyCicle( 125 );
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
  

  
}
