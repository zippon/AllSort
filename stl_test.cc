/*
 * stl_test.cc
 *
 *  Created on: Nov 6, 2012
 *      Author: parallels
 */

// Demonstration of the usage of STL.
// pair
// vector []
// list : no [], but has iterator.
// deque []
// stack : cannot traverse. (pop, push, top)
// queue : cannot traverse. (pop, push, front)
// priority_queue : cannot traverse. (pop, push, top)
// bitset []
// set : no [], but has iterator.
// multiset
// map []
// multimap []
// hash_map []
// hash_multimap []
// hash_set
// hash_multiset


// Some Std operator classes:
// T can be int, double, float, bool, string... which supports operator =
//
// divides<T>
// equal_to<T>
// greater<T>
// greator_equal<T>
// less<T>
// less_equal<T>
// minus<T>
// plus<T>
// multiplies<T>
// modulus<T>
// negate<T>
// not_equal_to<T>

#include <gtest/gtest.h>
#include <glog/logging.h>
#include <gflags/gflags.h>
#include <string>

using std::string;

class StlTest : public testing::Test {
public:
  virtual void SetUp() {
    for (int i = 0; i < 12; ++i) {
      int_array_[i] = (i + 10) % 13;
    }
    str_array_[0] = "Jan";
    str_array_[1] = "Feb";
    str_array_[2] = "Mar";
    str_array_[3] = "Apr";
    str_array_[4] = "May";
    str_array_[5] = "June";
    str_array_[6] = "July";
    str_array_[7] = "Aug";
    str_array_[8] = "Sep";
    str_array_[9] = "Oct";
    str_array_[10] = "Nov";
    str_array_[11] = "Dec";
  }
  int int_array_[12];
  string str_array_[12];
};

/**********************************************************************************************/
// Test for pair.

#include <utility>
using std::pair;

TEST_F(StlTest, PairTest) {
  pair<int, string> p0 (int_array_[0], str_array_[0]);
  LOG(INFO) << "p0.first: " << p0.first << "\tp0.second: " << p0.second << "\n";
  pair<int, string> p1;
  p1 = make_pair (int_array_[1], str_array_[1]);
  LOG(INFO) << "p1.first: " << p1.first << "\tp1.second: " << p1.second << "\n";
}
/**********************************************************************************************/


/**********************************************************************************************/
// Test for vector.

#include <vector>
#include <algorithm>
using std::vector;
using std::sort;
using std::find;
using std::remove;

struct StrCmp {
  bool operator() (const string& s1, const string& s2) {
    return strcmp(s1.c_str(), s2.c_str()) > 0;
  }
} my_cmp;

