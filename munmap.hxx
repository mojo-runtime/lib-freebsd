#pragma once

#include <c/size_t.h>
#include "Result.hxx"

#define EINVAL 22

#define __NR_munmap 73

namespace freebsd {

static inline
auto
munmap(void* address, size_t length) noexcept
{
    enum Error
    {
        _E(INVAL),
    };

    Result<void, Error>
    result;

#if defined(__x86_64__)
    asm volatile ("syscall\n"
                  "sbb %1, %1"
                  : "=a" (result.__word),
                    "=r" (result.__is_error)
                  : "a" (__NR_munmap),
                    "D" (address),
                    "S" (length)
                  : "memory");
#else
#  error
#endif

    return result;
}

}
