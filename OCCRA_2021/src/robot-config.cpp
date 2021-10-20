#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
limit limitSwitchD = limit(Brain.ThreeWirePort.D);
/*vex-vision-config:begin*/
signature Vision8__SIG_1 = signature (1, 7539, 10051, 8795, -1385, 1, -692, 3, 0);
vision Vision8 = vision (PORT8, 50, Vision8__SIG_1);
/*vex-vision-config:end*/
motor29 rightMotorB = motor29(Brain.ThreeWirePort.B, false);
motor29 leftMotorA = motor29(Brain.ThreeWirePort.A, false);
motor29 intakeMotorC = motor29(Brain.ThreeWirePort.C, false);
motor29 InsideintakeMotorE = motor29(Brain.ThreeWirePort.E, true);
motor29 topShootF = motor29(Brain.ThreeWirePort.F, false);
motor29 BottomShootG = motor29(Brain.ThreeWirePort.G, false);
motor testingShootingMotor = motor(PORT3, ratio18_1, false);
controller Controller2 = controller(partner);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}