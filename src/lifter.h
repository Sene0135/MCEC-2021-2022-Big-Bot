/*
 * The lifter controls the big lifter on front of the robot.
 *
 * Use the run method (passing in the controller) once per tick to keep the
 * lifter updated.
 *
 * During autonomous you can use the set_pos method to move the lifter to a
 * specific angle. The angle at the lifters starting position (pointing
 * up) is 0 degrees, and moving the lifter down is moving in the negative
 * direction
 *
 * From this header file, look for defined constants to change as necessary.
 * You can change the ports the motors plug into, the buttons used to move up,
 * down, and toggle modes, the constructor arguments of the motors, the
 * velocities of the motors moving up, down, when holding position, and during
 * autonomous, and the max and min angle the lifter is allowed to move to
 */

#ifndef LIFTER_H
#define LIFTER_H

#include "main.h"

// ports for the 2 motors powering the lifter
#define MOTOR_LEFT_PORT 10
#define MOTOR_RIGHT_PORT 9

// directions the 2 motors powering the lifter move in
#define MOTOR_LEFT_DIRECTION reversed
#define MOTOR_RIGHT_DIRECTION normal

// gearset and encoder units of the two motors
#define MOTOR_GEARSET pros::E_MOTOR_GEARSET_36    // red motor gearset: 100 rpm
#define MOTOR_UNITS pros::E_MOTOR_ENCODER_DEGREES // motor calculates in degrees

// controller buttons for moving lifter up and down
#define TOGGLE_BUTTON pros::E_CONTROLLER_DIGITAL_Y // Y button

// target velocity of motors
#define UP_VELOCITY 100    // target velocity going up //10000000
#define DOWN_VELOCITY 100  // target velocity going down

// angle limit for the lifter
#define UPPER_LIMIT 0 // highest angle lifter can stop on
#define LOWER_LIMIT 5 // lowest angle lifter can stop on

// stores direction for motors
enum DIRECTION{normal, reversed};

// mode of lifter
// controls whether lifter is held up or dozwn
enum MODE1{up, down};

// class controlling lifter on front of the robot
class Lifter
{
public:

  // default constructor
  Lifter();

  // take input from controller and act on it
  // intended to be run once per tick
  void run(pros::Controller);

private:

  // motor pointers
  pros::Motor* motor_left;
  pros::Motor* motor_right;

  // keeps track of whether the lifter is up or down
  MODE1 mode;

   //test code, this used to be MODE, will this fix the errors?

};

#endif
