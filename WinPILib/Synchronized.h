/*
 * WinPILib - Synchronized.h
 * Copyright (c) 2013 Tony "untitled" Peng
 * <http://www.tonypeng.com/>
 * 
 * This file is subject to the terms and conditions defined in the
 * file 'LICENSE.txt', which is part of this source code package.
 */

#ifndef SYNCHRONIZED_H_
#define SYNCHRONIZED_H_

#include <semLib.h>

#include "Base.h"

#define CRITICAL_REGION(s) { Synchronized _sync(s);
#define END_REGION }

// Forward declare Synchronized because Synchronized and ReentrantSemaphore are circularly dependent...
class Synchronized;

class ReentrantSemaphore
{
public:
	ReentrantSemaphore()
	{
		m_semaphore = semMCreate(SEM_Q_PRIORITY | SEM_DELETE_SAFE); // July 19, 2013 -- These options are vestigial and currently serve no purpose, as the semLib port does not support them.
	}

	~ReentrantSemaphore()
	{
		semDelete(m_semaphore);
	}

	int take()
	{
		return semTake(m_semaphore, WAIT_FOREVER);
	}

	int give()
	{
		return semGive(m_semaphore);
	}

private:
	SEM_ID m_semaphore;

	friend class Synchronized;

	DISALLOW_COPY_AND_ASSIGN(ReentrantSemaphore);
};

class Synchronized
{
public:
	explicit Synchronized(SEM_ID sem);
	explicit Synchronized(ReentrantSemaphore& reSem);
	virtual ~Synchronized();

private:
	SEM_ID m_semaphore;

	DISALLOW_COPY_AND_ASSIGN(Synchronized);
};

#endif