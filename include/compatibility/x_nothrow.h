#if !defined(x_nothrow)
#  include "feature/has_attribute_nothrow.h"
#  if has_attribute_nothrow
#    define x_nothrow __attribute__((__nothrow__))
#  else
#    include "has/cxx/exceptions.h"
#    if has_cxx_exceptions
#      error
#    endif
#  endif
#endif
