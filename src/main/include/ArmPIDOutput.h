/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include "ctre/Phoenix.h"
#include <WPILib.h>

class ArmPIDOutput : public frc::PIDOutput {
	TalonSRX* m_pTalon0;
  TalonSRX* m_pTalon1;
 public:
  ArmPIDOutput(TalonSRX* pTalon0, TalonSRX* pTalon1);
	virtual ~ArmPIDOutput();
	virtual void PIDWrite(double value);
};
