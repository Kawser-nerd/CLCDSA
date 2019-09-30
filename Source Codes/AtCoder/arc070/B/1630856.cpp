#include <iostream>
 
using namespace std;
 
int N, K, A[5000];
bool dp1[5002][5001];
bool dp2[5002][5001];
 
 
int main()
{
  cin >> N >> K;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    A[i] = min(A[i], K);
  }
 
  dp1[0][0] = true;
  for(int i = 0; i < N; i++) {
    for(int j = K; j >= A[i]; j--) {
      dp1[i + 1][j] |= dp1[i][j - A[i]];
    }
    for(int j = K; j >= 0; j--) {
      dp1[i + 1][j] |= dp1[i][j];
    }
  }
 
  dp2[N][0] = true;
  for(int i = N - 1; i >= 0; i--) {
    for(int j = K; j >= A[i]; j--) {
      dp2[i][j] |= dp2[i + 1][j - A[i]];
    }
    for(int j = K; j >= 0; j--) {
      dp2[i][j] |= dp2[i + 1][j];
    }
  }
 
  int ret = N;
  for(int i = 1; i <= N; i++) {
    bool flag = false;
    for(int j = K - A[i - 1]; j < K; j++) {
      for(int k = 0; k <= j; k++) {
        int other = j - k;
        if(0 <= other && other < K) {
          if(dp1[i - 1][k] && dp2[i][other]) {
            flag = true;
            break;
          }
        }
      }
      if(flag) break;
    }
    ret -= flag;
  }
 
  cout << ret << endl;
}