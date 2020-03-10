#include "Arduino.h"
#include "Motor.h"

Motor::Motor( unsigned char pinPwm, unsigned char pinForward, unsigned char pinBack ){
    _pinPwm = pinPwm;
    _pinForward = pinForward;
    _pinBack = pinBack;

    pinMode(_pinPwm, OUTPUT);
    pinMode(_pinForward, OUTPUT);
    pinMode(_pinBack, OUTPUT);

    analogWrite(_pinPwm, _dutyCicle);
    digitalWrite(_pinForward, 0);
    digitalWrite(_pinBack, 0);
}

void Motor::setDutyCicle( unsigned char dutyCicle ){
    _dutyCicle = dutyCicle;
    analogWrite( _pinPwm , _dutyCicle * 255 / 100);
}

void Motor::setAction( unsigned char action ){
  switch( action ){
    case START:
      start();
      break;
    case STOP:
      stop();
      break;
  }
}

void Motor::setState( unsigned char state ){
  _state = state;
  aplyState();
}

unsigned char Motor::getDutyCicle(){
    return _dutyCicle;
}

void Motor::start(){
    aplyState();
}

void Motor::stop(){
    digitalWrite(_pinForward, 0);
    digitalWrite(_pinBack, 0);
}

void Motor::aplyState(){
  switch( _state ){
      case REVERSE:
        digitalWrite(_pinForward, 0);
        digitalWrite(_pinBack, 1);
        break;
      case FORWARD:
        digitalWrite(_pinForward, 1);
        digitalWrite(_pinBack, 0);
        break;
      default:
        digitalWrite(_pinForward, 0);
        digitalWrite(_pinBack, 0);
    }
}