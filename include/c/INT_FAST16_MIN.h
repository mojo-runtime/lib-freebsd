// -*- C -*-

#pragma once

#if defined(__ILP32__) || defined(__LP64__)
#  include "INT_FAST16_MAX.h"
#  define INT_FAST16_MIN (-INT_FAST16_MAX - 1)
#else
#  error
#endif
