#ifndef NSFD_H_
#define NSFD_H_

#include <stddef.h>

typedef double real;

size_t ns_real_mem_size(void);

// shape of internal domain
typedef struct {
  size_t imax;
  size_t jmax;
} ns_d_shape;

// shape of grid, including boundary cells
typedef struct {
  size_t nx;
  size_t ny;
} ns_g_shape;

// scalar field
typedef struct ns_sf ns_sf;

size_t ns_sf_mem_size(ns_d_shape shape);
ns_sf *ns_sf_init(ns_d_shape shape, ns_sf *sfp, real init_val);
ns_d_shape ns_sf_d_shape(const ns_sf *sfp);
ns_g_shape n_sf_g_shape(const ns_sf *sfp);
real *ns_sf_get(ns_sf *sfp, size_t i, size_t j);
void ns_sf_set(ns_sf *sfp, size_t i, size_t j, real value);
void ns_sf_values(const ns_sf *sfp, real *values);

typedef struct {
  real x;
  real y;
} ns_vec;

// vector field
typedef struct ns_vf ns_vf;

size_t ns_vf_mem_size(ns_d_shape shape);
ns_vf *ns_vf_init(ns_d_shape shape, ns_vf *vfp, ns_vec init_val);
ns_d_shape ns_fv_d_shape(const ns_vf *vfp);
ns_g_shape ns_fv_g_shape(const ns_vf *vfp);
ns_vec *ns_fv_get(ns_vf *vfp, size_t i, size_t j);
void ns_fv_set(ns_vf *vfp, size_t i, size_t j, real x, real y);
void ns_fv_values(const ns_vf *vfp, real *x_values, real *y_values);

#endif
