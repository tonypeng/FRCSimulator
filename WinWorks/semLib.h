/*
 * WinWorks - semLib.h
 * Copyright (c) 2013 Tony "untitled" Peng
 * <http://www.tonypeng.com/>
 * 
 * This file is subject to the terms and conditions defined in the
 * file 'LICENSE.txt', which is part of this source code package.
 */

#ifndef SEMLIB_H_
#define SEMLIB_H_

#include "VxWorks.h"

#include <time.h> // for CLOCKS_PER_SEC
#include <boost/interprocess/sync/interprocess_semaphore.hpp>
#include <boost/interprocess/sync/interprocess_recursive_mutex.hpp>
#include <boost/interprocess/exceptions.hpp>

#define SEM_Q_FIFO		 0x00
#define SEM_Q_PRIORITY		 0x01
#define SEM_DELETE_SAFE		 0x04
#define SEM_INVERSION_SAFE	 0x08
#define SEM_EVENTSEND_ERR_NOTIFY 0x10
#define SEM_INTERRUPTIBLE        0x20

struct WINWORKS_SEMLIB_semaphore {
	boost::interprocess::interprocess_semaphore* intern_semaphore;
	boost::interprocess::interprocess_recursive_mutex* intern_mutex;

	enum {
		MUTEX, CSEMAPHORE, BSEMAPHORE
	} type;
};

typedef WINWORKS_SEMLIB_semaphore* SEM_ID;

enum SEM_B_STATE
{
	SEM_EMPTY = 0,
	SEM_FULL = 1
};

SEM_ID semCCreate(int initialCount);
SEM_ID semMCreate(int options);
SEM_ID semBCreate(int options, SEM_B_STATE initialState);

STATUS semGive(SEM_ID sem);
STATUS semTake(SEM_ID sem, int ticks);

STATUS semFlush(SEM_ID sem);

STATUS semDelete(SEM_ID sem);

#endif