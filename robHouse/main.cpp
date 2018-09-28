#include <iostream>

using std::cout;
using std::endl;
using std::max;

int rob_it(int n, int* h) {
  int s[n];
  int temp = 0;
  s[0] = h[0];
  s[1] = max(h[0], h[1]);
  for (int i = 2; i < n; i++) {
    temp = 0;
    for (int j = i - 2; j >= 0; j--) {
      temp = max(temp, s[j]);
    }
    s[i] = max(temp + h[i], h[i - 1]);
  }
  return s[n - 1];
}

// int rob_it(int n, int* h) {
//   int s[n];
//   int temp = 0;
//   s[0] = h[0];
//   s[1] = max(h[0], h[1]);
//   for (int i = 2; i < n; i++) {
//     s[i] = s[i - 1];
//     for (int j = i - 2; j >= 0; j--) {
//       s[i] = max(s[i], s[j]+h[i]);
//     }
//     // s[i] = max(temp + h[i], h[i - 1]);
//   }
//   return s[n - 1];
// }

int main() {
  int n = 5;
  int houses[n] = {1, 2, 3, 4 ,5};
  cout << rob_it(n, houses) << endl;
  return 0;
}