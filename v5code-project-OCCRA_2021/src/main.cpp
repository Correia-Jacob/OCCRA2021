
#include "vex.h"

/* Intake Motor is Port 10
* Top shooting motor is port 4
* Bottom shooting motor is port 3
* Drivetrain uses ports 1 and 2 for one side. Ports 11 and 12 for the other.
*/

using namespace vex;

vision::signature SIG_1 (1, 0, 0, 0, 0, 0, 0, 3.000, 0);
vision::signature SIG_2 (2, 0, 0, 0, 0, 0, 0, 2.500, 0);
vision::signature SIG_3 (3, 0, 0, 0, 0, 0, 0, 2.500, 0);
vision::signature SIG_4 (4, 0, 0, 0, 0, 0, 0, 2.500, 0);
vision::signature SIG_5 (5, 0, 0, 0, 0, 0, 0, 2.500, 0);
vision::signature SIG_6 (6, 0, 0, 0, 0, 0, 0, 2.500, 0);
vision::signature SIG_7 (7, 0, 0, 0, 0, 0, 0, 2.500, 0);
vex::vision Vision8 ( vex::PORT8, 50, SIG_1, SIG_2, SIG_3, SIG_4, SIG_5, SIG_6, SIG_7 );

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


Controller1.ButtonL2.pressed(intake);
Controller1.ButtonL1.pressed(stopintake);
LimitSwitchA.pressed(stopintake);

// set up camera facing down at an angle. make robot turn to the ball, find the distance to the ball, 
// and travel that distance or set for when object gets below a certain y coordinate
// try drawing this triangle on paper to solve that math if its possible
while (Vision8.objects[1].exists) { // reports if the sensor detects whatever
double xCoordinate = Vision8.objects[1].centerX; // finds x coordinate
double yCoordinate = Vision8.objects[1].centerY; // finds y coordinate


}

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
      DrivePort11and12.setVelocity(0, percent);
    } else {
      DrivePort11and12.setVelocity(rightMotorSpeed, percent);
    }

    DrivePort1and2.spin(forward);
    DrivePort11and12.spin(forward);

   
  }

  }


