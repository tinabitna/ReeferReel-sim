
#include "controllerLimitSwitch.hpp"
#include "controllerMotor.hpp"
#include "button.hpp"

const short POS_SPEED_RATE = 10;
const short NEG_SPEED_RATE = -10;

//controllers
ControlledMotor horizontal;
ControlledMotor vertical;
ControlledLimitSwitch leftLimit;
ControlledLimitSwitch rightLimit;
//buttons
Button up;
Button dn;
Button lt;
Button rt;
Button stp;

void setup() {
    //set up the controller classes with their respective pins
    horizontal = ControlledMotor(1);
    vertical = ControlledMotor(2);
    leftLimit = ControlledLimitSwitch(3);
    rightLimit = ControlledLimitSwitch(4);
    up = Button(5);
    dn = Button(6);
    lt = Button(7);
    rt = Button(8);
    stp = Button(9);
}

inline void moveRight() {
    //if not already moving right move to right
    if (horizontal.stopped() || horizontal.getSpeed() <= NEG_SPEED_RATE) {
        horizontal.changeSpeed(POS_SPEED_RATE);
    }
}

inline void moveLeft() {
    //if not already moving left move left
    if (horizontal.stopped() || horizontal.getSpeed() >= POS_SPEED_RATE) {
        horizontal.changeSpeed(NEG_SPEED_RATE);
    }
}

inline void moveUp() {
    //if not already moving up move up
    if (vertical.stopped() || vertical.getSpeed() <= NEG_SPEED_RATE) {
        vertical.changeSpeed(POS_SPEED_RATE);
    }
}

inline void moveDown() {
    //if not already moving down move down
    if (vertical.stopped() || vertical.getSpeed() >= POS_SPEED_RATE) {
        vertical.changeSpeed(NEG_SPEED_RATE);
    }
}

inline void stop() {
    //stop all motors
    horizontal.stop();
    vertical.stop();
}

void loop() {
    //determine move
    if (up.pressed()) moveUp();
    else if (dn.pressed()) moveDown();
    else if (lt.pressed()) moveLeft();
    else if (rt.pressed()) moveRight();
    else if (stp.pressed()) stop();

    //check if either limit is hit and change direction
    if (!horizontal.stopped() && (leftLimit.hitLimit() || rightLimit.hitLimit())) {
        horizontal.changeDirection();
    }
}


