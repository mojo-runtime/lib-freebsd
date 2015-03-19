#pragma once

#include <pid_t>

#include "__call.hxx"

namespace linux {

static inline
pid_t
getpid() noexcept
{
#if defined(__x86_64__)
    return __call<121>().ok<pid_t>();
#else
#  error
#endif
}

}