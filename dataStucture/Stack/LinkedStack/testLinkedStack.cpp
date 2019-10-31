//
// Created by S on 2019/10/31.
//

#include "LinkedStack.h"

#include <iostream>
#include <ctime>

using std::cout;
using std::endl;

void test01();

int main() {
  test01();
  return 0;
}

void test01() {
  LinkedStack<int> L;
  int e;
  srand(time(nullptr));

  for (int i = 0; i < 10; ++i) {
    L.Push(rand() % 1000);
  }

  cout << "The current size of the Stack is: " << L.getSize() << endl;
  L.getTop(e);
  cout << "The current Top of the Stack is : " << e << endl;
  L.Pop(e);
  cout << "The e popped is: " << e << endl;
  L.getTop(e);
  cout << "The current Top of the Stack is : " << e << endl;

  cout << "\nTest the Lte of the Lck:\n";
  if (L.IsEmpty()) cout << "The Lck is empty now!\n";
  else if (L.IsFull()) cout << "The Lck is full now!\n";
  else cout << "The Lck is not empty and not full now!\n";
  L.makeEmpty();
  cout << "Now make the Lck empty, then the Lte of the Lck is:\n";
  if (L.IsEmpty()) cout << "The Lck is empty now!\n";
  else if (L.IsFull()) cout << "The Lck is full now!\n";
  else cout << "The Lck is not empty and not full now!\n";
}
