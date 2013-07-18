#ifndef GENERIC_HID_H
#define GENERIC_HID_H

#include "TYPEDEF.h"

class GenericHID
{
public:
	typedef enum {
		kLeftHand = 0,
		kRightHand = 1
	} JoystickHand;

	virtual ~GenericHID() {}

	virtual float GetX(JoystickHand hand = kRightHand) = 0;
	virtual float GetY(JoystickHand hand = kRightHand) = 0;
	virtual float GetZ() = 0;
	virtual float GetTwist() = 0;
	virtual float GetThrottle() = 0;
	virtual float GetRawAxis(UINT32 axis) = 0;

	virtual bool GetTrigger(JoystickHand hand = kRightHand) = 0;
	virtual bool GetTop(JoystickHand hand = kRightHand) = 0;
	virtual bool GetBumper(JoystickHand hand = kRightHand) = 0;
	virtual bool GetRawButton(UINT32 button) = 0;
};

#endif