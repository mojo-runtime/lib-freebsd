#include "std/is_pointer"

static_assert( std::is_pointer<char*>(), "");
static_assert( std::is_pointer<const char*>(), "");
static_assert(!std::is_pointer<int>(), "");
