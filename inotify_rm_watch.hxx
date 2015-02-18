#ifndef linux_inotify_rm_watch_hxx_
#define linux_inotify_rm_watch_hxx_

#include "c/EBADF.h"
#include "c/EINVAL.h"
#include "c/SYS_inotify_rm_watch.h"
#include "c/_c_syscall2.h"

#include "linux/Result.hxx"

namespace linux {

static inline
auto
inotify_rm_watch(int fd, int wd) noexcept
{
    enum Error
    {
        // `fd` is not a valid file descriptor.
        EBADF = EBADF,

        // The watch descriptor `wd` is not valid; or
        // `fd` is not an inotify file descriptor.
        EINVAL = EINVAL,
    };

    return Result<void, Error>(_c_syscall2(SYS_inotify_rm_watch, fd, wd));
}

} // namespace linux

#endif
