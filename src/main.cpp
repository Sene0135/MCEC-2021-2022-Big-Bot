#include "main.h"

// hello

void opcontrol() {

	pros::Controller master(pros::E_CONTROLLER_MASTER);
	pros::Motor left_mtr(1);
	pros::Motor right_mtr(2);
	pros::Motor bottomright_mtr(3);
	pros::Motor bottomleft_mtr(4);
	pros::Motor grabber(13);
	pros::Motor conveyorbelt(8);


	while (true) {

		int power = master.get_analog(ANALOG_RIGHT_X);
	 int turn = master.get_analog(ANALOG_LEFT_Y);
	 int left = power + turn;
	 int right = power - turn;
	 left_mtr.move(left);
	 bottomleft_mtr.move(right);
	 bottomright_mtr.move(left);
	 right_mtr.move(right);

	 if (master.get_digital(DIGITAL_Y)) {

		 int left = left/2;
		 int right = right/2;


	 }


		if (master.get_digital(DIGITAL_R1)) {
			grabber.move_velocity(127);
			conveyorbelt.move_velocity(127);


		}
		else if (master.get_digital(DIGITAL_R2)) {
					grabber.move_velocity(-127);
					conveyorbelt.move_velocity(0);
				}
				else {
					grabber.move_velocity(0);
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
