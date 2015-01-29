#ifndef _c__ESPIPE_h
#define _c__ESPIPE_h

#include "c/ErrorNumber.h"

#ifdef __cplusplus
inline namespace c {
#endif

static
const ErrorNumber
ESPIPE =
#ifdef __linux__
 29
#else
#  error
#endif
 ;

#ifdef __cplusplus
} // inline namespace c
#endif

#endif
