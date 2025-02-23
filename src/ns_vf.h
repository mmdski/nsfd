#ifndef NS_VF_H_
#define NS_VF_H_

#include <stddef.h>

#include <nsfd.h>

// vector field structure definition
struct ns_vf {
  ns_geom_data geom_data;
  ns_vec field[];
};

#endif
