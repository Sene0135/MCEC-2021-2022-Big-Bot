
#include "drivecontrol.h"

Control::Control()
{
  pros::lcd::initialize();
  pros::lcd::set_text(3, "Version 3.0");
  // define motors using their ports
  //1 reverses motor, 0 is normal
  a_left = new pros::Motor(A_LEFT, GEAR, 1, MOTORUNITS);
  a_right = new pros::Motor(A_RIGHT, GEAR, 0, MOTORUNITS);

  left_mtr = new pros::Motor(TO_LEFT, GEAR, 0, MOTORUNITS);
  right_mtr = new pros::Motor(TO_RIGHT, GEAR, 1, MOTORUNITS);
  bottomleft_mtr = new pros::Motor(BOT_LEFT, GEAR, 0, MOTORUNITS);
  bottomright_mtr = new pros::Motor(BOT_RIGHT, GEAR, 1, MOTORUNITS);

  conbelt = new pros::Motor(MTR_BELT, GEAR, 1, MOTORUNITS);



  // set the motors' positions to 0
  a_left->tare_position();
  a_right->tare_position();
  right_mtr->tare_position();
  left_mtr->tare_position();
  bottomleft_mtr->tare_position();
  bottomright_mtr->tare_position();
  conbelt->tare_position();

  // set  the brake mode on the motors
//  a_left->set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
//  a_right->set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
//  right_mtr->set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
//  left_mtr->set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
//  bottomleft_mtr->set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
//  bottomright_mtr->set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
//  conbelt->set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
}



void Control::dcontrol(pros::Controller) {

pros::Controller master(pros::E_CONTROLLER_MASTER);

 // default movement control
turn = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
power = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
int right = -power + turn; //-power + turn
int left = power + turn; //power + turn
//std::cout << "right" << right <<std::endl;
//std::cout << "left" <<left <<std::endl;
left_mtr->move(left);
bottomleft_mtr->move(-left);
bottomright_mtr->move(right);
right_mtr->move(-right);

if (master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)) {

// slows doown robot

int right = (-power + turn)/ 2;
int left = (power + turn)/2;
 left_mtr->move(left);
 bottomleft_mtr->move(left);
 bottomright_mtr->move(right);
 right_mtr->move(right);


}

// Use Up and Down Arrows to make the robot go straight for a short time
//for loop used to gradually speed the bot up

if (master.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) {
 for(int i=0;i<=50; i+=10) {
 std::cout<< i << std::endl;
 left_mtr->move(i);
 bottomleft_mtr->move(i);
 bottomright_mtr->move(i);
 right_mtr->move(i);
 pros::delay(100);
 }

 left_mtr->move(0);
bottomleft_mtr->move(0);
bottomright_mtr->move(0);
right_mtr->move(0);

}
else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {

for(int i=0;i<=50; i+=10) {
std::cout<< i << std::endl;
left_mtr->move(-i);
bottomleft_mtr->move(-i);
bottomright_mtr->move(-i);
right_mtr->move(-i);
pros::delay(100);
}
left_mtr->move(0);
bottomleft_mtr->move(0);
bottomright_mtr->move(0);
right_mtr->move(0);

   }

//Moves conveyor belt and wheel

if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
//  conbelt->move(127);
//a_left->move(-127);
//a_right->move(127);
	conbelt->move(127);


}
else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
      conbelt->move(-127);
      //a_left->move(127);
      //a_right->move(-127);
//			conveyorbelt.move(0);
    }
    else {
      conbelt->move(0);
      //a_left->move(0);
      //a_right->move(0);
//			conveyorbelt->move(0);
    }
}
