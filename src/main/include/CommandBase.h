#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <memory>
#include <string>
#include <WPILib.h>
#include <frc/Commands/Command.h>
#include "OI.h"
#include "subsystems/DriveSubsystem.h"
#include "subsystems/CubeSubsystem.h"
#include "subsystems/ToteSubsystem.h"


/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use
 * CommandBase::exampleSubsystem
 */
class CommandBase: public frc::Command {
public:
	CommandBase(const std::string& name);
	CommandBase() = default;
	static void Init();
	// Create a single static instance of all of your subsystems
	static std::unique_ptr<OI> oi;
	static std::unique_ptr<DriveSubsystem> drivesubsystem;
	static std::unique_ptr<CubeSubsystem> cubesubsystem;
	static std::unique_ptr<ToteSubsystem> totesubsystem;
};
#endif  // COMMAND_BASE_H
