#pragma once

#if defined(__linux__)
#  if defined(__x86_64__)
#    define SYS_fstatat 262
#  elif defined(__arm__)
#    define SYS_fstatat 327
#  else
#    error
#  endif
#elif defined(__FreeBSD__)
#  define SYS_fstatat 493
#else
#  error
#endif