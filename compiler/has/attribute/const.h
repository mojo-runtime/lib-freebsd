#ifndef compiler_has_attribute_const
#  ifdef __has_attribute
#    define compiler_has_attribute_const __has_attribute(__const__)
#  elif defined __GNUC__
#    include "compiler/has/gcc/minor.h"
#    define compiler_has_attribute_const has_gcc_minor(2, 5)
#  else
#    error todo
#  endif
#endif