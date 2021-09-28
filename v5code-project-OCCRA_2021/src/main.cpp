/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\12489                                            */
/*    Created:      Mon Sep 27 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// LimitSwitchA         limit         A               
// DrivePort1and2       motor_group   1, 2            
// DrivePort10and11     motor_group   10, 11          
// IntakeMotor9         motor         9               
// ShootMotors3n4       motor_group   3, 4            
// ---- END VEXCODE CONFIGURED DEVICES ----

/* Intake Motor is Port 9
* Top shooting motor is port 4
* Bottom shooting motor is port 3
* Drivetrain uses ports 1 and 2 for one side. Ports 10 and 11 for the other.
*/


#include "vex.h"

using namespace vex;
int velocity = 75;
void stop() {ShootMotors3n4.stop(); }
void start() {ShootMotors3n4.spin(forward);}
void speedup() {ShootMotors3n4.setVelocity(velocity + 25, percent); }
void slowdown() {ShootMotors3n4.setVelocity(velocity - 25, percent); }
void intake() {IntakeMotor9.spin(forward);}
void stopintake() {IntakeMotor9.stop(); }

int main() {
  vexcodeInit();   

Controller1.ButtonUp.pressed(speedup);
Controller1.ButtonDown.pressed(slowdown);

  ShootMotors3n4.setVelocity(velocity,rpm);

Controller1.ButtonL2.pressed(intake);
LimitSwitchA.pressed(stopintake);
 
 Controller1.ButtonR2.pressed(start);
 Controller1.ButtonR1.pressed(stop);
 
  int deadband = 1;
  
  while (true) {
    int leftMotorSpeed = Controller1.Axis1.position() + Controller1.Axis3.position();
    int rightMotorSpeed = Controller1.Axis1.position() - Controller1.Axis3.position();

    if (abs(leftMotorSpeed) < deadband) {
      DrivePort1and2.setVelocity(0, percent);
    } else {
      DrivePort1and2.setVelocity(leftMotorSpeed, percent);
    }

    if (abs(rightMotorSpeed) < deadband) {
      DrivePort10and11.setVelocity(0, percent);
    } else {
      DrivePort10and11.setVelocity(rightMotorSpeed, percent);
    }

    DrivePort1and2.spin(forward);
    DrivePort10and11.spin(forward);

   
  }

  }


