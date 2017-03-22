#include <Servo.h>
#define NBR_SERVOS 48  // the number of servos, up to 48 for Mega, 12 for other boards
#define FIRST_SERVO_PIN 2 

Servo Servos[NBR_SERVOS] ; // max servos is 48 for mega, 12 for other boards

int pos = 0;      // variable to store the servo position 
int potPin = 0;   // connect a pot to this pin.

void setup() {
  for( int i =0; i < NBR_SERVOS; i++) {
    Servos[i].attach( FIRST_SERVO_PIN + i, 800, 2200);
  }
}

void turn_left(int servo_pin_number) {
  Serial.print(servo_pin_number);
  for( int pos = 0; pos <= 1023; pos = pos + 5) {
    Servos[servo_pin_number].write( map(pos, 0,1023,0,180));
    delay(2);
  }
}

void turn_right(int servo_pin_number) {
  for( int pos = 1023; pos >= 0; pos = pos - 5) {
    Servos[servo_pin_number].write( map(pos, 0,1023,0,180));
    delay(2);
  }
}

void loop()
{
  int i = 0;
  //for( int i = 0; i < NBR_SERVOS; i++) {
    turn_left(i);
    delay(1000);
    turn_right(i);
  //}
  
  //pos = analogRead(potPin);   // read a value from 0 to 1023
  //for( int i = 0; i < NBR_SERVOS; i++)  {
  //  int i = 2;
  //  turn_left(i);
  //  delay(1000);
  //  turn_right(i);
  //}
  
  delay(10000);
}
