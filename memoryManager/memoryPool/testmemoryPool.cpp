//
// Created by S on 2019/11/3.
//

#include <boost/pool/pool.hpp>
#include <boost/assign.hpp>
#include <boost/pool/object_pool.hpp>
#include <boost/noncopyable.hpp>

#include <iostream>
#include <string>
#include <vector>
#include <set>

using std::vector;
using std::string;
using std::set;
using std::cout;
using std::endl;

using namespace boost;
using namespace boost::assign;

void test01();
void test02();
void test03();

int main() {
  test02();
  return 0;
}

void test01() {
  pool<> p1(sizeof(int));

  int *p = (int *) p1.malloc();
  assert(p1.is_from(p));

  //p1.free(p);
  for (int i = 0; i < 100; ++i) {
    p1.ordered_malloc(10);
  }

}

void test02() {
  vector<int> v;

  v += 1, 2, 3, 4, 5, 6;
  set<string> s;

  s += "cpp", "java", "C#", "python";

}

void test03() {
  vector<int> v;
  push_back(v)(1)(2)(3)(4)(5);
}

