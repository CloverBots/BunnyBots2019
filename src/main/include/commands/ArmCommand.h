/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Command.h>

class ArmCommand : public frc::Command {
  bool lowered;
  int toggle = 0;
  bool go45 = false;
  bool finished = false;
  int janktimer = 0;
  bool grab;
  bool run_grab;
  bool spec_finished = false;
 public:
  ArmCommand(bool lowered, bool go45, bool run_grab, bool grab);
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
