/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ArmCommand.h"
#include "CommandBase.h"
#include <iostream>

ArmCommand::ArmCommand(bool lowered, bool go45, bool run_grab, bool grab) : lowered(lowered), go45(go45), run_grab(run_grab), grab(grab) {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(CommandBase::totesubsystem.get());
}

// Called just before this Command runs the first time
void ArmCommand::Initialize()
{
  CommandBase::totesubsystem->GetArmPID()->SetEnabled(true);
  CommandBase::totesubsystem->GetArmPID()->SetSetpoint(0);
  CommandBase::totesubsystem->SetToteGrabber(frc::DoubleSolenoid::Value::kReverse);
}

// Called repeatedly when this Command is scheduled to run
void ArmCommand::Execute()
{
  if(run_grab)
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
        frc::Wait(.75);
      }
      else
      {
        CommandBase::totesubsystem->SetToteSpeed(.5);
      }
    }
  }

  if(CommandBase::totesubsystem->GetBottom())
  {
    CommandBase::oi->enable_vision = true;
  }

  if(!finished)
  {
    if(!go45)
    {
      if(lowered)
      {
        CommandBase::totesubsystem->GetArmPID()->SetSetpoint(-1.41);
      }
      else
      {
        CommandBase::totesubsystem->GetArmPID()->SetSetpoint(0);
      }
    }
    else
    {
      CommandBase::totesubsystem->GetArmPID()->SetSetpoint(-.7);
      if (janktimer <= 55)
      {
        finished = true;
        spec_finished = true;
        janktimer++;
      }
    }
    if(CommandBase::totesubsystem->GetTop() && CommandBase::totesubsystem->GetBottom())
    {
      CommandBase::totesubsystem->GetArmPID()->SetOutputRange(0, 0);
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
      CommandBase::oi->enable_vision = true;
      CommandBase::totesubsystem->GetArmPID()->SetOutputRange(0, .3);
    }
    else
    {
      toggle = 0;
      CommandBase::totesubsystem->GetArmPID()->SetOutputRange(-1, .3);
    }
  }
  if(CommandBase::totesubsystem->GetTop())
  {
    std::cout << "top" << std::endl;
  }
  if(CommandBase::totesubsystem->GetBottom())
  {
    std::cout << "bottom" << std::endl;
  }
}

// Make this return true when this Command no longer needs to run execute()
bool ArmCommand::IsFinished() { return spec_finished; }

// Called once after isFinished returns true
void ArmCommand::End()
{
  finished = false;
  spec_finished = false;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmCommand::Interrupted() {}
