#pragma once

#include "Result.hxx"

#define EACCES 13
#define EDQUOT 69
#define EEXIST 17
#define EFAULT 14
#define EINTR 4
#define EINVAL 22
#define EIO 5
#define EISDIR 21
#define ELOOP 62
#define EMFILE 24
#define ENAMETOOLONG 63
#define ENOENT 2
#define ENOSPC 28
#define ENOTDIR 20
#define ENXIO 6
#define EOPNOTSUPP 45
#define EPERM 1
#define EROFS 30
#define ETXTBSY 26
#define EWOULDBLOCK 35

#define O_CLOEXEC 0x100000
#define O_CREAT 0x200
#define O_DIRECTORY 0x20000
#define O_NONBLOCK 0x4
#define O_RDONLY 0x0
#define O_RDWR 0x2
#define O_WRONLY 0x1

#define __NR_open 5

namespace freebsd {

static inline
auto
open(const char* pathname, int flags) noexcept
{
    enum Error
    {
        _E(ACCES),
        _E(DQUOT),
        _E(EXIST),
        _E(FAULT),
        _E(INTR),
        _E(INVAL),
        _E(IO),
        _E(ISDIR),
        _E(LOOP),
        _E(MFILE),
        _E(NAMETOOLONG),
        _E(NOENT),
        _E(NOSPC),
        _E(NOTDIR),
        _E(NXIO),
        _E(OPNOTSUPP),
        _E(PERM),
        _E(ROFS),
        _E(TXTBSY),
        _E(WOULDBLOCK),
    };

    Result<int, Error>
    result;

#if defined(__x86_64__)
    asm volatile ("syscall\n"
                  "sbb %1, %1"
                  : "=a" (result.__word),
                    "=r" (result.__is_error)
                  : "a" (__NR_open),
                    "D" (pathname),
                    "S" (flags)
                  : "memory");
#else
#  error
#endif

    return result;
}

}
