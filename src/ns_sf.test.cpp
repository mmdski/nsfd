#include <cstdlib>
#include <gtest/gtest.h>

extern "C" {
#include <nsfd.h>
}

namespace {
TEST(ns_fs, init) {
  ns_geom_data geom_data = {10, 5, 1, 1};
  size_t field_size = ns_sf_mem_size(&geom_data);
  auto* sfp = (ns_sf*)std::malloc(field_size);
  if (!sfp) {
    std::free(sfp);  // keep the linter from complaining
    ASSERT_TRUE(sfp);
  }
  real init_val = 0;
  sfp = ns_sf_init(&geom_data, sfp, init_val);
  if (!sfp) {
    std::free(sfp);
    ASSERT_TRUE(sfp);
  }

  std::free(sfp);
}
}  // namespace

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
