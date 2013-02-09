#include <iostream>
#include <conio.h>

template<unsigned N> struct ScalarProduct {
  static inline int result(int* a, int* b) { return a[N-1] * b[N-1] + ScalarProduct<N-1>::result(a, b); }
};

template<> struct ScalarProduct<1> {
  static inline int result(int* a, int* b) { return a[0] * b[0]; }
};

template<unsigned N> inline int scalarProduct(int* a, int* b) {
  return ScalarProduct<N>::result(a, b);
}

int main() {
  int a[] = { 1, 2, 3 };
  int b[] = { 2, 3, 4 };
  std::cout << scalarProduct<3>(a, b);
}


   