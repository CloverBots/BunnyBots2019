/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include "ctre/Phoenix.h"
#include "RobotMap.h"
#include <WPILib.h>
#include "ArmPIDOutput.h"
#include "ArmPIDSource.h"

class ToteSubsystem : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  TalonSRX* m_Arm_Motor0;
  TalonSRX* m_Arm_Motor1;
  TalonSRX* m_Tote_Motor;
  frc::DoubleSolenoid* m_Tote_Grabber;
  frc::DigitalInput* m_Left;
  frc::DigitalInput* m_Right;
  frc::PIDController* m_Arm_PID;
  ArmPIDSource* m_Arm_Source;
  ArmPIDOutput* m_Arm_Output;
  frc::DigitalInput* m_Top;
  frc::DigitalInput* m_Bottom;

  const double P = 0.47, I = 0, D = 0.06;
 public:
  ToteSubsystem();
  void SetArmSpeed(double speed);
  void SetToteSpeed(double speed);
  void SetToteGrabber(frc::DoubleSolenoid::Value value);
  bool GetLR();
  bool GetTop();
  bool GetBottom();
  ArmPIDSource* GetArmSource() { return m_Arm_Source; }
  frc::PIDController* GetArmPID();
  void InitDefaultCommand() override;
};
