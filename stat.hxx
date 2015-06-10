#pragma once

#define EACCES 13
#define EFAULT 14
#define EIO 5
#define ELOOP 62
#define ENAMETOOLONG 63
#define ENOENT 2
#define ENOTDIR 20
#define EOVERFLOW 84

#define __NR_stat 188

#include "c/struct-stat.h"
#include "Result.hxx"

namespace freebsd {

static inline
auto
stat(const char* pathname, struct stat* buf) noexcept
{
    enum Error
    {
        _E(ACCES),
        _E(FAULT),
        _E(IO),
        _E(LOOP),
        _E(NAMETOOLONG),
        _E(NOENT),
        _E(NOTDIR),
        _E(OVERFLOW),
    };

    Result<void, Error>
    result;

#if defined(__x86_64__)
    asm volatile ("syscall\n"
                  "sbb %1, %1"
                  : "=a" (result.__word),
                    "=r" (result.__is_error)
                  : "a" (__NR_stat),
                    "D" (pathname),
                    "S" (buf)
                  : "memory");
#else
#  error
#endif

    return result;
}

}
