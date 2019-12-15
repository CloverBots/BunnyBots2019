/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/ToteSubsystem.h"
#include "commands/ToteCommand.h"
#include <iostream>

ToteSubsystem::ToteSubsystem() : Subsystem("ExampleSubsystem") {}

void ToteSubsystem::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
  SetDefaultCommand(new ToteCommand());

  m_Arm_Motor0 = new TalonSRX(RobotMap::kArmMotor0);
	m_Arm_Motor0->ConfigSelectedFeedbackSensor(phoenix::motorcontrol::FeedbackDevice::QuadEncoder, 0, 0);
  m_Arm_Motor0->GetSensorCollection().SetQuadraturePosition(0, 10);
  m_Arm_Motor1 = new TalonSRX(RobotMap::kArmMotor1);
  m_Tote_Motor = new TalonSRX(RobotMap::kToteMotor);
  m_Tote_Grabber = new frc::DoubleSolenoid(0, 1);
  m_Left = new frc::DigitalInput(0);
  m_Right = new frc::DigitalInput(1);
  m_Arm_Source = new ArmPIDSource(m_Arm_Motor0);
  m_Arm_Output = new ArmPIDOutput(m_Arm_Motor0, m_Arm_Motor1);
  m_Arm_PID = new frc::PIDController(P, I, D, m_Arm_Source, m_Arm_Output);
  m_Top = new frc::DigitalInput(2);
  m_Bottom = new frc::DigitalInput(3);
}

void ToteSubsystem::SetArmSpeed(double speed)
{
  //std::cout << "pos: " << (double)m_Arm_Motor0->GetSelectedSensorPosition() / 4096.0 << std::endl;
  m_Arm_Motor0->Set(ControlMode::PercentOutput, speed);
  m_Arm_Motor1->Set(ControlMode::PercentOutput, -speed);
}

void ToteSubsystem::SetToteSpeed(double speed)
{
  m_Tote_Motor->Set(ControlMode::PercentOutput, speed);
}

void ToteSubsystem::SetToteGrabber(frc::DoubleSolenoid::Value value)
{
  m_Tote_Grabber->Set(value);
}

bool ToteSubsystem::GetLR()
{
  return !m_Left->Get() || !m_Right->Get(); 
}

frc::PIDController* ToteSubsystem::GetArmPID()
{
  return m_Arm_PID;
}

bool ToteSubsystem::GetTop()
{
  return !m_Top->Get();
}

bool ToteSubsystem::GetBottom()
{
  return !m_Bottom->Get();
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
