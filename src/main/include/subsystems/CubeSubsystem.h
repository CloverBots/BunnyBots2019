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

class CubeSubsystem : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  TalonSRX* m_Cube_Motor0;
  TalonSRX* m_Cube_Motor1;
  //frc::DoubleSolenoid* m_Flap_Latch;
  //frc::DoubleSolenoid* m_Bed;
 public:
  CubeSubsystem();
  void SetCubeSpeed(double speed);
  //void SetLatch(frc::DoubleSolenoid::Value value);
  //void SetBed(frc::DoubleSolenoid::Value value);
  void InitDefaultCommand() override;
};
