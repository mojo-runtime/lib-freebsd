#ifndef c_size_t_h_
#define c_size_t_h_

typedef
#ifdef __SIZE_TYPE__
__SIZE_TYPE__
#else
#  error
#endif
size_t;

#endif