//
// Created by S on 2019/10/31.
//

#ifndef SOMEDEOMSFORINTERVIEW_DATASTUCTURE_SET_BITSET_BITSET_H_
#define SOMEDEOMSFORINTERVIEW_DATASTUCTURE_SET_BITSET_BITSET_H_

#include <cassert>

const int DefaultSize = 50;

template<typename T>
class BitSet {
 public:
  explicit BitSet(int sz = DefaultSize);
  BitSet(const BitSet<T> &R);
  ~BitSet();
 public:
  bool getMember(const T &x);
  void putMember(const T &x, int v);
  void makeEmpty();
  bool addMember(const T &x);
  bool delMember(const T &x);
  BitSet<T> &operator=(const BitSet<T> &R);
  BitSet<T> operator+(const BitSet<T> &R);
  BitSet<T> operator*(const BitSet<T> &R);
  BitSet<T> operator-(const BitSet<T> &R);
  bool Contains(const T &x);
  bool subSet(BitSet<T> &R);
  bool operator==(BitSet<T> &R);
 private:
  int setSize;
  int vectorSize;
  unsigned short *bitVector;
};

template<typename T>
BitSet<T>::~BitSet() {
  delete[]bitVector;
}

template<typename T>
BitSet<T>::BitSet(const BitSet<T> &R) {
  setSize = R.setSize;
  vectorSize = R.vectorSize;
  bitVector = new unsigned short[vectorSize];
  assert(bitVector);
  for (int i = 0; i < vectorSize; ++i) {
    bitVector[i] = R.bitVector[i];
  }
}

template<typename T>
BitSet<T>::BitSet(int sz) {
  setSize = sz;
  assert(setSize > 0);
  vectorSize = (setSize + 15) >> 4;
  bitVector = new unsigned short[vectorSize];
  assert(bitVector);
  for (int i = 0; i < vectorSize; ++i) {
    bitVector[i] = 0;
  }

}

template<typename T>
bool BitSet<T>::operator==(BitSet<T> &R) {
  if (vectorSize != R.vectorSize) {
    return false;
  }
  for (int i = 0; i < vectorSize; i++) {
    if (bitVector[i] != R.bitVector[i]) {
      return false;
    }
  }
  return true;
}

template<typename T>
bool BitSet<T>::subSet(BitSet<T> &R) {
  assert (setSize == R.setSize);
  for (int i = 0; i < vectorSize; i++) {
    if (bitVector[i] & ~R.bitVector[i]) {
      return false;
    }
  }
  return true;
}

template<typename T>
bool BitSet<T>::Contains(const T &x) {
  return getMember(x);
}

template<typename T>
BitSet<T> BitSet<T>::operator-(const BitSet<T> &R) {
  assert(vectorSize == R.vectorSize);
  BitSet<T> temp(setSize);
  for (int i = 0; i < vectorSize; i++) {
    temp.bitVector[i] = bitVector[i] & ~R.bitVector[i];
  }
  return temp;
}

template<typename T>
BitSet<T> BitSet<T>::operator*(const BitSet<T> &R) {
  assert (vectorSize == R.vectorSize);
  BitSet<T> temp(setSize);
  for (int i = 0; i < vectorSize; i++) {
    temp.bitVector[i] = bitVector[i] & R.bitVector[i];
  }
  return temp;
}

template<typename T>
BitSet<T> BitSet<T>::operator+(const BitSet<T> &R) {
  assert(vectorSize == R.vectorSize);
  BitSet<T> temp(setSize);
  for (int i = 0; i < vectorSize; i++) {
    temp.bitVector[i] = bitVector[i] | R.bitVector[i];
  }
  return temp;
}

template<typename T>
BitSet<T> &BitSet<T>::operator=(const BitSet<T> &R) {
  if (this != &R) {
    setSize = R.setSize;
    vectorSize = R.vectorSize;
    delete[]bitVector;
    bitVector = new unsigned short[vectorSize];
    assert(bitVector);
    for (int i = 0; i < vectorSize; i++) {
      bitVector[i] = R.bitVector[i];
    }
  }
  return *this;
}

template<typename T>
bool BitSet<T>::delMember(const T &x) {
  assert(x >= 0 && x < setSize);
  if (getMember(x) == 1) {
    putMember(x, 0);
    return true;
  }
  return false;
}

template<typename T>
bool BitSet<T>::addMember(const T &x) {
  assert (x >= 0 && x < setSize);
  if (getMember(x) == 0) {
    putMember(x, 1);
    return true;
  }
  return false;
}

template<typename T>
void BitSet<T>::makeEmpty() {
  for (int i = 0; i < vectorSize; i++) {
    bitVector[i] = 0;
  }
}

template<typename T>
void BitSet<T>::putMember(const T &x, int v) {
  int ad = x / 16, id = x % 16;
  unsigned short elem = bitVector[ad];
  int temp = elem >> (15 - id);
  if (temp % 2 == 0 && v == 1) {
    temp = temp + 1;
  } else if (temp % 2 == 1 && v == 0) {
    temp = temp - 1;
  }
  bitVector[ad] = (temp << (15 - id)) | (((1 << (15 - id)) - 1) & elem);
}

template<typename T>
bool BitSet<T>::getMember(const T &x) {
  int ad = x / 16, id = x % 16;
  unsigned short elem = bitVector[ad];
  return ((elem >> (15 - id)) & 1);
}

#endif //SOMEDEOMSFORINTERVIEW_DATASTUCTURE_SET_BITSET_BITSET_H_
