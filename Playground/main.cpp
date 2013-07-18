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

class RBase
{
public:
	bool IsEnabled();

protected:
	RBase();
	virtual ~RBase();
};

RBase::RBase()
{
}

RBase::~RBase()
{
}

bool RBase::IsEnabled()
{
	return true;
}

class Rbt : public RBase
{
public:
	Rbt();
	virtual ~Rbt();
};

Rbt::Rbt()
{
}

Rbt::~Rbt()
{
}

int main()
{
	printf("RobotSimulator 1.0\n");
	printf("\n");

	//RBase *robot = new Rbt();

	//RobotBase* robot = new Robot();

	//printf("!");

	//FRC_userClassFactory();

	RobotBase::startRobotTask((FUNCPTR)FRC_userClassFactory);
	/*
	Task *t = new Task("test task", (FUNCPTR)ThreadEntry, 101, 20000);
	t->Start('a');

	Task *t2 = new Task("test task 2", (FUNCPTR)ThreadEntry, 101, 20000);
	t->Start('b');*/

	while(true) ;
	//system("PAUSE");
}