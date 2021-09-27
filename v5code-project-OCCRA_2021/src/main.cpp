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
// Rightmotor           motor         1               
// Controller1          controller                    
// LeftMotor            motor         2               
// Motor3               motor         3               
// LimitSwitchA         limit         A               
// ---- END VEXCODE CONFIGURED DEVICES ----


#include "vex.h"

using namespace vex;
int velocity = 75;
void stop() {Motor3.stop(); }
void start() {Motor3.spin(forward);}
void speedup() {Motor3.setVelocity(velocity + 25, percent); }
void slowdown() {Motor3.setVelocity(velocity - 25, percent); }

int main() {
  vexcodeInit();   

Controller1.ButtonUp.pressed(speedup);
Controller1.ButtonDown.pressed(slowdown);

  Motor3.setVelocity(velocity,rpm);

  LimitSwitchA.pressed(stop);

 Controller1.ButtonR2.pressed(start);
 Controller1.ButtonR1.pressed(stop);
 
  int deadband = 1;
  
  while (true) {
    int leftMotorSpeed = Controller1.Axis1.position() + Controller1.Axis3.position();
    int rightMotorSpeed = Controller1.Axis1.position() - Controller1.Axis3.position();

    if (abs(leftMotorSpeed) < deadband) {
      LeftMotor.setVelocity(0, percent);
    } else {
      LeftMotor.setVelocity(leftMotorSpeed, percent);
    }

    if (abs(rightMotorSpeed) < deadband) {
      Rightmotor.setVelocity(0, percent);
    } else {
      Rightmotor.setVelocity(rightMotorSpeed, percent);
    }

    LeftMotor.spin(forward);
    Rightmotor.spin(forward);

   
  }

  }


