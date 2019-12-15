/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "ArmPIDOutput.h"
#include <iostream>

ArmPIDOutput::ArmPIDOutput(TalonSRX* pTalon0, TalonSRX* pTalon1)
			: m_pTalon0(pTalon0), m_pTalon1(pTalon1)
{

}

ArmPIDOutput::~ArmPIDOutput() {

}

void ArmPIDOutput::PIDWrite(double value)
{
    //std::cout << value << std::endl;
	
	double output = value;
	if(value > 0)
	{
		output = output * 1.15;
	}
	m_pTalon0->Set(ControlMode::PercentOutput, output);
	m_pTalon1->Set(ControlMode::PercentOutput, -output);
}

