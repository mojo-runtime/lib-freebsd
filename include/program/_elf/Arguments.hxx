#pragma once

#include "c/__Byte.h"
#include "c/__Word.h"

namespace program { inline namespace _elf_ {

struct Arguments
{
    //----------------------------------------------------------------------------------------------

    __Word
    __argc;

    __Byte*
    __argv[1]; // At least 1 - NULL terminated
};

}}