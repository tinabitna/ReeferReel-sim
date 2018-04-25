
/*
  ControllerLimitSwitch.cpp
  implementation of the ControlledLimitSwitch class in controllerLimitSwitch.hpp
*/

#include "controllerLimitSwitch.hpp"

/*
  constructor
  default doesn't do anything
*/
ControlledLimitSwitch::ControlledLimitSwitch() {}

/*
  constructor
  instantiates the limit switch
*/
ControlledLimitSwitch::ControlledLimitSwitch(const short pin) {
  _pin = pin;
  pinMode(pin, INPUT);
}

/*
  hitLimit
  check if the limit has been hit
*/
const bool ControlledLimitSwitch::hitLimit() {
  return digitalRead(_pin) == LIMIT ? true : false;
}


