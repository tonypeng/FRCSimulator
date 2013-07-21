/*
 * WinPILib - Synchronized.cpp
 * Copyright (c) 2013 Tony "untitled" Peng
 * <http://www.tonypeng.com/>,
 * Varun Parthasarathy
 * 
 * This file is subject to the terms and conditions defined in the
 * file 'LICENSE.txt', which is part of this source code package.
 */

#include "Synchronized.h"

Synchronized::Synchronized(SEM_ID sem)
{
	m_semaphore = sem;
	
	semTake(m_semaphore, WAIT_FOREVER);
}

Synchronized::Synchronized(ReentrantSemaphore& reSem)
{
	m_semaphore = reSem.m_semaphore;

	semTake(m_semaphore, WAIT_FOREVER);
}

Synchronized::~Synchronized()
{
	semGive(m_semaphore);
}