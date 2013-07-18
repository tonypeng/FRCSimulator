#ifndef SYNCHRONIZED_H_
#define SYNCHRONIZED_H_

#ifndef SEMLIB_H_
#include "semLib.h"
#endif

#include <stdio.h>

class Synchronized
{
public:
	Synchronized( SEM_ID sem );
	~Synchronized();

private:
	SEM_ID m_semaphore;
};

#endif