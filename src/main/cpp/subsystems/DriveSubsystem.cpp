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
  m_leftLeadMotor.GetEncoder().SetPosition(0);
  m_rightLeadMotor.GetEncoder().SetPosition(0);
  m_Left_Output = new DrivePIDOutput(&m_leftLeadMotor, &m_leftFollowMotor);
  m_Right_Output = new DrivePIDOutput(&m_rightLeadMotor, &m_rightFollowMotor);
  m_Left_Source = new DrivePIDSource(&m_leftLeadMotor);
  m_Right_Source = new DrivePIDSource(&m_rightLeadMotor);
  m_Lime_Output = new LimePIDOutput();
  m_Lime_Source = new LimePIDSource();
  m_Left_PID = new frc::PIDController(P, I, D, m_Left_Source, m_Left_Output);
  m_Right_PID = new frc::PIDController(P, I, D, m_Right_Source, m_Right_Output);
  m_Lime_PID = new frc::PIDController(lP, lI, lD, m_Lime_Source, m_Lime_Output);
  m_Left_PID->SetAbsoluteTolerance(.25);
  m_Right_PID->SetAbsoluteTolerance(.25);
}

void DriveSubsystem::Drive(double speed, double turn, bool speed_override)
{
  std::cout << -m_leftLeadMotor.GetEncoder().GetPosition() << " : " << m_rightLeadMotor.GetEncoder().GetPosition() << std::endl;
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
  turn = turn / 2;
  double left_speed;
  double right_speed;
  if(!speed_override)
  {
    left_speed = sin(3.1415927 / 4 * (-speed + turn));
    right_speed = sin(3.1415927 / 4 * (speed + turn));
  }
  else
  {
    left_speed = -speed + sin(3.1415927 / 4 * (turn));
    right_speed = speed + sin(3.1415927 / 4 * (turn));    
  }
  
  m_leftLeadMotor.Set(left_speed);
  m_rightLeadMotor.Set(right_speed);
  m_leftFollowMotor.Set(left_speed);
  m_rightFollowMotor.Set(right_speed);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
