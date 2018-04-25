
/*
  button.hpp
  encapsulates a button
*/

#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "Arduino.h"

/*
  Button
  keeps track of button
*/
class Button {
  short _pin;
public:
  Button();
  Button(const short pin);
  const bool pressed();
};

#endif
