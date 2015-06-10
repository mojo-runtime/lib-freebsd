#pragma once

#include <c/size_t.h>
#include "Result.hxx"

#define EAGAIN 35
#define EBADF 9
#define EDESTADDRREQ 39
#define EDQUOT 69
#define EFAULT 14
#define EFBIG 27
#define EINTR 4
#define EINVAL 22
#define EIO 5
#define ENOSPC 28
#define EPIPE 32

#define __NR_write 4

namespace freebsd {

static inline
auto
write(int fd, const void* buffer, size_t length) noexcept
{
    enum Error
    {
        _E(AGAIN),
        _E(BADF),
        _E(DESTADDRREQ),
        _E(DQUOT),
        _E(FAULT),
        _E(FBIG),
        _E(INTR),
        _E(INVAL),
        _E(IO),
        _E(NOSPC),
        _E(PIPE),
    };

    Result<size_t, Error>
    result;

#if defined(__x86_64__)
    asm volatile ("syscall\n"
                  "sbb %1, %1"
                  : "=a" (result.__word),
                    "=r" (result.__is_error)
                  : "a" (__NR_write),
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
