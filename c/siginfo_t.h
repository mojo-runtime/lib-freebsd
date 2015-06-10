#pragma once

#include "pid_t.h"
#include "uid_t.h"
#include "union-sigval.h"

typedef struct
{
    int
    si_code;

    pid_t
    si_pid;

    uid_t
    si_uid;

    int
    si_status;

    void*
    si_addr;

    union sigval
    si_value;

    union
    {
        struct
        {
            int
            _trapno;
        }
        _fault;

        struct
        {
            int
            _timerid;

            int
            _overrun;
        }
        _timer;

        struct
        {
            int
            _mqd;
        }
        _mesgq;

        struct
        {
            long
            _band;
        }
        _poll;

        struct
        {
            long
            __spare1__;

            int
            __spare2__[7];
        }
        __spare__;
    }
    _reason;
}
siginfo_t;

#define si_trapno  _reason._fault._trapno
#define si_timerid _reason._timer._timerid
#define si_overrun _reason._timer._overrun
#define si_mqd     _reason._mesgq._mqd
#define si_band    _reason._poll._band
