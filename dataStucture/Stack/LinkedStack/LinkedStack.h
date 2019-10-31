//
// Created by S on 2019/10/31.
//

#ifndef SOMEDEOMSFORINTERVIEW_DATASTUCTURE_STACK_LINKEDSTACK_LINKEDSTACK_H_
#define SOMEDEOMSFORINTERVIEW_DATASTUCTURE_STACK_LINKEDSTACK_LINKEDSTACK_H_

#include <cassert>

template<typename T>
struct StackNode {
  T data;
  StackNode<T> *link;
  explicit StackNode(T d = 0, StackNode<T> *next = nullptr) : link(next), data(d) {}
};

template<typename T>
class LinkedStack {
 public:
  LinkedStack() : top(nullptr) {}
  ~LinkedStack() { makeEmpty(); }
 public:
  int getSize();
  void makeEmpty();
  void Push(const T &e);
  bool getTop(T &e) const;
  bool Pop(T &e);
  bool IsEmpty() const { return top == nullptr; }
  bool IsFull() const { return false; }
 private:
  StackNode<T> *top;
};
template<typename T>
void LinkedStack<T>::makeEmpty() {
  StackNode<T> *ptr;
  while (top) {
    ptr = top;
    top = top->link;
    delete ptr;
  }
}
template<typename T>
bool LinkedStack<T>::Pop(T &e) {
  if (IsEmpty()) {
    return false;
  } else {
    StackNode<T> *ptr = top;
    top = top->link;
    e = ptr->data;
    delete ptr;
    return true;
  }
}
template<typename T>
bool LinkedStack<T>::getTop(T &e) const {
  if (IsEmpty()) {
    return false;
  } else {
    e = top->data;
    return true;
  }
}
template<typename T>
void LinkedStack<T>::Push(const T &e) {
  top = new StackNode<T>(e, top);
  assert(top);
}
template<typename T>
int LinkedStack<T>::getSize() {
  StackNode<T> *p = top;
  int k = 0;
  while (p) {
    p = p->link;
    k++;
  }
  return k;
}

#endif //SOMEDEOMSFORINTERVIEW_DATASTUCTURE_STACK_LINKEDSTACK_LINKEDSTACK_H_
