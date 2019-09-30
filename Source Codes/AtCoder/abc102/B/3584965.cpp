#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  int A[N];
  cin >> A[0];
  int lower = A[0], upper = A[0];
  for (int i = 1; i < N; ++i) {
    cin >> A[i];
    if (A[i] < lower) lower = A[i];
    else if (A[i] > upper) upper = A[i];
  }
  cout << upper - lower << '\n';
  return 0;
}