
/*
  ControllerMotor.cpp
  implementation of the ControlledMotor class in controller.hpp
*/

#include "controllerMotor.hpp"

/*
  constructor
  default doesn't do anything
*/
ControlledMotor::ControlledMotor() {}


/*
  constructor
  instantiates the motor
*/
ControlledMotor::ControlledMotor(const short pin, const short speed = NO_SPEED) {
  _pin = pin;
  _speed = speed;
  pinMode(pin, OUTPUT);
  digitalWrite(pin, speed);
}

/*
  changeDirection
  changes direction of motor
*/
void ControlledMotor::changeDirection() {
   changeSpeed(0 - _speed);
}

/*
  stop
  stops the motor 
*/
void ControlledMotor::stop() {
  digitalWrite(_pin, NO_SPEED);
}

/*
  stopped
  check if motor is stopped 
*/
const bool ControlledMotor::stopped() {
  return _speed == NO_SPEED;
}

/*
  changeSpeed
  changes the speed of the motor
*/
const short ControlledMotor::changeSpeed(const short speed) {
  _speed = max(MIN_SPEED, min(MAX_SPEED, speed));
  digitalWrite(_pin, _speed);
  
  return _speed;
}

/*
  getSpeed
  returns the current speed of the dc motor
*/
const short ControlledMotor::getSpeed(){
  return _speed;
}

