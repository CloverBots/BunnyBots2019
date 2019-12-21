/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/CubeSubsystem.h"
#include "commands/CubeCommand.h"
#include <iostream>

CubeSubsystem::CubeSubsystem() : Subsystem("ExampleSubsystem") {}

void CubeSubsystem::InitDefaultCommand()
{
  m_Cube_Motor0 = new TalonSRX(RobotMap::kCubeMotor0);
  m_Cube_Motor1 = new TalonSRX(RobotMap::kCubeMotor1);
  m_Flap_Latch = new frc::DoubleSolenoid(4, 5);
  m_Bed = new frc::DoubleSolenoid(2, 3);
  SetDefaultCommand(new CubeCommand());
}

void CubeSubsystem::SetCubeSpeed(double speed)
{
  m_Cube_Motor0->Set(ControlMode::PercentOutput, -speed);
  m_Cube_Motor1->Set(ControlMode::PercentOutput, speed);
}


void CubeSubsystem::SetLatch(frc::DoubleSolenoid::Value value)
{
  m_Flap_Latch->Set(value);
}

void CubeSubsystem::SetBed(frc::DoubleSolenoid::Value value)
{
  m_Bed->Set(value);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
