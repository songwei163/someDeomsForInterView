//
// Created by S on 2019/11/1.
//

#include "DblList.h"
#include <ctime>

void test01();

int main() {
  test01();
  return 0;
}

void test01() {
  DblList<int> L(1);

  srand(time(nullptr));
  for (int i = 0; i <= 10; ++i) {
    L.Insert(i, i % 8, 1);
  }

//L.Insert(0,1,1);
//  L.Insert(1,2,1);
//  L.Insert(2,3,1);

  L.Print();
  L.Print(0);
  int e;
  L.Remove(1, e, 1);

  L.Print();

}
