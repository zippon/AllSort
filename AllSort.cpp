/*
 * AllSort.cpp
 *
 *  Created on: Oct 21, 2012
 *      Author: parallels
 */

#include "AllSort.h"

namespace algorithm {

void AllSort::Swap(int i, int j) {
  CHECK_LT(i, array_size_);
  CHECK_LT(j, array_size_);
  int temp = array_[i];
  array_[i] = array_[j];
  array_[j] = temp;
}

void AllSort::BubbleSort() {
  int flag = array_size_ - 1;
  for (int i = 0; i < array_size_; ++i) {
    int stop = flag;
    flag = 0;
    for (int j = 0; j < stop; ++j) {
      if (array_[j] < array_[j + 1]) {
        Swap(j, j + 1);
        flag = j;
      }
    }
    if (0 == flag)  break;
  }
}

void AllSort::HeapSort() {
  for (int i = array_size_/2 - 1; i >= 0; --i) {
    Sift(i, array_size_);
  }
  for (int j = array_size_ - 1; j >= 0; --j) {
    Swap(0, j);
    Sift(0, j - 1);
  }
}

// Sift the i-th item in the heap.
void AllSort::Sift(int i, int length) {
  // CHECK_LT(i, length);
  int l_child = i * 2 + 1;
  int r_child = l_child + 1;
  int position = i;
  // Create a max-heap.
  if ((l_child < length) && (array_[i] > array_[l_child])) {
    position = l_child;
  }
  if ((r_child < length) && (array_[position] > array_[r_child])) {
    position = r_child;
  }
  if (position != i) {
    Swap(i, position);
    Sift(position, length);
  }
}

} /* namespace algorithm */
