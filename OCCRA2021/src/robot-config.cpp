#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor29 rightDriveMotor = motor29(Brain.ThreeWirePort.B, false);
motor29 leftDriveMotor = motor29(Brain.ThreeWirePort.A, false);
motor29 intakeMotor = motor29(Brain.ThreeWirePort.C, false);
motor29 chamberMotor = motor29(Brain.ThreeWirePort.E, true);
motor29 shootingMotor1 = motor29(Brain.ThreeWirePort.F, false);
motor29 shootingMotor2 = motor29(Brain.ThreeWirePort.G, false);

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