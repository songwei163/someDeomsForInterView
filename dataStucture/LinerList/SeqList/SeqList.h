//
// Created by S on 2019/10/31.
//

#ifndef SOMEDEOMSFORINTERVIEW_DATASTUCTURE_LINERLIST_SEQLIST_SEQLIST_H_
#define SOMEDEOMSFORINTERVIEW_DATASTUCTURE_LINERLIST_SEQLIST_SEQLIST_H_

#include <iostream>

using std::cout;
using std::endl;

const int defaultSize = 100;

template<typename T>
class SeqList {
 public:
  SeqList(int sz = defaultSize);
  SeqList(SeqList<T> &L);
  ~SeqList() { delete[]data; }
 public:
  bool Insert(int i, T e);
  bool Remove(int i, T &e);
 public:
  bool getData(int i, T &e) const;
  bool setData(int i, T &e) const;
  int Search(T &e) const;
  int Locate(int i) const;
 public:
  void Print();
 public:
  int Size() const { return maxSize; }
  int Length() const { return last + 1; }
  bool IsEmpty() const { return last == -1; }
  bool IsFull() const { return last == maxSize - 1; }
 private:
  T *data;
  int maxSize;
  int last;
};

template<typename T>
SeqList<T>::SeqList(int sz) {
  if (sz > 0) {
    maxSize = sz;
    data = new T[maxSize];
    last = -1;
  }
}

template<typename T>
SeqList<T>::SeqList(SeqList<T> &L) {

}

template<typename T>
void SeqList<T>::Print() {
  for (int i = 0; i <= last; ++i) {
    cout << data[i] << ' ';
  }
  cout << endl;
}

template<typename T>
bool SeqList<T>::Insert(int i, T e) {
  if (IsFull()) { return false; }
  if (i < 0 || i > last + 1) { return false; }
  for (int j = last; j >= i; --j) { data[j + 1] = data[j]; }
  data[i] = e;
  ++last;
  return true;
}

template<typename T>
bool SeqList<T>::Remove(int i, T &e) {
  if (IsEmpty()) { return false; }
  if (i < 0 || i > last + 1) { return false; }
  e = data[i - 1];
  for (int j = i; j <= last; ++j) { data[j - 1] = data[j]; }
  --last;
  return true;
}

template<typename T>
bool SeqList<T>::getData(int i, T &e) const {
  if (i > 0 && i <= last + 1) {
    e = data[i - 1];
    return true;
  } else {
    return false;
  }
}

template<typename T>
bool SeqList<T>::setData(int i, T &e) const {
  if (i > 0 && i <= last + 1) {
    data[i - 1] = e;
  }
}

template<typename T>
int SeqList<T>::Search(T &e) const {
  for (int i = 0; i <= last; ++i) {
    if (data[i] == e) {
      return i + 1;
    }
  }
  return 0;
}

template<typename T>
int SeqList<T>::Locate(int i) const {
  if (i >= 1 && i <= last + 1) {
    return i;
  } else{
    return 0;
  }
}

#endif //SOMEDEOMSFORINTERVIEW_DATASTUCTURE_LINERLIST_SEQLIST_SEQLIST_H_
