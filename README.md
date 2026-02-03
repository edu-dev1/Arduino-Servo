# Arduino-Servo
Servomotor

## Features
- Currently only compatible with Arduino Uno (9 and 10 pins).
- Easy to use.

## Example of use
```C++
#include <servo.h>

/*---Creating the object---*/
int PWM_pin = 9;
float min_pulse_ms = .5, max_pulse_ms = 2.4;
Servo my_servo;

/*--Degrees--*/
int degrees[] = {0, 90, 180};

void setup() {
  /*---Inizializing the servo---*/
  my_servo.begin(PWM_pin, min_pulse_ms, max_pulse_ms);
}

void loop() {
  /*---Rotating the servo---*/
  for (int &degree : degrees){
    my_servo.rotate(degree);
    delay(1000);
  }
}
