#ifndef SYNCHRONIZED_H_
#include "Synchronized.h"
#endif

Synchronized::Synchronized(SEM_ID sem)
{
	m_semaphore = sem;

	int semRes = semTake(m_semaphore, WAIT_FOREVER);

	if(semRes != 0)
		printf("wait failed\n");
}

Synchronized::~Synchronized()
{
	semGive(m_semaphore);
}