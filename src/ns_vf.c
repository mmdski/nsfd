#include "ns_vf.h"

#include <nsfd.h>

#include "ns_chk.h"
#include "ns_geom.h"

size_t ns_vf_mem_size(const ns_geom_data *data_p) {
  chk_null(data_p);
  return chk_size_t_add(sizeof(ns_vf),
                        chk_size_t_mul(sizeof(ns_vec), geom_size(data_p)));
}

ns_vf *ns_vf_init(const ns_geom_data *data_p, ns_vf *vfp, ns_vec init_val) {
  chk_null(data_p);
  chk_null(vfp);

  geom_data_copy(data_p, &(vfp->geom_data));

  size_t grid_size = geom_size(data_p);

  for (size_t i = 0; i < grid_size; ++i) {
    vfp->field[i] = init_val;
  }

  return vfp;
}

void ns_vf_geom_data(const ns_vf *vfp, ns_geom_data *data_p) {
  chk_null(vfp);
  chk_null(data_p);
  geom_data_copy(&(vfp->geom_data), data_p);
}

ns_vec *ns_vf_get(ns_vf *vfp, size_t i, size_t j) {
  chk_null(vfp);
  geom_chk_idx(&(vfp->geom_data), i, j);
  return &vfp->field[GEOM_IDX(vfp->geom_data, i, j)];
}

void ns_vf_values(const ns_vf *vfp, real *x_values, real *y_values) {
  chk_null(vfp);
  chk_null(x_values);
  chk_null(y_values);
  size_t grid_size = geom_size(&(vfp->geom_data));
  for (size_t i = 0; i < grid_size; ++i) {
    x_values[i] = vfp->field[i].x;
    y_values[i] = vfp->field[i].y;
  }
}