TEST_F(StlTest, VectorTest) {
  vector<int> v1 (int_array_, int_array_ + sizeof(int_array_) / sizeof(int));
  LOG(INFO) << "\n\nv1...\n";
  for (int i = 0; i < v1.size(); ++i) {
    LOG(INFO) << v1[i];
  }
  vector<int> v2 (v1);
  LOG(INFO) << "\n\nv2...\n";
  for (int i = 0; i < v2.size(); ++i) {
    LOG(INFO) << v2[i];
  }
  // Take care! How to remove in vector.
  LOG(INFO) << "remove(v2.begin(), v2.end(), 10)";
  remove(v2.begin(), v2.end(), 10);
  for (int i = 0; i < v2.size(); ++i) {
    LOG(INFO) << v2[i];
  }
  LOG(INFO) << "v2.size()" << v2.size();
  LOG(INFO) << "v2.erase(remove(v2.begin(), v2.end(), 10), v2.end())";
  v1.erase(remove(v1.begin(), v1.end(), 10), v1.end());
  for (int i = 0; i < v1.size(); ++i) {
    LOG(INFO) << v1[i];
  }
  LOG(INFO) << "v1.size()" << v1.size();
  vector<int> v3 (12, 100);
  LOG(INFO) << "\n\nv3...\n";
  for (int i = 0; i < v3.size(); ++i) {
    LOG(INFO) << v3[i];
  }
  vector<string> v4;
  for (int i = 0; i < 12; ++i) {
    v4.push_back(str_array_[i]);
  }
  vector<string>::iterator it;
  LOG(INFO) << "\n\nv4...\n";
  for (it = v4.begin(); it != v4.end(); ++it) {
    LOG(INFO) << *it;
  }
  vector<string>::reverse_iterator rit;
  for (rit = v4.rbegin(); rit != v4.rend(); ++rit) {
    LOG(INFO) << *rit;
  }
  LOG(INFO) << "v4.front(): " << v4.front();
  LOG(INFO) << "v4.back(): " << v4.back();
  LOG(INFO) << "v4.at(0): " << v4.at(0);
  LOG(INFO) << "v4.at(11): " << v4.at(11);
  v1.clear();
  LOG(INFO) << "v1.clear() -----> v1.size(): " <<v1.size();
  LOG(INFO) << "v1.empty(): " <<v1.empty();
  v4.erase(v4.begin() + 1);
  LOG(INFO) << "v4.erase(v4.begin() + 1)";
  for (it = v4.begin(); it != v4.end(); ++it) {
    LOG(INFO) << *it;
  }
  v4.insert(v4.begin() + 1, "Feb");
  LOG(INFO) << "v4.inser(v4.begin() + 1, \"Feb\")";
  for (it = v4.begin(); it != v4.end(); ++it) {
    LOG(INFO) << *it;
  }
  vector<int>::iterator ii;
  v2.resize(5);
  LOG(INFO) << "v2.resize(5)";
  for (ii = v2.begin(); ii != v2.end(); ++ii) {
    LOG(INFO) << *ii;
  }
  LOG(INFO) << "v2.resize(10, 200); v2.resize(20)";
  v2.resize(10, 200);
  v2.resize(20);
  for (ii = v2.begin(); ii != v2.end(); ++ii) {
    LOG(INFO) << *ii;
  }
  // There is no sort function for vector.
  LOG(INFO) << "sort(v4.begin(), v4.end())";
  sort(v4.begin(), v4.end(), my_cmp);
  for (it = v4.begin(); it != v4.end(); ++it) {
    LOG(INFO) << *it;
  }
  LOG(INFO) << "v4.pop_back()";
  v4.pop_back();
  for (it = v4.begin(); it != v4.end(); ++it) {
    LOG(INFO) << *it;
  }
}
/**********************************************************************************************/


/**********************************************************************************************/
// Test for list.

#include <list>
using std::list;

// Comparing with vector, list allow fast insertion/deletion, but randomly access in slow.
// If you want to insert/remove, you do not need to erase and move the data (as in vector),
// what you need to do is only change the pointers.
// Since the elements are not stored sequentially in the memory. list do not provide [] operator.

TEST_F(StlTest, ListTest) {
  list<string> list1 (10, "hello");
  list<string>::iterator it;
  for (it = list1.begin(); it != list1.end(); ++it) {
    LOG(INFO) << *it;
  }
  LOG(INFO) << "list1.resize(20, \"world\")";
  list1.resize(20, "world");
  for (it = list1.begin(); it != list1.end(); ++it) {
    LOG(INFO) << *it;
  }
  // Assign is different from resize (dropping all the elements contained in the container object)!
  LOG(INFO) << "list1.assign(5, \"assign\")";
  list1.assign(5, "assign");
  for (it = list1.begin(); it != list1.end(); ++it) {
    LOG(INFO) << *it;
  }
  LOG(INFO) << "list1.assign(str_array_, str_array_ + 12)";
  list1.assign(str_array_, str_array_ + 12);
  for (it = list1.begin(); it != list1.end(); ++it) {
    LOG(INFO) << *it;
  }

  list1.push_back("push_back");
  list1.push_front("push_front");
  LOG(INFO) << list1.front();
  LOG(INFO) << list1.back();
  list1.pop_back();
  list1.pop_front();
  LOG(INFO) << list1.front();
  LOG(INFO) << list1.back();
  list1.sort(my_cmp);
  LOG(INFO) << "list1.sort(my_cmp)";
  for (it = list1.begin(); it != list1.end(); ++it) {
    LOG(INFO) << *it;
  }
  LOG(INFO) << "list1.reverse()";
  list1.reverse();
  for (it = list1.begin(); it != list1.end(); ++it) {
    LOG(INFO) << *it;
  }
  list1.remove("Feb");
  it = list1.begin();
  list1.insert(it, "Feb");
  it = find(list1.begin(), list1.end(), "Aug");
  LOG(INFO) << "it = find(list1.befin(), list1.end(), \"Aug\")";
  LOG(INFO) << *it;
  LOG(INFO) << "list1.erase(list1.begin(), list1.end())";
  list1.erase(list1.begin(), list1.end());
  for (it = list1.begin(); it != list1.end(); ++it) {
    LOG(INFO) << *it;
  }
  LOG(INFO) << "list1.size()" << list1.size();
}
/**********************************************************************************************/


