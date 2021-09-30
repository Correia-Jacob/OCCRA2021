
#include "vex.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// LimitSwitchA         limit         A               
// leftDrivePort1and2   motor_group   1, 2            
// righDrivePort11and12 motor_group   12, 11          
// ShootMotors3n4       motor_group   3, 4            
// IntakeMotor9n10      motor_group   9, 10           
// Vision8              vision        8               
// ---- END VEXCODE CONFIGURED DEVICES ----

/* Intake Motor is Port 10
* Top shooting motor is port 4
* Bottom shooting motor is port 3
* Drivetrain uses ports 1 and 2 for one side. Ports 11 and 12 for the other.
*/

using namespace vex;

vision::signature SIG_1 (1, 0, 0, 0, 0, 0, 0, 3.000, 0);
vex::vision Vision8 ( vex::PORT8, 50, SIG_1);
void autoIntake() {
while (Vision8.objects[1].exists) { // reports if the sensor detects it
double xCoordinate = Vision8.objects[1].centerX; // finds its x coordinate
double yCoordinate = Vision8.objects[1].centerY; // finds its y coordinate
if (xCoordinate< 158) { leftDrivePort1and2.spinToPosition(5, degrees); } //turn towards ball
if (xCoordinate> 158) { righDrivePort11and12.spinToPosition(5, degrees); }
if (yCoordinate < 160) {                          // move towards ball if its below cameras 160 y coordinate
    leftDrivePort1and2.spinFor(forward, 90, degrees); ;
    righDrivePort11and12.spinFor(forward, 90, degrees); }
if (Controller1.ButtonB.pressing()) {
  break;
}}}

void stopShooter() {ShootMotors3n4.stop(); }
void startShooter() {ShootMotors3n4.spin(forward);}

void intake() {IntakeMotor9n10.spin(forward);}
void stopintake() {IntakeMotor9n10.stop(); }

int velocity = 75;
void speedUpShooter() {ShootMotors3n4.setVelocity(velocity + 25, percent); }
void slowDownShooter() {ShootMotors3n4.setVelocity(velocity - 25, percent); }


int main() {
  vexcodeInit();   

Controller1.ButtonUp.pressed(speedUpShooter); // increases shooter velocity with ^ on controller
Controller1.ButtonDown.pressed(slowDownShooter); // decreases shooter velocity

ShootMotors3n4.setVelocity(velocity,rpm);

Controller1.ButtonR2.pressed(startShooter); // start shooting with R2 on controller
Controller1.ButtonR1.pressed(stopShooter); 

Controller1.ButtonA.pressed(autoIntake);

Controller1.ButtonL2.pressed(intake);
Controller1.ButtonL1.pressed(stopintake);
LimitSwitchA.pressed(stopintake);

  int deadband = 1;
  
  while (true) {
    int leftMotorSpeed = Controller1.Axis1.position() + Controller1.Axis3.position();
    int rightMotorSpeed = Controller1.Axis1.position() - Controller1.Axis3.position();

    if (abs(leftMotorSpeed) < deadband) {
      leftDrivePort1and2.setVelocity(0, percent);
    } else {
      leftDrivePort1and2.setVelocity(leftMotorSpeed, percent);
    }

    if (abs(rightMotorSpeed) < deadband) {
      righDrivePort11and12.setVelocity(0, percent);
    } else {
      righDrivePort11and12.setVelocity(rightMotorSpeed, percent);
    }

    leftDrivePort1and2.spin(forward);
    righDrivePort11and12.spin(forward);

   
  }

  }


