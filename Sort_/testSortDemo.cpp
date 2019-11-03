//
// Created by S on 2019/11/2.
//

#include <array>
#include <iostream>
#include <ctime>
using namespace std;

namespace Sort_ {

template<typename Type, int Size>
void BubbleSort(array<Type, Size> &arr) {
  for (int i = 0; i < arr.size() - 1; ++i) {
    bool flag = true;
    for (int j = 0; j < arr.size() - i - 1; ++j) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        flag = false;
      }
    }
    if (flag) {
      break;
    }
  }
}

template<typename Type, int Size>
void SelectSort(array<Type, Size> &arr) {
  int min;
  for (int i = 0; i < arr.size(); ++i) {
    min = i;
    for (int j = i + 1; j < arr.size(); ++j) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }
    if (i != min) {
      swap(arr[i], arr[min]);
    }
  }
}

template<typename Type, int Size>
void InsertSort(array<Type, Size> &arr) {
  int temp;
  for (int i = 1; i < arr.size(); ++i) {
    temp = arr[i];
    int j = i;
    while (j > 0 && temp < arr[j - 1]) {
      arr[j] = arr[j - 1];
      --j;
    }

    if (j != i) {
      arr[j] = temp;
    }
  }
}

}

void test01();

int main() {
  test01();
  return 0;
}

void test01() {
  srand(time(nullptr));
  array<int, 10> arr{};

  for (auto &i : arr) {
    i = rand() % 1000;
  }
  Sort_::BubbleSort<int, 10>(arr);
  for (auto &i : arr) {
    cout << i << ' ';
  }
  cout << endl;
}