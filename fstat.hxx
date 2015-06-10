#pragma once

#include "c/struct-stat.h"
#include "Result.hxx"

#define EBADF 9
#define EFAULT 14
#define EIO 5
#define EOVERFLOW 98

#define __NR_fstat 189

namespace freebsd {

static inline
auto
fstat(int fd, struct stat* sb) noexcept
{
    enum Error
    {
        _E(BADF),
        _E(FAULT),
        _E(IO),
        _E(OVERFLOW),
    };

    Result<void, Error>
    result;

#if defined(__x86_64__)
    asm volatile ("syscall"
                  "\nsbb %1, %1"
                  : "=a" (result.__word),
                    "=r" (result.__is_error)
                  : "a" (__NR_fstat),
                    "D" (fd),
                    "S" (sb)
                  : "memory");
#else
#  error
#endif

    return result;
}

}
