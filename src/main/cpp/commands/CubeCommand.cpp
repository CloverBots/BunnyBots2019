/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/CubeCommand.h"
#include "CommandBase.h"
#include <iostream>

CubeCommand::CubeCommand() {
  Requires(CommandBase::cubesubsystem.get());
}

// Called just before this Command runs the first time
void CubeCommand::Initialize()
{
  //CommandBase::cubesubsystem->SetBed(frc::DoubleSolenoid::Value::kReverse);
}

// Called repeatedly when this Command is scheduled to run
void CubeCommand::Execute()
{
  if(CommandBase::oi->GetButton(1, Buttons::X))
  {
    CommandBase::cubesubsystem->SetCubeSpeed(.50);
  }
  else
  {
    CommandBase::cubesubsystem->SetCubeSpeed(0);
  }
  /*
  if(CommandBase::oi->GetButton(1, Buttons::Start) || CommandBase::oi->GetButton(1, Buttons::Back))
  {
    CommandBase::cubesubsystem->SetBed(frc::DoubleSolenoid::Value::kForward);
  }
  else
  {
    CommandBase::cubesubsystem->SetBed(frc::DoubleSolenoid::Value::kReverse);
  }
  */
}

// Make this return true when this Command no longer needs to run execute()
bool CubeCommand::IsFinished() { return false; }

// Called once after isFinished returns true
void CubeCommand::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CubeCommand::Interrupted() {}
