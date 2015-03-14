#ifndef __syscall2

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreserved-id-macro"

#if defined(__linux__) && defined(__x86_64__)
#  include "__Word.h"
#  define __syscall2(n, a1, a2)                                         \
  _Pragma("clang diagnostic push")                                      \
  _Pragma("clang diagnostic ignored \"-Wgnu-statement-expression\"")    \
    ({                                                                  \
        __Word                                                          \
        result;                                                         \
                                                                        \
        register decltype(a1) r1 asm ("rdi") = a1;                      \
        register decltype(a2) r2 asm ("rsi") = a2;                      \
                                                                        \
        asm volatile (                                                  \
            "syscall"                                                   \
            : "=a" (result)                                             \
            : "0" (n), "r" (r1), "r" (r2)                               \
            : "rcx", "r11"                                              \
        );                                                              \
                                                                        \
        result;                                                         \
    })                                                                  \
  _Pragma("clang diagnostic pop")
#else
#  error
#endif

#pragma clang diagnostic pop

#endif