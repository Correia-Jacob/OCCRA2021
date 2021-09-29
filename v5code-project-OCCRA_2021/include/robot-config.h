using namespace vex;

extern brain Brain;

using signature = vision::signature;

// VEXcode devices
extern controller Controller1;
extern limit LimitSwitchA;
extern motor_group DrivePort1and2;
extern motor_group DrivePort11and12;
extern motor_group ShootMotors3n4;
extern motor_group IntakeMotor9n10;
extern signature Vision8__SIG_1;
extern signature Vision8__SIG_2;
extern signature Vision8__SIG_3;
extern signature Vision8__SIG_4;
extern signature Vision8__SIG_5;
extern signature Vision8__SIG_6;
extern signature Vision8__SIG_7;
extern vision Vision8;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );