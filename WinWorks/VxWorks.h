/*
 * WinWorks - VxWorks.h
 * Copyright (c) 2013 Tony "untitled" Peng
 * <http://www.tonypeng.com/>
 * 
 * This file is subject to the terms and conditions defined in the
 * file 'LICENSE.txt', which is part of this source code package.
 */

#ifndef VXWORKS_H_
#define VXWORKS_H_

#include <stdint.h>
#include <cassert>
#define wpi_assert assert
#define wpi_fatal(x)

#include <string>
#include <stdio.h>
#include <time.h>
#include <stdarg.h>
#include <algorithm>

#include <boost/current_function.hpp>

typedef int 		ARGINT;

#ifndef _STATUS_DEFINED
#define _STATUS_DEFINED
typedef	int		STATUS;
#endif /* _STATUS_DEFINED */

#ifndef _FUNCPTR_DEFINED
#define _FUNCPTR_DEFINED
#ifdef __cplusplus
typedef int 		(*FUNCPTR) (...);     /* ptr to function returning int */
#else
typedef int 		(*FUNCPTR) ();	   /* ptr to function returning int */
#endif /* __cplusplus */
#endif /* _FUNCPTR_DEFINED */

#ifndef _VOIDFUNCPTR_DEFINED
#define _VOIDFUNCPTR_DEFINED
#ifdef __cplusplus
typedef void 		(*VOIDFUNCPTR) (...); /* ptr to function returning void */
#else
typedef void 		(*VOIDFUNCPTR) (); /* ptr to function returning void */
#endif /* __cplusplus */
#endif /* _VOIDFUNCPTR_DEFINED */

#ifndef _DBLFUNCPTR_DEFINED
#define _DBLFUNCPTR_DEFINED
#ifdef __cplusplus
typedef double 		(*DBLFUNCPTR) (...);  /* ptr to function returning double*/
#else
typedef double 		(*DBLFUNCPTR) ();  /* ptr to function returning double*/
#endif /* __cplusplus */
#endif /* _DBLFUNCPTR_DEFINED */

#ifndef _FLTFUNCPTR_DEFINED
#define _FLTFUNCPTR_DEFINED
#ifdef __cplusplus
typedef float 		(*FLTFUNCPTR) (...);  /* ptr to function returning float */
#else
typedef float 		(*FLTFUNCPTR) ();  /* ptr to function returning float */
#endif /* __cplusplus */
#endif /* _FLTFUNCPTR_DEFINED */

#ifndef UINT8_DEF_
#define UINT8_DEF_
typedef	uint8_t		UINT8;
#endif

#ifndef UINT16_DEF_
#define UINT16_DEF_
typedef uint16_t	UINT16;
#endif

#ifndef UINT32_DEF_
#define UINT32_DEF_
typedef uint32_t	UINT32;
#endif

#ifndef UINT64_DEF_
#define UINT64_DEF_
typedef uint64_t	UINT64;
#endif

#ifndef INT8_DEF_
#define INT8_DEF_
typedef int8_t		INT8;
#endif

#ifndef INT16_DEF_
#define INT16_DEF_
typedef int16_t		INT16;
#endif

#ifndef INT32_DEF_
#define INT32_DEF_
typedef int32_t		INT32;
#endif

#ifndef INT64_DEF_
#define INT64_DEF_
typedef int64_t		INT64;
#endif

#ifndef BOOL_DEF_
#define BOOL_DEF_
typedef int BOOL;
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef OK
#define OK 0
#endif

#ifndef ERROR
#define ERROR (-1)
#endif

#ifndef NONE
#define NONE (-1)
#endif

#ifndef NO_WAIT
#define NO_WAIT 0
#endif

#ifndef WAIT_FOREVER
#define WAIT_FOREVER (-1)
#endif

#ifdef _DEBUG
#define DbgPrint(fmt, ...) printf(fmt, __VA_ARGS__)
#else
#define DbgPrint(fmt, ...)
#endif

#ifndef WINWORKS_NOT_IMPLEMENTED
#define WINWORKS_NOT_IMPLEMENTED DbgPrint("[SEVERE] %s::%s (Line %d): Unimplemented function called!\n", __FILE__, BOOST_CURRENT_FUNCTION, __LINE__)
#endif

#ifndef WINWORKS_NOT_IMPLEMENTED_MSG
#define WINWORKS_NOT_IMPLEMENTED_MSG(x) DbgPrint("[SEVERE] %s::%s (Line %d): Unimplemented function called! (Message: %s)\n", __FILE__, BOOST_CURRENT_FUNCTION, __LINE__, x)
#endif

#endif