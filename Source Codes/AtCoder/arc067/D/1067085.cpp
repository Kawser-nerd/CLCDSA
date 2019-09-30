#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

typedef long long int64;

int N, M;
int64 A[5001];
int B[5001][200];
int ans[200];

int main()
{

  scanf("%d %d", &N, &M);
  for(int i = 1; i < N; i++) {
    scanf("%lld", &A[i]);
    A[i] += A[i - 1];
  }
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) scanf("%d", &B[i][j]);
  }

  int64 ret = 0;
  for(int i = 0; i < N; i++) {
    memset(ans, 0, sizeof(ans));
    int64 res = 0;
    for(int j = i; j < N; j++) {
      for(int k = 0; k < M; k++) {
        if(ans[k] < B[j][k]) {
          res += B[j][k] - ans[k];
          ans[k] = B[j][k];
        }
      }
      ret = max(ret, res + A[i] - A[j]);
    }
  }

  printf("%lld\n", ret);
}