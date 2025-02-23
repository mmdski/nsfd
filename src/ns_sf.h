#ifndef NS_SF_H_
#define NS_SF_H_

#include <stddef.h>

#include <nsfd.h>

// scalar field structure definition
struct ns_sf {
  size_t size;
  ns_d_shape shape;
  real field[];
};

#endif
