#ifndef LRT_ASYNCPRINT_H_
#define LRT_ASYNCPRINT_H_

#include <queue>
#include <xstring>
#include <WPILib.h>

using std::string;

class AsyncPrinter
{
public:
	virtual ~AsyncPrinter();
	static AsyncPrinter& Instance();

	static int Printf(const char* format, ...);
	static void Quit();
	static bool QueueEmpty()
	{
		return Instance().queue_.empty();
	}

protected:
	AsyncPrinter();

private:
	static int PrinterTaskWrapper();
	int PrinterTask();

	bool quitting_;
	bool running_;

	SEM_ID semaphore_;
	int queue_bytes_;

	Task * printerTask;
	queue<string> queue_;

	const static int kMaxBuffer_ = 4096;
	DISALLOW_COPY_AND_ASSIGN(AsyncPrinter);
};

#endif
