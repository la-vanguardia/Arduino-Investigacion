#include "Arduino.h"
#include "Motor.h"

Motor::Motor( unsigned char pinPwm, unsigned char pinForward, unsigned pinBack ){
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
    analogWrite( _pinPwm , _dutyCicle * 255 / 100);
}

unsigned char Motor::getDutyCicle(){
    return _dutyCicle;
}

void Motor::action( unsigned char action  ){
    switch( action ){
        case STOP:
            analogWrite(_pinPwm, 0);
            break;
        case START:
            analogWrite(_pinPwm, _dutyCicle * 255 / 100);
            break;
        case FORWARD:
            digitalWrite(_pinForward, 1);
            digitalWrite(_pinBack, 0);
            break;
        case BACK:
            digitalWrite(_pinForward, 0);
            digitalWrite(_pinBack, 1);
            break;
    }
}

