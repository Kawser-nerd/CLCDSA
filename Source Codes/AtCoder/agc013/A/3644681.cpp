#include <iostream>
using namespace std;
enum {LE = -1, EQ = 0, GE = 1};
int A[100000 + 1];
int main() {
  int N; cin >> N;
  int total{1}, flag{EQ};
  if (N <= 2) {
    goto END;
  }
  cin >> A[0];
  for (size_t i{1}; i < N; ++i) {
    cin >> A[i];
    if (A[i] < A[i - 1]) {
      if (flag == GE) {
        ++total;
        flag = EQ;
        continue;
      }
      flag = LE;
    } else if (A[i] > A[i - 1]) {
      if (flag == LE) {
        ++total;
        flag =EQ;
        continue;
      }
      flag = GE;
    }
  }

  END:
  cout << total << "\n";
  return 0;
}