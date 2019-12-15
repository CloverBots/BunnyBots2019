#include "CommandBase.h"

#include <frc/Commands/Scheduler.h>
#include <iostream>

// Initialize a single static instance of all of your subsystems. The following
// line should be repeated for each subsystem in the project.

std::unique_ptr<OI> CommandBase::oi;
std::unique_ptr<DriveSubsystem> CommandBase::drivesubsystem;
std::unique_ptr<CubeSubsystem> CommandBase::cubesubsystem;
std::unique_ptr<ToteSubsystem> CommandBase::totesubsystem;

CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {
}

void CommandBase::Init()
{
	oi.reset(new OI);
	drivesubsystem.reset(new DriveSubsystem);
	cubesubsystem.reset(new CubeSubsystem);
	totesubsystem.reset(new ToteSubsystem);
}

