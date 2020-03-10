#ifndef Motor_h
#define Motor_h
#define DUTY_CICLE 30

#include "Arduino.h"

enum actions{
    START,
    STOP
};

enum states{
  REVERSE,
  FORWARD
};

class Motor{
   
    public:
        Motor( unsigned char pinPwm, unsigned char pinForward, unsigned char pinBack );
        void setDutyCicle( unsigned char dutyCicle );
        void setAction( unsigned char action );
        void setState( unsigned char state );

        unsigned char getDutyCicle();

        void start();
        void stop();

    private:
        unsigned char _pinPwm;
        unsigned char _pinForward;
        unsigned char _pinBack;
        unsigned char _dutyCicle = DUTY_CICLE;
        unsigned char _state = FORWARD;

        void aplyState();
    
};



#endif
