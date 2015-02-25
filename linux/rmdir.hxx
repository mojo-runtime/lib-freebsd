#ifndef linux_rmdir_hxx_
#define linux_rmdir_hxx_

#include "linux/c/_c_syscall1.h"
#include "linux/c/EACCES.h"
#include "linux/c/EBUSY.h"
#include "linux/c/EFAULT.h"
#include "linux/c/EINVAL.h"
#include "linux/c/ELOOP.h"
#include "linux/c/ENAMETOOLONG.h"
#include "linux/c/ENOENT.h"
#include "linux/c/ENOMEM.h"
#include "linux/c/ENOTDIR.h"
#include "linux/c/ENOTEMPTY.h"
#include "linux/c/EPERM.h"
#include "linux/c/EROFS.h"
#include "linux/c/SYS_rmdir.h"

#include "linux/Result.hxx"

namespace linux {

static inline
auto
rmdir(const char* pathname) noexcept
{
    enum Error
    {
        // Write access to the directory containing `pathname` was not allowed.
        //
        // One of the directories in the path prefix of `pathname` did not allow search permission.
        EACCES_ = EACCES,

        // `pathname` is currently in use by the system or some process that prevents its removal.
        // On Linux this means `pathname` is currently used as a mount point or is the root
        // directory of the calling process.
        EBUSY_ = EBUSY,

        // `pathname` points outside your accessible address space.
        EFAULT_ = EFAULT,

        // `pathname` has . as last component.
        EINVAL_ = EINVAL,

        // Too many symbolic links were encountered in resolving pathname.
        ELOOP_ = ELOOP,

        // `pathname` was too long.
        ENAMETOOLONG_ = ENAMETOOLONG,

        // A directory component in `pathname` does not exist or is a dangling symbolic link.
        ENOENT_ = ENOENT,

        // Insufficient kernel memory was available.
        ENOMEM_ = ENOMEM,

        // A component used as a directory in `pathname` is not, in fact, a directory.
        ENOTDIR_ = ENOTDIR,

        // `pathname` contains entries other than . and ..
        //
        // `pathname` has ..  as its final component.
        ENOTEMPTY_ = ENOTEMPTY,

        // The directory containing `pathname` has the sticky bit (S_ISVTX) set
        // and the process's effective user ID is neither the user ID of the file
        // to be deleted nor that of the directory containing it,
        // and the process is not privileged.
        //
        // The filesystem containing `pathname` does not support the removal of directories.
        EPERM_ = EPERM,

        // `pathname` refers to a directory on a read-only filesystem.
        EROFS_ = EROFS,
    };

    return Result<void, Error>(_c_syscall1(SYS_rmdir, pathname));
}

} // namespace linux

#endif