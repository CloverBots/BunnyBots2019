/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "frc/WPILib.h"
#include <ctre/Phoenix.h>

class ArmPIDSource : public frc::PIDSource
{
 private:
  TalonSRX* m_pTalon;
 public:
  ArmPIDSource(TalonSRX* pTalon);
  void Reset(double val);
	virtual ~ArmPIDSource();
	virtual double PIDGet();
};
