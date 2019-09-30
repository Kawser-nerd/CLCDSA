#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <cstdlib>
#include <utility>

using namespace std;

int solve(const vector<double>& A, const vector<double>& B) {
  int result = 0;
  int N = A.size();
  for(int i = N - 1, j = N - 1; i >= 0; i--) {
    if(A[j] > B[i]) {
      result++;
      j--;
    }
  }
  return result;
}

int main() {
  int T; cin >> T;
  for(int t = 1; t <= T; t++) {
    int N; cin >> N;
    vector<double> A(N), B(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    printf("Case #%d: %d %d\n", t, solve(A, B), N - solve(B, A));
  }
  return 0;
}
