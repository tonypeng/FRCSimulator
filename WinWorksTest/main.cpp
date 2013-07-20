#define BOOST_LIB_DIAGNOSTIC

#include <cstdio>
#include <iostream>
#include <taskLib.h>
#include <sysLib.h>
#include <semLib.h>

SEM_ID sem;

int threadFunc(UINT32 l)
{
	while(true)
	{
		std::printf("From thread 2. Value1: %u.\n", l);
		semTake(sem, sysClkRateGet());
	}
}

int main()
{
	sem = semBCreate(0, SEM_EMPTY);

	std::printf("From main thread.\n");
	taskSpawn("Thread 2", 1, 0, 0, (FUNCPTR)threadFunc, 1, 2, 3, 4, 5, 0, 0, 0, 0, 0);
	std::cin.get();
}