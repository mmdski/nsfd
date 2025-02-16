#include <cstdlib>
#include <gtest/gtest.h>

extern "C" {
#include <nsfd.h>
}

namespace {
TEST(ns_fv, init) {
  ns_d_shape shape = {10, 5};
  size_t field_size = ns_vf_mem_size(shape);
  auto* vfp = (ns_fv*)std::malloc(field_size);
  if (!vfp) {
    std::free(vfp);  // keep the linter from complaining
    ASSERT_TRUE(vfp);
  }
  ns_vec init_val = {.x = 0, .y = 1};
  vfp = ns_vf_init(shape, vfp, init_val);
  if (!vfp) {
    std::free(vfp);
    ASSERT_TRUE(vfp);
  }

  ns_d_shape field_shape = ns_fv_d_shape(vfp);
  ASSERT_EQ(shape.imax, field_shape.imax);
  ASSERT_EQ(shape.jmax, field_shape.jmax);

  for (size_t i = 1; i <= shape.imax; ++i) {
    for (size_t j = 1; j <= shape.jmax; ++j) {
      ASSERT_EQ(init_val.x, ns_fv_get(vfp, i, j)->x);
      ASSERT_EQ(init_val.y, ns_fv_get(vfp, i, j)->y);
    }
  }

  std::free(vfp);
}
}  // namespace

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
