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


  // set  the brake mode on the motors
arm_left->set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
 arm_right->set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
//  t_left->set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
//  t_right->set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
//  b_left->set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  //b_right->set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
//  belt->set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
}

//REAL: Distance sensor auton
void Auton::distance() {

 pros::ADIUltrasonic distance_sensor (ULTRA_PING, ULTRA_ECHO); //Initialize dist sensor

  t_left->move_velocity(-30);
  t_right->move_velocity(-30);
  b_left->move_velocity(-30);
  b_right->move_velocity(-30);
  	pros::lcd::set_text(3, std::to_string(distance_sensor.get_value()));
  pros::delay(1500); //move for a little bit to get enough space to rotates

bool mogodetected = false;

while (mogodetected == false ) { //rotate until goal is detected within range
if (!(distance_sensor.get_value() < 250 || distance_sensor.get_value() > 500)) {
  t_left->move_velocity(0);
  t_right->move_velocity(0);
  b_left->move_velocity(0);
  b_right->move_velocity(0);
  pros::lcd::set_text(3, std::to_string(distance_sensor.get_value()));
  /*
  if ((distance_sensor.get_value() < 500 )) {
    t_left->move_velocity(5);
    t_right->move_velocity(-5);
    b_left->move_velocity(5);
    b_right->move_velocity(-5);
  pros::delay(2000);
  mogodetected = true;
  break;
}
*/
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
t_left->move_velocity(0);
t_right->move_velocity(0);
b_left->move_velocity(0);
b_right->move_velocity(0);
delay(50);
  arm_left->move_absolute(105, 20); //Drop arms
  arm_right->move_absolute(105, 20);
  pros::delay(2000);

  while(distance_sensor.get_value() > 50 ) { //Move back until goal is within range
  t_left->move_velocity(-15);
  t_right->move_velocity(-15);
  b_left->move_velocity(-15);
  b_right->move_velocity(-15);
  delay(1);
}

  delay(1500);
/*
  if (!(distance_sensor.get_value() < 200 || distance_sensor.get_value() > 300)) { //if goal is in arms
    arm_left->move_velocity(-30); //Lift arms(with mogo in hopefully)
    arm_right->move_velocity(-30);
    delay(500);
    if(arm_right->get_efficiency() <= 60) {

      arm_left->move_absolute(30, 1000); //Lift arms(with mogo in hopefully)
      arm_right->move_absolute(30, 1000);
      delay(500);
      t_left->move_velocity(15);
      t_right->move_velocity(15);
      b_left->move_velocity(15);
      b_right->move_velocity(15);
    }

   else{
     arm_right->move_velocity(0);
     arm_left->move_velocity(0);
   pros::lcd::initialize();
   pros::lcd::set_text(2, "GOAL NOT DETECTED" );
  //add countercheck
    }

  }

  else {

    while(distance_sensor.get_value() > 260 ) { //Move back until goal is within range
    t_left->move_velocity(-15);
    t_right->move_velocity(-15);
    b_left->move_velocity(-15);
    b_right->move_velocity(-15);
    delay(100);
    }

    arm_left->move_absolute(30, 100000); //Lift arms(with mogo in hopefully)
    arm_right->move_absolute(30, 100000);

  }

*/

}

void Auton::ultrasonic() {


   pros::ADIUltrasonic distance_sensor (ULTRA_PING, ULTRA_ECHO); //Initialize dist sensor

    t_left->move_velocity(-30);
    t_right->move_velocity(-30);
    b_left->move_velocity(-30);
    b_right->move_velocity(-30);
    	pros::lcd::set_text(3, std::to_string(distance_sensor.get_value()));
    pros::delay(1500); //move for a little bit to get enough space to rotates
    t_left->move_velocity(10);
    t_right->move_velocity(-10);
    b_left->move_velocity(10);
    b_right->move_velocity(-10);
    delay(500);
  bool mogodetected = false;

  while (mogodetected == false ) { //rotate until goal is detected within range
  if (!(distance_sensor.get_value() < 60 || distance_sensor.get_value() > 500)) {
    //int time;
  //  int timer(time);


    t_left->move_velocity(10);
    t_right->move_velocity(-10);
    b_left->move_velocity(10);
    b_right->move_velocity(-10);
    pros::lcd::set_text(3, std::to_string(distance_sensor.get_value()));

//we
if (distance_sensor.get_value() > 600) //finds end point of mogo
{
  t_left->move_velocity(-10);
  t_right->move_velocity(10);
  b_left->move_velocity(-10);
  b_right->move_velocity(10);
  delay(1100); //1200 if perfectly at 0 deg
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
arm_left->move_absolute(110, 20); //CHECK efficiency
arm_right->move_absolute(110, 20);
//while (distance_sensor.get_value() > 50) {
  //arm_left->move_velocity(20); //CHECK efficiency
  //arm_right->move_velocity(20);
//  delay(1);
//}
delay(2000);
t_left->move_velocity(-15);
t_right->move_velocity(-15);
b_left->move_velocity(-15);
b_right->move_velocity(-15);
delay(2000);

arm_left->move_velocity(-30); //CHECK efficiency
arm_right->move_velocity(-30);
delay(500);

if(arm_right->get_efficiency() < 60) {
  arm_left->move_absolute(30, 10000000); //Lift arms(with mogo in hopefully)
  arm_right->move_absolute(30, 100000000);
}

else if(arm_right->get_efficiency() >= 60){
 arm_right->move_velocity(0);
 arm_left->move_velocity(0);
pros::lcd::initialize();
pros::lcd::set_text(2, "GOAL NOT DETECTED" );

}

t_left->move_velocity(0);
t_right->move_velocity(0);
b_left->move_velocity(0);
b_right->move_velocity(0);
delay(100);

t_left->move_velocity(15);
t_right->move_velocity(15);
b_left->move_velocity(15);
b_right->move_velocity(15);
delay(700);
t_left->move_velocity(15);
t_right->move_velocity(-15);
b_left->move_velocity(15);
b_right->move_velocity(-15);
delay(1600);
t_left->move_velocity(15);
t_right->move_velocity(15);
b_left->move_velocity(15);
b_right->move_velocity(15);
belt->move_velocity(600);
delay(3000);
exit(EXIT_SUCCESS);
}




//testing optical SENSOR_PORT
void Auton::visiontest()
{
 pros::Vision vision_sensor (VISION_SENSOR, pros::E_VISION_ZERO_CENTER);
  pros::vision_signature_s_t RED_SIG =
    pros::Vision::signature_from_utility(EXAMPLE_SIG, 8973, 11143, 10058, -2119, -1053, -1586, 5.4, 0);
  vision_sensor.set_signature(EXAMPLE_SIG, &RED_SIG);
vision_object_s_t object_arr[NUM_VISION_OBJECTS];

  //vision_object_s_t rtn = vision_sensor.get_by_size(0);
      // Gets the largest object
  //    pros::lcd::set_text(3, std::to_string(rtn.signature));
    //  std::cout << "sig: " << rtn.signature;
      pros::delay(2);
bool foundmogo = false;
pros::lcd::initialize();
  pros::c::vision_read_by_sig(VISION_SENSOR, 0, EXAMPLE_SIG, NUM_VISION_OBJECTS, object_arr);
   printf("sig: %d", object_arr[0].signature);
 if(object_arr[0].signature) {
    pros::lcd::set_text(4, "DETECTED MOGO!");
    vision_sensor.get_object_count();
 }
 else {
    pros::lcd::set_text(4, "NULL");
  }




}


//testing auton motion
void Auton::test() {
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
void Auton::rotate() {

   t_left->move_velocity(-10);
   t_right->move_velocity(-10);
   b_left->move_velocity(-10);
   b_right->move_velocity(-10);
   pros::delay(2700); //move for a little bit to get enough space to rotates

   //rotate until goal is detected within range
   t_left->move_velocity(10);
   t_right->move_velocity(-10);
   b_left->move_velocity(10);
   b_right->move_velocity(-10);
   delay(100);

   arm_left->move_absolute(105, 20); //Drop arms
   arm_right->move_absolute(105, 20);
   pros::delay(2000);

//Move back until goal is within range
   t_left->move_velocity(-15);
   t_right->move_velocity(-15);
   b_left->move_velocity(-15);
   b_right->move_velocity(-15);
   delay(3000);

   arm_left->move_velocity(-30); //CHECK efficiency
   arm_right->move_velocity(-30);
   delay(500);

   if(arm_right->get_efficiency() < 60) {
     arm_left->move_absolute(30, 10000000); //Lift arms(with mogo in hopefully)
     arm_right->move_absolute(30, 100000000);
   }

  else if(arm_right->get_efficiency() >= 60){
    arm_right->move_velocity(0);
    arm_left->move_velocity(0);
  pros::lcd::initialize();
  pros::lcd::set_text(2, "GOAL NOT DETECTED" );

   }

   t_left->move_velocity(0);
   t_right->move_velocity(0);
   b_left->move_velocity(0);
   b_right->move_velocity(0);

   pros::delay(500);

   t_left->move_velocity(15);
   t_right->move_velocity(15);
   b_left->move_velocity(15);
   b_right->move_velocity(15);
  pros::delay(1000);

  t_left->move_velocity(15);
  t_right->move_velocity(15);
  b_left->move_velocity(15);
  b_right->move_velocity(15);
 pros::delay(1000);

   }


 //gauges whether mogo is in arms
void Auton::motortest() {

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
