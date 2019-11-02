//
// Created by S on 2019/11/2.
//

#include "dataList.h"
#include "person.h"
#include <fstream>

void test01();

int main() {
  test01();
  return 0;
}

void test01() {
  ifstream fin("persons.txt");
  assert(fin);
  dataList<person, long> sc;
  fin >> sc;
  cout << sc;
}
