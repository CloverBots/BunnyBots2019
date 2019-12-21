/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/NoBunnyAuto.h"

NoBunnyAuto::NoBunnyAuto()
{
  AddParallel(new ArmCommand(true, false, true, true));
  AddSequential(new DriveDistanceCommand(267, true, true, .55, false, 0));
  AddSequential(new DriveDistanceCommand(-60, false, false, .3, true, 3));
  AddSequential(new ArmCommand(false, false, true, true));
}
