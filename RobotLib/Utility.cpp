/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#include "Utility.h"

#include "NetworkCommunication/FRCComm.h"
#include "ChipObject.h"
#include "Task.h"

#define DBG_DEMANGLE_PRINT_LEN 256  /* Num chars of demangled names to print */

extern "C"
{
	extern char * cplusDemangle (char *source, char *dest, INT32 n);
}

//char *wpi_getLabel(UINT addr, INT32 *found)
//{
//	throw NotSupportedException();
//}
/*
static void wpiTracePrint(INSTR *caller, INT32 func, INT32 nargs, INT32 *args, INT32 taskId, BOOL isKernelAdrs)
{
	char buf [MAX_SYS_SYM_LEN * 2];
	INT32 ix;
	INT32 len = 0;
	len += sprintf (&buf [len], "%s <%#010x>: ", wpi_getLabel((UINT)caller), (INT32)caller);
	len += sprintf (&buf [len], "%s <%#010x> (", wpi_getLabel((UINT)func), func);
	for (ix = 0; ix < nargs; ix++)
	{
		if (ix != 0)
			len += sprintf (&buf [len], ", ");
		len += sprintf (&buf [len], "%#x", args [ix]);
	}
	len += sprintf (&buf [len], ")\n");

	printf(buf);
}
*/
//static void wpiCleanTracePrint(INSTR *caller, INT32 func, INT32 nargs, INT32 *args, INT32 taskId, BOOL isKernelAdrs)
//{
//	throw NotSupportedException();
//}

extern "C"
{
	//extern void trcStack(REG_SET* pRegs, FUNCPTR printRtn, INT32 tid);
}

static INT32 wpiStackTask(INT32 taskId)
{
	throw NotSupportedException();
}

void wpi_selfTrace()
{
	throw NotSupportedException();
}

static bool stackTraceEnabled = false;
static bool suspendOnAssertEnabled = false;

/**
 * Enable Stack trace after asserts.
 */
void wpi_stackTraceOnAssertEnable(bool enabled)
{
	throw NotSupportedException();
}

/**
 * Enable suspend on asssert.
 * If enabled, the user task will be suspended whenever an assert fails. This
 * will allow the user to attach to the task with the debugger and examine variables
 * around the failure.
 */
void wpi_suspendOnAssertEnabled(bool enabled)
{
	suspendOnAssertEnabled = enabled;
}

static void wpi_handleTracing()
{
	throw NotSupportedException();
}

/**
 * Assert implementation.
 * This allows breakpoints to be set on an assert.
 * The users don't call this, but instead use the wpi_assert macros in Utility.h.
 */
bool wpi_assert_impl(bool conditionValue, 
					 const char *conditionText,
					 const char *message,
					 const char *fileName,
					 UINT32 lineNumber, 
					 const char *funcName)
{
	throw NotSupportedException();
}

/**
 * Common error routines for wpi_assertEqual_impl and wpi_assertNotEqual_impl
 * This should not be called directly; it should only be used by wpi_assertEqual_impl
 * and wpi_assertNotEqual_impl.
 */
void wpi_assertEqual_common_impl(int valueA,
					 	         int valueB,
					 	         const char *equalityType,
						         const char *message,
						         const char *fileName,
						         UINT32 lineNumber, 
						         const char *funcName)
{
	throw NotSupportedException();
}

/**
 * Assert equal implementation.
 * This determines whether the two given integers are equal. If not,
 * the value of each is printed along with an optional message string.
 * The users don't call this, but instead use the wpi_assertEqual macros in Utility.h.
 */
bool wpi_assertEqual_impl(int valueA,
					 	  int valueB,
						  const char *message,
						  const char *fileName,
						  UINT32 lineNumber, 
						  const char *funcName)
{
	throw NotSupportedException();
}

/**
 * Assert not equal implementation.
 * This determines whether the two given integers are equal. If so,
 * the value of each is printed along with an optional message string.
 * The users don't call this, but instead use the wpi_assertNotEqual macros in Utility.h.
 */
bool wpi_assertNotEqual_impl(int valueA,
					 	     int valueB,
						     const char *message,
						     const char *fileName,
						     UINT32 lineNumber, 
						     const char *funcName)
{
	throw NotSupportedException();
}


/**
 * Return the FPGA Version number.
 * For now, expect this to be competition year.
 * @return FPGA Version number.
 */
UINT16 GetFPGAVersion()
{
	throw NotSupportedException();
}

/**
 * Return the FPGA Revision number.
 * The format of the revision is 3 numbers.
 * The 12 most significant bits are the Major Revision.
 * the next 8 bits are the Minor Revision.
 * The 12 least significant bits are the Build Number.
 * @return FPGA Revision number.
 */
UINT32 GetFPGARevision()
{
	throw NotSupportedException();
}

/**
 * Read the microsecond-resolution timer on the FPGA.
 * 
 * @return The current time in microseconds according to the FPGA (since FPGA reset).
 */
UINT32 GetFPGATime()
{
	throw NotSupportedException();
}

// RT hardware access functions exported from ni_emb.out
extern "C"
{
	INT32 UserSwitchInput(INT32 nSwitch);
	INT32 LedInput(INT32 led);
	INT32 LedOutput(INT32 led, INT32 value);
}

/**
 * Read the value of the USER1 DIP switch on the cRIO.
 */
INT32 GetRIOUserSwitch()
{
	throw NotSupportedException();
}

/**
 * Set the state of the USER1 status LED on the cRIO.
 */
void SetRIOUserLED(UINT32 state)
{
	throw NotSupportedException();
}

/**
 * Get the current state of the USER1 status LED on the cRIO.
 * @return The curent state of the USER1 LED.
 */
INT32 GetRIOUserLED()
{
	throw NotSupportedException();
}

/**
 * Toggle the state of the USER1 status LED on the cRIO.
 * @return The new state of the USER1 LED.
 */
INT32 ToggleRIOUserLED()
{
	throw NotSupportedException();
}

/**
 * Set the state of the FPGA status LED on the cRIO.
 */
void SetRIO_FPGA_LED(UINT32 state)
{
	throw NotSupportedException();
}

/**
 * Get the current state of the FPGA status LED on the cRIO.
 * @return The curent state of the FPGA LED.
 */
INT32 GetRIO_FPGA_LED()
{
	throw NotSupportedException();
}

/**
 * Toggle the state of the FPGA status LED on the cRIO.
 * @return The new state of the FPGA LED.
 */
INT32 ToggleRIO_FPGA_LED()
{
	throw NotSupportedException();
}


