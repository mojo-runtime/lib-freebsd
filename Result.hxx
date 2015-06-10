#pragma once

#define _E(rest) E##rest##_ = E##rest

namespace freebsd {

template <typename Ok, typename Error>
struct Result
{
    explicit
    operator
    bool() const noexcept
    {
        return this->__is_error;
    }

    Error
    error() const
    {
        return static_cast<Error>(this->__word);
    }

    Ok
    ok() const
    {
        return static_cast<Ok>(this->__word);
    }

    //----------------------------------------------------------------------------------------------

    decltype(sizeof(int))
    __word;

    decltype(sizeof(int))
    __is_error;
};

}
