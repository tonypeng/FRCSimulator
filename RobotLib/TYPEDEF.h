// 4.9.2012
//
// Added in
// -Tony Peng

#ifndef TYPEDEF_H_
#define TYPEDEF_H_

#include <stdint.h>

#define NULL		0

typedef int	(*FUNCPTR) (...); /* Pointer to a int function */

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

#ifndef INT32_DEF_
#define INT32_DEF_
typedef int32_t		INT32;
#endif

typedef int			STATUS;

#endif // TYPEDEF_H_