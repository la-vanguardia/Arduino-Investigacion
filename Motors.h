#ifndef Motors_h
#define Motors_h

#include "Arduino.h"
#include "Motor.h"

enum motorRef{
    bottomLeft,
    bottomRight,
    topLeft,
    topRight,
    error
};


class Motors{
    public:
        Motors( unsigned char *pinsPwm, unsigned char *pinsForward, unsigned char *pinsBack  );
        void setAllDutyCicle( unsigned char dutyCicle );
        void setDutyCicle( unsigned char motorReference, unsigned char dutyCicle );

        unsigned char getDutyCicle( unsigned char motorReference );
        
        void motorAction( unsigned char motorReference, unsigned char action );
        void setAction( unsigned char action );
        
    private:
        Motor _bottomLeft;
        Motor _bottomRight;
        Motor _topLeft;
        Motor _topRight;
        
};


#endif