/**********************************************************************************************/
// Test for deque.

// Deque is very like vector. The only difference is is that deque provides the accesses to its double
// ends. In other words, the following two functions:
// pop_front();
// push_front();
// For randomly access (using operator[] or at()), the efficiency of vector is slightly better tha deque.

#include <deque>
using std::deque;

TEST_F (StlTest, DequeTest) {
  deque<int> d1 (int_array_, int_array_ + sizeof(int_array_) / sizeof(int));
  deque<string> d2 (str_array_, str_array_ + 12);
  d2.pop_front();
  LOG(INFO) << "d2.pop_front()";
  deque<string>::iterator it;
  for(it = d2.begin(); it != d2.end(); ++it) {
    LOG(INFO) << *it;
  }
  d2.push_front("Push");
  LOG(INFO) << "d2.push_front()";
  for(it = d2.begin(); it != d2.end(); ++it) {
    LOG(INFO) << *it;
  }
  deque<int>::iterator ii;
  ii = find(d1.begin(), d1.end(), 12);
  LOG(INFO) << (ii != d1.end());
  sort(d2.begin(), d2.end(), my_cmp);
  for(it = d2.begin(); it != d2.end(); ++it) {
    LOG(INFO) << *it;
  }
}

/**********************************************************************************************/


/**********************************************************************************************/
// Test for Stack.

#include<stack>
using std::stack;

// For stack and queue, there is no iterator and begin()/end().
// If you want to sort, traverse, and find ----- impossible...
// The constructor for stack looks like "stack<int>" or "stack<int, vector<int>". See below:
// template < class T, class Container = deque<T> > class stack;
TEST_F (StlTest, StackTest) {
  stack<int> s1;
  for (int i = 0; i < 10; ++i) {
    s1.push(int_array_[i]);
  }
  while (!s1.empty()) {
    LOG(INFO) << s1.top();
    s1.pop();
  }
  LOG(INFO) << "si.size(): " << s1.size();
}


/**********************************************************************************************/


/**********************************************************************************************/
// Test for queue.

#include <queue>
using std::queue;

TEST_F (StlTest, QueueTest) {
  queue<int> q1;
  for(int i = 0; i < 12; ++i) {
    q1.push(i);
  }
  LOG(INFO) << "q1.front(): " << q1.front();
  LOG(INFO) << "q1.back(): " << q1.back();
  while (!q1.empty()) {
    LOG(INFO) << q1.front();
    q1.pop();
  }
  LOG(INFO) << "q1.size(): " << q1.size();
}
/**********************************************************************************************/


/**********************************************************************************************/
// Test for Priority_queue.
// #include <queue>
using std::priority_queue;

// Constructor:
// template < class T, class Container = vector<T>, class Compare = less<typename Container::value_type> > class priority_queue;

// You can not traverse priority_queue. No begin(), end(), and iterator.

// For constructing priority_queue, set, and map, not like in the sort function or list.sort(my_cmp),
// we cannot provide an instance of StrCmp, but to provide the class type directly when we are constructing it.
TEST_F (StlTest, PriorityQueueTest) {
  priority_queue<string, vector<string>, StrCmp> p1 (str_array_, str_array_ + 12);
  priority_queue<int, vector<int>, std::greater<int> > p2 (int_array_, int_array_ + sizeof(int_array_) / sizeof(int));
  LOG(INFO) << p1.size();
  while (!p1.empty()) {
    LOG(INFO) << p1.top();
    p1.pop();
  }
}

/**********************************************************************************************/


/**********************************************************************************************/
// Test for bitset.

#include <bitset>
using std::bitset;

