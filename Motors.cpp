#include "arduino.h"
#include "Motors.h"

Motors::Motors( unsigned char *pinsPwm, unsigned char *pinsForward, unsigned char *pinsBack  ){
    unsigned char i;
    _bottomLeft = Motor( pinsPwm[0], pinsForward[0], pinsBack[0] );
    _bottomRight = Motor( pinsPwm[1], pinsForward[1], pinsBack[1] );
    _topLeft = Motor( pinsPwm[2], pinsForward[2], pinsBack[2] );
    _topRight = Motor( pinsPwm[3], pinsForward[3], pinsBack[3] );
}

void Motors::setDutyCicle( unsigned char motorReference, unsigned char dutyCicle ){
    switch( motorReference ){
        case bottomLeft:
            _bottomLeft.setDutyCicle( dutyCicle );
            break;
        case bottomRight:
            _bottomRight.setDutyCicle( dutyCicle );
            break;
        case topLeft:
            _topLeft.setDutyCicle( dutyCicle );
            break;
        case topRight:
            _topRight.setDutyCicle( dutyCicle );
            break;        
    }
}

void Motors::action( unsigned char action ){
    switch( action ){
        case STOP:
            _bottomLeft.stop();
            _bottomRight.stop();
            _topLeft.stop();
            _topRight.stop();
            break;
        case START:
            _bottomLeft.start();
            _bottomRight.start();
            _topLeft.start();
            _topRight.start();
            break;
        case FORWARD:
            _bottomLeft.forward();
            _bottomRight.forward();
            _topLeft.forward();
            _topRight.forward();
            break;
        case BACK:
            _bottomLeft.back();
            _bottomRight.back();
            _topLeft.back();
            _topRight.back();
            break;
    }
}