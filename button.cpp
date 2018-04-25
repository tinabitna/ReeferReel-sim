
/*
  button.cpp
  implementation of the button class in button.hpp
*/

#include "button.hpp"

/*
  constructor
  default doesn't do anything
*/
Button::Button() {}

/*
  constructor
  instantiates the button
*/
Button::Button(const short pin) {
  _pin = pin;
  pinMode(pin, INPUT);
}

/*
  pressedt
  check if the button has been pressed
*/
const bool Button::pressed() {
  return digitalRead(_pin) == HIGH;
}


