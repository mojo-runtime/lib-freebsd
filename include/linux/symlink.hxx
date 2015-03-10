#ifndef linux_symlink_hxx_
#define linux_symlink_hxx_

#include "linux/_syscall_2.h"
#include "linux/EACCES.h"
#include "linux/EDQUOT.h"
#include "linux/EEXIST.h"
#include "linux/EFAULT.h"
#include "linux/EIO.h"
#include "linux/ELOOP.h"
#include "linux/ENAMETOOLONG.h"
#include "linux/ENOENT.h"
#include "linux/ENOMEM.h"
#include "linux/ENOSPC.h"
#include "linux/ENOTDIR.h"
#include "linux/EPERM.h"
#include "linux/EROFS.h"
#include "c/SYS_symlink.h"

#include "linux/Result.hxx"

namespace linux {

static inline
auto
symlink(const char* target, const char* linkpath) noexcept
{
    enum Error
    {
        // Write access to the directory containing `linkpath` is denied.
        //
        // One of the directories in the path prefix of `linkpath` did not allow search permission.
        EACCES_ = EACCES,

        // The user's quota of resources on the filesystem has been exhausted.
        // The resources could be inodes or disk blocks,
        // depending on the filesystem implementation.
        EDQUOT_ = EDQUOT,

        // `linkpath` already exists.
        EEXIST_ = EEXIST,

        // `target` or `linkpath` points outside your accessible address space.
        EFAULT_ = EFAULT,

        // An I/O error occurred.
        EIO_ = EIO,

        // Too many symbolic links were encountered in resolving `linkpath`.
        ELOOP_ = ELOOP,

        // `target` or `linkpath` was too long.
        ENAMETOOLONG_ = ENAMETOOLONG,

        // A directory component in `linkpath` does not exist or is a dangling symbolic link.
        //
        // `target` is the empty string.
        ENOENT_ = ENOENT,

        // Insufficient kernel memory was available.
        ENOMEM_ = ENOMEM,

        // The device containing the file has no room for the new directory entry.
        ENOSPC_ = ENOSPC,

        // A component used as a directory in `linkpath` is not, in fact, a directory.
        ENOTDIR_ = ENOTDIR,

        // The filesystem containing `linkpath` does not support the creation of symbolic links.
        EPERM_ = EPERM,

        // `linkpath` is on a read-only filesystem.
        EROFS_ = EROFS,
    };

    return Result<void, Error>(_syscall_2(SYS_symlink, target, linkpath));
}

} // namespace linux

#endif
