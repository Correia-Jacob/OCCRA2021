/* Robot Configuration:
[Name]               [Type]     [Port(s)]
Controller1          controller   
leftDriveMotor       motor29       A                   
rightDriveMotor      motor29       B                            
intakeMotor          motor29       C               
chamberMotor         motor29       E               
shootingMotor1       motor29       F               
shootingMotor2       motor29       G               
*/

#include "vex.h"  
#include <sstream>
using namespace vex;

int velocity = 100;

void speedUp() {
 velocity += 10;
 Brain.Screen.clearLine();
 std::stringstream velocityChange;  
 std::string velocityString;
 velocityChange << velocity;
 velocityChange >> velocityString;
 Brain.Screen.print(("Velocity increased to " + velocityString + "%").c_str());
}
void slowDown() {
 velocity -= 10;
 Brain.Screen.clearLine();
 std::stringstream velocityChange;  
 std::string velocityString;
 velocityChange << velocity;
 velocityChange >> velocityString;
 Brain.Screen.print(("Velocity decreased to " + velocityString + "%").c_str());
} 

int main() {

 Controller1.ButtonUp.pressed(speedUp);
 Controller1.ButtonDown.pressed(slowDown);

 while (true) {
   shootingMotor1.setVelocity(velocity, percent);
   shootingMotor2.setVelocity(velocity, percent);
   intakeMotor.setVelocity(velocity, percent);
   chamberMotor.setVelocity(velocity, percent);

   if (Controller1.ButtonR2.pressing()) { // Shoot ball
   shootingMotor1.spin(forward);
   shootingMotor2.spin(forward);
   }
   else if (Controller1.ButtonR1.pressing()) { // Reverse Shooters if ball is stuck
     shootingMotor1.spin(reverse);
     shootingMotor2.spin(reverse);
     }
    else {
       shootingMotor1.stop();
       shootingMotor2.stop();
       }
  
   if (Controller1.ButtonL2.pressing()) { // Intake ball
     intakeMotor.spin(forward);
     }
     else if (Controller1.ButtonL1.pressing()) { // Reverse Intake if ball is stuck
       intakeMotor.spin(reverse);
       }
       else {
         intakeMotor.stop();
         }
     
   if (Controller1.ButtonA.pressing()) { // Start Chamber
     chamberMotor.spin(forward);
     }
       else if (Controller1.ButtonB.pressing()) { // Reverse Chamber
         chamberMotor.spin(reverse);
         }
         else {
           chamberMotor.stop();
           }

    
   //Joystick drive
  
   int leftMotorSpeed = Controller1.Axis1.position() + Controller1.Axis3.position();
   int rightMotorSpeed = Controller1.Axis1.position() - Controller1.Axis3.position();

   if (abs(leftMotorSpeed) < 0) {
     leftDriveMotor.setVelocity(0, percent);
     } 
     else {
       leftDriveMotor.setVelocity(leftMotorSpeed, percent);
       }

   if (abs(rightMotorSpeed) < 0) {
     rightDriveMotor.setVelocity(0, percent);
     } 
     else {
       rightDriveMotor.setVelocity(rightMotorSpeed, percent);
       }

    leftDriveMotor.spin(forward);
    rightDriveMotor.spin(forward);
 }
}

  


