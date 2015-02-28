#ifndef c_posix_getpid_h_
#define c_posix_getpid_h_

#include "compat/NOTHROW.h"

#include "SYS_getpid.h"
#include "pid_t.h"
#include "_system_call_0.h"
#include "_system_Result_ok.h"

NOTHROW
static
pid_t
getpid()
{
    return _system_Result_ok(pid_t, _system_call_0(SYS_getpid));
}

#endif