TEST_F (StlTest, BitsetTest) {
  bitset<10> bit1; // 0000000000
  bitset<6> bit2 (string("010101")); // 010101
  bitset<8> bit3 (255ul); // 11111111
  bitset<8> bit4 (0x0F); // 00001111
  LOG(INFO) << "bit1.to_string(): " << bit1.to_string();
  LOG(INFO) << "bit2.to_string(): " << bit2.to_string();
  LOG(INFO) << "bit3.to_string(): " << bit3.to_string();
  LOG(INFO) << "bit1.to_ulong(): " << bit1.to_ulong();
  LOG(INFO) << "bit2.to_ulong(): " << bit2.to_ulong();
  LOG(INFO) << "bit3.to_ulong(): " << bit3.to_ulong();
  LOG(INFO) << "bit2.count(): " << bit2.count();
  LOG(INFO) << "bit1.none(): " << bit1.none();
  // The sequence is from low (right) to high (left).
  for (int i = 0; i < bit2.size(); ++i) {
    LOG(INFO) << "bit2.[" << i << "]: " << bit2[i];
  }
  bit2.flip();
  LOG(INFO) << "bit2.flip()";
  for (int i = 0; i < bit2.size(); ++i) {
    LOG(INFO) << "bit2.[" << i << "]: " << bit2[i];
  }
  bit2.set(0);
  bit2.reset(1);
  // Unlike access operator ([]), function test performs a range check.
  LOG(INFO) << bit2.test(0);
  LOG(INFO) << bit2.test(1);
 }
/**********************************************************************************************/


/**********************************************************************************************/
// Test for set.

#include <set>
using std::set;

TEST_F (StlTest, SetTest) {
  set<int, std::greater<int> >s1 (int_array_, int_array_ + sizeof(int_array_) / sizeof(int));
  set<string, std::greater<string> > s2 (str_array_, str_array_ + 12);
  // set<string, StrCmp) s2 s2 (str_array_, str_array_ + 12);
  set<int> s3;
  set<string>::iterator it;
  for (it = s2.begin(); it != s2.end(); ++it) {
    LOG(INFO) << *it;
  }
  for (int i = 0; i < s1.size(); ++i) {
    s1.insert(10);
  }
  LOG(INFO) << "s1.count(10): " << s1.count(10);
  LOG(INFO) << "s1.count(13): " << s1.count(13);
  LOG(INFO) << "s1.erase(11)";
  LOG(INFO) << "ii = s1.find(12) ---- s1.erase(ii)";
  s1.erase(11);
  set<int>::iterator ii;
  ii = s1.find(12);
  s1.erase(ii);
  for (ii = s1.begin(); ii != s1.end(); ++ii) {
    LOG(INFO) << *ii;
  }
  pair<set<int>::iterator, bool > ret;
  ret = s1.insert(10);
  LOG(INFO) << "s1.insert(10): " << ret.second;
  ret = s1.insert(20);
  LOG(INFO) << "s1.insert(20): " << ret.second;
  LOG(INFO) << *ret.first;
  ii = s1.lower_bound(4);
  LOG(INFO) << "s1.lower_bound(4): " << *ii;
  set<int>::iterator ii2;
  ii2 = s1.lower_bound(8);
  LOG(INFO) << "s1.lower_bound(8): " << *ii2;
  s1.erase(ii2, ii);
  for (ii = s1.begin(); ii != s1.end(); ++ii) {
    LOG(INFO) << *ii;
  }
}
/**********************************************************************************************/


/**********************************************************************************************/
// Test for multiset.

#include <set>
using std::multiset;

