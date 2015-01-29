#ifndef _c__EDQUOT_h
#define _c__EDQUOT_h

#include "c/ErrorNumber.h"

#ifdef __cplusplus
inline namespace c {
#endif

static
const ErrorNumber
EDQUOT =
#ifdef __linux__
 #  ifdef __x86_64__
 122 // generic
#  else
#    error
#  endif
#else
#  error
#endif
 ;

#ifdef __cplusplus
} // inline namespace c
#endif

#endif
