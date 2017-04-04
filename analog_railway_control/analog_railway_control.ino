#include <DRV8835MotorShield.h>

/*
 * This example uses the DRV8835MotorShield library to drive each motor with the
 * Pololu DRV8835 Dual Motor Driver Shield for Arduino forward, then backward. 
 * The yellow user LED is on when a motor is set to a positive speed and off when
 * a motor is set to a negative speed.
 */

#define LED_PIN 13

DRV8835MotorShield motors;

int change_of_velocity = 0;

void setup()
{
  //motors.setM2Speed(400);
  
  pinMode(LED_PIN, OUTPUT);
  
  // uncomment one or both of the following lines if your motors' directions need to be flipped
  //motors.flipM1(true);
  //motors.flipM2(true);
}

void set_speed_and_delay(int speed)
{
  motors.setM1Speed(speed);
    
  if (speed < 100) {
    delay(2);
  } else {
    delay(speed/3);
  }
}

void accelerate_train() 
{
  change_of_velocity = 1;
  
  digitalWrite(LED_PIN, HIGH);

  for (int speed = 0; speed <= 400; speed++)
  {
    set_speed_and_delay(speed);
  }

  change_of_velocity = 0;
}

void slow_train_down()
{
  change_of_velocity = 1;
  
  for (int speed = 400; speed >= 0; speed--)
  {
    set_speed_and_delay(speed);
  }
  
  digitalWrite(LED_PIN, LOW);

  change_of_velocity = 0;
}

void loop()
{
  if (change_of_velocity == 0) 
  {
    accelerate_train();

    delay(5000);

    slow_train_down();
  }

  
/*
  // run M1 motor with positive speed
  
  digitalWrite(LED_PIN, HIGH);
  
  for (int speed = 0; speed <= 400; speed++)
  {
    motors.setM1Speed(speed);
    delay(2);
  }

  for (int speed = 400; speed >= 0; speed--)
  {
    motors.setM1Speed(speed);
    delay(2);
  }
  
  // run M1 motor with negative speed
  
  digitalWrite(LED_PIN, LOW);
  
  for (int speed = 0; speed >= -400; speed--)
  {
    motors.setM1Speed(speed);
    delay(2);
  }
  
  for (int speed = -400; speed <= 0; speed++)
  {
    motors.setM1Speed(speed);
    delay(2);
  }

  // run M2 motor with positive speed
  
  digitalWrite(LED_PIN, HIGH);
  
  for (int speed = 0; speed <= 400; speed++)
  {
    motors.setM2Speed(speed);
    delay(2);
  }

  for (int speed = 400; speed >= 0; speed--)
  {
    motors.setM2Speed(speed);
    delay(2);
  }
  
  // run M2 motor with negative speed
  
  digitalWrite(LED_PIN, LOW);
  
  for (int speed = 0; speed >= -400; speed--)
  {
    motors.setM2Speed(speed);
    delay(2);
  }
  
  for (int speed = -400; speed <= 0; speed++)
  {
    motors.setM2Speed(speed);
    delay(2);
  }
  
  delay(500);
*/
}
