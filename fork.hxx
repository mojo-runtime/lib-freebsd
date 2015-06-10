#pragma once

#include "c/pid_t.h"
#include "Result.hxx"

#define EAGAIN 35
#define ENOMEM 12

#define __NR_fork 2

namespace freebsd {

static inline
auto
fork() noexcept
{
    enum Error
    {
        _E(AGAIN),
        _E(NOMEM),
    };

    Result<pid_t, Error>
    result;

#if defined(__x86_64__)

    asm volatile ("syscall\n"
                  "sbb %1, %1"
                  : "=a" (result.__word),
                    "=r" (result.__is_error)
                  : "a" (__NR_fork)
                  : "memory");

#else
#  error
#endif

    return result;
}

}
