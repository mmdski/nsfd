#ifndef NSFD_INTERNAL_H_
#define NSFD_INTERNAL_H_

#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <nsfd.h>

// scalar field structure definition
struct ns_sf {
  size_t size;
  ns_d_shape shape;
  real field[];
};

// vector field structure definition
struct ns_vf {
  size_t size;
  ns_d_shape shape;
  ns_vec field[];
};

static inline void chk_null(const void* ptr) { assert(ptr); }

static inline size_t chk_size_t_add(size_t a, size_t b) {
  if (SIZE_MAX - a < b) {
    fprintf(stderr, "size_t addition of %zu and %zu will cause unsigned wrap\n",
            a, b);
    exit(EXIT_FAILURE);
  }
  return a + b;
}

static inline size_t chk_size_t_mul(size_t a, size_t b) {
  if (!a || !b) return 0;  // return if a or b are equal to zero
  if (a > SIZE_MAX / b) {
    fprintf(stderr,
            "size_t multiplication of %zu and %zu will cause unsigned wrap\n",
            a, b);
    exit(EXIT_FAILURE);
  }
  return a * b;
}

static inline void chk_indices(ns_d_shape shape, size_t i, size_t j) {
  assert(i < shape.imax + 2);
  assert(j < shape.jmax + 2);
}

static inline size_t calc_grid_size(ns_d_shape shape) {
  return chk_size_t_mul(chk_size_t_add(shape.imax, 2),
                        chk_size_t_add(shape.jmax, 2));
}

#endif
