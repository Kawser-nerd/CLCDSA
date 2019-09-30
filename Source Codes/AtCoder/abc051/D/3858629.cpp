#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using Matrix  = vector<vector<int>>;
const int INF = 100000000;

Matrix d;

int main() {
  int N, M;
  cin >> N >> M;

  int A[M], B[M], C[M];
  d = Matrix(N, vector<int>(N, INF));
  for (int i = 0; i < N; i++) {
    d[i][i] = 0;
  }

  for (int i = 0; i < M; i++) {
    cin >> A[i] >> B[i] >> C[i];
    A[i]--, B[i]--;
  }

  for (int i = 0; i < M; i++) {
    d[A[i]][B[i]] = min(d[A[i]][B[i]], C[i]);
    d[B[i]][A[i]] = min(d[B[i]][A[i]], C[i]);
  }

  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }

  int ans = M;
  for (int i = 0; i < M; i++) {
    bool flag = false;
    for (int j = 0; j < N; j++)
      if (d[j][A[i]] + C[i] == d[j][B[i]])
        flag = true;
    if (flag)
      ans--;
  }

  cout << ans << endl;
  return 0;
}