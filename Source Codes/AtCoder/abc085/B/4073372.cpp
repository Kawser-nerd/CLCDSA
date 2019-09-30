#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  int d[N];
  for (int i = 0; i < N; i++) {
    cin >> d[i];
  }
  sort(d, d + N, greater<int>());

  int max = 0;
  int prev = 0;
  for (int i = 0; i < N; i++) {
    if (d[i] != prev) {
      max++;
      prev = d[i];
    }
  }

  cout << max << endl;
  return 0;
}