#include "main.h"
#include "safe_motor.h"
using namespace pros;


void opcontrol() {

	pros::Controller master(pros::E_CONTROLLER_MASTER);
	Safe_Motor left_mtr(1);
	Safe_Motor right_mtr(2);
	Safe_Motor bottomright_mtr(3);
	Safe_Motor bottomleft_mtr(4);
	Safe_Motor grabber(13);
	Safe_Motor conveyorbelt(8);


	while (true) {

		int power = master.get_analog(ANALOG_RIGHT_X);
	 int turn = master.get_analog(ANALOG_LEFT_Y);
	 int left = power + turn;
	 int right = power - turn;
	 left_mtr.move(left);
	 bottomleft_mtr.move(right);
	 bottomright_mtr.move(left);
	 right_mtr.move(right);

	 if (master.get_digital(DIGITAL_L1)) { // slows down robot

		 int left = (power+turn)/2;
		 int right = (power-turn)/2;
		 left_mtr.move(left);
		 bottomleft_mtr.move(right);
		 bottomright_mtr.move(left);
		 right_mtr.move(right);


	 }


		if (master.get_digital(DIGITAL_R1)) {
			grabber.move(127);
			conveyorbelt.move(127);


		}
		else if (master.get_digital(DIGITAL_R2)) {
					grabber.move(-127);
					conveyorbelt.move(0);
				}
				else {
					grabber.move(0);
					conveyorbelt.move(0);
				}

			//	pros::Motor motor3(3);
			//	pros::Motor motor4(4);
				bool motorOn = false;	// flag for if conveyor motor is on or off
			  pros::Controller master (pros::E_CONTROLLER_MASTER);


					//
					// Handle toggleable conveyor
					//



pros::delay(2);

	}
}
