#include "car.h"


CAR::CAR() {

}

// initilize the car with parameter left and right motor
void CAR::init(Motor motor_left, Motor motor_right) {
    this->motor_left = motor_left;
    this->motor_right = motor_right;
    this->motor_left.init();
    this->motor_right.init();
}

// stop the car
void CAR::stop() {
  this->motor_left.stop();		// stop left motor
  this->motor_right.stop();		// stop right motor
}

// move forword with a previously seted speed
void CAR::fwd() {
  this->motor_left.fwd(speed);
  this->motor_right.fwd(speed);
}

// move forword with a speed send by its parameter
void CAR::fwd(int s) {
  carSpeed(s);				// set the car speed
  fwd();				// call the forword function
}

// move backword with a previously seted speed
void CAR::bkwd() {
  this->motor_left.bkwd(speed);		// rotate left motor backword
  this->motor_right.bkwd(speed);	// rotate right motor backword
}

// move the car backword with speed set by its parameter
void CAR::bkwd(int s) {
  carSpeed(s);				// set car speed
  bkwd();				// call backword functon
}

// turn the car right
void CAR::turnRight() {
  this->motor_left.fwd(rotate_speed);		// set left motor forword
  this->motor_right.bkwd(rotate_speed);		// set right motor backword
}

// turn rhe car right with a speed
void CAR::turnRight(int s) {
  carRotationSpeed(s);		//set rotation speed
  turnRight();			// turn right
}

// turn rhe car left
void CAR::turnLeft() {
  this->motor_left.bkwd(rotate_speed);		// set left motor backword
  this->motor_right.fwd(rotate_speed);		// set right motor forword
}

// turn rhe car left with a speed
void CAR::turnLeft(int s) {
  carRotationSpeed(s);				// set rotation speed
  turnLeft();					// turn left
}

// set the speed of the car
void CAR::carSpeed(int s) {
  if(s > 255)
    s = 255;
  else if(s < 0)
    s = 0;
  this->speed = s;
}

// set the rotation speed of the car
void CAR::carRotationSpeed(int s) {
  if(s > 255)
    s = 255;
  else if(s < 0)
    s = 0;
  this->rotate_speed = s / 2;
}
