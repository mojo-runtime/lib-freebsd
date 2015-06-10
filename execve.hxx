#pragma once

#include "Result.hxx"

#define E2BIG 7
#define EACCES 13
#define EFAULT 14
#define EIO 5
#define ELOOP 62
#define ENAMETOOLONG 63
#define ENOENT 2
#define ENOEXEC 8
#define ENOMEM 12
#define ENOTDIR 20
#define ETXTBSY 26

#define __NR_execve 59

namespace freebsd {

static inline
auto
execve(const char* path, char* const argv[], char* const envp[]) noexcept
{
    enum Error
    {
        _E(2BIG),
        _E(ACCES),
        _E(FAULT),
        _E(IO),
        _E(LOOP),
        _E(NAMETOOLONG),
        _E(NOENT),
        _E(NOEXEC),
        _E(NOMEM),
        _E(NOTDIR),
        _E(TXTBSY),
    };

    Error
    error;

#if defined(__x86_64__)

    asm volatile ("syscall"
                  : "=a" (error)
                  : "a" (__NR_execve),
                    "D" (path),
                    "S" (argv),
                    "d" (envp)
                  : "memory");

#else
#  error
#endif

    return error;
}

}
