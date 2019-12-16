/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "DrivePIDSource.h"

DrivePIDSource::DrivePIDSource(rev::CANSparkMax* pSpark) : m_pSpark(pSpark) 
{

}

DrivePIDSource::~DrivePIDSource()
{
}

double DrivePIDSource::PIDGet()
{
	return m_pSpark->GetEncoder().GetPosition() / 10.42 * (3.1425927 * 6);
}

void DrivePIDSource::Reset(double val)
{
	m_pSpark->GetEncoder().SetPosition(val);
}
