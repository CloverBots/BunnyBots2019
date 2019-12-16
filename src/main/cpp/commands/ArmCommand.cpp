/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ArmCommand.h"
#include "CommandBase.h"
#include <iostream>

ArmCommand::ArmCommand(bool lowered) : lowered(lowered) {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(CommandBase::totesubsystem.get());
}

// Called just before this Command runs the first time
void ArmCommand::Initialize()
{
  CommandBase::totesubsystem->GetArmPID()->SetEnabled(true);
  CommandBase::totesubsystem->GetArmPID()->SetSetpoint(0);
}

// Called repeatedly when this Command is scheduled to run
void ArmCommand::Execute()
{
  if(lowered)
  {
    CommandBase::totesubsystem->GetArmPID()->SetSetpoint(-1.41);
  }
  else
  {
    
    CommandBase::totesubsystem->GetArmPID()->SetSetpoint(0);
  }
  
  if(CommandBase::totesubsystem->GetTop())
  {
    if (toggle <= 25)
    {
      finished = true;
      CommandBase::totesubsystem->GetArmSource()->Reset(0);
      toggle++;
    }
    CommandBase::totesubsystem->GetArmPID()->SetOutputRange(-1, 0);
  }
  else if(CommandBase::totesubsystem->GetBottom())
  {
    
    toggle = 0;
    CommandBase::totesubsystem->GetArmPID()->SetOutputRange(0, .3);
  }
  else
  {
    toggle = 0;
    CommandBase::totesubsystem->GetArmPID()->SetOutputRange(-1, .3);
  }

}

// Make this return true when this Command no longer needs to run execute()
bool ArmCommand::IsFinished() { return finished; }

// Called once after isFinished returns true
void ArmCommand::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmCommand::Interrupted() {}
