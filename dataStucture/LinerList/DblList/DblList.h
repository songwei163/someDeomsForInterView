//
// Created by S on 2019/11/1.
//

#ifndef SOMEDEOMSFORINTERVIEW_DATASTUCTURE_LINERLIST_DBLLIST_DBLLIST_H_
#define SOMEDEOMSFORINTERVIEW_DATASTUCTURE_LINERLIST_DBLLIST_DBLLIST_H_

#include <iostream>
#include <cassert>
using std::cout;
using std::endl;

template<typename T>
struct DblNode {
  T data;
  DblNode<T> *lLink;
  DblNode<T> *rLink;
  explicit DblNode<T>(DblNode<T> *l = nullptr, DblNode<T> *r = nullptr)
      : lLink(l), rLink(r) {}
  explicit DblNode<T>(T val, DblNode<T> *l = nullptr, DblNode<T> *r = nullptr)
      : data(val), lLink(l), rLink(r) {}
};

template<typename T>
class DblList {
 public:
  explicit DblList(T value);
  ~DblList();
  int Length() const;
  void makeEmpty();
  bool IsEmpty() const { return first->rLink == first; }
  DblNode<T> *getHead() const { return first; }
  void setHead(DblNode<T> *ptr);
  DblNode<T> *Search(const T &e);
  DblNode<T> *Locate(int i, int d);
  bool Insert(int i, const T &e, int d);
  bool Remove(int i, T &e, int d);
  void Print(int d = 1);
 private:
  DblNode<T> *first;
};

template<typename T>
DblNode<T> *DblList<T>::Locate(int i, int d) {
  if (first->rLink == first || i == 0) {
    return first;
  } else {
    DblNode<T> *ptr;
    d == 0 ? ptr = first->lLink : ptr = first->rLink;
    for (int j = 1; j < i; ++j) {
      if (ptr == first) {
        break;
      } else if (d == 0) {
        ptr = ptr->lLink;
      } else {
        ptr = ptr->rLink;
      }
    }

    return (ptr != first) ? ptr : nullptr;
  }
}

template<typename T>
DblNode<T> *DblList<T>::Search(const T &e) {
  DblNode<T> *ptr = first->rLink;
  while (ptr != first && ptr->data != e) {
    ptr = ptr->rLink;
  }

  return (ptr != first) ? ptr : nullptr;
}

template<typename T>
int DblList<T>::Length() const {
  DblNode<T> *ptr = first->rLink;
  int count = 0;
  while (ptr != first) {
    ptr = ptr->rLink;
    ++count;
  }
  return count;
}

template<typename T>
DblList<T>::~DblList() {
  makeEmpty();
  delete first;
}

template<typename T>
DblList<T>::DblList(T value) {
  first = new DblNode<T>(value);
  assert(first != nullptr);
  first->rLink = first->lLink = first;
}

template<typename T>
bool DblList<T>::Insert(int i, const T &e, int d) {
  DblNode<T> *ptr = Locate(i, d);
  if (ptr == nullptr) {
    return false;
  } else {
    DblNode<T> *newNode = new DblNode<T>(e);
    assert(newNode != nullptr);
    if (d == 0) {
      newNode->lLink = ptr->lLink;
      ptr->lLink = newNode;
      newNode->lLink->rLink = newNode;
      newNode->rLink = ptr;
    } else {
      newNode->rLink = ptr->rLink;
      ptr->rLink = newNode;
      newNode->rLink->lLink = newNode;
      newNode->lLink = ptr;
    }
  }
  return true;
}

// 0 是 first
template<typename T>
bool DblList<T>::Remove(int i, T &e, int d) {
  DblNode<T> *ptr = Locate(i, d);
  if (ptr == nullptr || ptr == first) {
    return false;
  } else {
    ptr->rLink->lLink = ptr->lLink;
    ptr->lLink->rLink = ptr->rLink;
    e = ptr->data;
    delete ptr;
    return true;
  }
}

template<typename T>
void DblList<T>::setHead(DblNode<T> *ptr) {
  if (ptr != nullptr) {
    first = ptr;
  }
}

template<typename T>
void DblList<T>::Print(int d) {
  if (!IsEmpty()) {
    DblNode<T> *ptr;
    if (d == 1) {
      ptr = first->rLink;
      while (ptr != first) {
        cout << ptr->data << ' ';
        ptr = ptr->rLink;
      }
      cout << endl;
    } else {
      ptr = first->lLink;
      while (ptr != first) {
        cout << ptr->data << ' ';
        ptr = ptr->lLink;
      }
      cout << endl;
    }
  }
}
template<typename T>
void DblList<T>::makeEmpty() {
  DblNode<T> *ptr;
  while (first->rLink != first) {
    ptr = first->rLink;
    first->rLink = ptr->rLink;
    delete ptr;
  }
  first->lLink = first;
}

#endif //SOMEDEOMSFORINTERVIEW_DATASTUCTURE_LINERLIST_DBLLIST_DBLLIST_H_
