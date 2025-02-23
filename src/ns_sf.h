#ifndef NS_SF_H_
#define NS_SF_H_

#include <stddef.h>

#include <nsfd.h>

// scalar field structure definition
struct ns_sf {
  ns_geom_data geom_data;
  real field[];
};

#endif
