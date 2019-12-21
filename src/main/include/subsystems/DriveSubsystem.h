/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include "rev/CANSparkMax.h"
#include "RobotMap.h"
#include "DrivePIDOutput.h"
#include "DrivePIDSource.h"
#include "LimePIDOutput.h"
#include "LimePIDSource.h"
#include <WPILib.h>

class DriveSubsystem : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  
  rev::CANSparkMax m_leftLeadMotor{RobotMap::leftLeadDeviceID, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_rightLeadMotor{RobotMap::rightLeadDeviceID, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_leftFollowMotor{RobotMap::leftFollowDeviceID, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_rightFollowMotor{RobotMap::rightFollowDeviceID, rev::CANSparkMax::MotorType::kBrushless};
  DrivePIDOutput* m_Left_Output;
  DrivePIDOutput* m_Right_Output;
  DrivePIDSource* m_Left_Source;
  DrivePIDSource* m_Right_Source;
  LimePIDOutput* m_Lime_Output;
  LimePIDSource* m_Lime_Source;
  frc::PIDController* m_Left_PID;
  frc::PIDController* m_Right_PID;
  frc::PIDController* m_Lime_PID;
  const double P = 0.05, I = 1e-4, D = 0.06;
  const double lP = 0.006, lI = 0, lD = 0.0;
 public:
  DriveSubsystem();
  void Drive(double speed, double turn, bool speed_override);
  frc::PIDController* GetLeftPID() { return m_Left_PID; }
  frc::PIDController* GetRightPID() { return m_Right_PID; }
  frc::PIDController* GetLimePID() { return m_Lime_PID; }
  DrivePIDSource* GetLeftSource() { return m_Left_Source; }
  DrivePIDSource* GetRightSource() { return m_Right_Source; }
  DrivePIDOutput* GetLeftOutput() { return m_Left_Output; }
  DrivePIDOutput* GetRightOutput() { return m_Right_Output; }
  LimePIDOutput* GetLimeOutput() { return m_Lime_Output; }
  LimePIDSource* GetLimeSource() { return m_Lime_Source; }
  void InitDefaultCommand() override;
};
