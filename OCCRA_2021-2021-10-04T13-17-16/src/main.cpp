
#include "vex.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// LimitSwitchD         limit         D               
// Vision8              vision        8               
// rightMotorB          motor29       B               
// leftMotorA           motor29       A               
// intakeMotorC         motor29       C               
// InsideintakeMotorD   motor29       E               
// topShootF            motor29       F               
// BottomShootG         motor29       G               
// TestingMotor1        motor         1               
// TestingMotor2        motor         2               
// ---- END VEXCODE CONFIGURED DEVICES ----
using namespace vex;


void autoIntake() {
while (true) {
Vision8.takeSnapshot(0);
if (Vision8.objects[0].exists) { // reports if the sensor detects it
if (Vision8.objects[0].centerX < 158) {
  TestingMotor1.spinFor(forward, 90, degrees); //turn towards ball
} 
if (Vision8.objects[0].centerX > 158) {
  TestingMotor2.spinFor(forward, 90, degrees); //turn towards ball
}
if (Vision8.objects[0].centerY < 160) {                          // move towards ball if its below cameras 160 y coordinate
TestingMotor1.spinFor(forward, 90, degrees);
TestingMotor2.spinFor(forward, 90, degrees);
if (Controller1.ButtonB.pressing()) {
  break;
}
}
}}}


void stopShooter() {topShootF.stop(); 
BottomShootG.stop();}
void startShooter() {topShootF.spin(forward);
BottomShootG.spin(forward);}

void intake() {intakeMotorC.spin(forward);
InsideintakeMotorD.spin(forward);}
void stopintake() {intakeMotorC.stop(); 
InsideintakeMotorD.stop();}

int velocity = 75;
void speedUpShooter() {topShootF.setVelocity(velocity + 25, percent);
BottomShootG.setVelocity(velocity + 25, percent); }
void slowDownShooter() {topShootF.setVelocity(velocity - 25, percent);
BottomShootG.setVelocity(velocity - 25, percent);}

int main() {
  vexcodeInit();   

Controller1.ButtonUp.pressed(speedUpShooter); // increases shooter velocity with ^ on controller
Controller1.ButtonDown.pressed(slowDownShooter); // decreases shooter velocity

topShootF.setVelocity(velocity, percent);
BottomShootG.setVelocity(velocity, percent);

Controller1.ButtonR2.pressed(startShooter); // start shooting with R2 on controller
Controller1.ButtonR1.pressed(stopShooter); 

Controller1.ButtonA.pressed(autoIntake);

Controller1.ButtonL2.pressed(intake);
Controller1.ButtonL1.pressed(stopintake);
LimitSwitchD.pressed(stopintake);

  int deadband = 1;
  
  while (true) {
    int leftMotorSpeed = Controller1.Axis1.position() + Controller1.Axis3.position();
    int rightMotorSpeed = Controller1.Axis1.position() - Controller1.Axis3.position();

    if (abs(leftMotorSpeed) < deadband) {
      leftMotorA.setVelocity(0, percent);
    } else {
      leftMotorA.setVelocity(leftMotorSpeed, percent);
    }

    if (abs(rightMotorSpeed) < deadband) {
      rightMotorB.setVelocity(0, percent);
    } else {
      rightMotorB.setVelocity(rightMotorSpeed, percent);
    }

    leftMotorA.spin(forward);
    rightMotorB.spin(forward);

   
  }

  }


