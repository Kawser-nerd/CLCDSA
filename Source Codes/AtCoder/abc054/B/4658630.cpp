#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  int N, M;
  cin >> N >> M;
  vector<string> A(N);
  vector<string> B(M);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (int j = 0; j < M; j++) {
    cin >> B[j];
  }
  // cout<<"ok20"<<endl;
  for (int i = 0; i <= N - M; i++) {
    // cout<<"ok"<<endl;
    for (int j = 0; j <= N - M; j++) {
      for (int k = 0; k < M; k++) {
        for (int l = 0; l < M; l++) {
          if (A[i + k][j + l] != B[k][l]) goto label;
          if (k == M - 1 && l == M - 1) {
            cout << "Yes" << endl;
            return 0;
          }
        }
      }
    label:
      if (0) {
      };
    }
  }
  cout << "No" << endl;

  return 0;
}