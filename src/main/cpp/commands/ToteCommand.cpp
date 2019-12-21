/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ToteCommand.h"
#include "CommandBase.h"
#include <iostream>

ToteCommand::ToteCommand() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(CommandBase::totesubsystem.get());
}

// Called just before this Command runs the first time
void ToteCommand::Initialize()
{
  CommandBase::totesubsystem->SetToteGrabber(frc::DoubleSolenoid::Value::kForward);
  CommandBase::totesubsystem->GetArmPID()->SetEnabled(true);
  //CommandBase::totesubsystem->GetArmPID()->SetSetpoint(0);
}

// Called repeatedly when this Command is scheduled to run
void ToteCommand::Execute() 
{
  if(CommandBase::oi->GetAxis(1, Axis::LeftTrigger) > .02)
  {
    CommandBase::totesubsystem->SetToteSpeed(-CommandBase::oi->GetAxis(1, Axis::LeftTrigger));
    CommandBase::totesubsystem->SetToteGrabber(frc::DoubleSolenoid::Value::kReverse);
  }
  else if(CommandBase::oi->GetAxis(1, Axis::RightTrigger) > .02)
  {
    if(CommandBase::totesubsystem->GetLR())
    {
      CommandBase::totesubsystem->SetToteSpeed(0);
      CommandBase::totesubsystem->SetToteGrabber(frc::DoubleSolenoid::Value::kForward);
    }
    else
    {
      CommandBase::totesubsystem->SetToteSpeed(CommandBase::oi->GetAxis(1, Axis::RightTrigger));
    }
  }
  else
  {
    CommandBase::totesubsystem->SetToteSpeed(0);    
  }
  
  CommandBase::totesubsystem->SetToteSpeed(CommandBase::oi->GetAxis(1, Axis::RightTrigger) - CommandBase::oi->GetAxis(1, Axis::LeftTrigger));
  
  if (CommandBase::oi->GetButton(1, Buttons::A))
	{
    if(armtoggle)
    {
      CommandBase::totesubsystem->GetArmPID()->SetSetpoint(0);
    }
    else
    {
      CommandBase::totesubsystem->GetArmPID()->SetSetpoint(-1.41);
    }
		if (!armlatch)
		{
      armtoggle = !armtoggle;
    }
    
		armlatch = true;
	}
	else
	{
		armlatch = false;
	}

/*
    if(CommandBase::oi->GetButton(1, Buttons::A))
    {
      CommandBase::totesubsystem->GetArmPID()->SetSetpoint(0);
    }
    if(CommandBase::oi->GetButton(1, Buttons::B))
    {
      CommandBase::totesubsystem->GetArmPID()->SetSetpoint(-1.41);
    }
*/   
    if(!CommandBase::oi->GetButton(1, Buttons::Start))
    {
      CommandBase::totesubsystem->GetArmPID()->SetEnabled(true);
      if(CommandBase::totesubsystem->GetTop() && CommandBase::totesubsystem->GetBottom())
      {
        CommandBase::totesubsystem->GetArmPID()->SetOutputRange(0, 0);
      }
      else if(CommandBase::totesubsystem->GetTop())
      {
        if (toggle <= 25)
        {
          CommandBase::totesubsystem->GetArmSource()->Reset(0);
          toggle++;
          std::cout << "reset: " << toggle << std::endl;
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
    else
    {
      CommandBase::totesubsystem->GetArmPID()->SetEnabled(false);
      CommandBase::totesubsystem->SetArmSpeed(-CommandBase::oi->GetAxis(1, Axis::LeftUpDown) / 5);
      if(CommandBase::totesubsystem->GetTop())
      {
        CommandBase::totesubsystem->GetArmSource()->Reset(0);
        CommandBase::totesubsystem->GetArmPID()->SetOutputRange(-1, 0);
        armtoggle = false;
        CommandBase::totesubsystem->GetArmPID()->SetSetpoint(0);
      }
      else if(CommandBase::totesubsystem->GetBottom())
      {
        CommandBase::totesubsystem->GetArmPID()->SetOutputRange(0, .3);
      }
      else
      {
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
    std::cout << CommandBase::totesubsystem->GetArmSource()->PIDGet() << std::endl;

  //CommandBase::totesubsystem->SetArmSpeed(CommandBase::oi->GetAxis(1, Axis::RightUpDown));
}

// Make this return true when this Command no longer needs to run execute()
bool ToteCommand::IsFinished() { return false; }

// Called once after isFinished returns true
void ToteCommand::End()
{
  CommandBase::totesubsystem->GetArmPID()->Reset();
  CommandBase::totesubsystem->GetArmPID()->SetEnabled(false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToteCommand::Interrupted() {}
