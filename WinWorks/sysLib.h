/*
 * WinWorks - sysLib.h
 * Copyright (c) 2013 Tony "untitled" Peng
 * <http://www.tonypeng.com/>
 * 
 * This file is subject to the terms and conditions defined in the
 * file 'LICENSE.txt', which is part of this source code package.
 */

#ifndef SYSLIB_H_
#define SYSLIB_H_

#include "boost/date_time/posix_time/posix_time_types.hpp"

inline int sysClkRateGet()
{
	return boost::posix_time::time_duration::ticks_per_second();
}

#endif