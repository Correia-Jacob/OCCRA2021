using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor29 rightDriveMotor;
extern motor29 leftDriveMotor;
extern motor29 intakeMotor;
extern motor29 chamberMotor;
extern motor29 shootingMotor1;
extern motor29 shootingMotor2;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );