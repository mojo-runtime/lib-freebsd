#pragma once

#include "linux/__Number.hxx"

namespace linux::unlink {

static
const __Number
number =
#if defined(__x86_64__)
 87
#else
#  error
#endif
 ;

}