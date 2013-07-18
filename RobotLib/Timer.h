#ifndef TIMER_H_
#define TIMER_H_

#ifndef BASE_H_
#include "Base.h"
#endif
#ifndef SEMLIB_H_
#include "semLib.h"
#endif

#include <Windows.h>

#include "Synchronized.h"

typedef void (*TimerInterruptHandler)(void *param);

typedef struct {
	time_t tv_sec;
	long tv_nsec;
} timespec;

UINT32 GetFPGATime();

void Wait(double seconds);
double GetClock();
double GetTime();

class Timer
{
public:
	Timer();
	virtual ~Timer();
	double Get();

	void Reset();
	void Start();
	void Stop();

	bool HasPeriodPassed(double period);

	static double GetFPGATimestamp();
	static double GetPPCTimestamp(); // this function is actually a lie, unless you're running on PPC.
private:
	double m_startTime;
	double m_passedTime;

	bool m_isRunning;

	SEM_ID m_syncObj;

	DISALLOW_COPY_AND_ASSIGN(Timer);
};

#endif