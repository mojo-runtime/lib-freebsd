#pragma once

#include "EFAULT.h"
#include "EINVAL.h"
#include "ESRCH.h"
#include "SYS_set_thread_area.h"
#include "struct-user_desc.h"

#include "Result.hxx"
#include "abi/syscall-1.hxx"

namespace linux {

static inline
auto
set_thread_area(struct user_desc* u_info) noexcept
{
    enum Error
    {
        // `u_info` is an invalid pointer.
        EFAULT_ = EFAULT,

        // `u_info->entry_number` is out of bounds.
        EINVAL_ = EINVAL,

        // A free TLS entry count not be located.
        ESRCH_ = ESRCH,
    };

    return Result<void, Error>(abi::syscall(SYS_set_thread_area, u_info));
}

}