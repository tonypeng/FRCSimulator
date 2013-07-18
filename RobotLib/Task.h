/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

// 4.9.2012
//
// Ported to WIN32
// -Tony Peng

#ifndef __TASK_H__
#define __TASK_H__


/* put windows on a diet */
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <Windows.h>
#include <string.h>

#ifndef _BASE_H_
#include "Base.h"
#endif

#ifndef TYPEDEF_H_
#include "TYPEDEF.h"
#endif

typedef struct {
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
} threadParamStruct;

/**
 * WPI task is a wrapper for the native Task object.
 * All WPILib tasks are managed by a static task manager for simplified cleanup.
 **/
class Task
{
public:
	static const UINT32 kDefaultPriority = 101;
	static const INT32 kInvalidTaskID = -1;

	Task(const char* name, FUNCPTR function, INT32 priority = kDefaultPriority, UINT32 stackSize = 20000);
	virtual ~Task();

	bool Start(UINT32 arg0 = 0, UINT32 arg1 = 0, UINT32 arg2 = 0, UINT32 arg3 = 0, UINT32 arg4 = 0, 
			UINT32 arg5 = 0, UINT32 arg6 = 0, UINT32 arg7 = 0, UINT32 arg8 = 0, UINT32 arg9 = 0);
	bool Restart();
	bool Stop();

	bool IsReady();
	bool IsSuspended();

	bool Suspend();
	bool Resume();

	bool Verify();

	INT32 GetPriority();
	bool SetPriority(INT32 priority);
	const char* GetName();
	INT32 GetID();

private:
	FUNCPTR m_function;
	char* m_taskName;
	INT32 m_taskID;
	UINT32 m_stackSize;
	INT32 m_priority;
	HANDLE m_threadHandle;
	bool HandleError(STATUS results);
	static void ThreadEntry(LPVOID param);
	DISALLOW_COPY_AND_ASSIGN(Task);
};

#endif // __TASK_H__