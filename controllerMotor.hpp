
/*
  controllerMotor.hpp
  encapsulates a motor
*/

#ifndef CONTROLLEDMOTOR_HPP
#define CONTROLLEDMOTOR_HPP

#include "Arduino.h"

/*
  ControlledMotor
  keeps track of and manipulates a motor
*/
class ControlledMotor {
  const static short MAX_SPEED = 255;
  const static short MIN_SPEED = -255;
  const static short NO_SPEED = 0;
  short _speed;
  short _pin;
public:
  ControlledMotor();
  ControlledMotor(const short pin, const short speed = NO_SPEED);
  void changeDirection();
  void stop();
  const short changeSpeed(const short speed);
  const short getSpeed();
  const bool stopped();
};

#endif
