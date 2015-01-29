#ifndef _c__EISDIR_h
#define _c__EISDIR_h

#include "c/ErrorNumber.h"

#ifdef __cplusplus
inline namespace c {
#endif

static
const ErrorNumber
EISDIR =
#ifdef __linux__
 21
#else
#  error
#endif
 ;

#ifdef __cplusplus
} // inline namespace c
#endif

#endif
