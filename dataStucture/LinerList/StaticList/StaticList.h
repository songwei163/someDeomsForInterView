//
// Created by S on 2019/10/31.
//

#ifndef SOMEDEOMSFORINTERVIEW_DATASTUCTURE_LINERLIST_STATICLIST_STATICLIST_H_
#define SOMEDEOMSFORINTERVIEW_DATASTUCTURE_LINERLIST_STATICLIST_STATICLIST_H_

#include <iostream>

using std::cout;
using std::endl;

const int defaultSize = 100;
template<typename T>
struct SLinkNode {
  T data;
  int link;
};

template<typename T>
class StaticList {
 public:
  StaticList(int sz = defaultSize);
  ~StaticList();
 public:
  int Length() const;
  int Search(T x) const;
  int Locate(int i) const;
  bool getData(int i, T &x) const;
  bool Append(T x);
  bool Insert(int i, T x);
  bool Remove(int i);
  bool IsEmpty() const;
  void output(int type = 0);
 private:
  SLinkNode<T> *elem;
  int maxSize;
  int avil;
//  friend istream &operator>>(istream &in, StaticList<T> &stl) {
//    T data;
//    while (!in.eof()) {//ÔÚÔ­Á´±íºóÌí¼Ó£¬ÓëÆäËûÏßÐÔ±í²»Í¬
//      in >> data;
//      stl.Append(data);
//    }
//    return in;
//  }
//  friend ostream &operator<<(ostream &out, StaticList<T> &stl) {
//    int p = stl.elem[0].link;//elem[0]Îª¸½¼ÓÍ·½áµã
//    while (p != -1) {
//      cout << stl.elem[p].data << endl;
//      p = stl.elem[p].link;
//    }
//    cout << endl;
//    return out;
//  }
};

template<typename T>
StaticList<T>::StaticList(int sz) {
  maxSize = sz;
  elem = new SLinkNode<T>[maxSize];
  assert(elem);
  elem[0].link = -1;
  avil = 1;
  for (int i = 1; i < maxSize - 1; i++) elem[i].link = i + 1;
  elem[maxSize - 1].link = -1;
}

template<typename T>
StaticList<T>::~StaticList() {
  delete[]elem;
}

template<typename T>
int StaticList<T>::Length() const {
  int p = elem[0].link;
  int i = 0;
  while (p != -1) {
    p = elem[p].link;
    i++;
  }
  return i;
}

template<typename T>
bool StaticList<T>::IsEmpty() const {
  return elem[0].link == -1;
}

template<typename T>
int StaticList<T>::Search(T x) const {
  int p = elem[0].link;
  while (p != -1) {
    if (elem[p].data == x) break;
    else p = elem[p].link;
  }
  return p;
}

template<typename T>
int StaticList<T>::Locate(int i) const {
  if (i < 0) return -1;
  if (i == 0) return 0;
  int j = 1, p = elem[0].link;
  while (p != -1 && j < i) {
    p = elem[p].link;
    j++;
  }
  return p;
}

template<typename T>
bool StaticList<T>::getData(int i, T &x) const {
  int p = Locate(i);
  if (p == -1) return -1;
  x = elem[p].data;
  return true;
}

template<typename T>
bool StaticList<T>::Append(T x) {
  if (avil == -1) return false;
  int q = avil;
  avil = elem[avil].link;
  elem[q].data = x;
  elem[q].link = -1;
  int p = 0;
  while (elem[p].link != -1) p = elem[p].link;
  elem[p].link = q;
  return true;
}

template<typename T>
bool StaticList<T>::Insert(int i, T x) {
  int p = Locate(i);
  if (p == -1) return false;
  int q = avil;
  avil = elem[avil].link;
  elem[q].data = x;
  elem[q].link = elem[p].link;
  elem[p].link = q;
  return true;
}

template<typename T>
bool StaticList<T>::Remove(int i) {
  int p = Locate(i - 1);
  if (p == -1) return false;
  int q = elem[p].link;
  if (q == -1) return false;
  elem[p].link = elem[q].link;
  elem[q].link = avil;
  avil = q;
  return true;
}

template<typename T>
void StaticList<T>::output(int type) {
  if (IsEmpty()) {
    cout << "The static list is empty!\n";
    return;
  }
  if (type == 0) {
    cout << "Index\tData" << endl;
    cout << "0\thead" << endl;
    int p = elem[0].link;
    while (p != -1) {
      cout << p << "\t" << elem[p].data << endl;
      p = elem[p].link;
    }
    cout << "Static List length: " << Length() << endl;
  } else {
    cout << "Index\tData\tLink" << endl;
    cout << "0\thead\t" << elem[0].link << endl;
    int avl = avil;
    for (int i = 1, len = Length(); len > 0; i++) {
      if (i == avl) {
        cout << i << "\t\t" << elem[i].link << endl;
        avl = elem[avl].link;
      } else {
        cout << i << "\t" << elem[i].data << "\t" << elem[i].link << endl;
        len--;
      }
    }
    cout << "First available position: " << avil << endl;
  }
  cout << endl;
}

#endif //SOMEDEOMSFORINTERVIEW_DATASTUCTURE_LINERLIST_STATICLIST_STATICLIST_H_
