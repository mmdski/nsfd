#include <assert.h>
#include <stdio.h>

#include <nsfd.h>

#include "nsfd_internal.h"

size_t ns_sf_mem_size(ns_d_shape shape) {
  return chk_size_t_add(sizeof(ns_sf),
                        chk_size_t_mul(sizeof(real), calc_grid_size(shape)));
}

ns_sf *ns_sf_init(ns_d_shape shape, ns_sf *sfp, real init_val) {
  if (shape.imax == 0 || shape.jmax == 0) return sfp;
  if (!sfp) return sfp;
  sfp->shape = shape;
  sfp->size = calc_grid_size(sfp->shape);
  for (size_t i = 0; i < sfp->size; ++i) {
    sfp->field[i] = init_val;
  }
  return sfp;
}

ns_d_shape ns_sf_d_shape(const ns_sf *sfp) {
  if (!sfp) return (ns_d_shape){0};
  return sfp->shape;
}

ns_g_shape n_sf_g_shape(const ns_sf *sfp) {
  if (!sfp) return (ns_g_shape){0};
  return (ns_g_shape){sfp->shape.imax + 2, sfp->shape.jmax + 2};
}

real *ns_sf_get(ns_sf *sfp, size_t i, size_t j) {
  if (!sfp) return NULL;
  chk_indices(sfp->shape, i, j);
  return &sfp->field[i * (sfp->shape.jmax + 2) + j];
}

void ns_sf_set(ns_sf *sfp, size_t i, size_t j, real value) {
  if (!sfp) return;
  chk_indices(sfp->shape, i, j);
  sfp->field[i * (sfp->shape.jmax + 2) + j] = value;
}

void ns_sf_values(const ns_sf *sfp, real *values) {
  if (!values) return;
  for (size_t i = 0; i < sfp->size; ++i) {
    values[i] = sfp->field[i];
  }
}
