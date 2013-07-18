#include "DriverStationInput.h"

Task* DriverStationInput::_listenTask = NULL;
SEM_ID DriverStationInput::_dataSem = semBCreate(0, SEM_EMPTY);

DriverStationInput::DriverStationInput()
{ }

DriverStationInput::~DriverStationInput()
{ }

void DriverStationInput::NewData()
{
	// copy data

	semGive(_dataSem);
}

void DriverStationInput::StartLoop(SEM_ID inSem)
{
	printf("DriverStationInput::StartLoop() Starting loop.\n");

	_listenTask = new Task("FRCSim Mock Driverstation Task", (FUNCPTR)listenTask);
	_listenTask->Start((UINT32)inSem);
}

void DriverStationInput::Dispose()
{
	_listenTask->Stop();

	delete _listenTask;
}

int DriverStationInput::listenTask(SEM_ID inSem)
{
	printf("DriverStationInput::listenTask() Input listen task started.\n");

	while(true)
	{
		semTake(inSem, WAIT_FOREVER);

		semTake(_dataSem, WAIT_FOREVER);

		// stuff
		printf("DriverStationInput::listenTask() Received data.\n");

		semGive(inSem);

		Sleep(1);
	}
}

