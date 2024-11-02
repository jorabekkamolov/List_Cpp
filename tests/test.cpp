#include "../headers/list_cpp.h"

TEST(List_test, init) {
  List<int> l;
  l.push_back(12);
  l.push_back(13);
  EXPECT_EQ(l.size(), 2);
}

TEST(List_test, iterators) {
  List<int> l = {1, 2, 3, 4, 5};
  List<int>::iterator it = l.begin();
  ++it;
  EXPECT_EQ(*it, 2);
}

TEST(List_test, insert1) {
  List<int> l = {1, 2, 3, 4};
  auto it = l.begin();
  it = l.insert(it, 12);

  EXPECT_EQ(*it, 12);
}

TEST(List_test, insert2) {
  List<int> l = {1};
  auto it = l.begin();
  it = l.insert(it, 12);

  EXPECT_EQ(*it, 12);
}

TEST(List_test, insert3) {
  List<int> l = {1, 2, 3, 4};
  auto it = l.begin();
  ++it;
  ++it;
  it = l.insert(it, 12);
  EXPECT_EQ(*it, 12);
}

TEST(List_test, insert4) {
  List<int> l;
  auto it = l.begin();
  it = l.insert(it, 12);
  EXPECT_EQ(*it, 12);
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}