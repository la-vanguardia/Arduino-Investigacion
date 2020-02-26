#ifndef Motors_h
#define Motors_h

#include "Arduino.h"
#include "Motor.h"

enum motorRef{
    bottomLeft,
    bottomRight,
    topLeft,
    topRight
};

enum actions{
    START,
    STOP,
    FORWARD,
    BACK
};

class Motors{
    public:
        Motors( unsigned char *pinsPwm, unsigned char *pinsForward, unsigned char *pinsBack  );
        void setDutyCicle( unsigned char motorReference, unsigned char dutyCicle );
        void action( unsigned char action );

    private:
        Motor _bottomLeft;
        Motor _bottomRight;
        Motor _topLeft;
        Motor _topRight;
};


#endif
