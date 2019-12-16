/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "rev/CANSparkMax.h"
#include "frc/WPILib.h"

class DrivePIDSource : public frc::PIDSource
{
 private:
  rev::CANSparkMax* m_pSpark;
 public:
  DrivePIDSource(rev::CANSparkMax* pSpark);
  void Reset(double val);
	virtual ~DrivePIDSource();
	virtual double PIDGet();
};
