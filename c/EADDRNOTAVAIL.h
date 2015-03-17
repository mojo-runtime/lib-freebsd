#pragma once

#if defined(__linux__)
#  if defined(__x86_64__) // generic
#    define EADDRNOTAVAIL 99
#  else
#    error
#  endif
#elif defined(__FreeBSD__)
#  define EADDRNOTAVAIL 49
#else
#  error
#endif
