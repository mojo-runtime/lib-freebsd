#ifndef linux_gettid_hxx_
#define linux_gettid_hxx_

#include "linux/c/_c_syscall0.h"
#include "linux/c/SYS_gettid.h"
#include "linux/c/pid_t.h"

namespace linux {

static inline
pid_t
gettid() noexcept
{
    return static_cast<pid_t>(_c_syscall0(SYS_gettid));
}

} // namespace linux

#endif