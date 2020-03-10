
#include "arduino.h"
#include "Motor.h"
#include "Motors.h"

Motors::Motors( unsigned char *pinsPwm, unsigned char *pinsForward, unsigned char *pinsBack  )
:_bottomLeft( pinsPwm[0], pinsForward[0], pinsBack[0] ),
_bottomRight( pinsPwm[1], pinsForward[1], pinsBack[1] ),
_topLeft( pinsPwm[2], pinsForward[2], pinsBack[2] ),
_topRight( pinsPwm[3], pinsForward[3], pinsBack[3] )
{
 
}

void Motors::setAllDutyCicle( unsigned char dutyCicle ){
  _bottomLeft.setDutyCicle( dutyCicle );
  _bottomRight.setDutyCicle( dutyCicle );
  _topLeft.setDutyCicle( dutyCicle );
  _topRight.setDutyCicle( dutyCicle );
}

void Motors::setAllState( unsigned char state ){
  _bottomLeft.setState( state );
  _bottomRight.setState( state );
  _topLeft.setState( state );
  _topRight.setState( state );
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

unsigned char Motors::getDutyCicle( unsigned char motorReference ){
  unsigned char dutyCicle;
  switch( motorReference ){
        case bottomLeft:
            dutyCicle = _bottomLeft.getDutyCicle();
            break;
        case bottomRight:
            dutyCicle = _bottomRight.getDutyCicle();
            break;
        case topLeft:
            dutyCicle = _topLeft.getDutyCicle();
            break;
        case topRight:
            dutyCicle = _topRight.getDutyCicle();
            break;        
    }

 return dutyCicle;
}


void Motors::motorAction( unsigned char motorReference, unsigned char action ){
   switch( motorReference ){
        case bottomLeft:
            _bottomLeft.setAction( action );
            break;
        case bottomRight:
            _bottomRight.setAction( action );
            break;
        case topLeft:
            _topLeft.setAction( action );
            break;
        case topRight:
            _topRight.setAction( action );
            break;  
   }
}

void Motors::setAction( unsigned char action ){
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
        default:
            _bottomLeft.stop();
            _bottomRight.stop();
            _topLeft.stop();
            _topRight.stop();
    }
}
