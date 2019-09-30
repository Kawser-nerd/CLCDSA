#include <stdlib.h>
#include <stdio.h>

int cmp(const void *a, const void *b) {
  return *(int*)a - *(int*)b;
}

int main(void) {
  int N, K;
  scanf("%d %d", &N, &K);

  int XY[N][2];
  int Xs[N], Ys[N];
  for (int i = 0; i < N; ++i) {
    scanf("%d %d", &XY[i][0], &XY[i][1]);
    Xs[i] = XY[i][0];
    Ys[i] = XY[i][1];
  }
  qsort(Xs, N, sizeof(int), cmp);
  qsort(Ys, N, sizeof(int), cmp);

  unsigned long long ans = -1;

  for (int l = 0; l < N-1; ++l) {
    for (int r = l + 1; r < N; ++r) {
      for (int d = 0; d < N-1; ++d) {
        for (int u = d + 1; u < N; ++u) {
          int ll = Xs[l], rr = Xs[r];
          int dd = Ys[d], uu = Ys[u];
          unsigned long long area = (unsigned long long)(rr - ll) * (uu - dd);
          // printf("ll:%d, rr:%d, dd:%d, uu:%d, area:%llu\n", ll, rr, dd, uu, area);
          if (area >= ans)
            continue;

          int sum = 0;
          for (int i = 0; i < N; ++i) {
            int x = XY[i][0];
            int y = XY[i][1];
            if (ll <= x && x <= rr && dd <= y && y <= uu)
              ++sum;
            if (sum >= K) {
              ans = area;
              break;
            }
          }
        }
      }
    }
  }

  printf("%llu\n", ans);
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &N, &K);
   ^
./Main.c:15:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &XY[i][0], &XY[i][1]);
     ^