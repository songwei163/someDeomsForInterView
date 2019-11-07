//
// Created by S on 2009/0/7.
//

#include <stdio.h>

int main() {
  int count = 0, i, j;
  for (i = 100; i <= 200; ++i) {
    int a = 0;
    for (j = 2; j * j <= i; ++j) {
      if (i % j == 0) {
        ++a;
      }
    }
    if (a == 0) {
      printf("%-5d", i);
      ++count;
    }
    if (count == 8) {
      printf("\n");
      count = 0;
    }
  }
  return 0;
}
