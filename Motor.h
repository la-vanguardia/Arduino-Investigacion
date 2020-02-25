#ifndef Motor_h
#define Motor_h

#include "Arduino.h"

enum actions{
    START,
    STOP,
    FORWARD,
    BACK
};

class Motor{
   
    public:
        Motor( unsigned char pinPwm, unsigned char pinForward, unsigned pinBack );
        void setDutyCicle( unsigned char dutyCicle );

        void action( unsigned char action );

        unsigned char getDutyCicle();

    private:
        unsigned char _pinPwm;
        unsigned char _pinForward;
        unsigned char _pinBack;
        unsigned char _dutyCicle;

    
};

#endif