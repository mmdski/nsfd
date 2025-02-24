#include <cstdlib>
#include <gtest/gtest.h>

extern "C" {
#include <nsfd.h>
}

namespace {
TEST(ns_state, init) {
  ns_geom_data geom_data = {10, 5, 1, 1};
  size_t state_size = ns_state_mem_size(&geom_data);
  auto* sp = (ns_state*)std::malloc(state_size);
  if (!sp) {
    std::free(sp);  // keep the linter from complaining
    ASSERT_TRUE(sp);
  }
  real pi = 0;
  ns_vec ui = {1, 1};
  sp = ns_state_init(&geom_data, sp, pi, ui);
  if (!sp) {
    std::free(sp);
    ASSERT_TRUE(sp);
  }

  std::free(sp);
}
}  // namespace

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
