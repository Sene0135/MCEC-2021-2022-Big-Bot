#include "lifter.h"

// default constructor
Lifter::Lifter()
{
  // define motors using their ports
  motor_left = new pros::Motor(MOTOR_LEFT_PORT, MOTOR_GEARSET, 1, MOTOR_UNITS);
  motor_right = new pros::Motor(MOTOR_RIGHT_PORT, MOTOR_GEARSET, 0, MOTOR_UNITS);

  // set the motors' positions to 0
  motor_left->tare_position();
  motor_right->tare_position();

  // set the brake mode on the motors
//  motor_left->set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  //motor_right->set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

  // start the lifter in "hold" mode
  mode = up;
}

// take input from controller and act on it
// intended to be run once per tick
void Lifter::run(pros::Controller master)
{

  // toggle mode if toggled from controller
  if (master.get_digital_new_press(TOGGLE_BUTTON))
  {
    // toggle the mode
    if (mode == up)
      // set the lifter to go down
      mode = down;
    else
      // set the lifter to go up
      mode = up;
  }

  // move lifter up if set to be up
  if (mode == up)
  {
    // move lifter up
    motor_left->move_absolute(30, 1000);
    motor_right->move_absolute(30, 1000);
  }

  if (master.get_digital_new_press(DIGITAL_A)) { // Rotates back to 0 if it needs to (QOL Feature)
    mode = up;
    motor_left->move_absolute(0, 30);
    motor_right->move_absolute(0, 30);
  }
  // move lifter down if set to be down
  else
  {
    // move lifter down
    motor_left->move_absolute(90, 40);
    motor_right->move_absolute(90, 40);

    //  motor_left->move_absolute(LOWER_LIMIT, DOWN_VELOCITY);
      //motor_right->move_absolute(LOWER_LIMIT, DOWN_VELOCITY);

  }
}
