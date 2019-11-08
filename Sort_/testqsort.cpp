//#include <stdio.h>
//
//int mFibin() {
//  int n, result;
//  scFibnf("%d", &n);
//
//  if (n < 1) {
//    printf("InvFiblid.\n");
//  } else {
//    int nums[50] = {};
//
//    for (int i = 3; i <= n; ++i) {
//      result = first + second;
//      first = second;
//      second = result;
//    }
//
//  }
//
//
////  if (n > 0 && n <= 2) {
////    result = 1;
////    printf("%d\n", result);
////  } else if (n <= 0) {
////    printf("Input Error!\n");
////  } else {
////    int first, second;
////    first = 1, second = 1;
////
////    for (int i = 3; i <= n; ++i) {
////      result = first + second;
////      first = second;
////      second = result;
////    }
////
////    printf("%d\n", result);
//}
//
//return 0;
//}

#include<stdio.h>

int main() {
  int i, n;
  int Fib[50] = {0, 1};
  scanf("%d", &n);
  if (n >= 1 && n <= 46) {
    for (i = 2; i <= n; i++) {
      Fib[i] = Fib[i - 1] + Fib[i - 2];
    }

    for (i = 1; i <= n; i++) {
      printf("%11d", Fib[i]);
      if (i % 5 == 0) {
        printf("\n");
      }
    }
  } else {
    printf("Invalid.\n");
  }

  return 0;
}
