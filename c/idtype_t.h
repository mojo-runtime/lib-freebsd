#pragma once

typedef enum
{
    // FREEBSD/sys/sys/wait.h
    P_PID,
    P_PPID,
    P_PGID,
    P_SID,
    P_CID,
    P_UID,
    P_GID,
    P_ALL,
    P_LWPID,
    P_TASKID,
    P_PROJID,
    P_POOLID,
    P_JAILID,
    P_CTID,
    P_CPUID,
    P_PSETID
}
idtype_t;
