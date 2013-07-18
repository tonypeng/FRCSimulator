#include "Timer.h"

#include <Windows.h>
#include <time.h>

// because M$ was too busy not following standards to implement this
/* http://stackoverflow.com/questions/5404277/porting-clock-gettime-to-windows */

LARGE_INTEGER getFILETIMEoffset()
{
	SYSTEMTIME		s;
	FILETIME		f;
	LARGE_INTEGER	t;

	s.wYear = 1970;
	s.wMonth = 1;
	s.wDay = 1;
	s.wHour = 0;
	s.wMinute = 0;
	s.wSecond = 0;
	s.wMilliseconds = 0;

	SystemTimeToFileTime(&s, &f);

	t.QuadPart = f.dwHighDateTime;
	t.QuadPart <<= 32;
	t.QuadPart |= f.dwLowDateTime;

	return t;
}

/*
 * A word of warning:
 *
 * There are reports of un-reliableness of QueryPerformanceCounter
 * (A quick google search will show you...)
 * But there's not really anything else that can be done...
 */
int clock_gettime(int  X, timespec *tv)
{
	LARGE_INTEGER			t;
	FILETIME				f;
	double					microseconds;
	static LARGE_INTEGER	offset;
	static double			frequencyToMicroseconds;
	static int				initialized = 0;
	static BOOL				usePerformanceCounter = 0;

	if(!initialized)
	{
		LARGE_INTEGER performanceFrequency;
		initialized = 1;

		usePerformanceCounter = QueryPerformanceFrequency(&performanceFrequency);

		if(usePerformanceCounter)
		{
			QueryPerformanceCounter(&offset);
			frequencyToMicroseconds = (double)performanceFrequency.QuadPart / 1000000.0;
		}
		else
		{
			offset = getFILETIMEoffset();
			frequencyToMicroseconds = 10.0;
		}
	}

	if(usePerformanceCounter) QueryPerformanceCounter(&t);
	else
	{
		GetSystemTimeAsFileTime(&f);
		t.QuadPart = f.dwHighDateTime;
		t.QuadPart <<= 32;
		t.QuadPart |= f.dwLowDateTime;
	}

	t.QuadPart -= offset.QuadPart;
	microseconds = (double)t.QuadPart / frequencyToMicroseconds;
	t.QuadPart = microseconds;

	tv->tv_sec = t.QuadPart / 1000000;
	tv->tv_nsec = (t.QuadPart % 1000000) * 1000;

	return 0;
}

void Wait(double seconds)
{
	if(seconds < 0.0) return;

	Sleep((long)(seconds * 1000.0));
}

double GetClock()
{
	return Timer::GetFPGATimestamp();
}

double GetTime()
{
	timespec ts;
	
	clock_gettime(0, &ts);

	double realTime = (double)ts.tv_sec + (double)((double)ts.tv_nsec*1e-9);

	return realTime;
}

Timer::Timer()
	: m_startTime(0.0)
	, m_passedTime(0.0)
	, m_isRunning(false)
	, m_syncObj(0)
{
	m_syncObj = semMCreate(SEM_Q_PRIORITY | SEM_DELETE_SAFE | SEM_INVERSION_SAFE);
}

Timer::~Timer()
{
	semDelete(m_syncObj);
}

double Timer::Get()
{
	double result;
	double currentTime = GetFPGATimestamp();

	Synchronized s(m_syncObj);

	if(m_isRunning)	result = m_passedTime + currentTime - m_startTime;
	else	result = m_passedTime;

	return result;
}

void Timer::Reset()
{
	Synchronized s(m_syncObj);

	m_passedTime = 0;
	m_startTime = GetFPGATimestamp();
}

void Timer::Start()
{
	Synchronized s(m_syncObj);

	if(!m_isRunning)
	{
		m_startTime = GetFPGATimestamp();
		m_isRunning = false;
	}
}

void Timer::Stop()
{
	double temp = Get();

	Synchronized s(m_syncObj);

	if(m_isRunning)
	{
		m_passedTime += temp;
		m_isRunning = false;
	}
}

bool Timer::HasPeriodPassed(double period)
{
	if(Get() > period)
	{
		Synchronized s(m_syncObj);

		m_startTime += period;

		return true;
	}

	return false;
}

/* TO-DO: Possiblity for these two functions: Time since program started? */
double Timer::GetFPGATimestamp()
{
	return ((double)GetTickCount() / 1000.0);
}

double Timer::GetPPCTimestamp()
{
	return ((double)GetTickCount() / 1000.0); // not very accurate, timing is ±16 ms according to Win32 docs
}