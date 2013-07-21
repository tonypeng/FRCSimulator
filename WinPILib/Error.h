/*
 * WinPILib - Error.h
 * Copyright (c) 2013 Tony "untitled" Peng
 * <http://www.tonypeng.com/>,
 * Varun Parthasarathy
 * 
 * This file is subject to the terms and conditions defined in the
 * file 'LICENSE.txt', which is part of this source code package.
 */

#ifndef _ERROR_H
#define _ERROR_H

#include "Base.h"
#include "ChipObject/NiRio.h"
#include <string>
#include <vxWorks.h>

//  Forward declarations
class ErrorBase;

/**
 * Error object represents a library error. 
 */
class Error
{
public:
	typedef tRioStatusCode Code;

	Error();
	~Error();
	void Clone(Error &error);
	Code GetCode() const;
	const char *GetMessage() const;
	const char *GetFilename() const;
	const char *GetFunction() const;
	UINT32 GetLineNumber() const;
	const ErrorBase* GetOriginatingObject() const;
	double GetTime() const;
	void Clear();
	void Set(Code code, const char* contextMessage, const char* filename,
		const char *function, UINT32 lineNumber, const ErrorBase* originatingObject);
	static void EnableStackTrace(bool enable) { m_stackTraceEnabled=enable; }
	static void EnableSuspendOnError(bool enable) { m_suspendOnErrorEnabled=enable; }

private:
	void Report();

	Code m_code;
	std::string m_message;
	std::string m_filename;
	std::string m_function;
	UINT32 m_lineNumber;
	const ErrorBase* m_originatingObject;
	double m_timestamp;

	static bool m_stackTraceEnabled;
	static bool m_suspendOnErrorEnabled;
	DISALLOW_COPY_AND_ASSIGN(Error);
};

#endif

