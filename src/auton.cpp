//#ifndef AUTON_H
#include "auton.h"
using namespace pros;
Auton::Auton()
{
  // define motors using their ports
  //1 reverses motor, 0 is normal
  arm_left = new pros::Motor(LEFT_PORT, GEARSET, 1, MTR_UNITS);
  arm_right = new pros::Motor(RIGHT_PORT, GEARSET, 0, MTR_UNITS);

  t_left = new pros::Motor(TOP_LEFT, GEARSET, 0, MTR_UNITS);
  t_right = new pros::Motor(TOP_RIGHT, GEARSET, 1, MTR_UNITS);
  b_left = new pros::Motor(BOTTOM_LEFT, GEARSET, 0, MTR_UNITS);
  b_right = new pros::Motor(BOTTOM_RIGHT, GEARSET, 1, MTR_UNITS);

  belt = new pros::Motor(MOTOR_BELT, GEARSET, 1, MTR_UNITS);

  // set the motors' positions to 0
  arm_left->tare_position();
  arm_right->tare_position();
  t_left->tare_position();
  t_right->tare_position();
  b_left->tare_position();
  b_right->tare_position();
  belt->tare_position();

  // set  the brake mode on the motors
  arm_left->set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  arm_right->set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  t_left->set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  t_right->set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  b_left->set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  b_right->set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  belt->set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
}

//REAL: Distance sensor auton
void Auton::distance(pros::Controller master) {

 pros::Distance distance_sensor(DISTANCE_PORT); //Initialize dist sensor

  t_left->move_velocity(5);
  t_right->move_velocity(5);
  b_left->move_velocity(5);
  b_right->move_velocity(5);
  pros::delay(500); //move for a little bit to get enough space to rotates

while (distance_sensor.get() < 550 || distance_sensor.get() > 450 ) { //rotate until goal is detected within range
  t_left->move_velocity(-15);
  t_right->move_velocity(15);
  b_left->move_velocity(-15);
  b_right->move_velocity(15);
  delay(100);
}

  arm_left->move_absolute(90, 10); //Drop arms
  arm_right->move_absolute(90, 10);
  pros::delay(2000);

  while(distance_sensor.get() > 260 ) { //Move back until goal is within range
  t_left->move_velocity(-15);
  t_right->move_velocity(-15);
  b_left->move_velocity(-15);
  b_right->move_velocity(-15);
  delay(100);
}

  delay(1500);

  if (distance_sensor.get() < 200 || distance_sensor.get() > 300) { //if goal is in arms
    arm_left->move_velocity(-30); //Lift arms(with mogo in hopefully)
    arm_right->move_velocity(-30);
    delay(500);
    if(arm_right->get_efficiency() < 60) {

      arm_left->move_absolute(30, 1000); //Lift arms(with mogo in hopefully)
      arm_right->move_absolute(30, 1000);
    }

   else if(arm_right->get_efficiency() >= 60){
     arm_right->move_velocity(0);
     arm_left->move_velocity(0);
   pros::lcd::initialize();
   pros::lcd::set_text(2, "GOAL NOT DETECTED" );
  //add countercheck
    }

  }

  else {

    while(distance_sensor.get() > 260 ) { //Move back until goal is within range
    t_left->move_velocity(-15);
    t_right->move_velocity(-15);
    b_left->move_velocity(-15);
    b_right->move_velocity(-15);
    delay(100);
    }

    arm_left->move_absolute(30, 100000); //Lift arms(with mogo in hopefully)
    arm_right->move_absolute(30, 100000);

  }



}













//testing auton motion
void Auton::test(pros::Controller master) {
    //move arm down slowly
    arm_left->move_absolute(90, 10);
    arm_right->move_absolute(90, 10);
    pros::delay(2000);

    //slowly back up into goal
    t_left->move_velocity(-15);
    t_right->move_velocity(-15);
    b_left->move_velocity(-15);
    b_right->move_velocity(-15);
    pros::delay(1500); //delay function determines how long the robot moves in the given state


    //Move arm back up(hopefully with goal in hand)
    arm_left->move_absolute(30, 100000);
    arm_right->move_absolute(30, 100000);

    pros::delay(1000);

    belt->move_velocity(40); // suck up rings in the path
    t_left->move_velocity(40);
    t_right->move_velocity(40);
    b_left->move_velocity(40);
    b_right->move_velocity(40);

    pros::delay(3000);

    belt->move_velocity(400); // suck up rings in the path
    t_left->move_velocity(0);
    t_right->move_velocity(0);
    b_left->move_velocity(0);
    b_right->move_velocity(0);

}


//testing auton motion 2 (real scenario)
void Auton::rotate(pros::Controller master) {

  pros::Distance distance_sensor(DISTANCE_PORT); //Initialize dist sensor

   t_left->move_velocity(5);
   t_right->move_velocity(5);
   b_left->move_velocity(5);
   b_right->move_velocity(5);
   pros::delay(500); //move for a little bit to get enough space to rotates

   //rotate until goal is detected within range
   t_left->move_velocity(-15);
   t_right->move_velocity(15);
   b_left->move_velocity(-15);
   b_right->move_velocity(15);
   delay(1500);


   arm_left->move_absolute(90, 10); //Drop arms
   arm_right->move_absolute(90, 10);
   pros::delay(2000);

//Move back until goal is within range
   t_left->move_velocity(-15);
   t_right->move_velocity(-15);
   b_left->move_velocity(-15);
   b_right->move_velocity(-15);
   delay(2000);

   arm_left->move_velocity(-30); //CHECK efficiency
   arm_right->move_velocity(-30);
   delay(500);

   if(arm_right->get_efficiency() < 60) {
     arm_left->move_absolute(30, 1000); //Lift arms(with mogo in hopefully)
     arm_right->move_absolute(30, 1000);
   }

  else if(arm_right->get_efficiency() >= 60){
    arm_right->move_velocity(0);
    arm_left->move_velocity(0);
  pros::lcd::initialize();
  pros::lcd::set_text(2, "GOAL NOT DETECTED" );

   }

   }


 //gauges whether mogo is in arms
void Auton::motortest(pros::Controller) {

std::cout << arm_right->get_efficiency();
     arm_left->move_absolute(90, 10); //Lift arms(with mogo in hopefully)
     arm_right->move_absolute(90, 10);
     delay(5000);
     arm_left->move_velocity(-30); //Lift arms(with mogo in hopefully)
     arm_right->move_velocity(-30);
     delay(500);
std::cout << arm_right->get_efficiency();
   if(arm_right->get_efficiency() < 60) {
     arm_left->move_absolute(30, 1000); //Lift arms(with mogo in hopefully)
     arm_right->move_absolute(30, 1000);
   }

  else if(arm_right->get_efficiency() >= 60){
    arm_right->move_velocity(0);
    arm_left->move_velocity(0);
  pros::lcd::initialize();
  pros::lcd::set_text(2, "GOAL NOT DETECTED" );

   }

   }
