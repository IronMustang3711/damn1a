// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef ROBOTMAP_H
#define ROBOTMAP_H

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "WPILib.h"
#include "ctre/Phoenix.h"

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
class RobotMap {
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static std::shared_ptr<frc::SpeedController> upperTiltUpperMotor;
	static std::shared_ptr<frc::Encoder> upperTiltUpperEncoder;
	static std::shared_ptr<frc::SpeedController> bucketBucketMotor;
	static std::shared_ptr<frc::Encoder> bucketBucketEncoder;
	static std::shared_ptr<frc::SpeedController> clampTiltMotor;
	static std::shared_ptr<frc::Encoder> clampTiltEncoder;
	static std::shared_ptr<WPI_TalonSRX> chassisLeftFront;
	static std::shared_ptr<WPI_TalonSRX> chassisLeftRear;
	static std::shared_ptr<frc::SpeedControllerGroup> chassisLeftSide;
	static std::shared_ptr<WPI_TalonSRX> chassisRightFront;
	static std::shared_ptr<WPI_TalonSRX> chassisRightRear1;
	static std::shared_ptr<frc::SpeedControllerGroup> chassisRightSide;
	static std::shared_ptr<frc::DifferentialDrive> chassisDifferentialDrive;
	static std::shared_ptr<frc::SpeedController> clampClampMotor;
	static std::shared_ptr<frc::Encoder> clampClampEncoder;
	static std::shared_ptr<frc::PowerDistributionPanel> subsystem1PowerDistributionPanel1;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static std::shared_ptr<frc::SpeedController> winchMotor;

	static void init();
};
#endif
