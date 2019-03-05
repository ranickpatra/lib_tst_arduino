#include "motor.h"

// car class
class CAR {
private:
  int speed = 150;	// set initial default speed
  int rotate_speed = 150;	// set initial default rotation speed
  Motor motor_left, motor_right;	// varibales for motor
public:
  CAR();
  void init(Motor, Motor);
  void stop();
  void fwd();
  void fwd(int);
  void bkwd();
  void bkwd(int);
  void turnRight();
  void turnRight(int);
  void turnLeft();
  void turnLeft(int);
  void carSpeed(int);
  void carRotationSpeed(int);
};
