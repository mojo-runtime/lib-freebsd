#ifndef c_struct_user_desc_h_
#define c_struct_user_desc_h_

#if defined(__linux__) && defined(__x86_64__)
#  include "uint32_t.h"

struct user_desc
{
    uint32_t entry_number;
    uint32_t base_addr;
    uint32_t limit;
    uint32_t seg_32bit:1;
    uint32_t contents:2;
    uint32_t read_exec_only:1;
    uint32_t limit_in_pages:1;
    uint32_t seg_not_present:1;
    uint32_t useable:1;
    uint32_t lm:1;
    char __pad[3];
};

#else
#  error
#endif

#endif
