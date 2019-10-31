//
// Created by S on 2019/10/31.
//

#ifndef SOMEDEOMSFORINTERVIEW_DATASTUCTURE_LINERLIST_CIRCLIST_CIRCLIST_H_
#define SOMEDEOMSFORINTERVIEW_DATASTUCTURE_LINERLIST_CIRCLIST_CIRCLIST_H_

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

template<typename T>
class CircLinkNode {
 public:
  T data;
  CircLinkNode<T> *link;
  explicit CircLinkNode(CircLinkNode<T> *ptr = nullptr) : link(ptr) {}
  explicit CircLinkNode(const T &item, CircLinkNode<T> *ptr = nullptr) : data(item), link(ptr) {}
};

template<typename T>
class CircList {
 public:
  CircList() {
    last = first = new CircList<T>;
    first->link = first;
  }

  CircList(const T &e) {
    last = first = new CircList<T>(e);
    first->link = first;
  }
  CircList(CircList<T> &L);
  ~CircList() {
    makeEmpty();
    delete first;
  }
 public:
  void input();
 public:
  int Length() const;
  void makeEmpty();
 private:
  CircLinkNode<T> *first, *last;
};

template<typename T>
void CircList<T>::makeEmpty() {
  CircLinkNode<T> *ptr;
  while (first->link != first) {
    ptr = ptr->link;
    first->link = ptr->link;
    delete ptr;
  }
  last = first;
}

template<typename T>
int CircList<T>::Length() const {
  CircLinkNode<T> *ptr = first->link;
  int count = 0;
  while (ptr != first) {
    ptr = ptr->link;
    ++count;
  }
  return count;
}

template<typename T>
void CircList<T>::input() {
  CircLinkNode<T> *newNode;
  T val;
  cin >> val;
  while (val != '#') {
    newNode = new CircLinkNode<T>(val);
    newNode->link = first->link;
    first->link = newNode;
    if (last == first) {
      last = last->link;
    }
    cin >> val;
  }
}

#endif //SOMEDEOMSFORINTERVIEW_DATASTUCTURE_LINERLIST_CIRCLIST_CIRCLIST_H_
