#ifndef NS_GRID_H_
#define NS_GRID_H_

#include <stddef.h>

#include <nsfd.h>

#include "ns_chk.h"

#define GEOM_IDX(geom_data, i, j) (i * (geom_data.jmax + 2) + j)

static inline size_t geom_size(const ns_geom_data *data_p) {
  return chk_size_t_mul(chk_size_t_add(data_p->imax, 2),
                        chk_size_t_add(data_p->jmax, 2));
}

static inline void geom_data_copy(const ns_geom_data *from_p,
                                  ns_geom_data *to_p) {
  to_p->imax = from_p->imax;
  to_p->jmax = from_p->jmax;
  to_p->xlength = from_p->xlength;
  to_p->ylength = from_p->ylength;
}

static inline void geom_chk_idx(const ns_geom_data *data_p, size_t i,
                                size_t j) {
  chk_null(data_p);
  assert(i < data_p->imax + 2);
  assert(j < data_p->jmax + 2);
}

#endif
