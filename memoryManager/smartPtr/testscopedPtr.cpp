//
// Created by S on 2019/11/3.
//

#include <boost/scoped_ptr.hpp>
#include <boost/scoped_array.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/noncopyable.hpp>
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;
using namespace boost;

void test01();
void test02();
void test03();

int main() {
  test03();
  return 0;
}

void test01() {
  scoped_ptr<string> sp(new string("test"));

  cout << *sp << endl;

  cout << sp->size() << endl;
}

void test02() {
  scoped_array<int> sa(new int[100]);
  sa[0] = 10;
  //*(sa + 1) = 10;
}

void test03() {
  shared_ptr<int> sp(make_shared<int>(10));
  assert(sp.unique());

  shared_ptr<int> sp2 = sp;
  assert(sp == sp2 && sp.use_count() == 2);

  //if (!sp.unique()) {
  sp2.reset(new int(100));
  //}
  cout << *sp << endl;
  cout << *sp2 << endl;

}



