#ifndef ROBOTLIB_H_
#define ROBOTLIB_H_

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#define OK (0)
#define ERROR (-1)

#define VERBOSE

#include <limits>
#include <map>
#include <list>
#include <queue>

using namespace std;

#include "NotSupportedException.h"
#include "Macros.h"
#include "DriverStation.h"
#include "Joystick.h"
#include "TYPEDEF.h"
#include "RobotBase.h"
#include "SensorBase.h"
#include "Synchronized.h"
#include "Task.h"
#include "Timer.h"
#include "Watchdog.h"

#endif // ROBOTLIB_H_