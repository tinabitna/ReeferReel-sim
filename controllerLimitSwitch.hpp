
/*
  controllerLimitSwitch.hpp
  encapsulates a limit switch
*/

#ifndef CONTROLLEDLIMITSWITCH_HPP
#define CONTROLLEDLIMITSWITCH_HPP

#include "Arduino.h"

/*
  ControlledLimitSwitch
  keeps track of limit switch
*/
class ControlledLimitSwitch {
  const static short LIMIT = 1;
  const static short NOT_LIMIT = 0;
  short _pin;
public:
  ControlledLimitSwitch();
  ControlledLimitSwitch(const short pin);
  const bool hitLimit();
};

#endif
