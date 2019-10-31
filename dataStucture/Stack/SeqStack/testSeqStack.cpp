//
// Created by S on 2019/10/31.
//

#include "SeqStack.h"
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
  SeqStack<int> S;

  int e;
  srand(time(nullptr));

  for (int i = 0; i < 10; ++i) {
    S.Push(rand() % 1000);
  }

  //cout << "The initial Stack in the file is:\n" << S;
  cout << "The current size of the Stack is: " << S.getSize() << endl;
  S.getTop(e);
  cout << "The current Top of the Stack is : " << e << endl;
  S.Pop(e);
  //cout << "\nDo a Pop operation, then the Sck is:\n" << S << endl;
  cout << "The e popped is: " << e << endl;
  S.getTop(e);
  cout << "The current Top of the Stack is : " << e << endl;

  cout << "\nTest the Ste of the Sck:\n";
  if (S.IsEmpty()) cout << "The Sck is empty now!\n";
  else if (S.IsFull()) cout << "The Sck is full now!\n";
  else cout << "The Sck is not empty and not full now!\n";
  cout << "Now make the Sck empty, then the Ste of the Sck is:\n";
  S.makeEmpty();
  if (S.IsEmpty()) cout << "The Sck is empty now!\n";
  else if (S.IsFull()) cout << "The Sck is full now!\n";
  else cout << "The Sck is not empty and not full now!\n";

}


