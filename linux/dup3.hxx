#ifndef linux_dup3_hxx_
#define linux_dup3_hxx_

#include "linux/c/_c_syscall3.h"
#include "linux/c/EBADF.h"
#include "linux/c/EBUSY.h"
#include "linux/c/EINTR.h"
#include "linux/c/EINVAL.h"
#include "linux/c/EMFILE.h"
#include "linux/c/SYS_dup3.h"

#include "linux/Result.hxx"

namespace linux {

static inline
auto
dup3(int oldfd, int newfd, int flags) noexcept
{
    enum Error
    {
        // `oldfd` isn't an open file descriptor.
        //
        // `newfd` is out of the allowed range for file descriptors.
        EBADF_ = EBADF,

        // This may be returned by dup3() during a race condition with open(2) and dup().
        EBUSY_ = EBUSY,

        // The dup3() call was interrupted by a signal; see signal(7).
        EINTR_ = EINTR,

        // `flags` contain an invalid value.
        //
        // `oldfd` was equal to `newfd`.
        EINVAL_ = EINVAL,

        // The process already has the maximum number of file descriptors open
        // and tried to open a new one.
        EMFILE_ = EMFILE,
    };

    return Result<int, Error>(_c_syscall3(SYS_dup3, oldfd, newfd, flags));
}

} // namespace linux

#endif