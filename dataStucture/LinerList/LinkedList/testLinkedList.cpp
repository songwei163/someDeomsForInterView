//
// Created by S on 2019/10/31.
//

#include "LinkedList.h"

void test01();

int main() {
  test01();
  return 0;
}

void test01() {
  List<int> L;
  for (int i = 0; i < 100; ++i) {
    L.Insert(i, i + 1);
  }
  L.Print();
}