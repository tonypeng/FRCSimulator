/*
 * WinWorks - taskLib.h
 * Copyright (c) 2013 Tony "untitled" Peng
 * <http://www.tonypeng.com/>
 * 
 * This file is subject to the terms and conditions defined in the
 * file 'LICENSE.txt', which is part of this source code package.
 */

#ifndef TASKLIB_H_
#define TASKLIB_H_

#include "VxWorks.h"

#include "boost/thread.hpp"

struct taskInfo
{
	int id;
	std::string name;
	bool started;
	boost::thread* thread;
};

struct threadParamStruct {
	FUNCPTR func;
	UINT32 arg0;
	UINT32 arg1;
	UINT32 arg2;
	UINT32 arg3;
	UINT32 arg4; 
	UINT32 arg5;
	UINT32 arg6;
	UINT32 arg7;
	UINT32 arg8;
	UINT32 arg9;
};

STATUS taskDelay(int ticks);
STATUS taskSuspend(int tid);

int taskNameToId(char* name);

int taskSpawn(char* name, int priority, int options,
	int stackSize, FUNCPTR entryPt,
	int arg0,
	int arg1,
	int arg2,
	int arg3,
	int arg4,
	int arg5,
	int arg6,
	int arg7,
	int arg8,
	int arg9);

STATUS taskDelete(int tid);
STATUS taskResume(int tid);
STATUS taskRestart(int tid);
STATUS taskPrioritySet(int tid, int newPriority);
STATUS taskPriorityGet(int tid, int* pPriority);
BOOL taskIsReady(int tid);
BOOL taskIsSuspended(int tid);
STATUS taskIdVerify(int tid);

#endif