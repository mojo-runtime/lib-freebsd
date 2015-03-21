#pragma once

#include "c/EACCES.h"
#include "c/EAGAIN.h"
#include "c/EBADF.h"
#include "c/EINVAL.h"
#include "c/ENFILE.h"
#include "c/ENODEV.h"
#include "c/ENOMEM.h"
#include "c/EOVERFLOW.h"
#include "c/EPERM.h"
#include "c/ETXTBSY.h"
#include "c/SYS_mmap.h"
#include "c/off_t.h"
#include "c/size_t.h"

#include "Result.hxx"

namespace linux {

static inline
auto
mmap(void*  addr,
     size_t length,
     int    prot,
     int    flags,
     int    fd,
     off_t  offset) noexcept
{
    enum Error
    {
#define _(name) _##name = name
        _(EACCES),
        _(EAGAIN),
        _(EBADF),
        _(EINVAL),
        _(ENFILE),
        _(ENODEV),
        _(ENOMEM),
        _(EOVERFLOW),
        _(EPERM),
        _(ETXTBSY),
#undef _
    };

    return Result<void*, Error>(SYS_mmap, addr, length, prot, flags, fd, offset);
}

}