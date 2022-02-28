
#ifndef DRIVECONTROL_H
#define DRIVECONTROL_H


#include "api.h"
#include "okapi/api.hpp"

#define A_LEFT 10 //Arm left (mogo lifter)
#define A_RIGHT 9
#define TO_LEFT 1
#define TO_RIGHT 2
#define BOT_LEFT 3
#define BOT_RIGHT 4
#define MTR_BELT 13

#define LEFTSTICK E_CONTROLLER_ANALOG_LEFT_Y
#define RIGHTSTICK E_CONTROLLER_ANALOG_RIGHT_X

//#define DISTANCE_PORT 'A'

// directions the 2 motors powering the lifter move in
#define LEFT_DIR 0
#define RIGHT_DIR 1

// gearset and encoder units of the two motors
#define GEAR pros::E_MOTOR_GEARSET_36    // red motor gearset: 100 rpm
#define MOTORUNITS pros::E_MOTOR_ENCODER_DEGREES // motor calculates in degrees


class Control { //Short for 'autonomous'

public:

Control(); // default constructor

//functions
void dcontrol(pros::Controller);

private:

// member pointers for motors
pros::Motor* a_left;
pros::Motor* a_right;
pros::Motor* left_mtr; //top left wheel
pros::Motor* right_mtr;
pros::Motor* bottomleft_mtr; //bottom left wheel
pros::Motor* bottomright_mtr;
pros::Motor* conbelt;

int i = 10;
int power = 0;
int turn = 0;


};





#endif
