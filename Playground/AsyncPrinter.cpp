#include "AsyncPrinter.h"

#define PRINT 1

AsyncPrinter& AsyncPrinter::Instance()
{
	static AsyncPrinter printer = AsyncPrinter();
	return printer;
}

AsyncPrinter::AsyncPrinter()
{
	printerTask = new Task("AsynchronousPrinter",
			(FUNCPTR) AsyncPrinter::PrinterTaskWrapper);
	quitting_ = false;
	running_ = false;
	semaphore_ = semMCreate(0);
	queue_bytes_ = 0;

	printerTask->Start();
}

AsyncPrinter::~AsyncPrinter() { }

int AsyncPrinter::Printf(const char* format, ...)
{
	char buffer[256];

	AsyncPrinter& me = Instance();
	if (me.quitting_)
		return 0;

	va_list args;
	va_start(args, format);

	int n_bytes = vsprintf(buffer, format, args);
	va_end(args);

	if (n_bytes >= 0)
	{
		Synchronized s(me.semaphore_);
		if (me.quitting_)
			return 0;

		string str(buffer);

		me.queue_.push(str);
		me.queue_bytes_ += n_bytes;

		if (me.queue_bytes_ >= kMaxBuffer_)
		{
			while (!me.queue_.empty())
				me.queue_.pop();

			string overflow("(AsyncPrinter Buffer Overflow)\n");

			me.queue_.push(overflow);
			me.queue_bytes_ = overflow.length();
		}
	}
	return n_bytes;
}

void AsyncPrinter::Quit()
{
	Instance().quitting_ = true;
	
	Wait(0.010);

	if (Instance().running_)
	{
		Instance().printerTask->Stop();
		printf("[WARNING] AsyncPrinter task killed.\n");
	}
	
	semDelete(Instance().semaphore_);

	printf("Async Printer deleted\n\n");
}

int AsyncPrinter::PrinterTaskWrapper()
{
	Instance().running_ = true;
	int status = Instance().PrinterTask();
	printf("AsyncPrinter: Stopping Async Printing\n");
	Instance().running_ = false;
	
	return status;
}

int AsyncPrinter::PrinterTask()
{
	while (!quitting_)
	{
		while (!quitting_ && !queue_.empty())
		{
			string str;
			{
				//Critical block
				Synchronized s(semaphore_);
				if (quitting_)
					return 0;
				str = queue_.front();
				queue_.pop();
				queue_bytes_ -= str.length();
			}

			printf(str.c_str());
			Wait(0.001);
		}

		Wait(0.002);
	}
	return 0;
}
