#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;
typedef int64_t i64;

int main() {
  i64 T;
  scanf("%lld", &T);
  for (i64 zz = 1; zz <= T; zz++) {
    i64 N, Q;
    scanf("%lld %lld", &N, &Q);
    vector<i64> E(N), S(N);
    for (i64 i = 0; i < N; i++) {
      scanf("%lld %lld", &E[i], &S[i]);
    }
    vector<vector<i64>> D(N, vector<i64>(N));
    for (i64 i = 0; i < N; i++) {
      for (i64 j = 0; j < N; j++) {
        scanf("%lld", &D[i][j]);
        if (D[i][j] == -1) {
          if (i != j) {
            D[i][j] = 1e16;
          } else {
            D[i][j] = 0;
          }
        }
      }
    }

    for (i64 k = 0; k < N; k++)
      for (i64 i = 0; i < N; i++)
        for (i64 j = 0; j < N; j++)
          D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
    vector<vector<double>> T(N, vector<double>(N));
    for (i64 i = 0; i < N; i++) {
      for (i64 j = 0; j < N; j++) {
        T[i][j] = E[i] >= D[i][j] ? static_cast<double>(D[i][j]) / S[i] : 1e16;
      }
    }
    for (i64 k = 0; k < N; k++)
      for (i64 i = 0; i < N; i++)
        for (i64 j = 0; j < N; j++)
          T[i][j] = min(T[i][j], T[i][k] + T[k][j]);

    printf("Case #%lld:", zz);
    for (i64 i = 0; i < Q; i++) {
      i64 u, v;
      scanf("%lld %lld", &u, &v);
      u--;
      v--;
      printf(" %.09f", T[u][v]);
    }
    printf("\n");
  }
}
