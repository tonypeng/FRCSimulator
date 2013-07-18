#include "Task.h"

#include "semLib.h"

Task::Task(const char *name, FUNCPTR function, INT32 priority, UINT32 stackSize)
{
	m_taskID = kInvalidTaskID;
	m_function = function;
	m_priority = priority;
	m_stackSize = stackSize;
	m_taskName = new char[strlen(name) + 5];
	strcpy(m_taskName, "FRC_");
	strcpy(m_taskName+4, name);
}

Task::~Task()
{
	if(m_taskID != kInvalidTaskID) Stop();

	delete[] m_taskName;
	m_taskName = 0;
}

void Task::ThreadEntry(LPVOID param)
{
	//threadParamStruct* args = static_cast<threadParamStruct*>(param);
	threadParamStruct* args = (threadParamStruct*)param;
	
	(*(args->func))(args->arg0,
		args->arg1, args->arg2, args->arg3, args->arg4, args->arg5,
		args->arg6, args->arg7, args->arg8, args->arg9);
}

bool Task::Start(UINT32 arg0, UINT32 arg1, UINT32 arg2, UINT32 arg3, UINT32 arg4, 
		UINT32 arg5, UINT32 arg6, UINT32 arg7, UINT32 arg8, UINT32 arg9)
{
	// differing code!
	threadParamStruct* t = new threadParamStruct;

	t->func = m_function;
	t->arg0 = arg0; t->arg1 = arg1; t->arg2 = arg2; t->arg3 = arg3;
	t->arg4 = arg4; t->arg5 = arg5; t->arg6 = arg6; t->arg7 = arg7;
	t->arg8 = arg8; t->arg9 = arg9;

	DWORD id;

	m_threadHandle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)ThreadEntry, t, 0, &id);
	//m_threadHandle = (HANDLE) _beginthread(ThreadEntry, 0, (void*)&t);

	// oh no...
	if(m_threadHandle == NULL)
	{
		return false;
	}

	BOOL worked = SetThreadPriority(m_threadHandle, m_priority);

	if(!worked) return false;

	m_taskID = id;

	return true;
}

bool Task::Stop()
{
	// this method is BAD!
	// it can really screw up stuff if the executing thread
	// hasn't properly stopped!
	//
	// possible scenarios: unreleased locks, critical sections, no dtor called...
	return TerminateThread(m_threadHandle, 0);
}

const char* Task::GetName()
{
	return m_taskName;
}