TEST_F (StlTest, MultisetTest) {
  multiset<int, std::greater<int> > m1 (int_array_, int_array_ + sizeof(int_array_) / sizeof(int));
  multiset<string, std::less<string> > m2 (str_array_, str_array_ + 12);
  multiset<string, StrCmp> m3 (str_array_, str_array_ + 12);
  for (int i = 0; i < 5; ++i) {
    m1.insert(i);
  }
  multiset<int>::iterator it;
  for(it = m1.begin(); it != m1.end(); ++it) {
    LOG(INFO) << *it;
  }
  LOG(INFO) << "Before m1.erase(0)... size: " << m1.size();
  m1.erase(0);
  // This will erase all the "0" in this multiset.
  // Another way to do this is by first calling equal_range() [not find()],
  // and then erase.
  LOG(INFO) << "After... size: " << m1.size();
  it = m1.begin();
  m1.insert(it, 10);
  for(it = m1.begin(); it != m1.end(); ++it) {
    LOG(INFO) << *it;
  }
  m1.insert(10);
  it = m1.find(10);
  // This returns the first iterator pointing to "10".
  LOG(INFO) << "find(10)";
  for(; it != m1.end(); ++it) {
    LOG(INFO) << *it;
  }
  pair<multiset<int>::iterator, multiset<int>::iterator> ret;
  ret = m1.equal_range(10);
  LOG(INFO) << "equal_range(10)";
  for(it = ret.first; it != ret.second; ++it) {
    LOG(INFO) << *it;
  }
  multiset<int>::iterator i1, i2;
  i1 = m1.lower_bound(10);
  i2 = m1.upper_bound(10);
  LOG(INFO) << "i1 == ret.first: " << (i1 == ret.first);
  LOG(INFO) << "i2 == ret.second: " << (i2 == ret.second);

}
/**********************************************************************************************/


/**********************************************************************************************/
// Test for hash_set.

#include <ext/hash_set>
using __gnu_cxx::hash_set;

// Constructor.
// hash_set<Key, HashFcn, EqualKey, Alloc>

// For EqualKey, we can use "equal_to<T>", or the following:
// This struct equals to euqal_to<string>
struct StrEq {
  bool operator () (const string& s1, const string& s2) {
    return (strcmp(s1.c_str(), s2.c_str()) == 0);
  }
};

// For HashFcn, hash<T> is defined in the headers <hash_fun.h>
// T is only defined for type char*, const char*, crope, wrope, and the built-in integral types.
// T:
// char*
// const char*
// crope
// wrope
// char
// signed char
// unsigned char
// short
// unsigned short
// int
// unsigned int
// long
// unsigned long

// Since hash_set do not support hash<string>, we can not use string as the key.
// in c++11, we should use unprdered_set instead.
// Is using unordered_set allowed by Google?
TEST_F (StlTest, HashsetTest) {
  hash_set<int> h1 (int_array_, int_array_ + sizeof(int_array_) / sizeof(int));
  hash_set<int>::iterator it;
  for (it = h1.begin(); it != h1.end(); ++it) {
    LOG(INFO) << *it;
  }
  LOG(INFO) << "There are " << h1.bucket_count() << " buckets";
  for (int i = 0; i < h1.bucket_count(); ++i) {
    LOG(INFO) << "Bucket " << i;
  }

}

/**********************************************************************************************/


/**********************************************************************************************/
// Test for map.

#include <map>
using std::map;

TEST_F (StlTest, MapTest) {
  // The compare struct controls the way to rank the keys in pair<key, value>.
  map<int, string> m1; // less<int>
  map<int, string, std::greater<int> > m2;
  map<string, int> m3; // less<string>
  map<string, int, StrCmp> m4;
  for (int i = 0; i < 12; ++i) {
    m1[int_array_[i]] = str_array_[i];
    m2.insert(pair<int, string>(int_array_[i], str_array_[i]));
    m3[str_array_[i]] = int_array_[i];
    m4.insert(pair<string, int>(str_array_[i], int_array_[i]));
  }
  map<int, string>::iterator i1;
  map<string, int>::iterator i2;
  LOG(INFO) << "m1...";
  m1.insert(pair<int, string>(-100, "aaaa"));
  for (i1 = m1.begin(); i1 != m1.end(); ++i1) {
    LOG(INFO) << "i1.first: " << (*i1).first << " i1.second: " << (*i1).second;
  }
  LOG(INFO) << "m2...";
  m2.insert(pair<int, string>(-200, "bbbb"));
  for (i1 = m2.begin(); i1 != m2.end(); ++i1) {
    LOG(INFO) << "i1.first: " << (*i1).first << " i1.second: " << (*i1).second;
  }
  LOG(INFO) << "m3...";
  m3.insert(pair<string, int>("Acccc", -300));
  for (i2 = m3.begin(); i2 != m3.end(); ++i2) {
    LOG(INFO) << (*i2).first << " : " << (*i2).second;
  }
  LOG(INFO) << "m4...";
  pair<map<string, int>::iterator, bool> ret;

  for (i2 = m4.begin(); i2 != m4.end(); ++i2) {
    LOG(INFO) << (*i2).first << " : " << (*i2).second;
  }
  ret = m4.insert(pair<string, int>("Zcccc", -400));
  LOG(INFO) << "insert(m4.insert(pair<string, int>(\"Zcccc\", -400))";
  LOG(INFO) << ret.second;
  ret = m4.insert(pair<string, int>("Apr", -500));
  LOG(INFO) << "insert(m4.insert(pair<string, int>(\"Apr\", -500))";
  LOG(INFO) << ret.second;
}
/**********************************************************************************************/


