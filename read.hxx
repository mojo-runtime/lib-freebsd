#pragma once

#include <c/size_t.h>
#include "Result.hxx"

#define EAGAIN 35
#define EBADF 9
#define EBUSY 16
#define ECONNRESET 54
#define EFAULT 14
#define EINTR 4
#define EINVAL 22
#define EIO 5
#define EISDIR 21
#define EOPNOTSUPP 45

#define __NR_read 3

namespace freebsd {

static inline
auto
read(int fd, void* buffer, size_t length) noexcept
{
    enum Error
    {
        _E(AGAIN),
        _E(BADF),
        _E(BUSY),
        _E(CONNRESET),
        _E(FAULT),
        _E(INTR),
        _E(INVAL),
        _E(IO),
        _E(ISDIR),
        _E(OPNOTSUPP),
    };

    Result<size_t, Error>
    result;

#if defined(__x86_64__)
    asm volatile ("syscall\n"
                  "sbb %1, %1"
                  : "=a" (result.__word),
                    "=r" (result.__is_error)
                  : "a" (__NR_read),
                    "D" (fd),
                    "S" (buffer),
                    "d" (length)
                  : "memory");
#else
#  error
#endif

    return result;
}

}
