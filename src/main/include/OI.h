#pragma once

#include <frc/WPILib.h>

enum Axis
{
	LeftUpDown,
	RightUpDown,
	LeftLeftRight,
	RightLeftRight,
	LeftTrigger,
	RightTrigger
};

enum Buttons
{
	A,
	B,
	X,
	Y,
	Back,
	Start,
	LBumper,
	RBumper,
	LJoyDown,
	RJoyDown
};

class OI
{
public:

	frc::Joystick* pDriveStick;
	frc::Joystick* pOperatorStick;
	frc::JoystickButton* DriverAButton;
	frc::JoystickButton* DriverBButton;
	frc::JoystickButton* DriverXButton;
	frc::JoystickButton* DriverYButton;
	frc::JoystickButton* DriverBackButton;
	frc::JoystickButton* DriverStartButton;
	frc::JoystickButton* DriverLBumperButton;
	frc::JoystickButton* DriverRBumperButton;
	frc::JoystickButton* DriverLJoyDownButton;
	frc::JoystickButton* DriverRJoyDownButton;

	frc::JoystickButton* OperatorAButton;
	frc::JoystickButton* OperatorBButton;
	frc::JoystickButton* OperatorXButton;
	frc::JoystickButton* OperatorYButton;
	frc::JoystickButton* OperatorBackButton;
	frc::JoystickButton* OperatorStartButton;
	frc::JoystickButton* OperatorLBumperButton;
	frc::JoystickButton* OperatorRBumperButton;
	frc::JoystickButton* OperatorLJoyDownButton;
	frc::JoystickButton* OperatorRJoyDownButton;

	frc::Joystick* GetDriveStick();
	double GetAxis(int controller, Axis axis);
	bool GetButton(int controller, Buttons button);
	int GetDPad(int controller);
  
  	int GetDataCenter();
	OI();
};
