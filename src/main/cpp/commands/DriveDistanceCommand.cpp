/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DriveDistanceCommand.h"
#include "CommandBase.h"
#include <iostream>

DriveDistanceCommand::DriveDistanceCommand(double distance, bool stop, bool use_limelight, double speed_cap, bool usetimeout, int timeout) : distance(distance), stop(stop), use_limelight(use_limelight), speed_cap(speed_cap), usetimeout(usetimeout), timeout(timeout) {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(CommandBase::drivesubsystem.get());
}

// Called just before this Command runs the first time
void DriveDistanceCommand::Initialize()
{
  CommandBase::drivesubsystem->GetLeftPID()->SetOutputRange(-speed_cap , speed_cap);
  CommandBase::drivesubsystem->GetRightPID()->SetOutputRange(-speed_cap , speed_cap);
  CommandBase::drivesubsystem->GetLeftSource()->Reset(0);
  CommandBase::drivesubsystem->GetRightSource()->Reset(0);
  CommandBase::drivesubsystem->GetLimeSource()->SetInput(0);
  CommandBase::drivesubsystem->GetLeftPID()->SetSetpoint(distance);
  CommandBase::drivesubsystem->GetRightPID()->SetSetpoint(-distance);
  CommandBase::drivesubsystem->GetLimePID()->SetSetpoint(-2);
  CommandBase::drivesubsystem->GetLeftPID()->SetEnabled(true);
  CommandBase::drivesubsystem->GetRightPID()->SetEnabled(true);
  CommandBase::drivesubsystem->GetLimePID()->SetEnabled(true);
}

// Called repeatedly when this Command is scheduled to run
void DriveDistanceCommand::Execute()
{
  if(usetimeout)
  {
    if(timeout >= 0)
    {
      timeout--;
      std::cout << "timeout: " << timeout << std::endl;
    }
    else
    {
      std::cout << "stopdrive" << std::endl;
      stopdrive = true;
    }
  }
  if(use_limelight && CommandBase::oi->enable_vision)
  {
    std::cout << "center data: " << CommandBase::oi->GetDataCenter() << std::endl;
    CommandBase::drivesubsystem->GetLimeSource()->SetInput(CommandBase::oi->GetDataCenter());
    CommandBase::drivesubsystem->GetLeftOutput()->FFWrite(-CommandBase::drivesubsystem->GetLimeOutput()->GetOutput());
    CommandBase::drivesubsystem->GetRightOutput()->FFWrite(-CommandBase::drivesubsystem->GetLimeOutput()->GetOutput());
  }
  else
  {
    CommandBase::drivesubsystem->GetLeftOutput()->FFWrite(0);
    CommandBase::drivesubsystem->GetRightOutput()->FFWrite(0);
  }
  //std::cout << CommandBase::drivesubsystem->GetLeftPID()->GetError() << " : " << CommandBase::drivesubsystem->GetRightPID()->GetError() << std::endl;
}

// Make this return true when this Command no longer needs to run execute()
bool DriveDistanceCommand::IsFinished()
{
  if(stopdrive)
  {
    return true;
  }
  if(CommandBase::oi->stop_on_grab && stop)
  {
    return true;
  }
  return (CommandBase::drivesubsystem->GetLeftPID()->OnTarget() && CommandBase::drivesubsystem->GetRightPID()->OnTarget());
}

// Called once after isFinished returns true
void DriveDistanceCommand::End() 
{
  CommandBase::oi->stop_on_grab = false;
  CommandBase::drivesubsystem->GetLeftPID()->SetEnabled(false);
  CommandBase::drivesubsystem->GetRightPID()->SetEnabled(false);
  CommandBase::drivesubsystem->GetLimePID()->SetEnabled(false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveDistanceCommand::Interrupted() {}
