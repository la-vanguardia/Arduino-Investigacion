#ifndef Motor_h
#define Motor_h

#include "Arduino.h"



class Motor{
   
    public:
        Motor( unsigned char pinPwm, unsigned char pinForward, unsigned pinBack );
        void setDutyCicle( unsigned char dutyCicle );

        void start();
        void stop();
        void back();
        void forward();

        unsigned char getDutyCicle();

    private:
        unsigned char _pinPwm;
        unsigned char _pinForward;
        unsigned char _pinBack;
        unsigned char _dutyCicle;

    
};

#endif