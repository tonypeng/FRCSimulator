#ifndef SEMLIB_H_
#define SEMLIB_H_

/* put windows on a diet */
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <Windows.h>
#include <time.h> // for CLOCKS_PER_SEC

#define SEM_Q_FIFO		 0x00
#define SEM_Q_PRIORITY		 0x01
#define SEM_DELETE_SAFE		 0x04
#define SEM_INVERSION_SAFE	 0x08
#define SEM_EVENTSEND_ERR_NOTIFY 0x10
#define SEM_INTERRUPTIBLE        0x20

#define WAIT_FOREVER	-1
#define NO_WAIT			0

typedef struct semaphore {
	HANDLE m_handle;

	enum {
		MUTEX, BSEMAPHORE
	} m_syncType;

} rsSyncObj;

typedef rsSyncObj* SEM_ID;

typedef enum
{
	SEM_EMPTY,
	SEM_FULL
} SEM_B_STATE;

SEM_ID semMCreate(int options);
SEM_ID semBCreate(int options, SEM_B_STATE initialState);

void semGive(SEM_ID sem);
int semTake(SEM_ID sem, int ticks);

void semFlush(SEM_ID sem);

void semDelete(SEM_ID sem);

#endif