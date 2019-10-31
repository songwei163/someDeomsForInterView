//
// Created by S on 2019/10/31.
//

#ifndef SOMEDEOMSFORINTERVIEW_DATASTUCTURE_STACK_SEQSTACK_SEQSTACK_H_
#define SOMEDEOMSFORINTERVIEW_DATASTUCTURE_STACK_SEQSTACK_SEQSTACK_H_

#include <cassert>

const int stackDefaultSize = 50;
const int stackIncreament = 20;

template<typename T>
class SeqStack {
 public:
  explicit SeqStack(int sz = stackDefaultSize)
      : top(-1), maxSize(sz), element(new T[maxSize]) {}
  ~SeqStack() { delete[]element; }
 public:
  void Push(const T &e);
  bool Pop(T &e);
  bool getTop(T &e);
 public:
  bool IsEmpty() const { return top == -1; }
  bool IsFull() const { return top == maxSize - 1; }
  int getSize() const { return top + 1; }
  void makeEmpty() { top = -1; }
 private:
  int top;
  int maxSize;
  T *element;
  void overflowProcess();
};

template<typename T>
void SeqStack<T>::overflowProcess() {
  T *newArray = new T[maxSize + stackIncreament];
  assert(newArray);

  for (int i = 0; i <= top; i++)
    newArray[i] = element[i];
  maxSize = maxSize + stackIncreament;
  delete[]element;
  element = newArray;
}

template<typename T>
bool SeqStack<T>::getTop(T &e) {
  if (IsEmpty()) {
    return false;
  } else {
    e = element[top];
    return true;
  }
}

template<typename T>
bool SeqStack<T>::Pop(T &e) {
  if (IsEmpty()) {
    return false;
  } else {
    e = element[top--];
    return true;
  }
}

template<typename T>
void SeqStack<T>::Push(const T &e) {
  if (IsFull()) {
    overflowProcess();
  } else {
    element[++top] = e;
  }
}

#endif //SOMEDEOMSFORINTERVIEW_DATASTUCTURE_STACK_SEQSTACK_SEQSTACK_H_
