#ifndef unix_getuid_h_
#define unix_getuid_h_

#include "c/_c_nothrow.h"

#include "SYS_getuid.h"
#include "uid_t.h"
#include "_syscall_0.h"
#include "_syscall_Result_ok.h"

_c_nothrow
static
uid_t
getuid()
{
    return _syscall_Result_ok(uid_t, _syscall_0(SYS_getuid));
}

#endif