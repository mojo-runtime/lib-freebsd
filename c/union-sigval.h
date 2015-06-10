#pragma once

union sigval
{
    int
    sival_int;

    void*
    sival_ptr;

    int
    sigval_int;

    void*
    sigval_ptr;
};
