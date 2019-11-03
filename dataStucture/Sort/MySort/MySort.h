//
// Created by S on 2019/11/2.
//

#ifndef SOMEDEOMSFORINTERVIEW_DATASTUCTURE_SORT_MYSORT_MYSORT_H_
#define SOMEDEOMSFORINTERVIEW_DATASTUCTURE_SORT_MYSORT_MYSORT_H_

#include "../dataList/dataList.h"
#include "../dataList/person.h"
#include "../../Stack/SeqStack/SeqStack.h"

template<typename E, typename K>
void BubbleSort(dataList<E, K> &L, int left, int right);

template<typename E, typename K>
void ShakerSort(dataList<E, K> &L, int left, int right);

template<typename E, typename K>
void SelectSort(dataList<E, K> &L, int left, int right);

template<typename E, typename K>
void InsertSort(dataList<E, K> &L, int left, int right);

template<typename E, typename K>
void BinaryInsertSort(dataList<E, K> &L, int left, int right);

template<typename E, typename K>
void ShellSort(dataList<E, K> &L, int left, int right);

template<typename E, typename K>
void QuickSort(dataList<E, K> &L, int left, int right);

template<typename E, typename K>
void MergeSort(dataList<E, K> &L, int left, int right);

template<typename E, typename K>
void HeapSort(dataList<E, K> &L, int left, int right);

template<typename E, typename K>
void RadixSort(dataList<E, K> &L, int left, int right,
               int d, int (*getDigit)(E &elem, int d, int Radix));

template<typename E, typename K>
void BSTSort(dataList<E, K> &L, int left, int right);

template<typename E, typename K>
void CountSort(dataList<E, K> &L, int left, int right);

template<typename E, typename K>
void BubbleSort(dataList<E, K> &L, int left, int right) {
  int pass = left + 1;
  bool exchange = true;
  while (pass <= right && exchange) {
    exchange = false;
    for (int j = right; j >= pass; j--) {
      if (L[j - 1] > L[j]) {
        L.Swap(j - 1, j);
        exchange = true;
      }
    }
    pass++;
  }
}

template<typename E, typename K>
void SelectSort(dataList<E, K> &L, int left, int right) {
  for (int i = left; i < right; ++i) {
    int k = i;
    for (int j = i + 1; j <= right; ++j) {
      if (L[j] < L[k]) {
        k = j;
      }
      if (k != i) {
        L.Swap(i, k);
      }
    }
  }
}

template<typename E, typename K>
void InsertSort(dataList<E, K> &L, int left, int right) {
  E temp;
  int i, j;

  for (i = left + 1; i <= right; ++i) {
    if (L[i] < L[i - 1]) {
      temp = L[i];
      j = i - 1;
      do {
        L[j + 1] = L[j];
        --j;
      } while (j >= left && temp < L[j]);
    }
  }
}

#endif //SOMEDEOMSFORINTERVIEW_DATASTUCTURE_SORT_MYSORT_MYSORT_H_
