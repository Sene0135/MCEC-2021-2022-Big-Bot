#include "main.h"
#include "safe_motor.h"
#include "auton.h"
//#include "lifter.h"
//#include "drivecontrol.h"
using namespace pros;

Auton auton; //create auton object
//Control control;
//Lifter lifter;
    pros::Controller master(pros::E_CONTROLLER_MASTER);
    // quad motors
    Safe_Motor left_mtr(1);
    Safe_Motor right_mtr(2);
   Safe_Motor bottomright_mtr(3);
    Safe_Motor bottomleft_mtr(4);

    // conveyorbelt/sucky sucky
    Safe_Motor grabber(13);

    // goal lifter motors
    Safe_Motor lifter_left(9);
    Safe_Motor lifter_right(10);

    int i =10;
     int power =0;
     int turn = 0;



 void autonomous() {
// Activate by using time trial on controller/brain
pros::lcd::initialize();
pros::lcd::set_text(2, "Auton V1.9");
//auton.rotate(); //Runs test drive
pros::ADIUltrasonic distance_sensor (ULTRA_PING, ULTRA_ECHO);
while (true) {

		auton.ultrasonic();
		pros::delay(1);
		}
	}



void opcontrol() {

    while (true) {


        pros::lcd::initialize();
      //  pros::lcd::set_text(3, "Version 2.6");

         // default movement control
        turn = master.get_analog(ANALOG_RIGHT_X);
      power = master.get_analog(ANALOG_LEFT_Y);
      int right = -power + turn;
      int left = power + turn;

            pros::lcd::set_text(2, std::to_string(power));
     left_mtr.move(left);
     bottomleft_mtr.move(left);
     bottomright_mtr.move(right);
     right_mtr.move(right);

     if (master.get_digital(DIGITAL_LEFT)) {

     // slows doown robot

     int right = (-power + turn)/ 2;
    int left = (power + turn)/2;
         left_mtr.move(left);
         bottomleft_mtr.move(left);
         bottomright_mtr.move(right);
         right_mtr.move(right);


     }

// Use Up and Down Arrows to make the robot go straight for a short time
//for loop used to gradually speed the bot up

     if (master.get_digital(DIGITAL_UP)) {
         for(int i=0;i<=90; i+=10) {
         std::cout<< i << std::endl;
         left_mtr.move(i);
         bottomleft_mtr.move(i);
         bottomright_mtr.move(-i);
         right_mtr.move(-i);
         pros::delay(100);
         }

         left_mtr.move(0);
     bottomleft_mtr.move(0);
     bottomright_mtr.move(0);
     right_mtr.move(0);

     }
     else if (master.get_digital(DIGITAL_DOWN)) {

    for(int i=0;i<=90; i+=10) {
    std::cout<< i << std::endl;
    left_mtr.move(-i);
    bottomleft_mtr.move(-i);
    bottomright_mtr.move(i);
    right_mtr.move(i);
    pros::delay(100);
    }
    left_mtr.move(0);
    bottomleft_mtr.move(0);
    bottomright_mtr.move(0);
    right_mtr.move(0);

             }

//Moves conveyor belt and wheel

        if (master.get_digital(DIGITAL_L1)) {
        //    lifter_left.move(-127);
				//		lifter_right.move(127);
				lifter_left.move(-127);
				lifter_right.move(127);


        }
        else if (master.get_digital(DIGITAL_L2)) {
				//	lifter_left.move(127);
					//lifter_right.move(-127);
         	lifter_left.move(127);
					lifter_right.move(-127);
                }
                else {
									lifter_left.move(0);
								lifter_right.move(0);

                }


								        if (master.get_digital(DIGITAL_R1)) {
								        //    lifter_left.move(-127);
												//		lifter_right.move(127);
								      	grabber.move(127);


								        }
								        else if (master.get_digital(DIGITAL_R2)) {
												//	lifter_left.move(127);
													//lifter_right.move(-127);
								         	grabber.move(-127);
								                }
								                else {
																	//lifter_left.move(0);
																//	lifter_right.move(0);
								                    grabber.move(0);
								                }



//lifter.run(master);

pros::delay(1);
}

}
