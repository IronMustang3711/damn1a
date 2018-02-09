// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef UPPERTILTPOSITION_H
#define UPPERTILTPOSITION_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class UpperTiltPosition: public frc::Command {
public:
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR
	UpperTiltPosition(double setpoint);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;

private:
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=VARIABLES
    double m_setpoint;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=VARIABLES
    double startTime=0;
    double prevTime=0;
    double prevPosition=0;
    double holdPower;  // this is 20% of max power
    double maxPower;
    double maxVelocity;  // encoder counts per second (about 1/3 rev/sec
    double targetVelocity = 0;  // usually 1/2 maxVelocity;
    double velocityP;  // proportional control
    double velocityFF;  // feedforward control
    double acceleration;  // accel to 300 counts/sec in one second
    double deceleration;
    double PIDband;  // switch to PID when within this band.
    bool velocityControl=0;  // velocity or PID distance control
};

#endif
