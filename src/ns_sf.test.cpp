#include <cstdlib>
#include <gtest/gtest.h>

extern "C" {
#include <nsfd.h>
}

namespace {
TEST(ns_fs, init) {
  ns_d_shape shape = {10, 5};
  size_t field_size = ns_sf_mem_size(shape);
  auto* sfp = (ns_sf*)std::malloc(field_size);
  if (!sfp) {
    std::free(sfp);  // keep the linter from complaining
    ASSERT_TRUE(sfp);
  }
  real init_val = 0;
  sfp = ns_sf_init(shape, sfp, init_val);
  if (!sfp) {
    std::free(sfp);
    ASSERT_TRUE(sfp);
  }

  ns_d_shape field_shape = ns_sf_d_shape(sfp);
  ASSERT_EQ(shape.imax, field_shape.imax);
  ASSERT_EQ(shape.jmax, field_shape.jmax);

  for (size_t i = 1; i <= shape.imax; ++i) {
    for (size_t j = 1; j <= shape.jmax; ++j) {
      ASSERT_EQ(init_val, *ns_sf_get(sfp, i, j));
    }
  }

  std::free(sfp);
}
}  // namespace

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
