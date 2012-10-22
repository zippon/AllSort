/*
 * AllSort_test.cpp
 *
 *  Created on: Oct 21, 2012
 *      Author: parallels
 */

#include "AllSort.h"
//#include <boost/scoped_ptr.hpp>
#include <gtest/gtest.h>

namespace algorithm {

class AllSortTest : public testing::Test {
protected:
  virtual void SetUp() {
    int a[] = { 11, 23, 21, 67, 9, 43, 1, 67, 98, 20, 29, 78, 31, 10, 5, 81, 12 };
    sort = new AllSort(a, 17);
  }
  void AllSortTester() {
    ASSERT_EQ(sort->Get(0), 98);
    ASSERT_EQ(sort->Get(1), 81);
    ASSERT_EQ(sort->Get(2), 78);
    ASSERT_EQ(sort->Get(3), 67);
    ASSERT_EQ(sort->Get(4), 67);
    ASSERT_EQ(sort->Get(5), 43);
    ASSERT_EQ(sort->Get(6), 31);
    ASSERT_EQ(sort->Get(7), 29);
    ASSERT_EQ(sort->Get(8), 23);
    ASSERT_EQ(sort->Get(9), 21);
    ASSERT_EQ(sort->Get(10), 20);
    ASSERT_EQ(sort->Get(11), 12);
    ASSERT_EQ(sort->Get(12), 11);
    ASSERT_EQ(sort->Get(13), 10);
    ASSERT_EQ(sort->Get(14), 9);
    ASSERT_EQ(sort->Get(15), 5);
    ASSERT_EQ(sort->Get(16), 1);
  }
  virtual void TearDown() {
    delete sort;
  }
  AllSort* sort;
};

TEST_F(AllSortTest, QuickSortTest) {
  sort->QuickSort();
  AllSortTester();
}
TEST_F(AllSortTest, MergeSortTest) {
  sort->MergeSort();
  AllSortTester();
}
TEST_F(AllSortTest, SelectionSortTest) {
  sort->SelectionSort();
  AllSortTester();
}
TEST_F(AllSortTest, ShellSortTest) {
  // LOG(INFO) << "\nShellSortTest\n";
  sort->ShellSort();
  AllSortTester();
}
TEST_F(AllSortTest, InsertionSoetTest) {
	// LOG(INFO) << "\nInsertionTest\n";
	sort->InsertionSort();
	AllSortTester();
}
TEST_F(AllSortTest, BubbleSortTest) {
  // LOG(INFO) << "\nBubbleSortTest\n";
  sort->BubbleSort();
  AllSortTester();
}

TEST_F(AllSortTest, HeapSortTest) {
  // LOG(INFO) << "\nHeapSortTest\n";
  // sort->Print();
  sort->HeapSort();
  AllSortTester();
}

} /* namespace algorithm */

int main(int argc, char** argv) {
  google::ParseCommandLineFlags(&argc, &argv, true);
  google::InitGoogleLogging(argv[0]);
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
