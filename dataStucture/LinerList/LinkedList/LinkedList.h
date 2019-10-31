//
// Created by S on 2019/10/31.
//

#ifndef SOMEDEOMSFORINTERVIEW_DATASTUCTURE_LINERLIST_LINKEDLIST_LINKEDLIST_H_
#define SOMEDEOMSFORINTERVIEW_DATASTUCTURE_LINERLIST_LINKEDLIST_LINKEDLIST_H_

#include <iostream>

using std::cout;
using std::endl;

template<typename T>
struct LinkNode {
  T data;
  LinkNode<T> *link;
  explicit LinkNode(LinkNode<T> *ptr = nullptr) : link(ptr) {}

  explicit LinkNode(const T &item, LinkNode<T> *ptr = nullptr)
      : data(item), link(ptr) {}
};

template<typename T>
class List {
 public:
  List() : first(new LinkNode<T>) {}
  explicit List(const T &x) : first(new LinkNode<T>(x)) {}
  List(List<T> &L);
  ~List() {
    makeEmpty();
    delete first;
  }
 public:
  bool IsEmpty() const { return first->link == nullptr; }
  LinkNode<T> *getHead() const { return first; }
 public:
  void makeEmpty();
  LinkNode<T> *Locate(int i) const;
  bool Insert(int i, T e);
  void Print() const;
 private:
  LinkNode<T> *first;
};

template<typename T>
List<T>::List(List<T> &L) {
  T value;
  LinkNode<T> *srcptr = L.first;
  LinkNode<T> *desptr = first = new LinkNode<T>;

  while (srcptr->link != nullptr) {
    value = srcptr->link->data;
    desptr->link = new LinkNode<T>(value);
    desptr = desptr->link;
    srcptr = srcptr->link;
  }
}

template<typename T>
void List<T>::makeEmpty() {
  LinkNode<T> *ptr = nullptr;
  while (first->link != nullptr) {
    ptr = first->link;
    first->link = ptr->link;
    delete ptr;
  }
}

template<typename T>
LinkNode<T> *List<T>::Locate(int i) const {
  if (i < 0) {
    return nullptr;
  } else {
    LinkNode<T> *current = first;
    int k = 0;
    while (current && k < i) {
      current = current->link;
      ++k;
    }
    return current;
  }
}

template<typename T>
bool List<T>::Insert(int i, T e) {
  LinkNode<T> *current = Locate(i);
  if (current == nullptr) {
    return false;
  } else {
    auto *newNode = new LinkNode<T>(e);
    newNode->link = current->link;
    current->link = newNode;
  }
}

template<typename T>
void List<T>::Print() const {
  LinkNode<T> *current = first->link;
  while (current != nullptr) {
    cout << current->data << ' ';
    current = current->link;
  }
  cout << endl;
}

#endif //SOMEDEOMSFORINTERVIEW_DATASTUCTURE_LINERLIST_LINKEDLIST_LINKEDLIST_H_
