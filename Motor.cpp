#include "Arduino.h"
#include "Motor.h"

Motor::Motor( unsigned char pinPwm, unsigned char pinForward, unsigned char pinBack ){
    _pinPwm = pinPwm;
    _pinForward = pinForward;
    _pinBack = pinBack;

    pinMode(_pinPwm, OUTPUT);
    pinMode(_pinForward, OUTPUT);
    pinMode(_pinBack, OUTPUT);

    analogWrite(_pinPwm, 0);
    digitalWrite(_pinForward, 0);
    digitalWrite(_pinBack, 0);
}

void Motor::setDutyCicle( unsigned char dutyCicle ){
    _dutyCicle = dutyCicle;
}

void Motor::setAction( unsigned char action ){
  switch( action ){
    case START:
      start();
      break;
    case STOP:
      stop();
      break;
    case BACK:
      back();
      break;
    case FORWARD:
      forward();
      break;
  }
}

unsigned char Motor::getDutyCicle(){
    return _dutyCicle;
}

void Motor::start(){
    analogWrite( _pinPwm , _dutyCicle * 255 / 100);
}

void Motor::stop(){
    analogWrite( _pinPwm , 0);
}

void Motor::back(){
    digitalWrite(_pinForward, 0);
    digitalWrite(_pinBack, 1);
}

void Motor::forward(){
    digitalWrite(_pinForward, 1);
    digitalWrite(_pinBack, 0);
}
