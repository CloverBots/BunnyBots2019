/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "DrivePIDOutput.h"

DrivePIDOutput::DrivePIDOutput(rev::CANSparkMax* pSpark0, rev::CANSparkMax* pSpark1)
			: m_pSpark0(pSpark0), m_pSpark1(pSpark1)
{

}

DrivePIDOutput::~DrivePIDOutput() {

}

void DrivePIDOutput::FFWrite(double ff)
{
    this->ff = ff;
}

void DrivePIDOutput::PIDWrite(double value)
{
    value += ff;
	m_pSpark0->Set(value);
	m_pSpark1->Set(value);
}
