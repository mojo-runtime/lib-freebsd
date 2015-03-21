#pragma once

#include "c/EFAULT.h"
#include "c/SYS_uname.h"
#include "c/struct utsname.h"

#include "Result.hxx"

namespace linux {

static inline
auto
uname(struct utsname* buf) noexcept
{
    enum Error
    {
#define _(name) _##name = name
        _(EFAULT),
#undef _
    };

    return Result<void, Error>(SYS_uname, buf);
}

}