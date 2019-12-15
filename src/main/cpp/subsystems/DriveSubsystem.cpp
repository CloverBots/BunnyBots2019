/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/DriveSubsystem.h"
#include "commands/DriveCommand.h"
#include <iostream>

DriveSubsystem::DriveSubsystem() : Subsystem("DriveSubsystem") {}

void DriveSubsystem::InitDefaultCommand()
{
  // Set the default command for a subsystem here.
  SetDefaultCommand(new DriveCommand());
}

void DriveSubsystem::Drive(double speed, double turn)
{
  /*
  if(speed < .03 && speed > -.03)
  {
    speed = 0;
  }

  if(turn < .03 && speed > -.03)
  {
    turn = 0;
  }
  */
  turn = turn / 1.5;
  double left_speed = sin(3.1415927 / 4 * (-speed + turn));
  double right_speed = sin(3.1415927 / 4 * (speed + turn));
  m_leftLeadMotor.Set(left_speed);
  m_rightLeadMotor.Set(right_speed);
  m_leftFollowMotor.Set(left_speed);
  m_rightFollowMotor.Set(right_speed);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
