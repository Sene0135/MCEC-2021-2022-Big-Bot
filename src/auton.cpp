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


  // set  the brake mode on the motors
arm_left->set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
 arm_right->set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
//  t_left->set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
//  t_right->set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
//  b_left->set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  //b_right->set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
//  belt->set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
}


void Auton::ultrasonic() {


   pros::ADIUltrasonic distance_sensor (ULTRA_PING, ULTRA_ECHO); //Initialize dist sensor

    t_left->move_velocity(-40);
    t_right->move_velocity(-40);
    b_left->move_velocity(-40);
    b_right->move_velocity(-40);
    	pros::lcd::set_text(3, std::to_string(distance_sensor.get_value()));
    pros::delay(1000); //move for a little bit to get enough space to rotates
    t_left->move_velocity(20);
    t_right->move_velocity(-20);
    b_left->move_velocity(20);
    b_right->move_velocity(-20);
    delay(250);
  bool mogodetected = false;

  while (mogodetected == false ) { //rotate until goal is detected within range
  if ((distance_sensor.get_value() > 65 && distance_sensor.get_value() < 500)) {
    //int time;
  //  int timer(time);


    t_left->move_velocity(20);
    t_right->move_velocity(-20);
    b_left->move_velocity(20);
    b_right->move_velocity(-20);
    pros::lcd::set_text(3, std::to_string(distance_sensor.get_value()));

//we
if (distance_sensor.get_value() > 550) //finds end point of mogo
{

  t_left->move_velocity(-20);
  t_right->move_velocity(20);
  b_left->move_velocity(-20);
  b_right->move_velocity(20);
  delay(500); //1200 if perfectly at 0 deg
  break;
  mogodetected = true;

/*
t_left->move_absolute((t_left->get_position()/2), -10);
t_right->move_absolute(t_right->get_position()/2, 10);
b_left->move_absolute((b_left->get_position()/2), -10);
b_right->move_absolute(b_right->get_position()/2, 10);
*/
}

  }
  else {
    	pros::lcd::set_text(3, std::to_string(distance_sensor.get_value()));
    t_left->move_velocity(10);
    t_right->move_velocity(-10);
    b_left->move_velocity(10);
    b_right->move_velocity(-10);
    delay(1);
  }

}
//move back to goal
  t_left->move_velocity(0);
  t_right->move_velocity(0);
  b_left->move_velocity(0);
  b_right->move_velocity(0);
  arm_left->move_absolute(-295, 40); //CHECK efficiency
  arm_right->move_absolute(-295, 40);
  //while (distance_sensor.get_value() > 50) {
    //arm_left->move_velocity(20); //CHECK efficiency
    //arm_right->move_velocity(20);
  //  delay(1);
  //}
  delay(2300);
  t_left->move_velocity(15);
  t_right->move_velocity(15);
  b_left->move_velocity(15);
  b_right->move_velocity(15);
  delay(300);
  t_left->move_velocity(-25);
  t_right->move_velocity(-25);
  b_left->move_velocity(-25);
  b_right->move_velocity(-25);
  delay(1500);
  
  arm_left->move_absolute(-90, 80);
  arm_right->move_absolute(-90, 80);
  delay(600);



  t_left->move_velocity(0);
  t_right->move_velocity(0);
  b_left->move_velocity(0);
  b_right->move_velocity(0);
  delay(20);
  t_left->move_velocity(-11); //rotates to rings
  t_right->move_velocity(11);
  b_left->move_velocity(-11);
  b_right->move_velocity(11);
  delay(1000);
  t_left->move_velocity(20); // moves forward a bit after picking up goal
  t_right->move_velocity(20);
  b_left->move_velocity(20);
  b_right->move_velocity(20);
  delay(1600);
  t_left->move_velocity(15); //rotates to rings
  t_right->move_velocity(-15);
  b_left->move_velocity(15);
  b_right->move_velocity(-15);
  delay(2700);
  t_left->move_velocity(15);
  t_right->move_velocity(15);
  b_left->move_velocity(15);
  b_right->move_velocity(15);
  belt->move_velocity(69000);
  delay(6600);
  t_left->move_velocity(-20);
  t_right->move_velocity(-20);
  b_left->move_velocity(-20);
  b_right->move_velocity(-20);
  delay(5500);
  t_left->move_velocity(0);
  t_right->move_velocity(0);
  b_left->move_velocity(0);
  b_right->move_velocity(0);
  belt->move_velocity(0);
  arm_left->move_absolute(-295, 40);
  arm_right->move_absolute(-295, 40);
  delay(2000);
  t_left->move_velocity(25);
  t_right->move_velocity(25);
  b_left->move_velocity(25);
  b_right->move_velocity(25);
  belt->move_velocity(250000);
  delay(2800);
  t_left->move_velocity(0);
  t_right->move_velocity(0);
  b_left->move_velocity(0);
  b_right->move_velocity(0);
  belt->move_velocity(0);
  arm_left->move_absolute(-90, 80);
  arm_right->move_absolute(-90, 80);
  delay(300);
/*
t_left->move_velocity(20);
t_right->move_velocity(-20);
b_left->move_velocity(20);
b_right->move_velocity(-20);
delay(1400);
t_left->move_velocity(-50);
t_right->move_velocity(-50);
b_left->move_velocity(-50);
b_right->move_velocity(-50);
delay(2500);
t_left->move_velocity(-45);
t_right->move_velocity(45);
b_left->move_velocity(-45);
b_right->move_velocity(45);
delay(700);
t_left->move_velocity(0);
t_right->move_velocity(0);
b_left->move_velocity(0);
b_right->move_velocity(0);
delay(200000);
*/
}
