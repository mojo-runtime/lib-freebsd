#pragma once

#include "EACCES.h"
#include "EBADF.h"
#include "SYS_fchdir.h"

#include "Result.hxx"
#include "abi/syscall-1.hxx"

namespace linux {

static inline
auto
fchdir(int fd) noexcept
{
    // TODO(?): "The general errors for `fchdir()` are listed below:

    enum Error
    {
        // Search permission was denied on the directory open on `fd`.
        EACCES_ = EACCES,

        // `fd` is not a valid file descriptor.
        EBADF_ = EBADF,

        // ENOTDIR, I imagine?
    };

    return Result<void, Error>(abi::syscall(SYS_fchdir, fd));
}

}