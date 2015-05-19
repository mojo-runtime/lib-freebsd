#pragma once

#if defined(__linux__)
#  if defined(__x86_64__)
#    define SYS_uname 63
#  elif defined(__arm__)
#    define SYS_uname 122
#  else
#    error
#  endif
#else
#  error
#endif