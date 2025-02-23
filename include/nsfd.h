#ifndef NSFD_H_
#define NSFD_H_

#include <stddef.h>

typedef double real;

size_t ns_real_mem_size(void);

// shape of internal domain
typedef struct {
  size_t imax;
  size_t jmax;
  real xlength;
  real ylength;
} ns_geom_data;

// scalar field
typedef struct ns_sf ns_sf;

size_t ns_sf_mem_size(const ns_geom_data *data_p);
ns_sf *ns_sf_init(ns_geom_data *data_p, ns_sf *sfp, real init_val);
void ns_sf_geom_data(const ns_sf *sfp, ns_geom_data *data_p);
real *ns_sf_get(ns_sf *sfp, size_t i, size_t j);
void ns_sf_values(const ns_sf *sfp, real *values);

typedef struct {
  real x;
  real y;
} ns_vec;

// vector field
typedef struct ns_vf ns_vf;

size_t ns_vf_mem_size(const ns_geom_data *data_p);
ns_vf *ns_vf_init(const ns_geom_data *data_p, ns_vf *vfp, ns_vec init_val);
ns_geom_data ns_vf_d_shape(const ns_vf *vfp);
ns_vec *ns_vf_get(ns_vf *vfp, size_t i, size_t j);
void ns_vf_values(const ns_vf *vfp, real *x_values, real *y_values);

#endif
