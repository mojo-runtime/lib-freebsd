#pragma once

#include <c/size_t.h>
#include "Result.hxx"

#define EBADF 9
#define ECONNRESET 54
#define EINTR 4
#define ENOSPC 28

#define __NR_close 6

namespace freebsd {

static inline
auto
close(int fd) noexcept
{
    enum Error
    {
        _E(BADF),
        _E(CONNRESET),
        _E(INTR),
        _E(NOSPC),
    };

    Result<void, Error>
    result;

#if defined(__x86_64__)
    asm volatile ("syscall\n"
                  "sbb %1, %1"
                  : "=a" (result.__word),
                    "=r" (result.__is_error)
                  : "a" (__NR_close),
                    "D" (fd)
                  : "memory");
#else
#  error
#endif

    return result;
}

}
