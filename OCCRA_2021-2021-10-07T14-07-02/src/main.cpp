/* Robot Configuration:
[Name]               [Type]     [Port(s)]
Controller1          controller                    
LimitSwitchD         switch        D               
Vision8              camera        8               
rightMotorB          motor         B               
leftMotorA           motor         A               
intakeMotorC         motor         C               
InsideintakeMotorD   motor         E               
topShootF            motor         F               
BottomShootG         motor         G               
TestingMotorLeft     motor         1               
TestingMotorRight    motor         2 
TESTINTALEMOTOR3     motor         3                   
*/


#include "vex.h"
using namespace vex;

void intake() {
 intakeMotorC.spin(forward);
 InsideintakeMotorD.spin(forward);
 }
void stopintake() {
 intakeMotorC.stop(); 
 InsideintakeMotorD.stop();
}

void autoIntake() {
Brain.Screen.clearLine();
Brain.Screen.print("Starting Autointake");
TestingMotorRight.stop(); 
TestingMotorLeft.stop();
TestingMotorLeft.setVelocity(100, percent);
TestingMotorRight.setVelocity(100, percent);
while (true) {
 Vision8.takeSnapshot(0);
 if (Vision8.largestObject.exists) {
if (Vision8.objects[0].centerX < 140) {
   Brain.Screen.newLine();
   Brain.Screen.print("Turning left");
   TestingMotorRight.spinFor(forward, 180, degrees); 
} 
if (Vision8.objects[0].centerX > 185) {
   Brain.Screen.newLine(); 
   Brain.Screen.print("Turning right");
   TestingMotorLeft.spinFor(forward, 180, degrees);
}
if (Vision8.objects[0].centerY < 160 &&  Vision8.objects[0].centerX < 185
&& 140 < Vision8.objects[0].centerX ) {
   Brain.Screen.newLine();   
   Brain.Screen.print("Forward"); 
   TESTINTALEMOTOR3.spin(forward);
   TestingMotorRight.spin(forward); 
   TestingMotorLeft.spin(forward); 
}
else{
   TestingMotorLeft.stop();
   TestingMotorRight.stop();
   
}
if (Controller1.ButtonB.pressing()) { 
   Brain.Screen.newLine();
   Brain.Screen.print("Ending Autointake");
   TESTINTALEMOTOR3.stop();
   break;
}
 LimitSwitchD.pressed(stopintake);
 if (LimitSwitchD.pressing()) {
   Brain.Screen.newLine();
   Brain.Screen.print("Ending Autointake");
   TESTINTALEMOTOR3.stop();

   break;
}
}}}

void stopShooter() {
 topShootF.stop(); 
 BottomShootG.stop();
 Brain.Screen.clearLine();
 Brain.Screen.print("Stopped shooting");
}
void startShooter() {
 topShootF.spin(forward);
 BottomShootG.spin(forward);
 Brain.Screen.clearLine();
 Brain.Screen.print("Starting to shoot");
}

int velocity = 75;
void speedUpShooter() {topShootF.setVelocity(velocity + 25, percent);
BottomShootG.setVelocity(velocity + 25, percent); 
Brain.Screen.clearLine();
Brain.Screen.print("Velocity increased to " [velocity]);
}
void slowDownShooter() {topShootF.setVelocity(velocity - 25, percent);
BottomShootG.setVelocity(velocity - 25, percent);
Brain.Screen.clearLine();
Brain.Screen.print("Velocity decreased to " [velocity]);
}

int main() {
  vexcodeInit();   

 Controller1.ButtonUp.pressed(speedUpShooter);
 Controller1.ButtonDown.pressed(slowDownShooter);

 topShootF.setVelocity(velocity, percent);
 BottomShootG.setVelocity(velocity, percent);

 Controller1.ButtonR2.pressed(startShooter);
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


