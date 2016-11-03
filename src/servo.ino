#include <AccelStepper.h>
#define HALFSTEP 8

// Motor pin definitions
#define motor0Pin1  4     // IN1 on the ULN2003 driver 1
#define motor0Pin2  5     // IN2 on the ULN2003 driver 1
#define motor0Pin3  6     // IN3 on the ULN2003 driver 1
#define motor0Pin4  7     // IN4 on the ULN2003 driver 1
#define motor1Pin1  8     // IN1 on the ULN2003 driver 1
#define motor1Pin2  9     // IN2 on the ULN2003 driver 1
#define motor1Pin3  10     // IN3 on the ULN2003 driver 1
#define motor1Pin4  11     // IN4 on the ULN2003 driver 1

// Initialize with pin sequence IN1-IN3-IN2-IN4 for using the AccelStepper with 28BYJ-48
AccelStepper stepper0(HALFSTEP, motor0Pin1, motor0Pin3, motor0Pin2, motor0Pin4);
AccelStepper stepper1(HALFSTEP, motor1Pin1, motor1Pin3, motor1Pin2, motor1Pin4);

void setup()
{
	stepper1.setMaxSpeed(1000.0);
	stepper1.setAcceleration(100.0);
	stepper1.setSpeed(1000);
	stepper1.moveTo(20000);
	stepper0.setMaxSpeed(1000.0);
	stepper0.setAcceleration(100.0);
	stepper0.setSpeed(1000);
	stepper0.moveTo(20000);

}//--(end setup )---

void loop()
{

	//Change direction when the stepper reaches the target position
	if (stepper1.distanceToGo() == 0)
	{
		stepper1.moveTo(-stepper1.currentPosition());
	}
	stepper1.run();

	//Change direction when the stepper reaches the target position
	if (stepper0.distanceToGo() == 0)
	{
		stepper0.moveTo(-stepper0.currentPosition());
	}
	stepper0.run();
}
