#ifndef Motor_h
#define Motor_h

#include "Arduino.h"

enum actions{
    START,
    STOP,
    FORWARD,
    BACK
};

enum states{
  ON,
  OFF
};

class Motor{
   
    public:
        Motor( unsigned char pinPwm, unsigned char pinForward, unsigned char pinBack );
        void setDutyCicle( unsigned char dutyCicle );
        void setAction( unsigned char action );

        unsigned char getDutyCicle();

        void start();
        void stop();
        void back();
        void forward();

        

    private:
        unsigned char _pinPwm;
        unsigned char _pinForward;
        unsigned char _pinBack;
        unsigned char _dutyCicle;
        unsigned char _state;

    
};



#endif
