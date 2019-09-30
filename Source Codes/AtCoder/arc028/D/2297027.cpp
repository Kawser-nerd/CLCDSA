#include <cstdio>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;

int N, M, Q;
int A[2000];
int dp1[2001][2001];
int dp2[2001][2001];

int main() {


  scanf("%d %d %d", &N, &M, &Q);
  int all = 0;
  for(int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
    all += A[i];
  }

  dp1[0][0] = 1;
  for(int i = 0; i < N; i++) {
    int sum = 0;
    for(int j = 0; j <= M; j++) {
      (sum += dp1[i][j]) %= mod;
      (dp1[i + 1][j] += sum) %= mod;
      if(j - A[i] >= 0) (sum += mod - dp1[i][j - A[i]]) %= mod;
    }
  }

  dp2[N][0] = 1;
  for(int i = N - 1; i >= 0; i--) {
    int sum = 0;
    for(int j = 0; j <= M; j++) {
      (sum += dp2[i + 1][j]) %= mod;
      (dp2[i][j] += sum) %= mod;
      if(j - A[i] >= 0) (sum += mod - dp2[i + 1][j - A[i]]) %= mod;
    }
  }

  for(int i = 0; i < Q; i++) {
    int k, x;
    scanf("%d %d", &k, &x);
    --k;
    int rest = M - x;
    __int128_t ret = 0;
    for(int j = 0; j <= rest; j++) {
      ret += 1LL * dp1[k][j] * dp2[k + 1][rest - j];
    }
    printf("%d\n", (int) (ret % mod));
  }
}