/*
 * WinWorks - semLib.cpp
 * Copyright (c) 2013 Tony "untitled" Peng
 * <http://www.tonypeng.com/>
 * 
 * This file is subject to the terms and conditions defined in the
 * file 'LICENSE.txt', which is part of this source code package.
 */

#include "semLib.h"

#include <boost/date_time/posix_time/posix_time_types.hpp>

#include "sysLib.h"

SEM_ID semCCreate(int initialCount)
{
	SEM_ID sem = new semaphore();

	sem->type = semaphore::CSEMAPHORE;
	sem->intern_mutex = NULL;
	sem->intern_semaphore = new boost::interprocess::interprocess_semaphore(initialCount);

	return sem;
}

SEM_ID semMCreate(int options)
{
	SEM_ID sem = new semaphore();

	sem->type = semaphore::MUTEX;
	sem->intern_mutex = new boost::interprocess::interprocess_recursive_mutex();
	sem->intern_semaphore = NULL;

	return sem;
}

SEM_ID semBCreate(int options, SEM_B_STATE initialState)
{
	SEM_ID sem = new semaphore();

	sem->type = semaphore::BSEMAPHORE;
	sem->intern_mutex = NULL;
	sem->intern_semaphore = new boost::interprocess::interprocess_semaphore(initialState);

	return sem;
}

STATUS semGive(SEM_ID sem)
{
	try
	{
		switch(sem->type)
		{
		case semaphore::CSEMAPHORE:
			sem->intern_semaphore->post();
			break;
		case semaphore::BSEMAPHORE:
			sem->intern_semaphore->post();
			break;
		case semaphore::MUTEX:
			sem->intern_mutex->unlock();
			break;
		}
	}
	catch(boost::interprocess::interprocess_exception e)
	{
		return ERROR;
	}

	return OK;
}

STATUS semTake(SEM_ID sem, int ticks)
{
	try
	{
		if(ticks == WAIT_FOREVER)
		{
			switch(sem->type)
			{
			case semaphore::CSEMAPHORE:
				sem->intern_semaphore->wait();
					break;
			case semaphore::BSEMAPHORE:
				sem->intern_semaphore->wait();
				break;
			case semaphore::MUTEX:
				sem->intern_mutex->lock();
				break;
			}
		}
		else
		{
			boost::posix_time::ptime waitTime = boost::posix_time::microsec_clock::universal_time() + 
				boost::posix_time::seconds(ticks / sysClkRateGet());

			switch(sem->type)
			{
			case semaphore::CSEMAPHORE:
				sem->intern_semaphore->timed_wait(waitTime);
				break;
			case semaphore::BSEMAPHORE:
				sem->intern_semaphore->timed_wait(waitTime);
				break;
			case semaphore::MUTEX:
				sem->intern_mutex->timed_lock(waitTime);
				break;
			}
		}
	}
	catch (boost::interprocess::interprocess_exception e)
	{
		return ERROR;
	}

	return OK;
}

STATUS semFlush(SEM_ID sem)
{
	WINWORKS_NOT_IMPLEMENTED;

	return ERROR;
}

STATUS semDelete(SEM_ID sem)
{
	delete sem->intern_mutex;
	delete sem->intern_semaphore;

	delete sem;

	return OK;
}