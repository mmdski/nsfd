#include "ns_vf.h"

#include <nsfd.h>

#include "ns_chk.h"
#include "ns_grid.h"

size_t ns_vf_mem_size(ns_d_shape shape) {
  return chk_size_t_add(sizeof(ns_vf),
                        chk_size_t_mul(sizeof(ns_vec), grid_calc_size(shape)));
}

ns_vf *ns_vf_init(ns_d_shape shape, ns_vf *vfp, ns_vec init_val) {
  if (shape.imax == 0 || shape.jmax == 0) return vfp;
  if (!vfp) return vfp;
  vfp->shape = shape;
  vfp->size = grid_calc_size(vfp->shape);
  for (size_t i = 0; i < vfp->size; ++i) {
    vfp->field[i] = init_val;
  }

  return vfp;
}

ns_d_shape ns_vf_d_shape(const ns_vf *vfp) {
  if (!vfp) return (ns_d_shape){0};
  return vfp->shape;
}

ns_g_shape ns_vf_g_shape(const ns_vf *vfp) {
  if (!vfp) return (ns_g_shape){0};
  return (ns_g_shape){vfp->shape.imax + 2, vfp->shape.jmax + 2};
}

ns_vec *ns_vf_get(ns_vf *vfp, size_t i, size_t j) {
  if (!vfp) return NULL;
  chk_indices(vfp->shape, i, j);
  return &vfp->field[i * (vfp->shape.jmax + 2) + j];
}

void ns_vf_set(ns_vf *vfp, size_t i, size_t j, real x, real y) {
  if (!vfp) return;
  chk_indices(vfp->shape, i, j);
  vfp->field[i * (vfp->shape.jmax + 2) + j].x = x;
  vfp->field[i * (vfp->shape.jmax + 2) + j].y = y;
}

void ns_vf_values(const ns_vf *vfp, real *x_values, real *y_values) {
  if (!(x_values && y_values)) return;
  for (size_t i = 0; i < vfp->size; ++i) {
    x_values[i] = vfp->field[i].x;
    y_values[i] = vfp->field[i].y;
  }
}
