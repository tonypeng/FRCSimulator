#ifndef DS_INPUT_H_
#define DS_INPUT_H_

#include <stdio.h>
#include "semLib.h"
#include "Task.h"

/*
	DriverStationInput.h
	Author: untitled

	This file acts as the middle-man between the host and
	the library.
*/

class DriverStationInput
{
public:
	DriverStationInput();
	~DriverStationInput();

	static void NewData();

	static void StartLoop(SEM_ID inSem);
	static void Dispose();
	
private:
	static Task* _listenTask;
	static SEM_ID _dataSem;

	static int listenTask(SEM_ID inSem);
};

#endif