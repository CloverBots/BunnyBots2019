/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/TestAuto.h"

TestAuto::TestAuto() {
  
  AddParallel(new ArmCommand(true));
  AddSequential(new CubeIntakeAutoCommand(.4));
  AddSequential(new DriveDistanceCommand(3.1415927 * 1.5, false, false));
  AddSequential(new CubeIntakeAutoCommand(0));
  AddParallel(new ToteAutoCommand(true));
  AddSequential(new DriveDistanceCommand(279 - (3.1415927 * 1.5), true, true));
  AddSequential(new ArmCommand(false));
  AddSequential(new DriveDistanceCommand(-60, false, false));
  
  //AddSequential(new DriveDistanceCommand(0, false, true));
}
