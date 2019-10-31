//
// Created by S on 2019/10/31.
//

#include "SeqList.h"
#include <ctime>

void test01();

int main() {
  test01();
  return 0;
}

void test01() {
  srand(time(nullptr));
  SeqList<int> L;
  for (int i = 0; i < 100; ++i) {
    L.Insert(i, rand() % 1000);
  }

  L.Print();
}