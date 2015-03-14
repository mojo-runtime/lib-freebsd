#pragma once

#include "EAGAIN.h"
#include "ENOMEM.h"
#include "ENOSYS.h"
#include "SYS_fork.h"
#include "pid_t.h"

#include "Result.hxx"
#include "abi/syscall-0.hxx"

namespace linux {

static inline
auto
fork() noexcept
{
    enum Error
    {
        // fork() cannot allocate sufficient memory to copy the parent's page tables
        // and allocate a task structure for the child.
        //
        // It was not possible to create a new process because
        // the caller's RLIMIT_NPROC resource limit was encountered.
        // To exceed this limit, the process must have either the CAP_SYS_ADMIN
        // or the CAP_SYS_RESOURCE capability.
        EAGAIN_ = EAGAIN,

        // fork() failed to allocate the necessary kernel structures because memory is tight.
        ENOMEM_ = ENOMEM,

        // fork() is not supported on this platform
        // (for example, hardware without a Memory-Management Unit).
        ENOSYS_ = ENOSYS,
    };

    return Result<pid_t, Error>(abi::syscall(SYS_fork));
}

}