#include "semLib.h"

SEM_ID semMCreate(int options)
{
	SEM_ID sem = new rsSyncObj();

	sem->m_syncType = rsSyncObj::MUTEX;
	sem->m_handle = CreateMutex(NULL, FALSE, NULL);

	return sem;
}

SEM_ID semBCreate(int options, SEM_B_STATE initialState)
{
	SEM_ID sem = new rsSyncObj();

	sem->m_syncType = rsSyncObj::BSEMAPHORE;
	sem->m_handle = CreateSemaphore(NULL, initialState, 1, NULL); // restrict to [0],[1] (binary)

	return sem;
}

void semGive(SEM_ID sem)
{
	if(sem->m_syncType == rsSyncObj::MUTEX)
	{
		ReleaseMutex(sem->m_handle);
	}
	else if(sem->m_syncType == rsSyncObj::BSEMAPHORE)
	{
		ReleaseSemaphore(sem->m_handle, 1, NULL);
	}
}

int semTake(SEM_ID sem, int ticks)
{
	if(sem->m_handle == NULL) return -1;

	int res;

	if(ticks == WAIT_FOREVER)
	{
		res = WaitForSingleObject(sem->m_handle, INFINITE);

		return (res == WAIT_ABANDONED || res == WAIT_TIMEOUT || res == WAIT_FAILED) ? res : 0;
	}
	else
	{
		int millis = (int)(double(ticks) / (double(CLOCKS_PER_SEC) / double(1000)));

		res = WaitForSingleObject(sem->m_handle, millis);

		return (res == WAIT_ABANDONED || res == WAIT_TIMEOUT || res == WAIT_FAILED) ? res : 0;
	}

	return -1;
}

void semFlush(SEM_ID sem)
{
//#error Implement this!
#pragma message ( "Implementation needed!" )

}

void semDelete(SEM_ID sem)
{
	CloseHandle(sem->m_handle);

	delete sem;
}