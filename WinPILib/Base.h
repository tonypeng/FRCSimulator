/*
 * WinPILib - Base.h
 * Copyright (c) 2013 Tony "untitled" Peng
 * <http://www.tonypeng.com/>,
 * Varun Parthasarathy
 * 
 * This file is subject to the terms and conditions defined in the
 * file 'LICENSE.txt', which is part of this source code package.
 */

#ifndef BASE_H_
#define BASE_H_

// A macro to disallow the copy constructor and operator= functions
// This should be used in the private: declarations for a class
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
	TypeName(const TypeName&);               \
	void operator=(const TypeName&)

#endif