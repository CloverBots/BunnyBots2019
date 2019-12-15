/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "ArmPIDSource.h"
#include <iostream>

ArmPIDSource::ArmPIDSource(TalonSRX* pTalon) : m_pTalon(pTalon) 
{

}

ArmPIDSource::~ArmPIDSource()
{
}

double ArmPIDSource::PIDGet()
{
	//std::cout << m_pTalon->GetSelectedSensorPosition(0) / 4096.0 << std::endl;
	return m_pTalon->GetSelectedSensorPosition(0) / 4096.0;
}

void ArmPIDSource::Reset(double val)
{
	m_pTalon->GetSensorCollection().SetQuadraturePosition(val * 4096, 10);
}
