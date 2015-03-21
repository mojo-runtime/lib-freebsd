#pragma once

#include "c/EBADF.h"
#include "c/EINTR.h"
#include "c/EIO.h"
#include "c/SYS_close.h"

#include "Result.hxx"

namespace linux {

static inline
auto
close(int fd) noexcept
{
    enum Error
    {
#define _(name) _##name = name
        _(EBADF),
        _(EINTR),
        _(EIO),
#undef _
    };

    return Result<void, Error>(SYS_close, fd);
}

}