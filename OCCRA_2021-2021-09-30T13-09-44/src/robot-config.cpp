#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
limit LimitSwitchA = limit(Brain.ThreeWirePort.A);
motor leftDrivePort1and2MotorA = motor(PORT1, ratio18_1, false);
motor leftDrivePort1and2MotorB = motor(PORT2, ratio18_1, false);
motor_group leftDrivePort1and2 = motor_group(leftDrivePort1and2MotorA, leftDrivePort1and2MotorB);
motor righDrivePort11and12MotorA = motor(PORT12, ratio18_1, false);
motor righDrivePort11and12MotorB = motor(PORT11, ratio18_1, false);
motor_group righDrivePort11and12 = motor_group(righDrivePort11and12MotorA, righDrivePort11and12MotorB);
motor ShootMotors3n4MotorA = motor(PORT3, ratio18_1, false);
motor ShootMotors3n4MotorB = motor(PORT4, ratio18_1, true);
motor_group ShootMotors3n4 = motor_group(ShootMotors3n4MotorA, ShootMotors3n4MotorB);
motor IntakeMotor9n10MotorA = motor(PORT9, ratio18_1, true);
motor IntakeMotor9n10MotorB = motor(PORT10, ratio18_1, true);
motor_group IntakeMotor9n10 = motor_group(IntakeMotor9n10MotorA, IntakeMotor9n10MotorB);
/*vex-vision-config:begin*/
signature Vision8__SIG_1 = signature (1, 7539, 10051, 8795, -1385, 1, -692, 3, 0);
vision Vision8 = vision (PORT8, 50, Vision8__SIG_1);
/*vex-vision-config:end*/

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