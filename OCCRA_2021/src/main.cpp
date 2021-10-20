/* Robot Configuration:
[Name]               [Type]     [Port(s)]
Controller1          controller                    
Controller2          controller
limitSwitchD         switch        D               
Vision8              camera        8               
rightMotorB          motor         B               
leftMotorA           motor         A               
intakeMotorC         motor         C               
insideIntakeMotorD   motor         E               
topShootF            motor         F               
BottomShootG         motor         G               
testingShootingMotor motor         3                   
*/

#include "vex.h"
using namespace vex;

void intake() {
 intakeMotorC.spin(forward);
 Brain.Screen.clearLine();
 Brain.Screen.setFont(monoXXL); 
 Brain.Screen.setFillColor(blue); 
 Brain.Screen.print("COLLECTING");
 }

void reverseIntake() {
 intakeMotorC.spin(reverse);
 Brain.Screen.clearLine();
 Brain.Screen.setFont(monoXXL); 
 Brain.Screen.setFillColor(blue); 
 Brain.Screen.print("UNCOLLECTING");
 }

void stopIntake() {
 intakeMotorC.stop(); 
 Brain.Screen.clearLine();
 Brain.Screen.setFont(monoXXL); 
 Brain.Screen.setFillColor(red); 
 Brain.Screen.print("FINISHED COLLECTING");
}
void chamberStart() {
 InsideintakeMotorE.spin(forward);
}
void chamberStop() {
 InsideintakeMotorE.stop();
}

void reverseChamber() {
 InsideintakeMotorE.spin(reverse);
}


void stopShooter() {
 topShootF.stop(); 
 BottomShootG.stop();
 Brain.Screen.clearLine();
 Brain.Screen.setFont(monoXXL); 
 Brain.Screen.setFillColor(red); 
 Brain.Screen.print("STOPPED SHOOTING");
}
void startShooter() {
 topShootF.spin(forward);
 BottomShootG.spin(forward);
 Brain.Screen.clearLine();
Brain.Screen.setFont(monoXXL); 
 Brain.Screen.setFillColor(green); 
 Brain.Screen.print("SHOOTING");
}

void reverseShooter() {
 topShootF.spin(reverse);
 BottomShootG.spin(reverse);
 Brain.Screen.clearLine();
Brain.Screen.setFont(monoXXL); 
 Brain.Screen.setFillColor(green); 
 Brain.Screen.print("UNSHOOTING");
}

int main() {
  vexcodeInit();   

 Controller1.ButtonRight.pressed(reverseIntake);
 Controller1.ButtonRight.released(stopIntake);
 
 Controller1.ButtonDown.pressed(reverseChamber);
 Controller1.ButtonDown.released(chamberStop);

  Controller1.ButtonUp.pressed(reverseShooter);
 Controller1.ButtonUp.released(stopShooter);


 Controller2.ButtonUp.pressed(reverseShooter);
 Controller2.ButtonUp.released(stopShooter);
 
 Controller2.ButtonDown.pressed(reverseChamber);
 Controller2.ButtonDown.released(chamberStop);

  Controller2.ButtonRight.pressed(reverseIntake);
 Controller2.ButtonRight.released(stopIntake);


 topShootF.setVelocity(100, percent);
 BottomShootG.setVelocity(100, percent);
 intakeMotorC.setVelocity(100, percent);
 InsideintakeMotorE.setVelocity(100, percent);


 Controller1.ButtonX.pressed(startShooter);
 Controller1.ButtonX.released(stopShooter);

 Controller2.ButtonX.pressed(startShooter);
 Controller2.ButtonX.released(stopShooter);

 // Controller1.ButtonR2.pressed(autoIntake); [For Small Robot only]

 Controller1.ButtonA.pressed(intake); 
 Controller1.ButtonA.released(stopIntake);

 Controller2.ButtonA.pressed(intake);
 Controller2.ButtonA.released(stopIntake);


 limitSwitchD.pressed(stopIntake);

 Controller1.ButtonB.pressed(chamberStart);
 Controller1.ButtonB.released(chamberStop);

 Controller2.ButtonB.pressed(chamberStart);
 Controller2.ButtonB.released(chamberStop);

 limitSwitchD.pressed(stopIntake);
  
while (true) {

  int leftMotorSpeed = Controller1.Axis1.position() + Controller1.Axis3.position();
  int rightMotorSpeed = Controller1.Axis1.position() - Controller1.Axis3.position();

  if (abs(leftMotorSpeed) < 0) {
    leftMotorA.setVelocity(0, percent);
   } else {
      leftMotorA.setVelocity(leftMotorSpeed, percent);
    }

    if (abs(rightMotorSpeed) < 0) {
      rightMotorB.setVelocity(0, percent);
    } else {
      rightMotorB.setVelocity(rightMotorSpeed, percent);
    }

    leftMotorA.spin(forward);
    rightMotorB.spin(forward);

   
}
  
/* [For small robot only]
void autoIntake() {
Brain.Screen.clearLine();
Brain.Screen.print("Starting Autointake");
int degreesToTurn;
while (true) {
 leftMotorA.setVelocity(70, percent);
 rightMotorB.setVelocity(70, percent);
 Vision8.takeSnapshot(0);
 if (Vision8.largestObject.exists) {
if (Vision8.objects[0].centerX < 138) {
   Brain.Screen.newLine();
   Brain.Screen.print("Turning left");
   degreesToTurn = 158 - Vision8.objects[0].centerX;
   rightMotorB.spinFor(forward, (degreesToTurn*5.5), degrees); 
} 
if (Vision8.objects[0].centerX > 178) {
   Brain.Screen.newLine(); 
   Brain.Screen.print("Turning right");
   degreesToTurn = Vision8.objects[0].centerX - 158;
   leftMotorA.spinFor(forward, (degreesToTurn*5.5), degrees);
}
if (Vision8.objects[0].centerX < 178 && 138 < Vision8.objects[0].centerX ) {
   Brain.Screen.newLine();   
   Brain.Screen.print("Forward");
   leftMotorA.setVelocity(100, percent);
   rightMotorB.setVelocity(100, percent);
   testingShootingMotor.spin(forward);
   rightMotorB.spin(forward); 
   leftMotorA.spin(forward);
}
if (Controller1.ButtonB.pressing()) { 
   Brain.Screen.newLine();
   Brain.Screen.print("Ending Autointake");
   testingShootingMotor.stop();
   rightMotorB.stop(); 
   leftMotorA.stop(); 

   break;
}
 LimitSwitchD.pressed(stopintake);
 if (LimitSwitchD.pressing()) {
   Brain.Screen.newLine();
   Brain.Screen.print("Ending Autointake");
   testingShootingMotor.stop();

   break;
}
}
else {
  Brain.Screen.newLine();
  Brain.Screen.print("Object not found. Turning Right.");
  leftMotorA.spinFor(forward, 575, degrees); 
}
}}

int velocity = 75;
void speedUp() {
topShootF.setVelocity(velocity + 25, percent);
BottomShootG.setVelocity(velocity + 25, percent); 
Brain.Screen.clearLine();
Brain.Screen.print("Velocity increased to " [velocity]);
}
void slowDown() {
topShootF.setVelocity(velocity - 25, percent);
BottomShootG.setVelocity(velocity - 25, percent);
Brain.Screen.clearLine();
Brain.Screen.print("Velocity decreased to " [velocity]);
}


*/
  }

  


