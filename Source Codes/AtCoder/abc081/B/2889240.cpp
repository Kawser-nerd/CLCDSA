#include <iostream>
#include <string>

using namespace std;

// int
// main(int argc, char* argv[]) {
//   int n, i, count;
//   long long binAnd, _a;
//
//   cin >> n;
//
//   binAnd = 1000000000;
//   for(i=0; i<n; i++) {
//     cin >> _a;
//     binAnd = binAnd | _a;
//   }
//   count = 0;
//   while (true) {
//     if (binAnd % 2 == 0) {
//       count++;
//       binAnd = binAnd / 2;
//     } else {
//       cout << count << endl;
//       return 0;
//     }
//   }
//   cout << count << endl;
//
//   return 0;
// }
int
main(void) {
  int n, i, count;
  bool divivable;

  cin >> n;
  int A[n];

  for(i=0; i<n; i++) {
    cin >> A[i];
  }
  count = 0;
  while (true) {
    divivable = true;
    for(i=0; i<n; i++) {
      if (A[i] % 2 == 0) {
        A[i] /= 2;
      } else {
        divivable = false;
        break;
      }
    }
    if (divivable) {
      count++;
    } else {
      cout << count << endl;
      return 0;
    }
  }
}