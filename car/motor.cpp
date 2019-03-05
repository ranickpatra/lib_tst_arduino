#include "motor.h"

Motor::Motor() {
  
}

// motor constructor with pin1, pin2, and pwm pin
Motor::Motor(int p1, int p2, int en) {
  this->pin1 = p1;
  this->pin2 = p2;
  this->enable = en;
}

// initilize the motor with output pins
void Motor::init() {
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(enable, OUTPUT);
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  analogWrite(enable, 0);
  speed = 0;
}

// start motor
void Motor::start() {
  analogWrite(enable, speed);
}

// stop motor
void Motor::stop() {
  analogWrite(enable, 0);
}

// set forword rotation with previous speed
void Motor::fwd() {
  start();
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, LOW);
}

// set forword rotation with speed
void Motor::fwd(int s) {
  MSpeed(s);
  fwd();
}

// set backword rotation with previous speed
void Motor::bkwd() {
  start();
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, HIGH);
}

// set backword rotation with speed
void Motor::bkwd(int s) {
  MSpeed(s);
  bkwd();
}

// set motor speed
void Motor::MSpeed(int s) {
  if (s > 255)
    s = 255;
  else if (s < 0)
    s = 0;
  this->speed = s;
}
