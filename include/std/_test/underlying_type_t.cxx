#include "std/is_same"
#include "std/underlying_type_t"

enum class Char : char {};
enum class Int  : int  {};
enum class Long : long {};

static_assert(std::is_same<std::underlying_type_t<Char>, char>(), "");
static_assert(std::is_same<std::underlying_type_t<Int >, int >(), "");
static_assert(std::is_same<std::underlying_type_t<Long>, long>(), "");
