#include "../headers/list_cpp.h"

TEST(List_test, init) {
  List<int> l;
  l.push_back(12);
  l.push_back(13);
  EXPECT_EQ(l.size(), 2);
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}