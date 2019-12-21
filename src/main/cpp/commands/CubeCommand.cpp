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
  CommandBase::cubesubsystem->SetLatch(frc::DoubleSolenoid::Value::kForward);
  CommandBase::cubesubsystem->SetBed(frc::DoubleSolenoid::Value::kReverse);
}

// Called repeatedly when this Command is scheduled to run
void CubeCommand::Execute()
{
  if(janktimer <= 150)
  {
    CommandBase::cubesubsystem->SetLatch(frc::DoubleSolenoid::Value::kReverse);
    CommandBase::cubesubsystem->SetCubeSpeed(-.50);
    janktimer++;
  }
  else
  {
    if(CommandBase::oi->GetButton(1, Buttons::Back))
    {
      CommandBase::cubesubsystem->SetLatch(frc::DoubleSolenoid::Value::kReverse);
    }
    else
    {
      CommandBase::cubesubsystem->SetLatch(frc::DoubleSolenoid::Value::kForward);
    }
    
    if(CommandBase::oi->GetButton(1, Buttons::B))
    {
      enable_toggle = true;
      if(!intake_toggle)
      {
        intake_position = !intake_position;
      }
      intake_toggle = true;
    }
    else
    {
      intake_toggle = false;
    }

    if(CommandBase::oi->GetButton(1, Buttons::X) || CommandBase::oi->GetButton(1, Buttons::Y))
    {
      intake_position = false;
    }

    if(intake_position)
    {
      CommandBase::cubesubsystem->SetCubeSpeed(.3);
    }
    else
    {
      if(CommandBase::oi->GetButton(1, Buttons::X))
      {
        CommandBase::cubesubsystem->SetCubeSpeed(.45);
      }
      else if(CommandBase::oi->GetButton(1, Buttons::Y))
      {
        CommandBase::cubesubsystem->SetCubeSpeed(-.50);
      }
      else
      {
        CommandBase::cubesubsystem->SetCubeSpeed(0);
      }
    }
  }
  
  if(CommandBase::oi->GetButton(1, Buttons::Start))
  {
    CommandBase::cubesubsystem->SetBed(frc::DoubleSolenoid::Value::kForward);
  }
  else
  {
    CommandBase::cubesubsystem->SetBed(frc::DoubleSolenoid::Value::kReverse);
  }
  
}

// Make this return true when this Command no longer needs to run execute()
bool CubeCommand::IsFinished() { return false; }

// Called once after isFinished returns true
void CubeCommand::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CubeCommand::Interrupted() {}
