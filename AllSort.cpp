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

void AllSort::QuickSort() {
  QuickIter(0, array_size_ -1);
}

void AllSort::MergeSort() {
  int* temp = new int[array_size_];
  MergeIter(0, array_size_ - 1, temp);
  delete [] temp;
}

void AllSort::SelectionSort() {
  for (int i = 0; i < array_size_ - 1; ++i) {
    int max_ind = i;
    for (int j = i + 1; j < array_size_; ++j) {
      if (array_[j] > array_[max_ind]) {
        max_ind  = j;
      }
    }
    if (max_ind != i) {
      Swap(i, max_ind);
    }
  }
}

void AllSort::ShellSort() {
  for (int gap = array_size_ / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < array_size_; ++i) {
      for (int j = i - gap; (j >= 0) && (array_[j] < array_[j + gap]); j -= gap) {
          Swap(j, j + gap);
      }
    }
  }
}

void AllSort::InsertionSort() {
	for (int i = 1; i < array_size_; ++i) {
		for (int j = i - 1; (j >= 0) && (array_[j] < array_[j + 1]); --j) {
			Swap(j, j + 1);
		}
	}
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

// Merge: array1 a[first] ~ a[mid]
//        array2 a[mid + 1] ~ a[last]
void AllSort::MergeArray(int first, int mid, int last, int temp[]) {
  int a1_start = first;
  int a2_start = mid + 1;
  int a1_end = mid;
  int a2_end = last;
  int i = a1_start;
  int j = a2_start;
  int k = 0;
  while (i <= a1_end && j <= a2_end) {
    if (array_[i] > array_[j]) {
      temp[k++] = array_[i++];
    } else {
      temp[k++] = array_[j++];
    }
  }
  while (i <= a1_end) {
    temp[k++] = array_[i++];
  }
  while (j <= a2_end) {
    temp[k++] = array_[j++];
  }

  for (int u = 0; u < k; ++u) {
    array_[first + u] = temp[u];
  }
}
void AllSort::MergeIter(int first, int last, int temp[]) {
  if (first < last) {
    int mid = (last + first) / 2;
    MergeIter(first, mid, temp);
    MergeIter(mid + 1, last, temp);
    MergeArray(first, mid, last, temp);
  }
}

// Quick sort iteration.
// Sort the elements from first to last.
void AllSort::QuickIter(int first, int last) {
  if (first < last) {
    int x = array_[first];
    int i = first + 1;
    int j = last;
    while (i < j) {
      while ((array_[i] > x) && (i <= last))
        ++i;
      while ((array_[j] < x) && (first <= j))
        --j;
      if (i < j) {
        Swap(i, j);
      }
    }
    if (first < j)
      Swap(first, j);
    QuickIter(first, j - 1);
    QuickIter(j + 1, last);
  }
}

} /* namespace algorithm */
