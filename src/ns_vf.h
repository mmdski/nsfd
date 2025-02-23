#ifndef NS_VF_H_
#define NS_VF_H_

#include <stddef.h>

#include <nsfd.h>

// vector field structure definition
struct ns_vf {
  size_t size;
  ns_d_shape shape;
  ns_vec field[];
};

#endif
