#ifndef __builtin_assume_aligned

#include "feature/has_builtin_assume_aligned.h"

#if !has_builtin_assume_aligned
#  define __builtin_assume_aligned(x, ...) (x)
#endif

#endif