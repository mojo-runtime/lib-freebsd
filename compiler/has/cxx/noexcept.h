#ifndef compiler_has_cxx_noexcept
#  ifdef __has_feature
#    define compiler_has_cxx_noexcept __has_feature(cxx_noexcept)
#  elif defined __GNUC__
#    include "compiler/has/gnuc/minor.h"
#    define compiler_has_cxx_noexcept compiler_has_gnuc_minor(4, 6)
#  else
#    error todo
#  endif
#endif