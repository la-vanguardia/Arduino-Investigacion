
unsigned char pinsPwm[2] = { 9, 10 };
unsigned char pinControlPwm[4] = {7, 8, 11, 12};
unsigned char pinPWMOut1 = 8;
unsigned char pinPWMOut2 = 7;
unsigned char dutyCicle = 0;
unsigned char pinSerial = 0;
unsigned char bandera = 0;
unsigned char j = 0;
/*
 * Serial.println( dutyCicle );
    analogWrite( 9, dutyCicle * 255 / 100);
    dutyCicle = 0;


    unsigned char data = Serial.read(), i = 0;
  switch( j ){
    case 0:
      dutyCicle = 0;
      pinSerial = data - '0';
      j++;
      break;
    case 1:
      pinSerial *= 10;
      pinSerial += data - '0';
      j++;
    case 6:
      bandera = 1;
      j = 0;
      break;
     default:
      j++;
      dutyCicle *= 10;
      dutyCicle += data - '0';
  }
 */

void setTMR0(){
  TCCR1A = 0x00;
  TCCR1B = 0x11;
  ICR1 = 214;
}

void setPwms( unsigned char n ){
  unsigned char i;
  for( i=0; i<n; i++){
    pwm( pinsPwm[i] );
 }
}

void setPinsPwms( unsigned char n ){
  unsigned char i;
  for( i=0; i<n; i++){
    pinMode( pinControlPwm[i], OUTPUT );
    if( i%2 == 0 ){
      digitalWrite( pinControlPwm[i], HIGH );  
    } else{
      digitalWrite( pinControlPwm[i], LOW );
    }
   }
}

void pwm(unsigned char pin){
  pinMode( pin, OUTPUT );
  analogWrite( pin, 0 );
}

void serialRead(){
  String data = Serial.readStringUntil('\n');
  switch( j ){
    case 0:
      pinSerial = data.toInt();
      j++;
      break;
    case 1:
      bandera = 1;
      j = 0;
      dutyCicle = data.toInt();
      break;
  }
  
}

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
   Serial.println("HOLA, soy el Chacras! UwU");
   setPwms( 2 );
   setPinsPwms( 4 );  
}

void loop() {
  // put your main code here, to run repeatedly:
  if( Serial.available() > 0 ){
    serialRead();
  }
  if( bandera == 1 ){
    bandera = 0;
    Serial.println( dutyCicle );
    analogWrite( pinSerial, dutyCicle * 255 / 100 );
  }
}
