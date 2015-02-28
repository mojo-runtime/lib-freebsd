#ifndef glibc_assert_fail_h_
#define glibc_assert_fail_h_

#include "compat/NORETURN.h"
#include "compat/NOTHROW.h"

#ifdef __cplusplus
extern "C" {
#endif

NORETURN
NOTHROW
extern
void
__assert_fail(const char* expression, const char* file, unsigned int line, const char* function);

#ifdef __cplusplus
} // extern "C"
#endif


#endif
