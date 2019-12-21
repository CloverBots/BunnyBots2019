/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/CubeIntakeAutoCommand.h"
#include "CommandBase.h"

CubeIntakeAutoCommand::CubeIntakeAutoCommand(double speed) : speed(speed) {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(CommandBase::cubesubsystem.get());
}

// Called just before this Command runs the first time
void CubeIntakeAutoCommand::Initialize()
{
  CommandBase::cubesubsystem->SetLatch(frc::DoubleSolenoid::Value::kForward);
}

// Called repeatedly when this Command is scheduled to run
void CubeIntakeAutoCommand::Execute() 
{
  if (cubejanktimer <= 65)
  {
    cubejanktimer++;
    CommandBase::cubesubsystem->SetCubeSpeed(speed);
  }
  else
  {
    CommandBase::cubesubsystem->SetCubeSpeed(0);
  }
}

// Make this return true when this Command no longer needs to run execute()
bool CubeIntakeAutoCommand::IsFinished() { return false; }

// Called once after isFinished returns true
void CubeIntakeAutoCommand::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CubeIntakeAutoCommand::Interrupted() {}
