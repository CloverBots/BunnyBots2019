/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ToteAutoCommand.h"
#include "CommandBase.h"

ToteAutoCommand::ToteAutoCommand(bool grab) : grab(grab) 
{
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(CommandBase::totesubsystem.get());
}

// Called just before this Command runs the first time
void ToteAutoCommand::Initialize()
{
  CommandBase::totesubsystem->SetToteGrabber(frc::DoubleSolenoid::Value::kReverse);
}

// Called repeatedly when this Command is scheduled to run
void ToteAutoCommand::Execute()
{
  if(!grab)
  {
    CommandBase::totesubsystem->SetToteSpeed(-.5);
    CommandBase::totesubsystem->SetToteGrabber(frc::DoubleSolenoid::Value::kReverse);
  }
  else
  {
    if(CommandBase::totesubsystem->GetLR())
    {
      CommandBase::totesubsystem->SetToteSpeed(0);
      CommandBase::totesubsystem->SetToteGrabber(frc::DoubleSolenoid::Value::kForward);
      CommandBase::oi->stop_on_grab = true;
      frc::Wait(1);
    }
    else
    {
      CommandBase::totesubsystem->SetToteSpeed(.5);
    }
  }
}

// Make this return true when this Command no longer needs to run execute()
bool ToteAutoCommand::IsFinished() { return false; }

// Called once after isFinished returns true
void ToteAutoCommand::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToteAutoCommand::Interrupted() {}
