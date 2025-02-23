#include <cstdlib>
#include <gtest/gtest.h>

extern "C" {
#include <nsfd.h>
}

namespace {
TEST(ns_fv, init) {
  ns_geom_data geom_data = {10, 5, 1, 1};
  size_t field_size = ns_vf_mem_size(&geom_data);
  auto* vfp = (ns_vf*)std::malloc(field_size);
  if (!vfp) {
    std::free(vfp);  // keep the linter from complaining
    ASSERT_TRUE(vfp);
  }
  ns_vec init_val = {.x = 0, .y = 1};
  vfp = ns_vf_init(&geom_data, vfp, init_val);
  if (!vfp) {
    std::free(vfp);
    ASSERT_TRUE(vfp);
  }

  std::free(vfp);
}
}  // namespace

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
