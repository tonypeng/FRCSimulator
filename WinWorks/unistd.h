/*
 * WinWorks - unistd.h
 * Copyright (c) 2013 Tony "untitled" Peng
 * <http://www.tonypeng.com/>
 * 
 * This file is subject to the terms and conditions defined in the
 * file 'LICENSE.txt', which is part of this source code package.
 */

#ifndef UNISTD_H_
#define UNISTD_H_

#include <string>

static inline void bzero(void* s, size_t n) { memset(s, n, 0); }

#endif