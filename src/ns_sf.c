#include "ns_sf.h"

#include <assert.h>
#include <stdio.h>

#include <nsfd.h>

#include "ns_chk.h"
#include "ns_geom.h"

size_t ns_sf_mem_size(const ns_geom_data *data_p) {
  chk_null(data_p);
  return chk_size_t_add(sizeof(ns_sf),
                        chk_size_t_mul(sizeof(real), geom_size(data_p)));
}

ns_sf *ns_sf_init(const ns_geom_data *data_p, ns_sf *sfp, real init_val) {
  chk_null(data_p);
  chk_null(sfp);
  size_t grid_size = geom_size(data_p);
  for (size_t i = 0; i < grid_size; ++i) {
    sfp->field[i] = init_val;
  }
  return sfp;
}

void ns_sf_geom_data(const ns_sf *sfp, ns_geom_data *data_p) {
  chk_null(sfp);
  chk_null(data_p);
  geom_data_copy(&(sfp->geom_data), data_p);
}

real *ns_sf_get(ns_sf *sfp, size_t i, size_t j) {
  chk_null(sfp);
  geom_chk_idx(&(sfp->geom_data), i, j);
  return &sfp->field[GEOM_IDX(sfp->geom_data, i, j)];
}

void ns_sf_values(const ns_sf *sfp, real *values) {
  if (!values) return;
  size_t grid_size = geom_size(&(sfp->geom_data));
  for (size_t i = 0; i < grid_size; ++i) {
    values[i] = sfp->field[i];
  }
}
