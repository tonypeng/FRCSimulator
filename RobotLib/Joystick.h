#ifndef JOYSTICK_H_
#define JOYSTICK_H_

#include "Base.h"
#include "GenericHID.h"

class DriverStation;

class Joystick : public GenericHID
{
public:
	static const UINT32 kDefaultXAxis = 1;
	static const UINT32 kDefaultYAxis = 2;
	static const UINT32 kDefaultZAxis = 3;
	static const UINT32 kDefaultTwistAxis = 4;
	static const UINT32 kDefaultThrottleAxis = 3;
	typedef enum
	{
		kXAxis, kYAxis, kZAxis, kTwistAxis, kThrottleAxis, kNumAxisTypes
	} AxisType;
	static const UINT32 kDefaultTriggerButton = 1;
	static const UINT32 kDefaultTopButton = 2;
	typedef enum
	{
		kTriggerButton, kTopButton, kNumButtonTypes
	} ButtonType;

	explicit Joystick(UINT32 port);
	Joystick(UINT32 port, UINT32 numAxisTypes, UINT32 numButtonTypes);
	virtual ~Joystick();

	UINT32 GetAxisChannel(AxisType axis);
	void SetAxisChannel(AxisType axis, UINT32 channel); 

	virtual float GetX(JoystickHand hand = kRightHand);
	virtual float GetY(JoystickHand hand = kRightHand);
	virtual float GetZ();
	virtual float GetTwist();
	virtual float GetThrottle();
	virtual float GetAxis(AxisType axis);
	float GetRawAxis(UINT32 axis);

	virtual bool GetTrigger(JoystickHand hand = kRightHand);
	virtual bool GetTop(JoystickHand hand = kRightHand);
	virtual bool GetBumper(JoystickHand hand = kRightHand);
	virtual bool GetButton(ButtonType button);
	bool GetRawButton(UINT32 button);
	static Joystick* GetStickForPort(UINT32 port);
	
	virtual float GetMagnitude();
	virtual float GetDirectionRadians();
	virtual float GetDirectionDegrees();

private:
	DISALLOW_COPY_AND_ASSIGN(Joystick);
	void InitJoystick(UINT32 numAxisTypes, UINT32 numButtonTypes);

	DriverStation *m_ds;
	UINT32 m_port;
	UINT32 *m_axes;
	UINT32 *m_buttons;
};

#endif