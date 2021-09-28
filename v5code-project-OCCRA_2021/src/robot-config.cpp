#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
limit LimitSwitchA = limit(Brain.ThreeWirePort.A);
motor DrivePort1and2MotorA = motor(PORT1, ratio18_1, false);
motor DrivePort1and2MotorB = motor(PORT2, ratio18_1, false);
motor_group DrivePort1and2 = motor_group(DrivePort1and2MotorA, DrivePort1and2MotorB);
motor DrivePort10and11MotorA = motor(PORT10, ratio18_1, false);
motor DrivePort10and11MotorB = motor(PORT11, ratio18_1, false);
motor_group DrivePort10and11 = motor_group(DrivePort10and11MotorA, DrivePort10and11MotorB);
motor IntakeMotor9 = motor(PORT9, ratio18_1, true);
motor ShootMotors3n4MotorA = motor(PORT3, ratio18_1, false);
motor ShootMotors3n4MotorB = motor(PORT4, ratio18_1, true);
motor_group ShootMotors3n4 = motor_group(ShootMotors3n4MotorA, ShootMotors3n4MotorB);

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