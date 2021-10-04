using namespace vex;

extern brain Brain;

using signature = vision::signature;

// VEXcode devices
extern controller Controller1;
extern limit LimitSwitchD;
extern signature Vision8__SIG_1;
extern signature Vision8__SIG_2;
extern signature Vision8__SIG_3;
extern signature Vision8__SIG_4;
extern signature Vision8__SIG_5;
extern signature Vision8__SIG_6;
extern signature Vision8__SIG_7;
extern vision Vision8;
extern motor29 rightMotorB;
extern motor29 leftMotorA;
extern motor29 intakeMotorC;
extern motor29 InsideintakeMotorD;
extern motor29 topShootF;
extern motor29 BottomShootG;
extern motor TestingMotor1;
extern motor TestingMotor2;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );