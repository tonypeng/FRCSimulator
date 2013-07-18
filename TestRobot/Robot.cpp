#include "AsyncPrinter.h"

int ThreadEntry(UINT32 code)
{
	while(true)
	{
		printf("%c!\n", code);

		Sleep(15);
	}
}

class Robot : public RobotBase
{
public:
	Robot();
	virtual ~Robot();

	void StartCompetition();
	void RobotInit();
	void MainLoop();
};

Robot::Robot()
{
}

Robot::~Robot()
{
	AsyncPrinter::Quit();
}

void Robot::StartCompetition()
{
	printf("Robot::StartCompetition() task name: %s\n", m_task->GetName());

	//for(int i = 0; i < 100; i++)

	Sleep(1000);

	printf("\n");

	int i = 0;
	while(true)
	{
		printf("%d\n", i++);
		DriverStationInput::NewData();

		Sleep(1000);

		printf("\n");
	}
	
}

RobotBase* FRC_userClassFactory()
{
	return new Robot();
}

extern "C"
{
__declspec(dllexport) INT32 FRC_UserProgram_StartupLibraryInit()
{
	RobotBase::startRobotTask((FUNCPTR) FRC_userClassFactory);
	return 0;
}
}

extern "C" __declspec(dllexport) void InteropTest()
{
	printf("From unmanaged DLL!\n");
}