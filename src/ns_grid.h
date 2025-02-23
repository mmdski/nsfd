#ifndef NS_GRID_H_
#define NS_GRID_H_

#include <stddef.h>

#include <nsfd.h>

#include "ns_chk.h"

static inline size_t grid_calc_size(ns_d_shape shape) {
  return chk_size_t_mul(chk_size_t_add(shape.imax, 2),
                        chk_size_t_add(shape.jmax, 2));
}

#endif
