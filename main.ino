#include "Motor.h"
#include "Motors.h"

unsigned char pinsPwm[4] = { 9, 10, 5, 6 };
unsigned char pinsBack[4] = {7, 12, 2, 11};
unsigned char pinsForwards[4] = {8, 13, 3, 13};

void setTMR0(){
  TCCR1A = 0x00;
  TCCR1B = 0x11;
  ICR1 = 214;
}

void setPwms( unsigned char n ){
  unsigned char i;
  for( i=0; i<n; i++){
    pwm( pinsPwm[i] );
 }
}

void setPinsPwms( unsigned char n ){
  unsigned char i;
  for( i=0; i<n; i++){
    pinMode( pinControlPwm[i], OUTPUT );
    if( i%2 == 0 ){
      digitalWrite( pinControlPwm[i], HIGH );  
    } else{
      digitalWrite( pinControlPwm[i], LOW );
    }
   }
}

void pwm(unsigned char pin){
  pinMode( pin, OUTPUT );
  analogWrite( pin, 123 );
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
  // put your setup code here, to run once:
   Serial.begin( 19200 );
   Serial.println("HOLA, soy el Chacras! UwU");
   //setPwms( 2 );
   //setPinsPwms( 4 );  
   //pinMode( 6, INPUT );
   motor.setDutyCicle( 50 );
   Serial.println( motor.getDutyCicle() );
   motor.start();
   motor.forward();
}

void loop() {
  // put your main code here, to run repeatedly:
  if( Serial.available() > 0 ){
    serialRead();
  }
  if( bandera == 1 ){
    bandera = 0;
    Serial.println( dutyCicle );
    motor.setDutyCicle( dutyCicle );
    motor.start();
  }
  

  
}
