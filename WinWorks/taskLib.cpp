/*
 * WinWorks - taskLib.cpp
 * Copyright (c) 2013 Tony "untitled" Peng
 * <http://www.tonypeng.com/>
 * 
 * This file is subject to the terms and conditions defined in the
 * file 'LICENSE.txt', which is part of this source code package.
 */

#include "taskLib.h"

#include <vector>

#include "sysLib.h"

std::vector<taskInfo> WINWORKS_TASKLIB_taskInfo;
int WINWORKS_TASKLIB_nextId = 0;

STATUS taskDelay(int ticks)
{
	boost::this_thread::sleep_for(boost::chrono::seconds(ticks / sysClkRateGet()));

	return OK;
}

STATUS taskSuspend(int tid)
{
	WINWORKS_NOT_IMPLEMENTED;

	return ERROR;
}

int taskNameToId(char* name)
{
	for(int i = 0; i < WINWORKS_TASKLIB_taskInfo.size(); ++i)
	{
		if(strcmp(name, WINWORKS_TASKLIB_taskInfo[i].name.c_str()) == 0)
		{
			return WINWORKS_TASKLIB_taskInfo[i].id;
		}
	}

	return ERROR;
}

void threadEntryWrapper(threadParamStruct t)
{
	t.func(t.arg0, t.arg1, t.arg2, t.arg3, t.arg4, t.arg5, t.arg6, t.arg7, t.arg8, t.arg9);
}

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
	int arg9)
{
	threadParamStruct t;

	t.func = entryPt;
	t.arg0 = arg0; t.arg1 = arg1; t.arg2 = arg2; t.arg3 = arg3;
	t.arg4 = arg4; t.arg5 = arg5; t.arg6 = arg6; t.arg7 = arg7;
	t.arg8 = arg8; t.arg9 = arg9;

	taskInfo task;

	task.id = WINWORKS_TASKLIB_nextId++;
	task.name = name;
	task.started = true;
	task.thread = new boost::thread(&threadEntryWrapper, t);

	return ERROR;
}

STATUS taskDelete(int tid)
{
	for(int i = 0; i < WINWORKS_TASKLIB_taskInfo.size(); ++i)
	{
		if(WINWORKS_TASKLIB_taskInfo[i].id == tid)
		{
			// UNSAFE!!! UNSAAAAAAAAAFE!!!!!
			WINWORKS_TASKLIB_taskInfo[i].thread->interrupt();
			delete WINWORKS_TASKLIB_taskInfo[i].thread;
			WINWORKS_TASKLIB_taskInfo.erase(WINWORKS_TASKLIB_taskInfo.begin() + i);
			return OK;
		}
	}

	return ERROR;
}

STATUS taskResume(int tid)
{
	WINWORKS_NOT_IMPLEMENTED;

	return ERROR;
}

STATUS taskRestart(int tid)
{
	WINWORKS_NOT_IMPLEMENTED;

	return ERROR;
}

STATUS taskPrioritySet(int tid, int newPriority)
{
	WINWORKS_NOT_IMPLEMENTED;

	return ERROR;
}

STATUS taskPriorityGet(int tid, int* pPriority)
{
	WINWORKS_NOT_IMPLEMENTED;

	return ERROR;
}

BOOL taskIsReady(int tid)
{
	WINWORKS_NOT_IMPLEMENTED;

	return FALSE;
}

BOOL taskIsSuspended(int tid)
{
	WINWORKS_NOT_IMPLEMENTED;

	return FALSE;
}

STATUS taskIdVerify(int tid)
{
	for(int i = 0; i < WINWORKS_TASKLIB_taskInfo.size(); ++i)
	{
		if(WINWORKS_TASKLIB_taskInfo[i].id == tid)
			return OK;
	}

	return ERROR;
}