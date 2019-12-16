/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "rev/CANSparkMax.h"
#include <frc/WPILib.h>

class DrivePIDOutput : public frc::PIDOutput {
	rev::CANSparkMax* m_pSpark0;
	rev::CANSparkMax* m_pSpark1;
  double ff = 0;
 public:
  DrivePIDOutput(rev::CANSparkMax* pSpark0, rev::CANSparkMax* pSpark1);
	virtual ~DrivePIDOutput();
	void FFWrite(double ff);
	virtual void PIDWrite(double value);
};
