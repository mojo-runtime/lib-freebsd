#pragma once

#include <c/size_t.h>
#include "c/off_t.h"
#include "Result.hxx"

#define EACCES 13
#define EBADF 9
#define EINVAL 22
#define ENODEV 19
#define ENOMEM 12

#define MAP_ANONYMOUS 0x1000
#define MAP_PRIVATE 0x2
#define MAP_SHARED 0x1

#define PROT_EXEC 0x4
#define PROT_NONE 0x0
#define PROT_READ 0x1
#define PROT_WRITE 0x2

#define __NR_mmap 477

namespace freebsd {

static inline
auto
mmap(void* addr, size_t length, int prot, int flags, int fd, off_t offset) noexcept
{
    enum Error
    {
        _E(ACCES),
        _E(BADF),
        _E(INVAL),
        _E(NODEV),
        _E(NOMEM),
    };

    Result<void*, Error>
    result;

#if defined(__x86_64__)
    register auto r8 asm ("r8") = fd;
    register auto r9 asm ("r9") = offset;

    asm volatile ("syscall\n"
                  "sbb %1, %1"
                  : "=a" (result.__word),
                    "=r" (result.__is_error)
                  : "a" (__NR_mmap),
                    "D" (addr),
                    "S" (length),
                    "d" (prot),
                    "c" (flags),
                    "r" (r8),
                    "r" (r9)
                  : "memory");
#else
#  error
#endif

    return result;
}

}
