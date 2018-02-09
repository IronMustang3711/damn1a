// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.



#include "BucketTiltPosition.h"
#include "../Robot.h"

using namespace frc;

struct{
	float armPosition;
	float bucketPosition;
} gearing[6] = {{0,-25},
		{130,-25},
		{150,5},
		{200,30},
		{300,80},
		{400,130}};


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

BucketTiltPosition::BucketTiltPosition(double setpoint): Command() {
    m_setpoint = setpoint;
        // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::bucket.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void BucketTiltPosition::Initialize() {
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZE
    Robot::bucket->Enable();

    if (m_setpoint != 100)  //special setpoint to keep bucket oriented to hold cube as arm is raised
    	Robot::bucket->SetSetpoint(m_setpoint);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZE
	Robot::bucket->SetOutputRange(-0.8,0.8);  // enable full power.

}

// Called repeatedly when this Command is scheduled to run
void BucketTiltPosition::Execute() {
	double currentPosition = Robot::bucket->GetPosition();

	if (m_setpoint == 100) {  // this is the special upper arm following code
		double bucketSetpoint;
//		double upperPosition = Robot::upperTilt->ReturnPIDInput();
		double upperPosition = Robot::upperTilt->GetPosition();
		int index = 0;

		for (int i = 5; i > 0; i--) {
			if (upperPosition > gearing[i].armPosition) {
				index = i;
				break;
			}
		}

		if (index > 4)
			bucketSetpoint = gearing[5].bucketPosition; // end of gearing table
		else if (index > 0)  // lineally interpolate
			bucketSetpoint = gearing[index].bucketPosition
					+ (upperPosition - gearing[index].armPosition)
							* (gearing[index + 1].bucketPosition
									- gearing[index].bucketPosition)
							/ (gearing[index + 1].armPosition
									- gearing[index].armPosition);
		else
			bucketSetpoint = gearing[0].bucketPosition; // start at beginning of gearing table

//		SmartDashboard::PutNumber("Index", index);
//		SmartDashboard::PutNumber("Upper", upperPosition);
//		SmartDashboard::PutNumber("bucketSetpoint", bucketSetpoint);
		Robot::bucket->SetSetpoint(bucketSetpoint);
	}
	else
	{
	    if (m_setpoint == 200){
	    	if (Robot::upperTilt->GetPosition() > 250) // are we at scale?
	    		Robot::bucket->SetSetpoint(210);
	    	else
	    		Robot::bucket->SetSetpoint(80);
	    }

		if (m_setpoint > currentPosition)  // if dropping bucket, then low power
			Robot::bucket->SetOutputRange(-0.4,0.4);  // hold at low power
	}
	SmartDashboard::PutNumber("Bucket",currentPosition);
}

// Make this return true when this Command no longer needs to run execute()
bool BucketTiltPosition::IsFinished() {
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ISFINISHED
	if (m_setpoint == 100)
		return false;
	else
		return Robot::bucket->OnTarget();

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ISFINISHED
}

// Called once after isFinished returns true
void BucketTiltPosition::End() {
	Robot::bucket->SetOutputRange(-0.2,0.2);  // hold at low power
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BucketTiltPosition::Interrupted() {

}
