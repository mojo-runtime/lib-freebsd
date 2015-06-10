#pragma once

#if defined(__x86_64__)
#  include <c/int32_t.h>
typedef int32_t clock_t;
#else
#  error
#endif
