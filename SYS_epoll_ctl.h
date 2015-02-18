#ifndef c_SYS_epoll_ctl_h_
#define c_SYS_epoll_ctl_h_

#include "c/SystemCallNumber.h"

__c_namespace_open

static
const SystemCallNumber
SYS_epoll_ctl =
#if defined(__linux__) && defined(__x86_64__)
 233
#else
#  error
#endif
 ;

__c_namespace_close

#endif
