#pragma once

#include "cc_t.h"
#include "speed_t.h"
#include "tcflag_t.h"

#define NCCS 20

struct termios
{
    tcflag_t
    c_iflag;

    tcflag_t
    c_oflag;

    tcflag_t
    c_cflag;

    tcflag_t
    c_lflag;

    cc_t
    c_cc[NCCS];

    speed_t
    c_ispeed;

    speed_t
    c_ospeed;
};
