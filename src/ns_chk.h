#ifndef NS_CHK_H_
#define NS_CHK_H_

#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include <nsfd.h>

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

#endif