/**********************************************************************************************/
// Test for multimap.

#include <map>
using std::multimap;

TEST_F (StlTest, MultimapTest) {
  multimap<string, int, StrCmp> m4;
  for (int i = 0; i < 12; ++i) {
    m4.insert(pair<string, int>(str_array_[i], int_array_[i]));
  }
  multimap<string, int>::iterator i2;
  LOG(INFO) << "m4...";
  //
  // The return value for insert() is different from map.
  //
  multimap<string, int>::iterator ret;
  ret = m4.insert(pair<string, int>("Zcccc", -400));
  LOG(INFO) << "insert(m4.insert(pair<string, int>(\"Zcccc\", -400))";
  ret = m4.insert(pair<string, int>("Apr", 500));
  LOG(INFO) << "insert(m4.insert(pair<string, int>(\"Apr\", 500))";
  for (i2 = m4.begin(); i2 != m4.end(); ++i2) {
    LOG(INFO) << (*i2).first << " : " << (*i2).second;
  }
}
/**********************************************************************************************/


/**********************************************************************************************/
// Test for hash_map.
// c++11 provides unordered_map instead.

#include <ext/hash_map>
using __gnu_cxx::hash_map;

TEST_F (StlTest, HashmapTest) {
  hash_map<int, string> h1;
  // Because hash<string> does not exist. We cannot use string as key...
  // hash_map<string, int> h2;       // Not support.
  // unordered_map can!
  for (int i = 0; i < 12; ++i) {
    h1[int_array_[i]] = str_array_[i];
  }
  LOG(INFO) << "h1.bucket_count(): " << h1.bucket_count();
  pair<hash_map<int, string>::iterator, bool> ret;
  ret = h1.insert(pair<int, string>(100, "add new"));
  LOG(INFO) << "ret.second: " << ret.second;
  LOG(INFO) << h1[10];
  LOG(INFO) << h1.find(10)->first << " : " << h1.find(10)->second;
  h1.erase(h1.find(6));
  for (hash_map<int, string>::iterator it = h1.begin(); it != h1.end(); ++it) {
    LOG(INFO) << it->first << " : " << it->second;
  }

}
/**********************************************************************************************/



int main(int argc, char** argv) {
  google::ParseCommandLineFlags(&argc, &argv, true);
  google::InitGoogleLogging(argv[0]);
  // ::testing::GTEST_FLAG(filter) = "StlTest.PairTest";
  // ::testing::GTEST_FLAG(filter) = "StlTest.VectorTest";
  // ::testing::GTEST_FLAG(filter) = "StlTest.ListTest";
  // ::testing::GTEST_FLAG(filter) = "StlTest.DequeTest";
  // ::testing::GTEST_FLAG(filter) = "StlTest.StackTest";
  // ::testing::GTEST_FLAG(filter) = "StlTest.QueueTest";
  // ::testing::GTEST_FLAG(filter) = "StlTest.PriorityQueueTest";
  // ::testing::GTEST_FLAG(filter) = "StlTest.BitsetTest";
  // ::testing::GTEST_FLAG(filter) = "StlTest.SetTest";
  // ::testing::GTEST_FLAG(filter) = "StlTest.MultisetTest";
  // ::testing::GTEST_FLAG(filter) = "StlTest.HashsetTest";
  // ::testing::GTEST_FLAG(filter) = "StlTest.MapTest";
  // ::testing::GTEST_FLAG(filter) = "StlTest.MultimapTest";
  // ::testing::GTEST_FLAG(filter) = "StlTest.HashmapTest";
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}







