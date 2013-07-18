#include "Watchdog.h"

const double Watchdog::kDefaultWatchdogExpiration = 0.5;

Watchdog::Watchdog()
	//:	m_fpgaWatchDog(NULL)
{
	tRioStatusCode localStatus = NiFpga_Status_Success;
	//m_fpgaWatchDog = tWatchdog::create(&localStatus);
	//SetExpiration(kDefaultWatchdogExpiration);
	//SetEnabled(true);
}

Watchdog::~Watchdog()
{
	//SetEnabled(false);
	//delete m_fpgaWatchDog;
	//m_fpgaWatchDog = NULL;
}

bool Watchdog::Feed()
{
	throw NotSupportedException();
	return true;
	/*
	bool previous = GetEnabled();
	tRioStatusCode localStatus = NiFpga_Status_Success;
	//m_fpgaWatchDog->strobeFeed(&localStatus);
	return previous;*/
}

void Watchdog::Kill()
{
	throw NotSupportedException();

	/*
	tRioStatusCode localStatus = NiFpga_Status_Success;*/
	//m_fpgaWatchDog->strobeKill(&localStatus);
}

double Watchdog::GetTimer()
{
	throw NotSupportedException();

	/*
	tRioStatusCode localStatus = NiFpga_Status_Success;
	UINT32 timer = m_fpgaWatchDog->readTimer(&localStatus);
	return timer / (kSystemClockTicksPerMicrosecond * 1e6);*/
}

double Watchdog::GetExpiration()
{
	throw NotSupportedException();
	return 0.0;
	/*
	tRioStatusCode localStatus = NiFpga_Status_Success;
	UINT32 expiration = m_fpgaWatchDog->readExpiration(&localStatus);
	return expiration / (kSystemClockTicksPerMicrosecond * 1e6);*/
}

void Watchdog::SetExpiration(double expiration)
{
	throw NotSupportedException();
	/*
	tRioStatusCode localStatus = NiFpga_Status_Success;
	m_fpgaWatchDog->writeExpiration((UINT32)(expiration * (kSystemClockTicksPerMicrosecond * 1e6)), &localStatus);*/
}

bool Watchdog::GetEnabled()
{
	throw NotSupportedException();

	return true;
	/*
	tRioStatusCode localStatus = NiFpga_Status_Success;
	bool enabled = !m_fpgaWatchDog->readImmortal(&localStatus);
	return enabled;*/
}

void Watchdog::SetEnabled(bool enabled)
{
	throw NotSupportedException();

	/*
	tRioStatusCode localStatus = NiFpga_Status_Success;
	m_fpgaWatchDog->writeImmortal(!enabled, &localStatus);*/
}

bool Watchdog::IsAlive()
{
	throw NotSupportedException();

	return true;
	/*
	tRioStatusCode localStatus = NiFpga_Status_Success;
	bool alive = m_fpgaWatchDog->readStatus_Alive(&localStatus);
	return alive;*/
}

bool Watchdog::IsSystemActive()
{
	throw NotSupportedException();

	return true;
	/*
	tRioStatusCode localStatus = NiFpga_Status_Success;
	bool alive = m_fpgaWatchDog->readStatus_SystemActive(&localStatus);
	return alive;*/
}

