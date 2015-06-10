#pragma once

#include "Result.hxx"

#define EBADF 9
#define EFAULT 14
#define EINVAL 22
#define ENOTTY 25

#define __NR_ioctl 54

namespace freebsd {

// The type of `request` varies from man page to man page.
// See: https://sourceware.org/bugzilla/show_bug.cgi?id=14362

template <typename Arg>
static inline
auto
ioctl(int fd, int request, Arg arg) noexcept
{
    enum Error
    {
        _E(BADF),
        _E(FAULT),
        _E(INVAL),
        _E(NOTTY),
    };

    Result<void, Error>
    result;

#if defined(__x86_64__)
    asm volatile ("syscall\n"
                  "sbb %1, %1"
                  : "=a" (result.__word),
                    "=r" (result.__is_error)
                  : "a" (__NR_ioctl),
                    "D" (fd),
                    "S" (request),
                    "d" (arg)
                  : "memory");
#else
#  error
#endif

    return result;
}

}
