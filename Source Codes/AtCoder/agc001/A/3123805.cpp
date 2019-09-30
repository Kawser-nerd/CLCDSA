#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <utility>

using namespace std;

int N;
int L[200];

int main() {
  cin >> N;
  for (int i = 0; i < 2 * N; i++) {
    cin >> L[i];
  }
  sort(L, L + 2*N);

  int res = 0;
  for (int i = 0; i < N; i++) {
    res += L[2 * i];
  }
  cout << res << endl;
  return 0;
}