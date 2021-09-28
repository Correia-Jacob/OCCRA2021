using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern limit LimitSwitchA;
extern motor_group DrivePort1and2;
extern motor_group DrivePort11and12;
extern motor IntakeMotor10;
extern motor_group ShootMotors3n4;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );