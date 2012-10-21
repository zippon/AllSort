/*
 * AllSort.h
 *
 *  Created on: Oct 21, 2012
 *      Author: parallels
 */

#ifndef ALLSORT_H_
#define ALLSORT_H_

#include <gflags/gflags.h>
#include <glog/logging.h>

namespace algorithm {

class AllSort {
public:
  AllSort(int a[], int a_size) {
    // LOG(INFO) << "\nConstructed!\n";
    array_size_ = a_size;
    array_ = new int[a_size];
    for (int i = 0; i < a_size; ++i) {
      array_[i] = a[i];
    }
  }
  virtual ~AllSort() {
    delete [] array_;
    array_ = NULL;
    // LOG(INFO) << "\nDestructed!\n";
  }
  void Print() {
    for (int i = 0; i < array_size_; ++i) {
      LOG(INFO) << array_[i];
    }
    LOG(INFO) << "\n";
  }

  void BubbleSort();
  void HeapSort();

  int Get(int i) {
    CHECK_GE(i, 0);
    CHECK_LT(i, array_size_);
    return array_[i];
  }

private:
  void Swap(int i, int j);
  void Sift(int i, int length);
  int *array_;
  int array_size_;

  // Disallow evil constructions.
  AllSort(AllSort&);
  void operator= (AllSort&);
};

} /* namespace algorithm */
#endif /* ALLSORT_H_ */
