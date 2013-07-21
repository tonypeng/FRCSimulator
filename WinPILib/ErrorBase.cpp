/*
 * WinPILib - ErrorBase.cpp
 * Copyright (c) 2013 Tony "untitled" Peng
 * <http://www.tonypeng.com/>,
 * Varun Parthasarathy
 * 
 * This file is subject to the terms and conditions defined in the
 * file 'LICENSE.txt', which is part of this source code package.
 */

#include "ErrorBase.h"
#include "Synchronized.h"
#include "nivision.h"
#define WPI_ERRORS_DEFINE_STRINGS
#include "WPIErrors.h"
SEM_ID ErrorBase::_globalErrorMutex = semMCreate(SEM_Q_PRIORITY | SEM_DELETE_SAFE | SEM_INVERSION_SAFE);
Error ErrorBase::_globalError;

ErrorBase::ErrorBase()
{}

ErrorBase::~ErrorBase()
{}

Error& ErrorBase::GetError()
{
	return m_error;
}

const Error& ErrorBase::GetError() const
{
	return m_error;
}

void ErrorBase::ClearError() const
{
	m_error.Clear();
}

void ErrorBase::SetErrnoError(const char *contextMessage,
		const char* filename, const char* function, UINT32 lineNumber) const
{
	WINWORKS_NOT_IMPLEMENTED;
} 

void ErrorBase::SetImaqError(int success, const char *contextMessage, const char* filename, const char* function, UINT32 lineNumber) const
{
	//  If there was an error
	if (success <= 0) {
		char err[256];
		sprintf(err, "%s: %s", contextMessage, imaqGetErrorText(imaqGetLastError()));

		//  Set the current error information for this object.
		m_error.Set(imaqGetLastError(), err, filename, function, lineNumber, this);

		// Update the global error if there is not one already set.
		Synchronized mutex(_globalErrorMutex);
		if (_globalError.GetCode() == 0) {
			_globalError.Clone(m_error);
		}
	}
}

void ErrorBase::SetError(Error::Code code, const char *contextMessage,
		const char* filename, const char* function, UINT32 lineNumber) const
{
	//  If there was an error
	if (code != 0) {
		//  Set the current error information for this object.
		m_error.Set(code, contextMessage, filename, function, lineNumber, this);

		// Update the global error if there is not one already set.
		Synchronized mutex(_globalErrorMutex);
		if (_globalError.GetCode() == 0) {
			_globalError.Clone(m_error);
		}
	}
}

void ErrorBase::SetWPIError(const char *errorMessage, const char *contextMessage,
		const char* filename, const char* function, UINT32 lineNumber) const
{
	char err[256];
	sprintf(err, "%s: %s", errorMessage, contextMessage);

	//  Set the current error information for this object.
	m_error.Set(-1, err, filename, function, lineNumber, this);

	// Update the global error if there is not one already set.
	Synchronized mutex(_globalErrorMutex);
	if (_globalError.GetCode() == 0) {
		_globalError.Clone(m_error);
	}
}

void ErrorBase::CloneError(ErrorBase *rhs) const
{
	m_error.Clone(rhs->GetError());
}

bool ErrorBase::StatusIsFatal() const
{
	return m_error.GetCode() < 0;
}

void ErrorBase::SetGlobalError(Error::Code code, const char *contextMessage,
		const char* filename, const char* function, UINT32 lineNumber)
{
	//  If there was an error
	if (code != 0) {
		Synchronized mutex(_globalErrorMutex);

		//  Set the current error information for this object.
		_globalError.Set(code, contextMessage, filename, function, lineNumber, NULL);
	}
}

void ErrorBase::SetGlobalWPIError(const char *errorMessage, const char *contextMessage,
        const char* filename, const char* function, UINT32 lineNumber)
{
	char err[256];
	sprintf(err, "%s: %s", errorMessage, contextMessage);

	Synchronized mutex(_globalErrorMutex);
	if (_globalError.GetCode() != 0) {
		_globalError.Clear();
	}
	_globalError.Set(-1, err, filename, function, lineNumber, NULL);
}

Error& ErrorBase::GetGlobalError()
{
	Synchronized mutex(_globalErrorMutex);
	return _globalError;
}

